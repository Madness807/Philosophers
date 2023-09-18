/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:41:22 by joterret          #+#    #+#             */
/*   Updated: 2023/09/18 20:59:56 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void grab_time_before(t_head *head)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	head->start_time = (start.tv_sec * 1000 + start.tv_usec / 1000);
	

}

unsigned long long grab_time_dif(t_head *head)
{
	long long int	result;
	long long int	now;
	struct timeval after;
	
	gettimeofday(&after, NULL);
	now = (after.tv_sec * 1000 + after.tv_usec / 1000);
	
	result = now - head->start_time;
	return (result);
}
