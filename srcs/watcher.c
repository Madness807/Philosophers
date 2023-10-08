/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:41:22 by joterret          #+#    #+#             */
/*   Updated: 2023/10/08 22:01:00 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	die_timer(t_head *head, int i)
{
	long			gap_time;
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	pthread_mutex_lock(&head->printing);
	gap_time = (time_now - head->philo[i].time_since_last_meal);
	pthread_mutex_unlock(&head->printing);
	if (gap_time > head->time_to_die)
		return (1);
	return (0);
}

void	*watcher(void *head)
{
	t_head	*current;
	int		i;
	int		j;
	int		all_eat;

	j = 0;
	all_eat = 0;
	current = head;
	while (1)
	{
		i = 0;
		if (j == 1 || all_eat == current->number_of_philosophers)
			return (0);
		while (i < current->number_of_philosophers)
		{
			if ((die_timer(head, i)) == 1)
			{
				ft_is_dead(&current->philo[i]);
				j = 1;
			}
			pthread_mutex_lock(&current->meal);
			if (current->philo[i].meal_count == current->nbr_times_philosopher_must_eat)
				all_eat++;
			pthread_mutex_unlock(&current->meal);
			i++;
		}
	}
}
