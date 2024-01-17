/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:33:24 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 21:09:17 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// X 
// ne devrais plus etre utile car on gere les doubles quotes en amont mais on peut toujours y faire reference
// si besoin avec le type_token->rstick/lstick
// bool is_empty_token(t_token *token)
// {
// 	if (!token)
// 		return (true);
// 	if (token && token->str[0] == '\0'
// 		&& (token->type_str == S_QUOTE
// 		|| token->type_str == D_QUOTE))
// 	{
// 		return (true);
// 	}
// 	return (false);
// }

void parse_input(t_data *data)
{
    parse_quote_tokens(data);
    determine_token_types(data);
}