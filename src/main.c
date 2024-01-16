/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:51 by blax              #+#    #+#             */
/*   Updated: 2023/12/25 08:05:05 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

int				g_info;

// il faut afficher un message de sortie: "exit" quand on clique sur ctrl+D
void handle_signal(int signo)
{
    // Vous pouvez personnaliser la gestion des signaux ici si nécessaire
    if (signo == SIGINT)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        write(STDOUT_FILENO, "\n", 1);
    }
}

int main(int argc, char *argv[])
{
    t_tree *tree;
    char *command;

    if (argc > 1)
    {
        printf("minishell : parameters : bad usage\n");
        return (0);
    }
    argv[0] = '\0';
    signal(SIGINT, handle_signal);
    while (1)
    {
        command = readline("minishell> ");
        if (command == NULL)
        {
            printf("exit\n");
            break; // Sortir de la boucle si Ctrl+D est pressé
        }
        if (command && *command)
        {
            add_history(command);
            ft_main(tree, command);
            printf("\n");
        }
        free(command);
    }
    rl_clear_history();
    free_tree(tree);

    return (0);
}

int ft_main(t_tree *tree, char *str)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (0);
    init_data(data, str);
    ft_lexer(data);
    parse_input(data);
    // print_tokens(data->token);
    expand_tokens(data);
    print_expanded_tokens(data->token);
    print_ast(tree);
    // print_tokens_for_python(data->token);
    free_data(data);
    return (0);
}