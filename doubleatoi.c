/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:59:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/27 09:43:03 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	doubleatoi(const char *str)
{
	int		i;
	int		sign;
	double	result;
	int		counter;

	i = 0;
	sign = 1;
	result = 0;
	counter = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while ((str[i] == '-' || str[i] == '+') && counter++ == 0)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
