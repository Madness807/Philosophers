/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:49:28 by joterret          #+#    #+#             */
/*   Updated: 2023/05/31 04:49:15 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo_tab(t_head *head)
{
	head->philo = malloc(head->number_of_philosophers * sizeof(t_philosopher));
	if (!head->philo)
		printf("L'allocation memoire du tab philo a echouer");
}

void	init_philo(t_head *head)
{	
	int i;
	
	i = 0;
	while (i < head->number_of_philosophers)
	{
		pthread_create (&head->philo[i].thread, NULL, &routine, &head);
		head->philo[i].id_philo = i;
		head->philo[i].time_awake = 0;
		head->philo[i].meal_count = 0;
		head->philo[i].time_since_last_meal = 0;
		i++;
	}
}
