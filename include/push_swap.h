/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:59:30 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/07 14:52:37 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
// Sorter
void		ft_sort(t_list **stack_a);
void		ft_sort_big(t_list **stack_a, t_list **stack_b);
void		ft_sort_min(t_list **stack_a);

// Finders
int			ft_min(t_list *a);
int			ft_max(t_list *a);
int			ft_find_index(t_list *a, int nbr);
int			ft_find_place_b(t_list *stack_b, int nbr_push);
int			ft_find_place_a(t_list *a, int nbr);

// Operations Add
void		ft_ra(t_list **a, int j);
void		ft_rb(t_list **b, int j);
void		ft_sa(t_list **a, int j);
void		ft_pa(t_list **a, t_list **b, int j);
void		ft_pb(t_list **stack_a, t_list **stack_b, int j);
// Operations Add
void		ft_rra(t_list **a, int j);
void		ft_ss(t_list **a, t_list **b, int j);
void		ft_rr(t_list **a, t_list **b, int j);
void		ft_rrr(t_list **a, t_list **b, int j);
// Operations Add 2
void		ft_rrb(t_list **b, int j);
void		ft_sb(t_list **b, int j);

// type rotation
int			ft_calc_rotate_ab(t_list *a, t_list *b);
int			ft_calc_rotate_ba(t_list *a, t_list *b);
// rotation func
int			ft_exec_rarb(t_list **a, t_list **b, int c, char s);
int			ft_exec_rrarrb(t_list **a, t_list **b, int c, char s);
int			ft_exec_rrarb(t_list **a, t_list **b, int c, char s);
int			ft_exec_rarrb(t_list **a, t_list **b, int c, char s);

// LIBFT add
int			ft_issign(int c);
int			ft_isspace(int c);
void		ft_freestr(char **lst);
#endif