/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:41:22 by joterret          #+#    #+#             */
/*   Updated: 2023/06/14 01:40:40 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void grab_time_before(t_head * head)
{
	struct timeval before;
	
	gettimeofday(&before, NULL);
	head->time.before_ms = (before.tv_sec * 1000 + before.tv_usec / 1000);
	//printf("le temp avant en ms %llu\n", head->time.before_ms);
}

void grab_time_after(t_head * head)
{
	struct timeval after;

	gettimeofday(&after, NULL);
	head->time.after_ms = (after.tv_sec * 1000 + after.tv_usec / 1000);
	//printf("le temp apres en ms %llu\n", head->time.after_ms);
}

unsigned long long grab_time_dif(t_head * head)
{
	unsigned long long result;

	result = head->time.after_ms - head->time.before_ms;
	return (result);
}

// void	sleep_nano(t_head *head)
// {

	
// }