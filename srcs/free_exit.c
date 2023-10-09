/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:39:22 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 18:19:17 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	join_thread(t_head *head)
{
	int	i;

	i = 0;
	while (i < head->number_of_philosophers)
	{
		pthread_join(head->philo[i].thread, NULL);
		i++;
	}
	pthread_join(head->watcher, NULL);
}

int	destroy_mutex(t_head *head)
{
	int	i;

	i = 0;
	while (i < head->number_of_philosophers)
	{
		pthread_mutex_destroy(&head->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&head->printing);
	pthread_mutex_destroy(&head->index);
	pthread_mutex_init(&head->dead, NULL);
	pthread_mutex_init(&head->meal, NULL);
	return (0);
}

void	free_malloc(t_head *head)
{
	free(head->philo);
	free(head->fork);
}
