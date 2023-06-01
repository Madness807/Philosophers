/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/05/31 04:42:20 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_head	*head;
	int		i;

	head = (t_head *)arg;
	i = 0;
	while (i != head->number_of_philosophers)
	{
		ft_think(head->philo[i].id_philo);
		pthread_mutex_lock(head->philo[i].fork_l);
		pthread_mutex_lock(head->philo[i].fork_r);
		ft_eat(head->philo->id_philo);
		pthread_mutex_unlock(head->philo[i].fork_l);
		pthread_mutex_unlock(head->philo[i].fork_r);
		ft_sleep(head->philo[i].id_philo);
		sleep(head->time_to_sleep * 1000);
		i++;
	}
	return (NULL);
}
