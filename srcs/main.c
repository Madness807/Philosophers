/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/10/08 21:02:18 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
