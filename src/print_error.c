/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:31:27 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 19:34:55 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	red(void)
{
	write(1, "\033[1;31m", 7);
}

void	reset(void)
{
	write(1, "\033[0m", 3);
}

void	print_error(char *str)
{
	char	*str1;
	char	*str2;

	red();
	str1 = "\n\n\n\n\n\n\n\n\n\n\n......................................\n\n\n";
	str2 = "\n\n\n......................................\n\n\n\n\n\n\n\n\n\n\n";
	write(1, str1, ft_strlen(str1));
	write(1, str, ft_strlen(str));
	write(1, str2, ft_strlen(str2));
	reset();
	exit (1);
}
