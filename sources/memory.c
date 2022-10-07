/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:47:38 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:48:15 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_master	*ft_new_master(void)
{
	t_master	*m;

	m = malloc(sizeof(t_master));
	m->top = 0;
	m->bottom = 0;
	m->nb_value = 0;
	m->arr_sort = 0;
	m->effi = 0;
	m->mr = 0;
	m->push_med = 0;
	return (m);
}

t_master	*ft_tab_to_stack(t_master *m, int *tab, int *rank, int i)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (!element)
		exit(EXIT_FAILURE);
	element->value = tab[i - 1];
	element->position = i;
	element->prev = 0;
	element->rank = rank[i - 1];
	if (ft_is_empty_master(m))
	{
		element->next = 0;
		m->bottom = element;
	}
	else
	{
		m->top->prev = element;
		element->next = m->top;
	}
	m->top = element;
	m->nb_value++;
	return (m);
}

char	**ft_mem_two_args(char **argv)
{
	char	**tabstr;

	tabstr = ft_split(argv[1], ' ');
	if (!tabstr)
		ft_error();
	return (tabstr);
}

char	**ft_mem_many_args(int argc, char **argv)
{
	char	**tabstr;
	int		i;
	int		j;

	tabstr = malloc(sizeof(char *) * argc);
	if (!tabstr)
		ft_error();
	i = 0;
	while (i < (argc - 1))
	{
		tabstr[i] = malloc(sizeof(char) * (ft_strlen(argv[(i + 1)]) + 1));
		if (!tabstr[i])
			ft_error_tabstr(tabstr, i);
		j = 0;
		while (argv[(i + 1)][j])
		{
			tabstr[i][j] = argv[(i + 1)][j];
			j++;
		}
		tabstr[i][j] = '\0';
		i++;
	}
	tabstr[i] = 0;
	return (tabstr);
}

int	*ft_mem_tab_int(char **tabstr)
{
	int	*tab;
	int	i;

	i = 0;
	while (tabstr[i])
		i++;
	tab = malloc(sizeof(int) * i);
	i = 0;
	while (tabstr[i])
	{
		tab[i] = ft_atoi(tabstr[i]);
		i++;
	}
	return (tab);
}
