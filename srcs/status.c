/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/09/30 19:13:24 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philosopher *philo_id)
{	
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;32m%i\t🥣 is eating\t\t\033[0m\t", philo_id->id_philo);
	philo_id->time_since_last_meal = grab_time_now();
	philo_id->meal_count++;
	printf("%ld\n", philo_id->time_since_last_meal);
	pthread_mutex_unlock(&current->printing);
}

void	ft_sleep(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;36m%i\t💤 is sleeping\t\t\033[0m\n", philo_id->id_philo);
	pthread_mutex_unlock(&current->printing);
	exec_action(current->time_to_sleep);
}

void	ft_think(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;33m%i\t🤔 is thinking\t\t\033[0m\n", philo_id->id_philo);
	pthread_mutex_unlock(&current->printing);
}

void	ft_taken_fork(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("%i\t🥄 has taken a fork\t\n", philo_id->id_philo);
	pthread_mutex_unlock(&current->printing);
}

void	ft_is_dead(t_philosopher *philo_id)
{
	t_head	*current;

	current = philo_id->head;
	pthread_mutex_lock(&current->printing);
	printf("\033[0;46m%i\t🪦 dead\t\t\033[0m\n", philo_id->id_philo);
}
