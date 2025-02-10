/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:11:54 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/10 08:50:35 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	stk_append(t_stack **stk, int value)
{
	t_stack	*new;

	if (!stk)
		return ;
	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = *stk;
	new->prev = NULL;
	if (*stk)
		(*stk)->prev = new;
	*stk = new;
}

void	stk_pop(t_stack **stk)
{
	t_stack	*tmp;

	if (!stk)
		return ;
	tmp = (*stk)->next;
	free(*stk);
	*stk = tmp;
}

bool	stk_issorted(t_stack *stk)
{
	while (stk->next)
	{
		if (stk->value > stk->next->value)
			return (false);
		stk = stk->next;
	}
	return (true);
}

void	stk_clear(t_stack **stk)
{
	t_stack	*current_stack;
	t_stack	*tmp;

	if (stk)
	{
		current_stack = (*stk);
		while (current_stack)
		{
			tmp = current_stack->next;
			free(current_stack);
			current_stack = tmp;
		}
		*stk = NULL;
	}
}

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
