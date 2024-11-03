/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:49:37 by fvon-der          #+#    #+#             */
/*   Updated: 2024/08/07 04:19:00 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	a = ft_process_input(argc, argv);
	if (!a)
	{
		ft_free(&a);
		print_exit("Allocation failed, main", 1);
	}
	 if (is_duplicate(a))
	{
		ft_free(&a);
		print_exit("Duplicates", 1);
	}
	if (!is_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}