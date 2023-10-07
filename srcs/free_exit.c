/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:39:22 by joterret          #+#    #+#             */
/*   Updated: 2023/10/07 21:37:20 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// //TODO - free le tableau de philosophe

// void    free_philo_tab(t_head *head)
// {
//     free(head->philo);
// }

// //TODO - détruire les mutex 
/*
void	join_thread(t_head *head)
{
	int			i;
	pthread_t	*curr;

	i = 0;
	while (i < head->number_of_philosophers)
	{
		curr = &head->philo[i].thread;
		pthread_join(*curr, NULL);
		i++;
	}
}
*/