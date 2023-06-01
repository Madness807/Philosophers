/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:08:43 by joterret          #+#    #+#             */
/*   Updated: 2023/05/31 03:26:24 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_head *head)
{
	printf("Le philosphe %i\n est en train de manger", head->philo->id_philo);
}

void	ft_sleep(t_head *head)
{
	printf("Le philosphe %i\n est en train de dormir", head->philo->id_philo);
}

void	ft_think(t_head *head)
{
	printf("Le philosphe %i\n est en train de penser", head->philo->id_philo);
}
