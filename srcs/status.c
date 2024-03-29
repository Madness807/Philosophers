/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 17:34:06 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_eat(t_philosopher *philo_id)
{	
	t_head			*current;
	long long int	dif;

	current = philo_id->head;
	pthread_mutex_lock(&current->dead);
	if (current->has_died == 0)
	{
		pthread_mutex_unlock(&current->dead);
		dif = grab_time_dif(current);
		pthread_mutex_lock(&current->printing);
		printf("%llu\t", dif);
		printf("\033[0;32m%i\t🥣 is eating\t\t\033[0m\n", philo_id->id_philo);
		philo_id->time_since_last_meal = grab_time_now();
		pthread_mutex_unlock(&current->printing);
		pthread_mutex_lock(&current->meal);
		philo_id->meal_count++;
		pthread_mutex_unlock(&current->meal);
		exec_action(current->time_to_eat);
		return (0);
	}
	pthread_mutex_unlock(&current->dead);
	return (1);
}

int	ft_sleep(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->dead);
	if (current->has_died == 0)
	{
		pthread_mutex_unlock(&current->dead);
		pthread_mutex_lock(&current->printing);
		printf("%llu\t", grab_time_dif(current));
		printf("\033[0;36m%i\t💤 is sleeping\t\t\033[0m\n", philo_id->id_philo);
		pthread_mutex_unlock(&current->printing);
		exec_action(current->time_to_sleep);
		return (0);
	}
	pthread_mutex_unlock(&current->dead);
	return (1);
}

int	ft_think(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->dead);
	if (current->has_died == 0)
	{
		pthread_mutex_unlock(&current->dead);
		pthread_mutex_lock(&current->printing);
		printf("%llu\t", grab_time_dif(current));
		printf("\033[0;33m%i\t🤔 is thinking\t\t\033[0m\n", philo_id->id_philo);
		pthread_mutex_unlock(&current->printing);
		return (0);
	}
	pthread_mutex_unlock(&current->dead);
	return (1);
}

int	ft_taken_fork(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->dead);
	if (current->has_died == 0)
	{
		pthread_mutex_unlock(&current->dead);
		pthread_mutex_lock(&current->printing);
		printf("%llu\t", grab_time_dif(current));
		printf("%i\t🥄 has taken a fork\t\n", philo_id->id_philo);
		pthread_mutex_unlock(&current->printing);
		return (0);
	}
	pthread_mutex_unlock(&current->dead);
	return (1);
}

void	ft_is_dead(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->dead);
	current->has_died = 1;
	pthread_mutex_unlock(&current->dead);
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;31m%i\t☠️ dead\t\t\033[0m\n", philo_id->id_philo);
	pthread_mutex_unlock(&current->printing);
}
