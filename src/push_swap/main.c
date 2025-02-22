/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:49:37 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/22 12:53:12 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	a = ft_process_input(argc, argv);
	if (!a)
	{
		ft_free(&a);
		ft_printf("Allocation failed, [main]");
		return (EXIT_FAILURE);
	}
	if (is_duplicate(a))
	{
		ft_free(&a);
		ft_printf("Duplicates");
		return (0);
	}
	if (!is_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
