/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:07 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/23 13:50:15 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_stkrotate(t_stack **stk)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	if (!stk || !*stk)
		return ;
	top = (*stk);
	middle = top->next;
	bottom = middle->next;
	(*stk) = middle;
	(*stk)->next = bottom;
	(*stk)->next->next = top;
	(*stk)->next->next->next = NULL;
}

void	ft_stkrrotate(t_stack **stk)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	if (!stk || !*stk)
		return ;
	top = (*stk);
	middle = top->next;
	bottom = middle->next;
	(*stk) = bottom;
	(*stk)->next = top;
	(*stk)->next->next = middle;
	(*stk)->next->next->next = NULL;
}

void	ft_stkswap(t_stack **stk)
{
	t_stack *top;
	t_stack *middle;
	t_stack *bottom;

	if (!stk || !*stk)
		return ;
	top = (*stk);
	middle = top->next;
	bottom = middle->next;
	(*stk) = middle;
	(*stk)->next = top;
	(*stk)->next->next = bottom;
	(*stk)->next->next->next = NULL;
}