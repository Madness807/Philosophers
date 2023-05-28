/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:09:50 by joterret          #+#    #+#             */
/*   Updated: 2023/05/28 05:14:34 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//FIXME - la verification de si c est un digit en entrer ou pas ne marche pas
// void	check_is_digit(char *num)
// {
// 	int	i;

// 	i = 0;
// 	while (num[i] != 0)
// 	{
// 		if (num[i] == '-' && i != 0)
// 			printf("ERROR: not a digit\n");
// 		if (num[i] == '-')
// 			i++;
// 		if (ft_isdigit(num[i]) == 1)
// 			i++;
// 		else
// 			printf("ERROR: not a digit\n");
// 	}
// 	return ;
// }

// void	check_if_args_is_digit(char **argv)
// {
// 	int i;

// 	i = 1;
// 	while (argv[i] != 0)
// 	{
// 		printf("%s\n", argv[i]);
// 		check_is_digit(argv[i]);
// 		i++;
// 	}
// }

void	take_rec_args(t_args *philo_args, char **argv)
{
	philo_args->number_of_philosophers = ft_atoi(argv[1]);
	philo_args->time_to_die = ft_atoi(argv[2]);
	philo_args->time_to_eat = ft_atoi(argv[3]);
	philo_args->time_to_spleep = ft_atoi(argv[4]);
}
