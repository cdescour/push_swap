/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:21:00 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:51:08 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

bool	ft_is_valid_stack(t_master *a)
{
	t_node	*stack;

	stack = a->top;
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (true);
	}
	return (false);
}

void	ft_sort_back(t_master *m1, t_master *m2)
{
	if (m2->nb_value)
	{
		if (m2->top->rank < m1->top->rank && m2->top->rank > m1->bottom->rank)
			ft_push(m2, m1, 'a');
		else if (m2->top->rank < m1->top->rank
			&& m2->top->rank < m1->bottom->rank)
			ft_reverse_rotate(m1, 'a');
		else
			ft_rotate(m1, 'a');
	}
	else
	{
		ft_set_apex(m1);
		while (m1->top->rank != m1->min)
		{
			if (m1->mr > m1->nb_value / 2 + 1)
				ft_reverse_rotate(m1, 'a');
			else
				ft_rotate(m1, 'a');
		}
	}
}

void	ft_sort_low(t_master *m1, t_master *m2)
{
	while (m1->nb_value > 3)
	{
		if (m1->top->rank == m1->min || m1->top->rank == m1->max)
			ft_rotate(m1, 'a');
		else
			ft_push(m1, m2, 'b');
	}
	while (!(m1->bottom->rank > m1->top->next->rank
			&& m1->top->next->rank > m1->top->rank))
	{
		if (m1->top->rank > m1->bottom->rank
			&& m1->top->rank > m1->top->next->rank)
			ft_rotate(m1, 'a');
		else if (m1->top->next->rank > m1->bottom->rank)
			ft_reverse_rotate(m1, 'a');
		else if (m1->top->rank > m1->top->next->rank)
			ft_swap(m1, 'a');
	}
	while (m2->nb_value > 0 || m1->top->rank != m1->min)
		ft_sort_back(m1, m2);
}

void	ft_sort(t_master *a, t_master *b)
{
	if (!ft_is_valid_stack(a))
		return ;
	else if (a->nb_value == 2)
	{
		ft_swap(a, 'a');
		return ;
	}
	if (a->nb_value <= 8)
		ft_sort_low(a, b);
	else
		ft_stack_split(a, b, a->push_med);
}
