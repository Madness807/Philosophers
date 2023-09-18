/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/09/18 20:56:40 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

void	*routine(void *arg)
{
	t_head *head;
	int		i;

	head = arg;
	
	i = head->n_thread;
	while (1)
	{
		if(head->philo[i].meal_count >= head->number_of_times_each_philosopher_must_eat)	
			break;
		pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
		ft_taken_fork(&head->philo[i]);
		pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
		ft_taken_fork(&head->philo[i]);
		ft_eat(&head->philo[i]);
		usleep(head->time_to_eat * 1000);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);
		ft_sleep(&head->philo[i]);
		ft_think(&head->philo[i]);
	}
	return (0);
}
