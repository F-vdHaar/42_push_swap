/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:59:30 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/07 14:21:24 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

// Input 
t_list		*ft_process_input(int argc, char **argv);
// list utils
void		list_args(char **argv, t_list **stack_a);
t_list		*ft_lstnew_int(int value);
// list_utils add
void		ft_free(t_list **lst);
// list validation
int			is_sorted(t_list *stack_a);
int			is_duplicate(t_list *a);
//Error utils
void		print_exit(char *message, int mode);
// sorter
void		ft_sort(t_list **stack_a);
// LIBFT add
int			ft_issign(int c);
int			ft_isspace(int c);
void		ft_freestr(char **lst);
#endif