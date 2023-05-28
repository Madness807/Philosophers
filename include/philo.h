/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:37 by joterret          #+#    #+#             */
/*   Updated: 2023/05/28 04:55:37 by joterret         ###   ########.fr       */
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
    int             id;
    pthread_t       thread_id;//a comprendre
    pthread_mutex_t left_fork;//a comprendre
    pthread_mutex_t right_fork;//a comprendre
    // d'autres informations nécessaires, comme les heures de début et de fin des repas
}               t_philosopher;

typedef struct	s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_spleep;
	
}t_args;

//main function
void	take_rec_args(t_args *input_args, char **argv);
void	check_if_args_is_digit(char **argv);
void	check_is_digit(char *num);

//State function
void	ft_eat(void);
void	ft_sleep(void);
void	ft_think(void);

//utils function 
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

//exit function 

#endif

