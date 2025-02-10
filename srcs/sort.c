/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:45:07 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/10 09:45:15 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sort_three(t_stack **stk)
{
	int	max;

	max = stk_max((*stk));
	if ((*stk)->value == max)
		stk_rotate(stk, STACK_A);
	if ((*stk)->next->value == max)
		stk_rrotate(stk, STACK_A);
	if ((*stk)->value > (*stk)->next->value)
		stk_swap(stk, STACK_A);
}

void	sort_five(t_stack **stk)
{
	int		min;
	t_stack	*tmp;
	int		size;

	tmp = NULL;
	while (true)
	{
		size = stk_size(*stk);
		if (size <= 3)
			break ;
		min = stk_min(*stk);
		if ((*stk)->value == min)
			stk_push(stk, &tmp, STACK_B);
		else if (stk_index(*stk, min) <= size / 2)
			stk_rotate(stk, STACK_A);
		else
			stk_rrotate(stk, STACK_A);
	}
	if (!stk_issorted(*stk))
		sort_three(stk);
	while (stk_size(tmp) > 0)
		stk_push(&tmp, stk, STACK_A);
	stk_clear(&tmp);
}
