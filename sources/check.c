/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 01:41:02 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:35:59 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

bool	ft_is_empty_master(t_master *m)
{
	if (m)
	{
		if (m->top == 0 && m->bottom == 0)
			return (true);
		else
			return (false);
	}
	else
		return (true);
}
