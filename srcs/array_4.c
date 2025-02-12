/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:08 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/12 16:42:57 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_arr	*arr_fromstk(t_stack *stk)
{
	size_t	i;
	size_t	size;
	t_arr	*arr;
	t_stack	*current;

	size = stk_size(stk);
	arr = arr_new(size, 0);
	current = stk;
	i = 0;
	while (i < size)
	{
		arr_set(arr, i, current->value);
		current = current->next;
		i++;
	}
	return (arr);
}
