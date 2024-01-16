/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   off_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:26:34 by blax              #+#    #+#             */
/*   Updated: 2024/01/16 20:37:35 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				g_info;

int main(int argc, char *argv[])
{
    t_data data;

    if (argc < 2)
        return (0);
    init_data(&data, argv[1]);
    verif_syntax(&data);
    // ft_lexer(data);
    // parse_input(data);
    // expand_tokens(data);
    // build_ast(tree, data);
    // print_ast(tree);
    // free_data(&data);
    return (0);
}