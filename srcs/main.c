/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:32 by joterret          #+#    #+#             */
/*   Updated: 2023/05/31 05:41:10 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	main(int argc, char **argv)
{
	t_head head;
	
	if (argc < 5)
		return (0);
	check_if_args_is_digit(argv);
	take_rec_args(&head, argv);
	init_philo_tab(&head);
	init_philo(&head);
	
	//TODO - cree les threads ailleurs que dans init_philo
	//TODO - cree les mutex
	//TODO - et d autre truc que je sais pas encore

	//TODO - Liberer la memoire et quitter le programme
	return (0);
}






