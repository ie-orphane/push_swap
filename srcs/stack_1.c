/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:11:54 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/19 10:51:22 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	if (!stk)
		return (true);
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

void	stk_show(t_stack *stk)
{
	t_stack	*node;

	node = stk;
	while (node)
	{
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}
