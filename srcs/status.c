/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/09/21 17:25:48 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philosopher *head)
{	
	t_head	*current;

	current = head->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;32m%i\t🥣 is eating\t\t\033[0m\n", head->id_philo);
	head->meal_count++;
	pthread_mutex_unlock(&current->printing);
}

void	ft_sleep(t_philosopher *head)
{
	t_head	*current;

	current = head->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;36m%i\t💤 is sleeping\t\t\033[0m\n", head->id_philo);
	pthread_mutex_unlock(&current->printing);
	exec_action(current->time_to_sleep);
}

void	ft_think(t_philosopher *head)
{
	t_head	*current;

	current = head->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("\033[0;33m%i\t🤔 is thinking\t\t\033[0m\n", head->id_philo);
	pthread_mutex_unlock(&current->printing);
}

void	ft_taken_fork(t_philosopher *head)
{
	t_head	*current;

	current = head->head;
	pthread_mutex_lock(&current->printing);
	printf("%llu\t", grab_time_dif(current));
	printf("%i\t🥄 has taken a fork\t\n", head->id_philo);
	pthread_mutex_unlock(&current->printing);
}

void	ft_is_dead(t_philosopher *head)
{
	t_head	*current;

	current = head->head;
	pthread_mutex_lock(&current->printing);
	printf("\033[0;46m%i\t🪦 dead\t\t\033[0m\n", head->id_philo);
}
