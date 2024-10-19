/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:36:21 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 21:46:12 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_list **list_a, t_list **list_b)
{
	rotate_a(list_a);
	rotate_b(list_b);
	ft_printf("rr\n");

}
