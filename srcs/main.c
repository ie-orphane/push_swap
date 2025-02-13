/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/13 09:47:45 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	if (!vars.stk || stk_issorted(vars.stk))
		ft_exit(&vars, 0);
	if (vars.ac - 1 <= 5)
		sort_five(&vars.stk);
	else
		sort_large(&vars.stk);
	ft_exit(&vars, 0);
}
