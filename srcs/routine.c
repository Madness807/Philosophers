/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 01:00:46 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

void	take_fork_1(t_head *head, int i)
{
	pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
	ft_taken_fork(&head->philo[i]);
	pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
	ft_taken_fork(&head->philo[i]);
}

void	take_fork_2(t_head *head, int i)
{
	usleep(50);
	pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
	ft_taken_fork(&head->philo[i]);
	pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
	ft_taken_fork(&head->philo[i]);
}

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
			return (0);
		if (i % 2 == 0)
			take_fork_1(head, i);
		else
			take_fork_2(head, i);


		if (ft_eat(&head->philo[i]) == 1)
		{
			pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
			pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);
			return (0);
		}
		
		exec_action(head->time_to_eat);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);


		if (ft_sleep(&head->philo[i]) == 1)
			return (0);
		if (ft_think(&head->philo[i]) == 1)
			return (0);
	}
	return (0);
}
