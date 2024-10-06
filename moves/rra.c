/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:46:33 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/02 17:07:35 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void reverse_rotate_a(t_list **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    t_list *current = *head;
    t_list *last = NULL;
    t_list *second_last = NULL;

    while (current->next->next != NULL) {
        current = current->next;
    }
    second_last = current;
    last = current->next;
    second_last->next = NULL;
    last->next = *head;
    *head = last;
}