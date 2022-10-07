/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:09:53 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:47:22 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_free_tabstr(char **tabstr)
{
	int	i;
	int	size;

	i = 0;
	while (tabstr[i])
		i++;
	size = i;
	while (i != 0)
		free(tabstr[i--]);
	free(tabstr[i]);
	free(tabstr);
	return (size);
}

void	ft_free_list(t_master *m)
{
	t_node	*stack;

	while (m->top)
	{
		stack = m->top;
		m->top = m->top->next;
		free(stack);
	}
	if (m->effi)
		free(m->effi);
	if (m->arr_sort)
		free(m->arr_sort);
}
