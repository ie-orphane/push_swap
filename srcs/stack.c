/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:11:54 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/23 17:46:05 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	stk_push(t_stack **stk, int value)
{
	t_stack	*new;

	if (!stk)
		return ;
	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = *stk;
	*stk = new;
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
