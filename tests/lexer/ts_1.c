/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:17:12 by blax              #+#    #+#             */
/*   Updated: 2023/11/21 15:54:23 by blax             ###   ########.fr       */
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

Test(lexer1, 1)
{
    char *input = "a";
    const char *list_tokens[] = {"a", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer1, 2)
{
    char *input = "b";
    const char *list_tokens[] = {"b", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer1, 3)
{
    char *input = "ab";
    const char *list_tokens[] = {"ab", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer1, 4)
{
    char *input = "abc";
    const char *list_tokens[] = {"abc", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}

Test(lexer1, 5)
{
    char *input = "abcdefghi";
    const char *list_tokens[] = {"abcdefghi", NULL};
    
    t_token *tokens = ft_lexer(input);
    t_token *current_token = tokens;
    check_all_tokens(current_token, list_tokens);
}