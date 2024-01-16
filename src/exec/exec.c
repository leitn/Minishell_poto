/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:04:08 by blax              #+#    #+#             */
/*   Updated: 2024/01/15 17:27:47 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Fonction pour exécuter un nœud de commande
void execute_command_node(t_ast_node *node)
{
    char *cmd;

    cmd = node->content.command.args[0];
    if (!cmd)
        exit(EXIT_FAILURE);
    if (node->type != AST_COMMAND)
    {
        fprintf(stderr, "Tentative d'exécution d'un type de nœud non-commande\n");
        return ;
    }
    if (fork() == 0)
    {
        execvp(cmd, node->content.command.args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL); // Attendre que le processus enfant se termine
    }
}

int	execute_redir_node(t_tree *tree, t_ast_node *node)
{
	int		ret;
    t_state redir_type;
    int save_fd[2];

    save_fd[IN] = STDIN_FILENO;
    save_fd[OUT] = STDOUT_FILENO;
    redir_type = node->content.redirect.type;
    if (redir_type == T_REDIR_IN)
        ret = apply_redir_in(tree, node);
    else if (redir_type == T_REDIR_OUT)
        ret = apply_redir_out(tree, node);
    else if (redir_type == T_REDIR_APPEND)
        ret = apply_redir_append(tree, node);
    // else if (redir_type == T_REDIR_HEREDOC)
    //     return (apply_redir_heredoc(tree, node));
    if (ret == FAILURE)
        return (FAILURE);
    execute_ast(tree, node->content.redirect.child);
	restore_std(tree, save_fd);

	return (SUCCESS);
}

// Fonction pour exécuter un nœud de pipe
int execute_pipe_node(t_tree *tree, t_ast_node *node)
{
    int fds[2];

    if (pipe(fds) == -1)
        ft_error("pipe");
    if (fork() == 0)
    {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
        execute_ast(tree, node->content.pipe.left);
        close(fds[1]);
        return (SUCCESS);
    }
    else
    {
        close(fds[1]);
        if (fork() == 0)
        {
            dup2(fds[0], STDIN_FILENO);
            execute_ast(tree, node->content.pipe.right);
            close(fds[0]);
            return (SUCCESS);
        }
    }
    close(fds[0]);
    wait(NULL);
    wait(NULL);
    return (SUCCESS);
}

// Fonction pour exécuter l'AST
void execute_ast(t_tree *tree, t_ast_node *ast)
{
    if (ast == NULL)
        return ;

    if (ast->type == AST_COMMAND)
        execute_command_node(ast);
    else if (ast->type == AST_PIPE)
        execute_pipe_node(tree, ast);
    else if (ast->type == AST_REDIRECT)
        execute_redir_node(tree, ast);
}