/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/06/06 17:10:26 by joterrett        ###   ########.fr       */
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
	// while (!head->has_died)
	while (1)
	{
		if(curr->meal_count >= head->number_of_times_each_philosopher_must_eat)	
		{
			
			printf(" Philo (%i) Has Eated (%i) for max (%i) \n", curr->id_philo, curr->meal_count, head->number_of_times_each_philosopher_must_eat);
			break;
		}
		ft_eat(curr);
		printf("in loop : philo id (%i). Has Eated (%i)\n", curr->id_philo, curr->meal_count);

		//pthread_mutex_lock(curr->fork_r);
		pthread_mutex_lock(curr->fork_l);

		//pthread_mutex_unlock(curr->fork_r);
		pthread_mutex_unlock(curr->fork_l);

		ft_sleep(curr);
		usleep(50);
		ft_think(curr);
	}
	return (0);
}

