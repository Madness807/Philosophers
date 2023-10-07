/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/10/07 22:57:37 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

void	*routine(void *arg)
{
	t_head	*head;
	int		i;
	int		nbr_m_eat;

	head = arg;
	nbr_m_eat = head->nbr_times_philosopher_must_eat;
	pthread_mutex_lock(&(head->index));
	i = head->n_thread;
	pthread_mutex_unlock(&(head->index));
	while (1)
	{
		if (nbr_m_eat != -1 && head->philo[i].meal_count >= nbr_m_eat)
		{
			break ;
		}
		if (i % 2 == 0)
		{
			pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
			ft_taken_fork(&head->philo[i]);
			pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
			ft_taken_fork(&head->philo[i]);
		}
		else
		{
			usleep(50);
			pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
			ft_taken_fork(&head->philo[i]);
			pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
			ft_taken_fork(&head->philo[i]);
		}
		ft_eat(&head->philo[i]);
		exec_action(head->time_to_eat);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);
		ft_sleep(&head->philo[i]);
		ft_think(&head->philo[i]);
	}
	return (0);
}
