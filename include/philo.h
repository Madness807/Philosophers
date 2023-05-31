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

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

//struct
typedef struct  s_philosopher
{
	int		id_philo;
	int		time_awake;
	int		meal_count;
	int		fork1;
	int		time_since_last_meal;
	pthread_t	thread;

}t_philosopher;

typedef struct	s_head
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_spleep;
	t_philosopher	*philo;
	
}t_head;

//initialisation 
void	init_head(t_head *head);
void	init_philo_tab(t_head *head);
void	init_philo(t_head *head);

//main function
void	take_rec_args(t_head *input_args, char **argv);
void	check_if_args_is_digit(char **argv);
void	check_is_digit(char *num);

//State function
void	ft_eat();
void	ft_sleep();
void	ft_think();

//utils function 
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);


void	*routine(void *arg);



//exit function 

#endif

