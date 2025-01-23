/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:11:54 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/23 13:53:03 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_stkpush(t_stack **stk, int value)
{
	t_stack	*new;

	if (!stk)
		return ;
	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = *stk;
	*stk = new;
}

void	ft_stkclear(t_stack **stk)
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
