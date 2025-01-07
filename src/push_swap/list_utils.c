/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:54:01 by fvon-de           #+#    #+#             */
/*   Updated: 2025/01/07 17:39:01 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_args(char **argv, t_list **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(stack_a, ft_lstnew_int(ft_atoi(argv[i])));
		i++;
	}
}

t_list	*ft_lstnew_int(int value)
{
	t_list	*new;
	int		*content;

	new = malloc(sizeof (t_list));
	if (!new)
		print_exit("Allocation stack failed", 1);
	content = (int *)malloc(sizeof(int));
	if (!content)
	{
		free(new);
		print_exit("Allocation int * failed", 1);
		return (NULL);
	}
	*content = value;
	new->content = content;
	new->next = NULL;
	return (new);
}
