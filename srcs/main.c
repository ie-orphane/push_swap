/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/24 15:26:38 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	stk_show(t_stack *stk)
{
	t_stack	*node;

	node = stk;
	while (node)
	{
		// ft_printf("%p %14p %d\n", node, node->next, node->value);
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	int		c;
	t_stack	*stk;

	stk = NULL;
	c = ac;
	while (--c)
		stk_push(&stk, ft_atoi(av[c]));
	stk_show(stk);
	while (!stk_issorted(stk))
	{
		if (stk->value > stk->next->value)
		{
			if (stk->value < stk->next->next->value)
				stk_swap(&stk, STACK_A);
			else
				stk_rotate(&stk, STACK_A);
		}
		else
			stk_rrotate(&stk, STACK_A);
	}
	stk_show(stk);
	stk_clear(&stk);
	return (0);
}
