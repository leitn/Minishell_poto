/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:17:12 by blax              #+#    #+#             */
/*   Updated: 2023/11/21 15:38:59 by blax             ###   ########.fr       */
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

Test(lexer3, 1)
{
    char *input = "a a a";
    const char *list_tokens[] = {"a", "a", "a", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer3, 2)
{
    char *input = "b b b";
    const char *list_tokens[] = {"b", "b", "b", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer3, 3)
{
    char *input = "ab ab ab";
    const char *list_tokens[] = {"ab", "ab", "ab", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer3, 4)
{
    char *input = "abc abc abc";
    const char *list_tokens[] = {"abc", "abc", "abc", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer3, 5)
{
    char *input = "abcdefghi abcdefghi abcdefghi";
    const char *list_tokens[] = {"abcdefghi", "abcdefghi", "abcdefghi", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer3, 6)
{
    char *input = "abcdefghi abcdefghi abcdefghi abcdefghi";
    const char *list_tokens[] = {"abcdefghi", "abcdefghi", "abcdefghi", "abcdefghi", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}