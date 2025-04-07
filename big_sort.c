/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:26:25 by numussan          #+#    #+#             */
/*   Updated: 2022/11/11 05:47:48 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*insertion_sort_array(t_stack **a, int *arr)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < op_stack_size(a))
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
		i++;
	}
	return (arr);
}

int	*fill_array(t_stack **a, int *arr)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (i < op_stack_size(a))
	{
		arr[i++] = tmp->nbr;
		tmp = tmp->next;
	}
	return (arr);
}

void	find_min_max_med(t_stack **a, int *min, int *max, int *med)
{
	int	*arr;
	int	size;

	size = op_stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		ft_putstr_fd("Error\n", 2);
	arr = insertion_sort_array(a, fill_array(a, arr));
	*min = arr[0];
	*max = arr[size - 1];
	*med = arr[size / 2];
	determine_position(a, arr);
	free(arr);
	arr = NULL;
}

void	transfer_to_stack_b(t_stack **a, t_stack **b)
{
	int		min;
	int		max;
	int		med;
	int		size;

	size = op_stack_size(a);
	find_min_max_med(a, &min, &max, &med);
	while (size > 3)
	{
		if ((*a)->nbr == min || (*a)->nbr == max || (*a)->nbr == med)
			ra(a, 1);
		else
		{
			pb(a, b);
			size--;
		}
	}
}

void	preparation_for_big_sorting(t_stack **a, t_stack **b)
{
	transfer_to_stack_b(a, b);
	presort_3(a);
	while (*b)
		transfer_to_stack_a(a, b);
}
