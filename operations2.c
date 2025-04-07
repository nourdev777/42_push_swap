/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:36:33 by numussan          #+#    #+#             */
/*   Updated: 2022/11/11 05:47:27 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_check_sorted_or_presorted(t_stack **a)
{
	t_stack	*tmp;
	int		count;

	tmp = *a;
	count = 0;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			count++;
		tmp = tmp->next;
	}
	if (count > 1 || (tmp->nbr > (*a)->nbr && count > 0))
		return (1);
	if (count == 1)
		return (2);
	return (0);
}

void	op_delete_head(t_stack **head)
{
	t_stack		*temp;

	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	op_push_to_head(t_stack **head, int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_putstr_fd("Error\n", 2);
	new_node->nbr = nbr;
	new_node->pos = 0;
	new_node->next = *head;
	new_node->r_a = 0;
	new_node->rr_a = 0;
	new_node->r_b = 0;
	new_node->rr_b = 0;
	new_node->best = 0;
	*head = new_node;
}
