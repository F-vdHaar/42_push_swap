/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:53:07 by fvon-de           #+#    #+#             */
/*   Updated: 2025/01/07 17:38:41 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list		*ft_sub_process(char **argv);

static t_list	*ft_sub_process(char **argv)
{
	t_list	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi(tmp[i]);
		ft_lstadd_back(&a, ft_lstnew_int(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_list	*ft_process_input(int argc, char **argv)
{
	t_list	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		print_exit("Usage: Provide input.", 1);
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi(argv[i]);
			ft_lstadd_back(&a, ft_lstnew_int(j));
			i++;
		}
	}
	return (a);
}
