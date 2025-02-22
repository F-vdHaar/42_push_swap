/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:53:10 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/22 12:48:31 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exec_rarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while (*(int *)(*a)->content != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (*(int *)(*b)->content != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while (*(int *)(*b)->content != c)
			ft_rb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_exec_rrarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while (*(int *)(*a)->content != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (*(int *)(*b)->content != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while (*(int *)(*b)->content != c)
			ft_rrb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_exec_rrarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while (*(int *)(*b)->content != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_exec_rarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while (*(int *)(*b)->content != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
