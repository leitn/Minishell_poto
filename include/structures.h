/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:19:02 by blax              #+#    #+#             */
/*   Updated: 2024/01/16 20:58:23 by edesaint         ###   ########.fr       */
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

typedef struct s_node
{
    int             id;
    char			**tab_exec;
    struct s_redirect *redirs;
	struct s_node	*next;
} t_node;

typedef struct s_data
{
    char            *str;
    char            type_quote;
    char            in_quote;
	struct s_node	*node;
}				t_data;

#endif
