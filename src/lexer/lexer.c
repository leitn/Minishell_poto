/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:08:04 by blax              #+#    #+#             */
/*   Updated: 2024/01/16 20:17:29 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Crée un nouveau token avec les données fournies et le retourne. */
t_token *create_token(t_data *data, int end)
{
    t_token *token;
    int len;
    
    len = end - data->start;
    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->id = data->nb_tokens;
    token->type_token = T_NOREDIR;
    token->str = ft_substr(data->str, (unsigned int) data->start, (size_t) len);
    token->type_str = ft_type_char(data->str[--end]);
    token->type_stick = ft_type_char(data->str[++end]);
    token->prev = NULL;
    token->next = NULL;
    
    return (token);
}

/* Ajoute un nouveau token à la liste chaînée de tokens dans 'data'. */
void add_token(t_data *data, int end)
{
    t_token *new_token;
    t_token *temp;

    new_token = create_token(data, end);
    if (new_token)
    {
        if (data->token == NULL)
        {
            new_token->prev = NULL;
            data->token = new_token;
        }
        else
        {
            temp = data->token;
            while (temp->next != NULL)
                temp = temp->next;
            new_token->prev = temp;
            temp->next = new_token;
        }
    }
}

/* Traite une séquence de guillemets dans la chaîne de caractères de 'data'. */
int process_quote(t_data *data, int *i)
{
    char type_quote;

    if (!data->str[*i])
        return (0);
    if (!is_quote(data->str[*i]))
        return (0);
    type_quote = data->str[*i];
    (*i)++;
    while (data->str[*i])
    {
        if (data->str[*i] && is_quote(data->str[*i]))
        {
            if (data->str[*i] == type_quote)
            {
                // if ((*i)++ - data->start == 1)
                //     return (2); 
                (*i)++;
                return (1);
            }
        }
        (*i)++;
    }
    return (1);
}

/* Analyse la chaîne de caractères 'str' et remplit 'data' avec les tokens. */
void ft_lexer(t_data *data)
{
    int i;
    int result;
    
    i = 0;
    while (data->str[i])
    {
        skip_spaces(data, &i);
        data->start = i;
        result = process_quote(data, &i);
        // if (result == 0)
        //     result = process_grammar(data, &i);
        if (result == 0)
            process_space(data, &i);
        
        // if (ret_pq != 2)
        add_token(data, i);
        // i--;
        data->nb_tokens++;
        // if (str[i] == '\0')
        //     return ;
        // i++;
    }
}