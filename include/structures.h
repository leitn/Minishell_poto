/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:19:02 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 20:51:05 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>
# include "enum.h"

typedef struct s_redirect
{
    t_state type;
    char *file;
    struct s_redirect *next;
} t_redirect;

typedef struct s_token
{
	int				id;
	char			*str;
    bool            is_space;
	t_stick_token	type_str;
	t_stick_token	type_rstick;
	t_stick_token	type_lstick;
	t_state			type_token;
	struct s_token	*next;
    struct s_token	*prev;
}				t_token;

typedef struct s_node
{
    int             id;
    // int             start_token;
    // int             end_token;
    char			**tab_exec;
    struct s_redirect *redirs;
    // struct s_token	*tokens;
	struct s_node	*next;
} t_node;

typedef struct s_data
{
    int             start;
    int             end;
    int             nb_tokens;
    bool            is_space;
    char            type_quote;
    char            in_quote;
    char            *str;
    struct s_token	*token;
	struct s_node	*node;
}				t_data;

#endif
