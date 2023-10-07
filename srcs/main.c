/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/10/07 22:51:35 by joterret         ###   ########.fr       */
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
	return (0);
}

int	main(int argc, char **argv)
{
	t_head	head;

	if (argc < 5)
		return (0);
	check_if_args_is_digit(argv);
	init_head(&head, argv, argc);
	init_mutex(&head);
	init_philo(&head);
	init_thread(&head);
	join_thread(&head);
	destroy_mutex(&head);
}
