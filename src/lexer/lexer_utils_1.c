/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:55:05 by blax              #+#    #+#             */
/*   Updated: 2024/01/16 20:23:56 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Avance l'indice 'i' pour ignorer les espaces dans la chaîne de caractères. */
void skip_spaces(t_data *data, int *i)
{
    while (data->str[*i] && is_space(data->str[*i]))
        (*i)++;
}

/* Avance l'indice 'i' jusqu'à ce qu'un espace ou un guillemet soit trouvé. */
bool process_space(t_data *data, int *i)
{
    while (data->str[*i] && !is_space(data->str[*i])
        && !is_quote(data->str[*i])) //&& !is_grammar(data, i))
    {
        (*i)++;
    }
    return (true);
}

int ft_end_string(char *str)
{
    int i;
    
    i = ft_strlen(str) - 1;
    while (i >= 0 && is_space(str[i]))
        i--;
    return (++i);
}