/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 06:47:01 by wnguyen           #+#    #+#             */
/*   Updated: 2023/12/14 18:02:06 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
* Affiche le répertoire de travail actuel sur la sortie standard.
* En cas d'erreur, affiche un message d'erreur.
*/

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		ft_putstr_fd(cwd, 1);
		free(cwd);
	}
	else
	{
		perror("ft_pwd: getcwd error");
	}
	ft_putchar_fd('\n', 1);
}
