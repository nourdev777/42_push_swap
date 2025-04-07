/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:11:38 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 13:13:16 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_moves_a(t_stack **a, t_stack *b)
{
	int		i;
	int		prev_a;
	t_stack	*tmp_a;
	int		size;

	size = op_stack_size(a);
	while (b)
	{
		tmp_a = *a;
		i = 0;
		prev_a = op_find_last(*a)->nbr;
		while (tmp_a)
		{
			if (prev_a < b->nbr && tmp_a->nbr > b->nbr)
			{
				b->r_a = i;
				b->rr_a = size - i;
			}
			i++;
			prev_a = tmp_a->nbr;
			tmp_a = tmp_a->next;
		}
		b = b->next;
	}
}

void	count_moves_b(t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = *b;
	size = op_stack_size(b);
	while (tmp)
	{
		tmp->r_b = i;
		tmp->rr_b = size - i;
		i++;
		tmp = tmp->next;
	}
}

void	transfer_to_stack_a(t_stack **a, t_stack **b)
{
	count_moves_b(b);
	count_moves_a(a, *b);
	choose_best_solution(b);
	process_decision(a, b, get_best_node(*b));
}
