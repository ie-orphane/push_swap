/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/10 10:03:45 by ielyatim         ###   ########.fr       */
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

void	stk_summary(t_stack *stk)
{
	t_stack	*node;

	node = stk;
	while (node)
	{
		printf("%14p %14p %14p %d\n", node->prev, node, node->next,
			node->value);
		node = node->next;
	}
	ft_printf("\n");
}

void	stk_result(t_stack *stk)
{
	if (stk_issorted(stk))
		ft_printf(B_GREEN "OK" R_GREEN ": ");
	else
		ft_printf(B_RED "KO" R_RED ": ");
	stk_show(stk);
	ft_printf(RESET);
}

int	main(int ac, char **av)
{
	int		c;
	t_stack	*stk;
	// t_stack	*tmp;

	stk = NULL;
	// tmp = NULL;
	c = ac;
	while (--c)
		stk_append(&stk, ft_atoi(av[c]));
	sort_five(&stk);
	stk_clear(&stk);
	return (0);
}
