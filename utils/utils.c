/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:14:59 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 16:35:20 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (sign * res);
}

int	check_is_digit(char *num)
{
	int	i;

	i = 0;
	while (num[i] != 0)
	{
		if (ft_isdigit(num[i]) == 1)
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_if_args_is_digit(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != 0)
	{
		if (check_is_digit(argv[i]) == 1)
		{
			printf(SYNTAX_ERREUR);
			return (1);
		}
		i++;
	}
	return (0);
}
