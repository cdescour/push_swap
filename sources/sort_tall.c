/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:00:47 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:53:56 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_set_effi2(int eff[3], t_master *m, t_node *stack, int nb_v)
{
	if (eff[0] >= eff[2])
	{
		if (eff[0] >= m->effi->effi && (stack->position - 1
				< ((nb_v + 1) - stack->position) % nb_v))
		{
			m->effi->rank = stack->rank;
			m->effi->effi = eff[0];
			m->effi->type = srotate;
			m->effi->nb_coup = stack->position - 1;
		}
	}
	else
	{
		if (eff[2] > m->effi->effi)
		{
			m->effi->rank = stack->rank;
			m->effi->effi = eff[2];
			m->effi->type = rrotate;
			m->effi->nb_coup = ((nb_v + 1)
					- stack->position) % nb_v;
		}
	}
}

void	ft_set_effi(int n, t_master *m, t_node *stack, int nb_v)
{
	int	eff[4];

	if (!m->effi)
		m->effi = malloc(sizeof(t_eff));
	m->effi->effi = INT_MIN;
	while (stack)
	{
		eff[0] = stack->rank - stack->position;
		eff[3] = ((nb_v + 1) - (stack->position + 1)) % nb_v;
		eff[2] = stack->rank - eff[3];
		eff[1] = n - stack->rank;
		if (n < stack->rank)
			eff[1] = (stack->rank + 1) - n;
		eff[0] -= eff[1];
		eff[2] -= eff[1];
		ft_set_effi2(eff, m, stack, nb_v);
		stack = stack->next;
	}
}

void	ft_sort_algo(t_master *m1, t_master *m2)
{
	while (m2->nb_value > 0)
	{
		ft_set_effi(m1->top->rank, m2, m2->top, m2->nb_value);
		while (--m2->effi->nb_coup > -1)
		{
			if (m2->effi->type == srotate)
			{
				if (m2->effi->rank > m1->top->rank)
					ft_drotate(ft_rotate, m1, m2);
				else
					ft_rotate(m2, 'b');
			}
			else
			{
				if (m2->effi->rank < m1->bottom->rank)
					ft_drotate(ft_reverse_rotate, m1, m2);
				else
					ft_reverse_rotate(m2, 'b');
			}
		}
		while (m2->top && m2->top->rank == m2->effi->rank)
			ft_sort_back(m1, m2);
	}
	while (m1->top->rank != m1->min)
		ft_reverse_rotate(m1, 'a');
}

void	ft_stack_split(t_master *m1, t_master *m2, int med)
{
	int	i[2];

	i[0] = 0;
	while (m1->nb_value > 2)
	{
		i[1] = m1->top->rank;
		if (i[1] == m1->max || i[1] == m1->min)
			ft_rotate(m1, 'a');
		else if ((m2->nb_value == 0 && i[1] <= 2 * med)
			|| i[0] > (2 * med) - 2)
			ft_push(m1, m2, 'b');
		else
		{
			if (i[1] <= 2 * med && i[0]++)
				ft_push(m1, m2, 'b');
			else
				ft_rotate(m1, 'a');
			if (i[1] <= med)
				ft_rotate(m2, 'b');
		}
	}
	if (m1->top->rank < m1->top->next->rank)
		ft_rotate(m1, 'a');
	ft_sort_algo(m1, m2);
}
