/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/10/08 22:04:25 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

/*
int	ft_meal_check(x, y)
{
	pthread_mutex_lock(&head->);
	if (val_mutexed != 1) // val_mutexed == is_dead
	{
		if (y == eat)
			ft_eat
		else if (y == sleep)
			ft_sleep;
		else
			ft_wait;
		unlock_mutex;
		return (0);
	}
	else
	{
		unlock_mutex;
		return (1);
	}
}*/

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
	pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
	ft_taken_fork(&head->philo[i]);
	pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
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
		ft_eat(&head->philo[i]);
		//if (ft_meal_check(x, "eat"))
			//return (0);
		exec_action(head->time_to_eat);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);
		ft_sleep(&head->philo[i]);
		ft_think(&head->philo[i]);
		if (nbr_m_eat != -1 && head->philo[i].meal_count >= nbr_m_eat)
		{
			return (0);
		}
		//if (ft_meal_check(x, "sleep") || ft_check(x, "wait"))
		//	return (0);
	}
	return (0);
}
