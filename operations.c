/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:22:48 by numussan          #+#    #+#             */
/*   Updated: 2022/11/11 05:47:00 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_stack_size(t_stack **head)
{
	t_stack	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_stack	*op_find_prelast(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*op_find_last(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	op_fill_list_a(t_stack **a, int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_putstr_fd("Error\n", 2);
	new_node->nbr = nbr;
	new_node->pos = 0;
	new_node->r_a = 0;
	new_node->rr_a = 0;
	new_node->r_b = 0;
	new_node->rr_b = 0;
	new_node->best = 0;
	new_node->next = NULL;
	if (!*a)
		*a = new_node;
	else
		op_find_last(*a)->next = new_node;
}
