/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:20:39 by blax              #+#    #+#             */
/*   Updated: 2024/01/15 18:56:53 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int apply_redir_in(t_tree *tree, t_ast_node *node)
{
    int fd;
    char *name;

    name = node->content.redirect.file;
    fd = open(name, O_RDONLY);
    if (fd < 0)
        return (ft_error("open"));
    if (tree->fd[IN] == 0)
    {
        if (dup2(fd, tree->fd[IN]) < 0)
        {
            close(fd);
            return (ft_error("dup2"));
        }
    }
    close(fd);
    return (SUCCESS);
}

int apply_redir_append(t_tree *tree, t_ast_node *node)
{
    int fd;
    char *name;

    if (tree->fd[OUT] == 1)
    {
        name = node->content.redirect.file;
        fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0)
            return (ft_error("open"));
        if (dup2(fd, tree->fd[OUT]) < 0)
        {
            close(fd);
            return (ft_error("dup2"));
        }
        tree->fd[OUT] = fd;
    }
    close(fd);

    return (SUCCESS);
}

int apply_redir_out(t_tree *tree, t_ast_node *node)
{
    int fd;
    char *name;

    if (tree->fd[OUT] == 1)
    {
        name = node->content.redirect.file;
        fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
            return (ft_error("open"));
        if (dup2(fd, tree->fd[OUT]) < 0)
        {
            close(fd);
            return (ft_error("dup2"));
        }
        close(fd);
    }
    
    return (SUCCESS);
}

// int apply_redir_heredoc(t_tree *tree, t_ast_node *node)
// {
//     return (0);
// }

void restore_std(t_tree *tree, int save_fd[2])
{
    if (dup2(save_fd[IN], tree->fd[IN]) < 0)
    {
        close(save_fd[IN]);
        ft_error("dup2");
    }
    close(save_fd[IN]);
    if (dup2(save_fd[OUT], tree->fd[OUT]) < 0)
    {
        close(save_fd[OUT]);
        ft_error("dup2");
    }
    close(save_fd[OUT]);
}