/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:47:36 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/19 11:17:10 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_show_result(t_vars *vars)
{
	if (stk_issorted(vars->stk) && !vars->tmp)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(vars, 0);
}

int	main(int ac, char **av)
{
	char		*line;
	t_action	action;
	t_vars		vars;

	ft_bzero(&vars, sizeof(vars));
	vars.ac = ac;
	vars.av = av;
	ft_parse(&vars);
	if (!vars.stk)
		ft_exit(&vars, 0);
	while (true)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		action = get_action(line);
		free(line);
		if (action == STK_N)
		{
			get_next_line(-1);
			ft_exit(&vars, 1);
		}
		exe_action(&vars.stk, &vars.tmp, action);
	}
	_show_result(&vars);
}
