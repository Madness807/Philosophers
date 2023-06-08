/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/06/07 05:16:25 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>

void	*routine(void *arg)
{
	t_philosopher *curr;
	t_head *head;
	
	curr = (t_philosopher *) arg;
	head = curr->head;
	if(curr->id_philo % 2)
		usleep(200);
	while (1)
	{
		if(curr->meal_count >= head->number_of_times_each_philosopher_must_eat)	
		{
			printf("|---------------------->Philo|[%i]|eat✅\n", curr->id_philo);
			break;
		}
		ft_eat(curr);
		printf("\033[4m|in loop : philo id [%i]\n", curr->id_philo);
		// pthread_mutex_lock(curr->fork_r);
		// pthread_mutex_lock(curr->fork_l);

		// pthread_mutex_unlock(curr->fork_r);
		// pthread_mutex_unlock(curr->fork_l);
		usleep(50);
		ft_sleep(curr);
		usleep(50);
		ft_think(curr);
	}
	return (0);
}

