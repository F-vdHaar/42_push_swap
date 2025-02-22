/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:47:20 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/22 13:36:52 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_command_add(t_list **a, t_list **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

char	*ft_command_exec(t_list **a, t_list **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_command_add(a, b, line);
	else
	{
		ft_printf("KO");
		return (NULL);
	}
	return (get_next_line(0));
}

void	ft_ps_operation_validity(t_list **a, t_list **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_command_exec(a, b, line);
		free(tmp);
		if (!line)
			return ;
	}
	if (*b)
		ft_printf("KO\n");
	else if (!is_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	b = NULL;
	a = ft_process_input(argc, argv);
	if (!a || is_duplicate(a))
	{
		ft_free (&a);
		ft_printf("Error Duplicates  |  checker\n");
		exit(EXIT_SUCCESS);
	}
	line = get_next_line(0);
	if (!line && !is_sorted(a))
		ft_printf("KO\n");
	else if (!line && is_sorted(a))
		ft_printf("OK\n");
	else
		ft_ps_operation_validity(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
