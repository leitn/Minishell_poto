/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:17:12 by blax              #+#    #+#             */
/*   Updated: 2023/11/21 15:53:40 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../../include/minishell.h"
#include "../../include/test_common.h"

// TEST LEXER:
// 1 chaine de caractere
// différentes taille
// caracteres alphanumerique

Test(lexer2, 1)
{
    char *input = "a a";
    const char *list_tokens[] = {"a", "a", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer2, 2)
{
    char *input = "b b";
    const char *list_tokens[] = {"b", "b", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer2, 3)
{
    char *input = "ab ab";
    const char *list_tokens[] = {"ab", "ab", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer2, 4)
{
    char *input = "abc abc";
    const char *list_tokens[] = {"abc", "abc", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer2, 5)
{
    char *input = "abcdefghi abcdefghi";
    const char *list_tokens[] = {"abcdefghi", "abcdefghi", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}