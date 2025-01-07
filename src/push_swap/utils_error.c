/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:42:48 by fvon-de           #+#    #+#             */
/*   Updated: 2025/01/07 17:37:46 by fvon-der         ###   ########.fr       */
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
		ft_printf("\nError: %s\n", message);
		exit(EXIT_FAILURE);
	}
}
