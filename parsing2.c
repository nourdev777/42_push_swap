/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:39:12 by numussan          #+#    #+#             */
/*   Updated: 2022/11/11 06:09:39 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_dubl(t_stack **a)
{
	t_stack		*temp;
	t_stack		*current;

	current = *a;
	temp = current->next;
	while (current->next != NULL)
	{
		while (temp != NULL)
		{
			if (current->nbr == temp->nbr)
			{
				ft_free_stack(a);
				ft_putstr_fd("Error\n", 2);
			}
			temp = temp->next;
		}
		current = current->next;
		temp = current->next;
	}
}

void	ft_is_it_number(t_stack **a, char **str, char *s)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	if (s[0] == '-' || s[0] == '+')
	{
		if (!s[1])
			ft_err_free_split_and_list(a, str);
		i++;
	}
	while (s[i] == '0')
	{
		i++;
		zero++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			ft_err_free_split_and_list(a, str);
		i++;
	}
	if (i - zero > 11)
		ft_err_free_split_and_list(a, str);
}

void	ft_add_numbers_to_stack_a(t_stack **a, char **str, char *s)
{
	long long	nbr;

	ft_is_it_number(a, str, s);
	nbr = ft_atoi(s);
	if (!(nbr >= -2147483648 && nbr <= 2147483647))
		ft_err_free_split_and_list(a, str);
	op_fill_list_a(a, (int)nbr);
}
