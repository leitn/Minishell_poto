/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:11:22 by blax              #+#    #+#             */
/*   Updated: 2023/11/21 15:13:30 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/redirect.h>
#include "../../include/test_common.h"

void	redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

// Fonction pour vérifier tous les tokens et avancer vers le suivant
void check_all_tokens(t_token *current_token, const char **expected_tokens)
{
    int i = 0;
    // t_token *deb_token = current_token;

    while (expected_tokens[i] != NULL)
    {
        cr_assert(current_token != NULL);
        cr_assert_str_eq(current_token->string, expected_tokens[i]);
        cr_assert_eq(current_token->type, -1);
        current_token = get_next_token(current_token);
        i++;
    }
    // cr_assert(*current_token == NULL);
    // free_tokens(deb_token);
}

t_token *get_next_token(t_token *current_token)
{
    if (current_token != NULL)
        return (current_token->next);
    return (NULL);
}

// void free_tokens(t_token *tokens)
// {
//     t_token *temp;

//     // Libérer la mémoire allouée pour les tokens (à adapter selon vos besoins)
//     while (tokens != NULL)
//     {
//         temp = tokens;
//         tokens = tokens->next;
//         free(temp->string);
//         free(temp);
//     }
// }

// // Fonction pour vérifier le token actuel et avancer vers le suivant
// void check_and_advance_token(t_token **current_token, 
//     const char *expected_string)
// {
//     cr_assert(*current_token != NULL);
//     cr_assert_str_eq((*current_token)->string, expected_string);
//     cr_assert_eq((*current_token)->type, -1);
//     *current_token = get_next_token(*current_token);
// }