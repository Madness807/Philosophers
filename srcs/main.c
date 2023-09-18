/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/09/18 16:40:42 by joterrett        ###   ########.fr       */
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
	init_mutex(&head);
	init_philo(&head);
	init_thread(&head);
	join_thread(&head);

}