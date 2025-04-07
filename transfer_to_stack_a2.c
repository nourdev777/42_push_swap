/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_stack_a2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:03:52 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 14:59:04 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_decision(t_stack **a, t_stack **b, t_stack *best)
{
	if (best->r_a != -1)
	{
		while (best->r_a-- > 0)
			ra(a, 1);
	}
	else
	{
		while (best->rr_a-- > 0)
			rra(a, 1);
	}
	if (best->r_b != -1)
	{
		while (best->r_b-- > 0)
			rb(b, 1);
	}
	else
	{
		while (best->rr_b-- > 0)
			rrb(b, 1);
	}
	pa(a, b);
}

t_stack	*get_best_node(t_stack *b)
{
	t_stack		*tmp;
	t_stack		*best;

	tmp = b;
	best = b;
	while (tmp != NULL)
	{
		if (tmp->best < best->best)
			best = tmp;
		tmp = tmp->next;
	}
	return (best);
}

void	best_solution_a(t_stack *tmp, int *min_a)
{
	if (tmp->r_a <= tmp->rr_a)
	{
		*min_a = tmp->r_a;
		tmp->rr_a = -1;
	}
	else
	{
		*min_a = tmp->rr_a;
		tmp->r_a = -1;
	}
}

void	best_solution_b(t_stack *tmp, int *min_b)
{
	if (tmp->r_b <= tmp->rr_b)
	{
		*min_b = tmp->r_b;
		tmp->rr_b = -1;
	}
	else
	{
		*min_b = tmp->rr_b;
		tmp->r_b = -1;
	}
}

void	choose_best_solution(t_stack **b)
{
	t_stack	*tmp;
	int		min_a;
	int		min_b;

	tmp = *b;
	while (tmp)
	{
		best_solution_b(tmp, &min_b);
		best_solution_a(tmp, &min_a);
		tmp->best = min_b + min_a;
		tmp = tmp->next;
	}
}
