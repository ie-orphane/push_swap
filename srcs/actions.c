/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:07 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/23 17:45:40 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	stk_rotate(t_stack **stk, t_type type)
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
	ft_printf("r%c\n", type);
}

void	stk_rrotate(t_stack **stk, t_type type)
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
	ft_printf("rr%c\n", type);
}

void	stk_swap(t_stack **stk, t_type type)
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
	(*stk)->next = top;
	(*stk)->next->next = bottom;
	(*stk)->next->next->next = NULL;
	ft_printf("s%c\n", type);
}
