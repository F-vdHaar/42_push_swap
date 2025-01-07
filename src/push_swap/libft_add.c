/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:23:56 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/07 17:38:11 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

//check if character is space character
//TODO get rid off, use libft
int	ft__isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

void	ft_freestr(char **lst)
{
	char	**temp;

	if (!lst)
		return ;
	temp = lst;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	temp = lst;
	while (*temp)
	{
		temp++;
	}
	if (temp)
	{
		*temp = NULL;
	}
}
