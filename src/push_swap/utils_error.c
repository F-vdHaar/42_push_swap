/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:42:48 by fvon-de           #+#    #+#             */
/*   Updated: 2025/01/11 21:13:26 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_exit(char *message, int mode)
{
	if (mode == 0)
	{
		ft_printf("%s\n", message);
		exit(EXIT_SUCCESS);
	}
	else if (mode == 1)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}
