/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/05/28 03:19:52 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(void)
{
	write(1, "eat", 3);
	write(1, "\n", 1);
}

void	ft_sleep(void)
{
	write(1, "sleep", 5);
	write(1, "\n", 1);
}

void	ft_think(void)
{
	write(1, "think", 5);
	write(1, "\n", 1);
}
