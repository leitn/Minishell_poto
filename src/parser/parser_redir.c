/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:15:57 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/22 17:30:00 by edesaint         ###   ########.fr       */
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
    if (access(name, F_OK) == -1)
    {
        fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0)
            return (ft_error("open"), false);
        close(fd);
        return (true);
    }
    if (access(name, W_OK) == -1)
        return (ft_error("write access denied"), false);
    return (true);
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
    if (access(name, F_OK) == -1)
    {
        fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
            return (ft_error("open"), false);
        close(fd);
        return (true);
    }
    if (access(name, W_OK) == -1)
        return (ft_error("write access denied"), false);
    return (true);
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
    if (access(name, F_OK))
    {
        fd = open(name, O_RDONLY, 0644);
        if (fd < 0)
            return (ft_error("open"), false);
        close(fd);
        return (true);
    }
    if (access(name, R_OK) == -1)
        return (ft_error("read access denied"), false);
    return (true);
}

// bool is_redir_heredoc(t_token *token)
// {
//     int fd;
//     char *name;

//     if (!token)
//         return (false);
//     if (token->type_token != T_REDIR_HEREDOC)
//         return (false);
//     // code will (implementer le heredoc)
//     return (true);
// }

bool update_redir(t_node *node, t_token *token)
{
    if (is_file_redir(token))
    {
        if (is_redir_in(token))
        {
            node->redir_in = get_name_redir(token);
            if (!node->redir_in)
                return (false);
            node->redir_heredoc = NULL;
        }
        if (is_redir_out(token))
        {
            node->redir_out = get_name_redir(token);
            node->redir_append = NULL;
        }
        if (is_redir_append(token))
        {
            node->redir_append = get_name_redir(token);
            node->redir_out = NULL;
        }
        // if (is_redir_heredoc(token))
        // {
        //     node->redir_heredoc = get_name_redir(token);
        //     node->redir_in = NULL;
        // }
    }
}

// parcourir le maillon et creer si necessaire les fichiers parcourus
bool init_redir(t_data *data, t_node *node, t_token *token)
{
    while (token && in_node(data, token))
    {
        update_redir(node, token);
        token = token->next;
    }
    return (true);
}