/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:49:28 by joterret          #+#    #+#             */
/*   Updated: 2023/06/06 17:09:23 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_head(t_head *head, char **argv)
{
	head->number_of_philosophers = ft_atoi(argv[1]);
	head->time_to_die = ft_atoi(argv[2]);
	head->time_to_eat = ft_atoi(argv[3]);
	head->time_to_sleep = ft_atoi(argv[4]);
	head->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	head->has_died = 0;
}

void	init_philo(t_head *head)
{	
	int	i;

	i = 0;
	head->philo = malloc(head->number_of_philosophers * sizeof(t_philosopher));
	if (!head->philo)
		printf("L'allocation memoire du tab philo a echouer");
	while (i < head->number_of_philosophers)
	{
		head->philo[i].id_philo = i;
		head->philo[i].time_awake = 0;
		head->philo[i].meal_count = 0;
		head->philo[i].time_since_last_meal = 0;
		head->philo[i].head = head;
		head->philo[i].thread = malloc(sizeof(*(head->philo[i].thread)));
		if (!head->philo[i].thread)
			printf("ZOOO");
		i++;
	}
}

void	init_thread(t_head *head)
{
	int	i;

	t_philosopher *curr;

	i = 0;
	// printf("Number of thread to create : (%d)", head->number_of_philosophers);

	while (i < head->number_of_philosophers)
	{
		curr = head->philo + i;
		// if (pthread_create(head->philo[i].thread, 0, &routine, ((void *) head->philo + i)))
		// {
		// 	printf("Erreur lors de la création du thread pour le philosophe %d\n", i);
		// 	exit(0);
		// }
		pthread_create(head->philo[i].thread, 0, &routine, ((void *) curr));
		usleep(15);
		i++;
	}
}

void	init_mutex(t_head *head)
{
	int	i;

	i = 0;
	head->philo->fork_l = malloc(head->number_of_philosophers * sizeof(pthread_mutex_t));
	if (!head->philo->fork_l)
	{
		printf("L'allocation mémoire pour le tableau 'forks' a échoué\n");
	}
	while (i < head->number_of_philosophers)
	{
		if (pthread_mutex_init(&head->philo->fork_l[i], NULL) != 0)
		{
			printf("Erreur lors de l'initialisation du mutex pour la fourchette %d\n", i);
		}
		i++;
	}
}
