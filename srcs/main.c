/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/18 23:30:51 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		sort_small(&vars.stk);
	else
		sort_large(&vars.stk);
	ft_exit(&vars, 0);
}
