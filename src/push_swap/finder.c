/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:07:55 by fvon-der          #+#    #+#             */
/*   Updated: 2024/08/09 18:20:28 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_min(t_list *a)
{
	int		i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content < i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_list *a)
{
	int		i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_find_index(t_list *a, int nbr)
{
	int		i;

	i = 0;
	while (*(int *)a->content != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_find_place_b(t_list *stack_b, int nbr_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr_push > *(int *) stack_b->content && nbr_push
		< *(int *)ft_lstlast(stack_b)->content)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (*(int *)stack_b->content < nbr_push
			|| *(int *)tmp->content > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_list *stack_a, int nbr_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr_push < *(int *)stack_a->content && nbr_push
		> *(int *)ft_lstlast(stack_a)->content)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (*(int *)stack_a->content > nbr_push
			|| *(int *)tmp->content < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
