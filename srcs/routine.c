/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:06:14 by joterret          #+#    #+#             */
/*   Updated: 2023/06/14 02:21:31 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>



void	*routine(void *arg)
{
	t_head *head;
	int		i;

	head = arg;
	i = head->n_thread;
	if(i % 2)
		usleep(200);
	while (1)
	{
		if(head->philo[i].meal_count >= head->number_of_times_each_philosopher_must_eat)	
		{
			//printf("|---------------------->Philo|[%i]|eat✅\n", curr->id_philo);
			break;
		}
		printf("forkl de %d : %p\n", i + 1, &head->fork[head->philo[i].fork_l]);
		printf("forkr de %d : %p\n", i + 1, &head->fork[head->philo[i].fork_r]);
		pthread_mutex_lock(&head->fork[head->philo[i].fork_l]);
		pthread_mutex_lock(&head->fork[head->philo[i].fork_r]);
		ft_eat(&head->philo[i]);
		grab_time_after(head);
		printf("TIMESTAMP %lld\n", grab_time_dif(head));
		usleep(1000 * head->time_to_eat);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_l]);
		pthread_mutex_unlock(&head->fork[head->philo[i].fork_r]);
		//usleep(50);
		ft_sleep(&head->philo[i]);
		//usleep(50);
		ft_think(&head->philo[i]);
	}
	return (0);
}



// void	*routine(void *arg)
// {
// 	t_philosopher *curr;
// 	t_head *head;
	
// 	curr = (t_philosopher *) arg;
// 	head = curr->head;
// 	if(curr->id_philo % 2)
// 		usleep(200);
// 	while (1)
// 	{
// 		if(curr->meal_count >= head->number_of_times_each_philosopher_must_eat)	
// 		{
// 			printf("|---------------------->Philo|[%i]|eat✅\n", curr->id_philo);
// 			break;
// 		}
// 		printf("1\n");
// 		pthread_mutex_lock(&head->fork[curr->fork_l]);
// 		printf("2\n");
// 		pthread_mutex_lock(&head->fork[curr->fork_r]);
// 		printf("3\n");
// 		ft_eat(curr);
// 		grab_time_after(head);
// 		printf("TIMESTAMP %lld\n", grab_time_dif(head));
// 		usleep(1000 * head->time_to_eat);
// 		printf("4\n");
// 		pthread_mutex_unlock(&head->fork[curr->fork_l]);
// 		pthread_mutex_unlock(&head->fork[curr->fork_r]);
// 		//usleep(50);
// 		ft_sleep(curr);
// 		//usleep(50);
// 		ft_think(curr);
// 	}
// 	return (0);
// }

