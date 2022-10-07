/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:21:52 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 22:13:12 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_check_is_nbr(char **tabstr)
{
	int	i;
	int	j;
	int	signe;

	i = 0;
	while (tabstr[i])
	{
		j = 0;
		signe = 1;
		while (tabstr[i][j])
		{
			if (ft_isdigit(tabstr[i][j]))
				signe = 0;
			else if ((tabstr[i][j] == '-' || tabstr[i][j] == '+') && signe == 1)
				signe = 0;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_int(char *str)
{
	int				i;
	int				signe;
	long long int	nb;

	i = 0;
	nb = 0;
	signe = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1 * signe;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		nb = nb * 10 + str[i] - '0';
		if (signe * nb > INT_MAX || signe * nb < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_is_int(char **tabstr)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (tabstr[i])
	{
		check = ft_is_int(tabstr[i]);
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_argv(char **tabstr)
{
	if (ft_check_is_nbr(tabstr) == 0)
		return (0);
	if (ft_check_is_int(tabstr) == 0)
		return (0);
	return (1);
}

int	ft_check_double(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
