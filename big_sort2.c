/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:43:01 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 11:43:27 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sorting(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		max;
	int		med;
	int		steps;

	tmp = *a;
	find_min_max_med(a, &min, &max, &med);
	steps = 0;
	while (tmp->nbr != min)
	{
		steps++;
		tmp = tmp->next;
	}
	if (steps <= op_stack_size(a) / 2)
	{
		while (steps-- > 0)
			ra(a, 1);
	}
	else
	{
		while (steps++ < op_stack_size(a))
			rra(a, 1);
	}
}

void	determine_position(t_stack **head, int *arr)
{
	int		i;
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		i = 0;
		while (arr[i] != tmp->nbr)
			i++;
		tmp->pos = i;
		tmp = tmp->next;
	}
}
