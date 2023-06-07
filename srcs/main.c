/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/06/07 04:24:21 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_head head;

	(void)argv;
	(void)argc;

	if (argc < 6)
		return (0);
	check_if_args_is_digit(argv);
	init_head(&head, argv);
	init_philo(&head);
	init_thread(&head);
	join_thread(&head);

	// NOTE - test de la partie qui gere le temp
	grab_time_before(&head);
	usleep(1000);
	grab_time_after(&head);
	unsigned long long resultat;
	resultat = grab_time_dif(&head);
	printf("je print la dif %llu\n", resultat);
	if (resultat > 10)
		printf("le temp est trop grand");	
}