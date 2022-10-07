/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:02:00 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:54:37 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_swap(t_master *m, char a)
{
	t_node	*temp;

	if (m->nb_value > 1)
	{
		temp = m->top->next;
		m->top->next = temp->next;
		m->top->prev = temp;
		temp->next = m->top;
		temp->prev = 0;
		m->top = temp;
	}
	if (a == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (a == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ft_rotate(t_master *m, char a)
{
	t_node	*stack;

	stack = m->top;
	stack->position += m->nb_value;
	if (m->nb_value > 1)
	{
		m->bottom->next = m->top;
		m->top->prev = m->bottom;
		m->top = m->top->next;
		m->bottom = m->bottom->next;
		m->top->prev = 0;
		m->bottom->next = 0;
	}
	stack = m->top;
	while (stack)
	{
		stack->position--;
		stack = stack->next;
	}
	if (a == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (a == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (a == 'r')
		ft_putstr_fd("rr\n", 1);
}

void	ft_reverse_rotate(t_master *m, char a)
{
	t_node	*stack;

	if (m->nb_value > 1)
	{
		m->bottom->next = m->top;
		m->top->prev = m->bottom;
		m->top = m->top->prev;
		m->bottom = m->bottom->prev;
		m->top->prev = 0;
		m->bottom->next = 0;
	}
	stack = m->top;
	stack->position = 0;
	while (stack)
	{
		stack->position++;
		stack = stack->next;
	}
	if (a == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (a == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (a == 'r')
		ft_putstr_fd("rrr\n", 1);
}

void	ft_push(t_master *m1, t_master *m2, char a)
{
	ft_set_position(m1->top, m2->top);
	if (m2->nb_value == 0)
	{
		m2->top = m1->top;
		m2->bottom = m1->top;
		m1->top = m1->top->next;
		m2->top->next = 0;
	}
	else
	{
		m2->top->prev = m1->top;
		m1->top = m1->top->next;
		m2->top->prev->next = m2->top;
		m2->top = m2->top->prev;
	}
	if (m1->nb_value != 1)
		m1->top->prev = 0;
	m2->nb_value++;
	m1->nb_value--;
	if (a == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (a == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	ft_drotate(void (*f)(t_master *, char), t_master *m1, t_master *m2)
{
	(*f)(m1, 'r');
	(*f)(m2, ' ');
}
