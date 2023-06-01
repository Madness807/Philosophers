/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:37 by joterret          #+#    #+#             */
/*   Updated: 2023/05/31 04:39:05 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

////////////////////////////////////////////////////////////////////////////////
// 									Librairies							      //
////////////////////////////////////////////////////////////////////////////////

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////
typedef struct s_philosopher
{
	int				id_philo;
	int				time_awake;
	int				meal_count;
	long int		time_since_last_meal;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		thread;

}t_philosopher;

typedef struct s_head
{
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_philosopher	*philo;
}t_head;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//		initialisation
void	init_head(t_head *input_args, char **argv);
void	init_philo(t_head *head);
void	init_thread(t_head *head);
void	init_mutex(t_head *head);

//		State function
void	ft_eat(t_head *head);
void	ft_sleep(t_head *head);
void	ft_think(t_head *head);

//		utils function 
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	check_if_args_is_digit(char **argv);
void	check_is_digit(char *num);

// a remplir
void	*routine(void *arg);

//		exit and free function 
void	free_philo_tab(t_head *head);

#endif