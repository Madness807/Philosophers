/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 17:36:20 by joterret         ###   ########.fr       */
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

void	unlock_forks(t_head *head, int i)
{
	pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
	pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);
}

void	*routine(void *arg)
{
	t_head	*head;
	int		i;

	head = arg;
	pthread_mutex_lock(&(head->index));
	i = head->n_thread;
	pthread_mutex_unlock(&(head->index));
	while (1)
	{
		if (head->nbtoeat != -1 && head->philo[i].meal_count >= head->nbtoeat)
			return (0);
		if (i % 2 == 0)
			take_fork_1(head, i);
		else
			take_fork_2(head, i);
		if (ft_eat(&head->philo[i]) == 1)
		{
			unlock_forks(head, i);
			return (0);
		}
		unlock_forks(head, i);
		if (ft_sleep(&head->philo[i]) == 1 || ft_think(&head->philo[i]) == 1)
			return (0);
	}
	return (0);
}
