/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 15:15:37 by joterret         ###   ########.fr       */
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
