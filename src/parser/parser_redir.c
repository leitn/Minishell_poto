/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:15:57 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/20 21:19:01 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_redir_append(t_token *token)
{
    int fd;
    char *name;

    if (!token)
        return (false);
    if (token->type_token != T_REDIR_APPEND)
        return (false);
    name = token->str;
    if (access(name, F_OK) && access(name, W_OK))
    {
        fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0)
            return (ft_error("open"), false);
        close(fd);
        return (true);
    }
    return (false);
}

bool is_redir_out(t_token *token)
{
    int fd;
    char *name;

    if (!token)
        return (false);
    if (token->type_token != T_REDIR_OUT)
        return (false);
    name = token->str;
    if (access(name, F_OK) && access(name, W_OK))
    {
        fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
            return (ft_error("open"), false);
        close(fd);
        return (true);
    }
    return (false);
}

// verifie si il existe et que tu a le droit de le lire
bool is_redir_in(t_token *token)
{
    int fd;
    char *name;

    if (!token)
        return (false);
    if (token->type_token != T_REDIR_IN)
        return (false);
    name = token->str;
    if (access(name, F_OK) && access(name, R_OK))
    {
        fd = open(name, O_RDONLY, 0644);
        if (fd < 0)
            return (ft_error("open"), false);
        close(fd);
        return (true);
    }
    return (false);
}

bool is_redir_heredoc(t_token *token)
{
    int fd;
    char *name;

    if (!token)
        return (false);
    if (token->type_token != T_REDIR_HEREDOC)
        return (false);
    // code will (implementer le heredoc)
    return (false);
}

// - parcourir le maillon et creer si necessaire les fichiers parcourus
bool init_redir(t_data *data, t_node *node, t_token *token)
{
    int fd;

    while (token)
    {
        if (is_file_redir(token))
        {
            if (is_redir_in(token->type_token))
                node->redir_in = token->str;
            if (is_redir_out(token->type_token))
            {
                node->redir_out = token->str;
                node->redir_append = NULL;
            }
            if (is_redir_append(token->type_token))
            {
                node->redir_append = token->str;
                node->redir_out = NULL;
            }
            if (is_redir_heredoc(token->type_token))
                node->redir_heredoc = token->str;
        }
        token = token->next;
    }
}