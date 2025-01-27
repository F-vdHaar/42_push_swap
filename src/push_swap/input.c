/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:53:07 by fvon-de           #+#    #+#             */
/*   Updated: 2025/01/11 21:54:19 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list		*ft_sub_process(char **argv);
static int			is_valid_integer(const char *str);

static int	is_valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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
		if (!is_valid_integer(argv[i]))
		{
			print_exit("No", 1);
		}
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
		exit(EXIT_FAILURE);
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			if (!is_valid_integer(argv[i]))
			{
				print_exit("No", 1);
			}
			j = ft_atoi(argv[i]);
			ft_lstadd_back(&a, ft_lstnew_int(j));
			i++;
		}
	}
	return (a);
}
