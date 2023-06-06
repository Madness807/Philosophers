/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/06/02 17:43:41 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philosopher *head)
{
	printf("\033[0;42m Le philosphe %i est en train de manger\033[0m\n", head->id_philo);
	head->meal_count++;
}

void	ft_sleep(t_philosopher *head)
{
	printf("\033[0;43m Le philosphe %i est en train de dormir\033[0m\n", head->id_philo);
}

void	ft_think(t_philosopher *head)
{
	printf("\033[0;46m Le philosphe %i est en train de penser\033[0m\n", head->id_philo);
}

void	ft_is_dead(t_philosopher *head)
{
	printf("\033[0;46m Le philosphe %i est en train de penser\033[0m\n", head->id_philo);
}