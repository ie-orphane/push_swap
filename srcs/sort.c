/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:45:07 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/25 22:44:18 by ielyatim         ###   ########.fr       */
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

	tmp = NULL;
	while (true)
	{
		ft_printf("a: ");
		stk_show(*stk);
		ft_printf("b: ");
		stk_show(tmp);
		int size = stk_size(*stk);
		if (size <= 3)
			break ;
		min = stk_min(*stk);
		ft_printf("%d %d\n", min, (*stk)->value);
		if ((*stk)->value == min)
		{
			stk_push(stk, &tmp, STACK_B);
			continue ;
		}
		if (stk_index(*stk, min) <= size / 2)
			stk_rotate(stk, STACK_A);
		else
			stk_rrotate(stk, STACK_A);
	}
	stk_clear(&tmp);
}
