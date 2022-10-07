/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:02:13 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:48:56 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_pushswap(int *tab, int size)
{
	int			*rank;
	int			i;
	t_master	*a;
	t_master	*b;

	a = ft_new_master();
	b = ft_new_master();
	i = 0;
	rank = ft_get_rank(tab, size);
	i = size;
	while (i > 0)
		ft_tab_to_stack(a, tab, rank, i--);
	ft_set_value(a);
	ft_set_apex(a);
	ft_sort(a, b);
	ft_free_list(a);
	ft_free_list(b);
	free(a);
	free(b);
	free(rank);
}

void	ft_check_double_false(int *tab)
{
	free(tab);
	ft_error();
}

int	main(int argc, char **argv)
{
	char	**tabstr;
	int		*tab;
	int		size;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (0);
		tabstr = ft_mem_two_args(argv);
	}
	if (argc > 2)
		tabstr = ft_mem_many_args(argc, argv);
	if (ft_check_argv(tabstr) == 0)
		ft_error();
	tab = ft_mem_tab_int(tabstr);
	size = ft_free_tabstr(tabstr);
	if (ft_check_double(tab, size) == 0)
		ft_check_double_false(tab);
	ft_pushswap(tab, size);
	free(tab);
	return (0);
}
