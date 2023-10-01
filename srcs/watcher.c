/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:41:22 by joterret          #+#    #+#             */
/*   Updated: 2023/09/30 15:49:32 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	die_timer(t_head *head)
{
	long			gap_time;
	struct timeval	time;
	long			time_now;

	gap_time = 0;
	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	gap_time = (time_now - head->philo->time_since_last_meal);
	if (gap_time > head->time_to_die)
		return (1);
	else
		return (0);
}

void	*watcher(void *head)
{
	t_head	*current;

	current = head;
	while (1)
	{
		while (current->philo->id_philo < current->number_of_philosophers)
		{
			if (die_timer(head) == 0)
				continue ;
			else if ((die_timer(head)) == 1)
				exit (1);
		}
	}	
}
