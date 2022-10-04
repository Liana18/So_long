/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:28:17 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/13 21:05:52 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int nb, char *str)
{	
	if (nb < 2)
		print_error("                Error\n\n         Too few arguments 😥");
	else if (nb > 2)
		print_error("                Error\n\n         Too many arguments 😥");
	else if (check_ber(str))
		print_error("                Error\n\n The arguments is not .ber format");
}
