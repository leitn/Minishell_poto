/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:46:52 by blax              #+#    #+#             */
/*   Updated: 2023/12/25 08:57:27 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool ft_error(char *str)
{
    perror(str);
    return (FAILURE);
}

bool ft_error_2(char *str)
{
    perror(str);
    exit (FAILURE);
}