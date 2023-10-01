/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:41:22 by joterret          #+#    #+#             */
/*   Updated: 2023/09/30 16:18:41 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	grab_time_now(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (time_now);
}

void	grab_time_start(t_head *head)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	head->start_time = (start.tv_sec * 1000 + start.tv_usec / 1000);
}

unsigned long long	grab_time_dif(t_head *head)
{
	long long int	result;
	long long int	now;
	struct timeval	after;

	gettimeofday(&after, NULL);
	now = (after.tv_sec * 1000 + after.tv_usec / 1000);
	result = now - head->start_time;
	return (result);
}

int	find_delta(struct timeval t1, struct timeval t2)
{
	int	start;
	int	end;

	start = (int)(t1.tv_sec * 1000 + t1.tv_usec / 1000);
	end = (int)(t2.tv_sec * 1000 + t2.tv_usec / 1000);
	return (end - start);
}

void	exec_action(long long time)
{
	struct timeval	t1;
	struct timeval	t2;
	int				delta;

	delta = 0;
	gettimeofday(&t1, NULL);
	while (delta < time)
	{
		usleep(100);
		gettimeofday(&t2, NULL);
		delta = find_delta(t1, t2);
	}
}
