/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:11:54 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/13 18:41:51 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stk_max(t_stack *stk)
{
	int	max;

	max = stk->value;
	while (stk)
	{
		if (stk->value > max)
			max = stk->value;
		stk = stk->next;
	}
	return (max);
}

int	stk_min(t_stack *stk)
{
	int	min;

	min = stk->value;
	while (stk)
	{
		if (stk->value < min)
			min = stk->value;
		stk = stk->next;
	}
	return (min);
}

int	stk_index(t_stack *stk, int value)
{
	int	i;

	i = 0;
	while (stk)
	{
		if (stk->value == value)
			return (i);
		stk = stk->next;
		i++;
	}
	return (-1);
}

int	stk_size(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

bool	stk_exists(t_stack *stk, int value)
{
	while (stk)
	{
		if (stk->value == value)
			return (true);
		stk = stk->next;
	}
	return (false);
}
