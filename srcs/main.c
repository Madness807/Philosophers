/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/05/28 05:45:46 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine()
{
	printf("test for threads\n");
	sleep(3);
	printf("ending threads\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	// t_args input_args;
	pthread_t t1;
	pthread_t t2;
	
	// if (argc < 5)
	// 	return (0);

	// check_if_args_is_digit(argv);
	// take_rec_args(&input_args, argv);
	pthread_create (&t1, NULL, &routine, NULL);
	pthread_create (&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return (0);
}
