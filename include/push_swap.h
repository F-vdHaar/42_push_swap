/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:59:30 by fvon-der          #+#    #+#             */
/*   Updated: 2024/11/03 01:58:25 by fvon-de          ###   ########.fr       */
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
#endif