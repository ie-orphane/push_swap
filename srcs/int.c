/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:21 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/12 16:12:42 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int.h"

bool	int_ispos(int num)
{
	return (num >= 0);
}

bool	int_isneg(int num)
{
	return (num < 0);
}

size_t	int_len(int num)
{
	size_t len;

	len = 1;
	while (true)
	{
		num /= 10;
		if (num == 0)
			break ;
		len++;
	}
	return (len);
}