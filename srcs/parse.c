/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:18:36 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/19 11:18:36 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_exit(t_vars *vars, int status)
{
	if (vars->stk)
		stk_clear(&vars->stk);
	if (vars->tmp)
		stk_clear(&vars->tmp);
	if (vars->arr)
		ft_strs_free(&vars->arr);
	if (status != 0)
		ft_putstr_fd("Error\n", 2);
	exit(status);
}

static int	_parse_number(t_vars *vars, char *number)
{
	long	num;

	if (!ft_isnumber(number + (number[0] == '+' || number[0] == '-')))
		ft_exit(vars, 1);
	num = ft_atoi(number);
	if (num > INT_MAX || num < INT_MIN)
		ft_exit(vars, 1);
	if (stk_exists(vars->stk, num))
		ft_exit(vars, 1);
	return (num);
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
			i++;
		while (i--)
			stk_append(&vars->stk, _parse_number(vars, vars->arr[i]));
		ft_strs_free(&vars->arr);
	}
}
