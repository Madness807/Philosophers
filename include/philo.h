/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:37 by joterret          #+#    #+#             */
/*   Updated: 2023/06/07 04:37:38 by joterret         ###   ########.fr       */
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
	int				meal_count;
	long			time_awake;
	long			time_since_last_meal;
	void			*head;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		*thread;

}t_philosopher;

typedef struct s_time
{
	unsigned long long before_ms;
	unsigned long long after_ms;
	
}t_time;

typedef struct s_head
{
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	int				has_died;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	t_philosopher	*philo;
	t_time			time;
	
}t_head;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//					initialisation
void				init_head(t_head *input_args, char **argv);
void				init_philo(t_head *head);
void				init_thread(t_head *head);
void				init_mutex(t_head *head);

//					State function
void				ft_eat(t_philosopher *head);
void				ft_sleep(t_philosopher *head);
void				ft_think(t_philosopher *head);
void				ft_is_dead(t_philosopher *head);

//					time function
void				grab_time_before(t_head *head);
void				grab_time_after(t_head *head);
unsigned long long	grab_time_dif(t_head *head);

//					utils function 
long				ft_atol(const char *nptr);
int					ft_isdigit(int c);
void				check_if_args_is_digit(char **argv);
void				check_is_digit(char *num);
void				*routine(void *arg);

//					exit and free function 
void				free_philo_tab(t_head *head);
void				join_thread(t_head *head);

#endif
