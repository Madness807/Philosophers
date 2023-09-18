/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:41:22 by joterret          #+#    #+#             */
/*   Updated: 2023/09/18 16:17:08 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void grab_time_before(t_head * head)
{
	struct timeval before;
	
	gettimeofday(&before, NULL);
	head->time.before_ms = (before.tv_sec * 1000 + before.tv_usec / 1000);
}

unsigned long long grab_time_dif(t_head * head)
{
	unsigned long long result;
	struct timeval after;
	
	gettimeofday(&after, NULL);
	result = (after.tv_sec * 1000 + after.tv_usec / 1000) - head->time.before_ms;
	return (result);
}
