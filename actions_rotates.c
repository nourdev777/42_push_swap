/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:19:22 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 08:49:47 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **head, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *head;
	last = op_find_last(tmp);
	last->next = tmp;
	*head = tmp->next;
	tmp->next = NULL;
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack **head_b, int flag)
{
	t_stack	*last;

	last = op_find_last(*head_b);
	last->next = *head_b;
	*head_b = (*head_b)->next;
	last->next->next = NULL;
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	ft_printf("rr\n");
}
