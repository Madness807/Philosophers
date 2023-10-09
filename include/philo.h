/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:37 by joterret          #+#    #+#             */
/*   Updated: 2023/10/09 17:36:20 by joterret         ###   ########.fr       */
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
//									define									  //
////////////////////////////////////////////////////////////////////////////////

# define TOO_MANY_ARGS "ERR_INPUT: TOO MANY ARGUMENTS\n"
# define NOT_ENOUG_ARGS "ERR_INPUT: NOT ENOUG ARGUMENTS\n"
# define SYNTAX_ERREUR "ERR_INPUT: IS NOT A DIGIT\n"

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_head
{
	int						number_of_philosophers;
	int						nbtoeat;
	int						has_died;
	long					time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	long long int			start_time;
	int						n_thread;
	struct s_philosopher	*philo;
	pthread_mutex_t			*fork;
	pthread_mutex_t			*print;
	pthread_mutex_t			printing;
	pthread_mutex_t			index;
	pthread_mutex_t			dead;
	pthread_mutex_t			meal;
	pthread_t				watcher;
}t_head;

typedef struct s_philosopher
{
	int				id_philo;
	int				meal_count;
	long			time_awake;
	long			time_since_last_meal;
	t_head			*head;
	int				fork_l;
	int				fork_r;
	pthread_t		thread;

}t_philosopher;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//					input_checker
int					input_check(int argc);

//					initialisation
int					init_head(t_head *head, char **argv, int argc);
void				init_philo(t_head *head);
void				init_thread(t_head *head);
void				init_mutex(t_head *head);

//					State function
int					ft_eat(t_philosopher *head);
int					ft_sleep(t_philosopher *head);
int					ft_think(t_philosopher *head);
int					ft_taken_fork(t_philosopher *head);
void				ft_is_dead(t_philosopher *head);

//					time function
long				grab_time_now(void);
void				grab_time_start(t_head *head);
void				grab_time_after(t_head *head);
unsigned long long	grab_time_dif(t_head *head);
void				exec_action(long long time);

//					watcher
void				*watcher(void *head);

//					utils function 
long				ft_atol(const char *nptr);
int					ft_isdigit(int c);
int					check_if_args_is_digit(char **argv);
int					check_is_digit(char *num);
void				*routine(void *arg);

//					exit and free function 
void				join_thread(t_head *head);
int					destroy_mutex(t_head *head);

#endif
