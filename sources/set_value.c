/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:12:34 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:34:02 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_set_sort(int *arr, int nb_value)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < nb_value - 1)
	{
		j = i + 1;
		while (j < nb_value)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_set_value(t_master *m)
{
	int		i;
	int		*new_arr;
	t_node	*stack;
	int		val;

	val = m->nb_value;
	free(m->arr_sort);
	i = 0;
	stack = m->top;
	new_arr = malloc(sizeof(int) * val);
	while (stack)
	{
		new_arr[i++] = stack->value;
		stack = stack->next;
	}
	ft_set_sort(new_arr, val);
	m->push_med = val / 3;
	m->arr_sort = new_arr;
}

void	ft_set_apex(t_master *m1)
{
	t_node	*element;

	m1->min = INT_MAX;
	m1->max = INT_MIN;
	element = m1->top;
	while (element)
	{
		if (element->rank < m1->min)
		{
			m1->min = element->rank;
			m1->mr = element->position - 1;
		}
		if (element->rank > m1->max)
			m1->max = element->rank;
		element = element->next;
	}
}

void	ft_set_position(t_node *stack1, t_node *stack2)
{
	stack1 = stack1->next;
	while (stack1)
	{
		stack1->position--;
		stack1 = stack1->next;
	}
	while (stack2)
	{
		stack2->position++;
		stack2 = stack2->next;
	}
}
