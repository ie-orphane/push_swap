/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:17:37 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/18 23:22:13 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_action	get_action(char *action)
{
	const char	*actions[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	i = 0;
	while (actions[i])
	{
		if (ft_strncmp(actions[i], action, ft_strlen(actions[i])) == 0)
			break ;
		i++;
	}
	return (i);
}

void	exe_action(t_stack **stk_a, t_stack **stk_b, t_action action)
{
	if (action == STK_SA || action == STK_SS)
		stk_swap(stk_a, STACK_N);
	if (action == STK_SB || action == STK_SS)
		stk_swap(stk_b, STACK_N);
	if (action == STK_PA)
		stk_push(stk_b, stk_a, STACK_N);
	if (action == STK_PB)
		stk_push(stk_a, stk_b, STACK_N);
	if (action == STK_RA || action == STK_RR)
		stk_rotate(stk_a, STACK_N);
	if (action == STK_RB || action == STK_RR)
		stk_rotate(stk_b, STACK_N);
	if (action == STK_RRA || action == STK_RRR)
		stk_rrotate(stk_a, STACK_N);
	if (action == STK_RRB || action == STK_RRR)
		stk_rrotate(stk_b, STACK_N);
}
