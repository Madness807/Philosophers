/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 19:53:40 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_head	head;

	if (one_philo_case(argv) == 1)
		return (1);
	if (input_check(argc) == 1)
		return (1);
	if (check_if_args_is_digit(argv) == 1)
		return (1);
	init_head(&head, argv, argc);
	init_mutex(&head);
	init_philo(&head);
	init_thread(&head);
	join_thread(&head);
	destroy_mutex(&head);
	free_malloc(&head);
}
