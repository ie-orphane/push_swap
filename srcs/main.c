/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/25 18:42:53 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int	main(int ac, char **av)
{
	int		c;
	t_stack	*stk;
	int		max;

	stk = NULL;
	c = ac;
	while (--c)
		stk_push(&stk, ft_atoi(av[c]));
	max = stk_max(stk);
	if (stk->value == max)
		stk_rotate(&stk, STACK_A);
	if (stk->next->value == max)
		stk_rrotate(&stk, STACK_A);
	if (stk->value > stk->next->value)
		stk_swap(&stk, STACK_A);
	// if (stk_issorted(stk))
	// 	ft_printf(B_GREEN "OK" R_GREEN ": ");
	// else
	// 	ft_printf(B_RED "KO" R_RED ": ");
	// stk_show(stk);
	// ft_printf(RESET);
	stk_clear(&stk);
	return (0);
}
