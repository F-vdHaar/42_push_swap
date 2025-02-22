/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:53:07 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/22 12:57:38 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list		*ft_sub_process(char **argv);
static int			is_valid_integer(const char *str);
static t_list *process_arg(t_list **a, char *arg);

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
			ft_printf("Error: Input not valid Integer");
            ft_freestr(tmp);
            free(tmp);
            return (NULL);
		}
		j = ft_atoi(tmp[i]);
		ft_lstadd_back(&a, ft_lstnew_int(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}
static t_list *process_arg(t_list **a, char *arg)
{
    int     val;
    int     *content;
    t_list  *new_node;

    if (!is_valid_integer(arg))
    {
        ft_free(a);
        ft_printf("Error: Invalid integer: %s\n", arg);
        return (NULL);
    }
    val = ft_atoi(arg);
    content = malloc(sizeof(int));
    if (!content)
    {
        ft_free(a);
        return (NULL);
    }
    *content = val;
    new_node = ft_lstnew(content);
    if (!new_node)
    {
        free(content);
        return (ft_free(a), NULL);
    }
    ft_lstadd_back(a, new_node);
    return (*a);
}

t_list *ft_process_input(int argc, char **argv)
{
    t_list *a;
    int i;

    if (argc < 2)
        exit(EXIT_FAILURE);
    if (argc == 2)
        return (ft_sub_process(argv));
    a = NULL;
    i = 1;
    while (i < argc)
    {
        if (!process_arg(&a, argv[i]))
            return (NULL);
        i++;
    }
    return (a);
}
