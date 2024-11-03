/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:42:48 by fvon-de           #+#    #+#             */
/*   Updated: 2024/11/03 01:43:05 by fvon-de          ###   ########.fr       */
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
