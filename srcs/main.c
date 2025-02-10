/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/10 11:33:37 by ielyatim         ###   ########.fr       */
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

void	ft_exit(t_vars *vars, int status)
{
	if (vars->stk)
		stk_clear(&vars->stk);
	if (vars->arr)
		ft_strs_free(&vars->arr);
	if (status != 0)
		ft_printf("Error\n");
	exit(status);
}

void	ft_parse(t_vars *vars)
{
	int		i;
	char	*num;
	int		c;

	c = vars->ac;
	while (--c)
	{
		num = ft_strtrim(vars->av[c], " ");
		i = ft_strlen(num);
		free(num);
		if (i == 0)
			ft_exit(vars, 1);
		vars->arr = ft_split(vars->av[c], ' ');
		i = 0;
		while (vars->arr[i])
		{
			if (!ft_isnumber(vars->arr[i] + (vars->arr[i][0] == '+'
						|| vars->arr[i][0] == '-')))
				ft_exit(vars, 1);
			stk_append(&vars->stk, ft_atoi(vars->arr[i]));
			i++;
		}
		ft_strs_free(&vars->arr);
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	vars.ac = ac;
	vars.av = av;
	ft_parse(&vars);
	sort_five(&vars.stk);
	stk_clear(&vars.stk);
	return (0);
}
