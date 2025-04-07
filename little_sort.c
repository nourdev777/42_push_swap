/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:26:11 by numussan          #+#    #+#             */
/*   Updated: 2022/11/11 09:49:35 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_3(t_stack **a)
{
	int		one;
	int		two;
	int		three;

	one = (*a)->nbr;
	two = (*a)->next->nbr;
	three = (*a)->next->next->nbr;
	if (one > two && one > three && two > three)
		sa(a, 1);
	else if (two > one && two > three && three > one)
		sa(a, 1);
	else if (three > one && three > two && one > two)
		sa(a, 1);
}

void	sorting_3(t_stack **a)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->nbr;
	two = (*a)->next->nbr;
	three = (*a)->next->next->nbr;
	if (one > two && one > three && two > three)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (one > two && one > three && three > two)
		ra(a, 1);
	else if (two > one && two > three && one > three)
		rra(a, 1);
	else if (two > one && two > three && three > one)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (three > one && three > two && one > two)
		sa(a, 1);
}

void	ft_sorting(t_stack **a)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = op_stack_size(a);
	if (op_check_sorted_or_presorted(a) == 1)
	{
		if (size == 2 && (*a)->nbr > (*a)->next->nbr)
			sa(a, 1);
		if (size == 3)
			sorting_3(a);
		if (size == 4)
			sorting_4(a, &b);
		if (size == 5)
			sorting_5(a, &b);
		if (size > 5)
			preparation_for_big_sorting(a, &b);
	}
	ft_free_stack(&b);
	if (op_check_sorted_or_presorted(a) == 2)
		final_sorting(a);
}
