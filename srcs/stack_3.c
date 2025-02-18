/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:07 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/18 14:55:54 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stk_rotate(t_stack **stk, t_type type)
{
	t_stack	*last;
	t_stack	*head;

	if (!stk || !*stk)
		return ;
	last = (*stk);
	while (last->next)
		last = last->next;
	head = (*stk)->next;
	last->next = (*stk);
	(*stk)->prev = last;
	head->prev = NULL;
	(*stk)->next = NULL;
	(*stk) = head;
	if (type != STACK_N)
		ft_printf("r%c\n", type);
}

void	stk_rrotate(t_stack **stk, t_type type)
{
	t_stack	*last;
	t_stack	*tail;

	if (!stk || !*stk)
		return ;
	last = (*stk);
	while (last->next)
		last = last->next;
	last->next = (*stk);
	tail = last->prev;
	tail->next = NULL;
	last->prev = NULL;
	(*stk)->prev = last;
	(*stk) = last;
	if (type != STACK_N)
		ft_printf("rr%c\n", type);
}

void	stk_swap(t_stack **stk, t_type type)
{
	t_stack	*tmp;

	if (!stk || !*stk)
		return ;
	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	tmp->next = (*stk);
	(*stk)->prev = tmp;
	tmp->prev = NULL;
	(*stk) = tmp;
	if (type != STACK_N)
		ft_printf("s%c\n", type);
}

void	stk_push(t_stack **stk1, t_stack **stk2, t_type type)
{
	t_stack	*tmp;

	if (!stk1 || !*stk1)
		return ;
	tmp = (*stk1)->next;
	(*stk1)->next = *stk2;
	*stk2 = *stk1;
	*stk1 = tmp;
	if (type != STACK_N)
		ft_printf("p%c\n", type);
}
