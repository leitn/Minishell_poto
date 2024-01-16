/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:17:12 by blax              #+#    #+#             */
/*   Updated: 2023/12/06 18:34:03 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../../include/minishell.h"
#include "../../include/test_common.h"

// TEST LEXER:
// plusieurs chaine de caractere
// différentes taille
// caracteres alphanumerique

Test(lexer5, 1)
{
    char *input = "a  a";
    const char *list_tokens[] = {"a", "a", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer5, 2)
{
    char *input = "bz bz bz bzzzzz a111111111111111 r";
    const char *list_tokens[] = {"bz", "bz", "bz", "bzzzzz", "a111111111111111", "r", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer5, 3)
{
    char *input = "abcdefghi abcdefghi abcdefghi abcdefghi";
    const char *list_tokens[] = {"abcdefghi", "abcdefghi", "abcdefghi", "abcdefghi", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer5, 4)
{
    char *input = "a b c d e f g h i j";
    const char *list_tokens[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}