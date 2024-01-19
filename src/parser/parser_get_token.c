/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:22:11 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/19 15:14:30 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *get_command(t_token *token)
{
    if (token == NULL)
        return (NULL);
    if (token->type_token == T_COMMAND)
        return (token->str);
    return (NULL);
}

// il faut absolument que le token bouge de place et le reste
t_token *next_arg(t_data *data, t_token *token)
{
    if (!token)
        return (NULL);
    while (token != NULL)
    {
        if (in_node(data, token))
        {
            if (token->type_token == T_ARGUMENT)
            {
                return (token);
            }
        }
        token = token->next;
    }
    return (NULL);
}

char *get_argument(t_data *data, t_token *token)
{
    token = next_arg(data, token);
    if (!token)
        return (NULL);
    return (token->str);
}

char **create_tab_exec(t_data *data, int nb_args)
{
    char **tab_exec;
    t_token *token;
    int i;

    i = 0;
    token = data->token;
    tab_exec = malloc(sizeof(char *) * (nb_args + 1));
    if (!tab_exec)
        return (NULL);
    tab_exec[0] = get_command(token);
    if (!tab_exec[0])
        return (NULL);
    token = token->next;
    while (i < nb_args) // while(token != NULL)
    {
        tab_exec[i] = get_argument(data, token); // END_NODE enum pour dire signifier la fin du maillon
        if (!tab_exec[i])
            ft_error("Erreur: argument");
        token = token->next;
        i++;
    }
    tab_exec[i] = NULL;
    return (tab_exec);
}

char **init_tab_exec(t_data *data)
{
    int nb_args;
    
    nb_args = compt_args(data);
    if (nb_args < 0)
        ft_error("Il n'y a pas de token !");
    return (create_tab_exec(data, nb_args));
}