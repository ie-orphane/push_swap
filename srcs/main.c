/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/23 13:51:39 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	ft_stkshow(t_stack *stk)
{
	t_stack	*node;

	node = stk;
	while (node)
	{
		printf("%p %14p %d\n", node, node->next, node->value);
		node = node->next;
	}
}

int	main(int ac, char **av)
{
	int		c;
	t_stack	*stk;

	stk = NULL;
	c = ac;
	while (--c)
		ft_stkpush(&stk, ft_atoi(av[c]));
	ft_stkshow(stk);
	if (stk->value > stk->next->value
		&& stk->next->value < stk->next->next->value)
	{
		ft_stkrotate(&stk);
		printf("ra\n");
	}
	else if (stk->value < stk->next->value
		&& stk->next->next->value < stk->value)
	{
		ft_stkrrotate(&stk);
		printf("rra\n");
	}
	else if (stk->value > stk->next->value)
	{
		ft_stkswap(&stk);
		printf("sa\n");
	}
	ft_stkshow(stk);
	ft_stkclear(&stk);
	return (0);
}
