/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:07:30 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/06 02:58:59 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_rank_max(int *temptab, int size)
{
	int	i;
	int	pos;
	int	nb;

	i = 0;
	nb = INT_MIN;
	while (i < size)
	{
		if (nb <= temptab[i])
		{
			pos = i;
			nb = temptab[i];
		}
		i++;
	}
	return (pos);
}

int	ft_rank_min(int *temptab, int size)
{
	int	i;
	int	pos;
	int	nb;

	i = 0;
	nb = INT_MAX;
	while (i < size)
	{
		if (nb >= temptab[i])
		{
			pos = i;
			nb = temptab[i];
		}
		i++;
	}
	return (pos);
}

int	*ft_rank(int *temptab, int *rank, int size)
{
	int	i;
	int	nb;

	nb = ft_rank_max(temptab, size);
	rank[nb] = size;
	temptab[nb] = INT_MAX;
	i = 1;
	while (i < size)
	{
		nb = ft_rank_min(temptab, size);
		rank[nb] = i;
		temptab[nb] = INT_MAX;
		i++;
	}
	return (rank);
}

int	*ft_get_rank(int *tab, int size)
{
	int	*rank;
	int	*temptab;
	int	i;

	rank = malloc(sizeof(int) * size);
	if (!rank)
	{
		free(tab);
		ft_error();
	}
	temptab = malloc(sizeof(int) * size);
	if (!temptab)
	{
		free(tab);
		free(rank);
		ft_error();
	}
	i = 0;
	while (i++ < size)
		temptab[i - 1] = tab[i - 1];
	ft_rank(temptab, rank, size);
	free(temptab);
	return (rank);
}
