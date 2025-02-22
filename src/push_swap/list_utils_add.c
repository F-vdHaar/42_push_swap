/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:18:27 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/22 12:48:00 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(t_list **lst)
{
    t_list *current;
    t_list *next;

    if (!lst || !*lst)
        return;
    current = *lst;
    while (current)
    {
        next = current->next;
        if (current->content) // Free the int *content
            free(current->content);
        free(current); // Free the node itself
        current = next;
    }
    *lst = NULL;
}
