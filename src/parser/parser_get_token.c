/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:22:11 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/18 22:35:13 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *get_command(t_data *data)
{
    t_token *token;

    token = data->token;
    if (token == NULL)
        return (NULL);
    if (in_node(data, token) && \
        token->type_token == T_COMMAND && token->id == data->start)
    {
        return (token->str);
    }
    return (NULL);
}

t_token *place_token(t_data *data)
{
    t_token *token;

    token = data->token;
    if (!token)
        return (NULL);
    while (token && token->id != data->start)
        token = token->next;
    return (token);
}

// ajouter en attribut de la structure token, le nombre de double quotes successsives
// ajouter en attribut de la structure token, le nombre de double spaces successsives

// bool go_to_end()
// dans la tructure data/ ou dans create_tab_exec avoir une variable 
// qui recupere le token->id du token argument renvoyer
// char *get_argument(t_data *data, int *place_arg)
// {
//     t_token *token;

//     if (place_arg == token->id)
//     {
//         while (token != NULL && token->type_token != T_ARGUMENT)
//             token = token->next;
//     }
//     else if (place_arg > token->id)
//     {
//         while (token != NULL && token->id != place_arg)
//             token = token->next;
//     }
//     if (token == NULL)
//         return (NULL);
//     if (token->type_token == T_ARGUMENT)
//     {
//         place_arg = token->id;
//         return (token->str);
//     }
//     return (NULL);
// }

char *get_argument(t_token *token)
{
    while (token != NULL && token->type_token != T_ARGUMENT)
        token = token->next;
    if (token == NULL)
        return (NULL);
    if (token->type_token == T_ARGUMENT)
        return (token->str);
    return (NULL);
}

char **create_tab_exec(t_data *data)
{
    t_token *token;
    int nb_args;
    char **tab_exec;
    int i;
    
    token = place_token(data);
    if (!token)
        return (NULL);
    nb_args = compt_args(data);
    if (nb_args < 0)
        ft_error("Il n'y a pas de token !");
    tab_exec = malloc(sizeof(char *) * (nb_args + 1));
    if (!tab_exec)
        return (NULL);
    tab_exec[0] = get_command(data);
    if (!tab_exec[0])
        return (NULL);
    while (i < nb_args)
    {
        tab_exec[i] = get_argument(token);
        token = token->next;
        i++;
    }
    tab_exec[i] = NULL;
    return (tab_exec);
}