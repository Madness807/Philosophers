/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:49:28 by joterret          #+#    #+#             */
/*   Updated: 2023/10/07 22:50:53 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_head(t_head *head, char **argv, int argc)
{
	head->number_of_philosophers = ft_atol(argv[1]);
	head->time_to_die = ft_atol(argv[2]);
	head->time_to_eat = ft_atol(argv[3]);
	head->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		head->nbr_times_philosopher_must_eat = ft_atol(argv[5]);
	else
		head->nbr_times_philosopher_must_eat = -1;
	head->has_died = 0;
}

void	init_philo(t_head *head)
{
	int	i;

	i = 0;
	head->philo = malloc(head->number_of_philosophers * sizeof(t_philosopher));
	if (!head->philo)
	{
		printf("L'allocation memoire du tab philo a echouer");
		exit (1);
	}
	while (i < head->number_of_philosophers)
	{
		head->philo[i].id_philo = i;
		head->philo[i].time_awake = 0;
		head->philo[i].meal_count = 0;
		head->philo[i].time_since_last_meal = grab_time_now();
		head->philo[i].head = head;
		head->philo[i].fork_l = i;
		head->philo[i].fork_r = (i + 1);
		if (i + 1 == head->number_of_philosophers)
			head->philo[i].fork_r = 0;
		i++;
	}
}

void	init_thread(t_head *head)
{
	int	i;

	grab_time_start(head);
	i = 0;
	while (i < head->number_of_philosophers)
	{
		pthread_mutex_lock(&(head->index));
		head->n_thread = i;
		pthread_mutex_unlock(&(head->index));
		pthread_create(&head->philo[i].thread, 0, &routine, ((void *) head));
		usleep(50);
		i++;
	}
	pthread_create(&head->watcher, 0, &watcher, ((void *) head));
}

void	init_mutex(t_head *head)
{
	int	i;

	i = 0;
	head->fork = malloc(head->number_of_philosophers * sizeof(pthread_mutex_t));
	while (i < head->number_of_philosophers)
	{
		pthread_mutex_init(&head->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&head->printing, NULL);
	pthread_mutex_init(&head->index, NULL);
}
