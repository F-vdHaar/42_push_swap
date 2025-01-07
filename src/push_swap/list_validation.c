/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:43:39 by fvon-de           #+#    #+#             */
/*   Updated: 2025/01/07 13:04:15 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	int	i;

	i = *(int *)stack_a->content;
	while (stack_a)
	{
		if (i > *(int *)stack_a->content)
			return (0);
		i = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_duplicate(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (*(int *)a->content == *(int *)tmp->content)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
