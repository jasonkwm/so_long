/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:29:58 by jakoh             #+#    #+#             */
/*   Updated: 2022/04/06 12:30:03 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Implementation of atoi (ASCII to Integer)
int	ft_atoi(const char *str)
{
	int	i;
	int	ans;
	int	neg;

	neg = 1;
	ans = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans *= 10;
		ans += (str[i] - '0');
		i++;
	}
	ans *= neg;
	return (ans);
}
