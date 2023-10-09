/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 19:54:03 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	input_check(int argc)
{
	if (argc < 5)
	{
		printf(NOT_ENOUG_ARGS);
		return (1);
	}
	if (argc > 6)
	{
		printf(TOO_MANY_ARGS);
		return (1);
	}
	return (0);
}

int	one_philo_case(char **argv)
{
	if (ft_atol(argv[1]) == 1)
	{
		printf("0\t🥄 has taken a fork\t\n");
		printf("\033[0;31m%li\t☠️ dead\t\t\033[0m\n", ft_atol(argv[2]));
		return (1);
	}
	return (0);
}