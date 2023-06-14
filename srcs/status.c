/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/06/14 02:00:14 by joterrett        ###   ########.fr       */
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
	t_head *current = head->head;

	printf("\033[0;33m|👨|%i| is sleeping\033[0m\n", head->id_philo);
	usleep(current->time_to_sleep);
}

void	ft_think(t_philosopher *head)
{
	printf("\033[0;36m|👨|%i| is thinking\033[0m\n", head->id_philo);
}

void	ft_is_dead(t_philosopher *head)
{
	printf("\033[0;46m|👨|%i| is dead\033[0m|\n", head->id_philo);
}

