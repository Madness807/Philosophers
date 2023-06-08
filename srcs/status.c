/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/06/07 05:01:26 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philosopher *head)
{
	printf("\033[0;32m|👨|%i| is eating\033[0m\n", head->id_philo);
	head->meal_count++;
}

void	ft_sleep(t_philosopher *head)
{
	printf("\033[0;33m|👨|%i| is sleeping\033[0m\n", head->id_philo);
}

void	ft_think(t_philosopher *head)
{
	printf("\033[0;36m|👨|%i| is thinking\033[0m\n", head->id_philo);
}

void	ft_is_dead(t_philosopher *head)
{
	printf("\033[0;46m|👨|%i| is dead\033[0m|\n", head->id_philo);
}
