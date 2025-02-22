/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:54:01 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/22 13:38:29 by fvon-de          ###   ########.fr       */
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

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	content = malloc(sizeof(int));
	if (!content)
	{
		free(new);
		return (NULL);
	}
	*content = value;
	new->content = content;
	new->next = NULL;
	return (new);
}
