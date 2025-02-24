/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:05 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/24 09:03:42 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	size_t	size;
	size_t	end;

	ft_bzero(&vars, sizeof(vars));
	vars.ac = ac;
	vars.av = av;
	ft_parse(&vars);
	if (!vars.stk || stk_issorted(vars.stk))
		ft_exit(&vars, 0);
	if (vars.ac - 1 <= 5)
		sort_small(&vars.stk);
	else
	{
		size = stk_size(vars.stk);
		if (size <= 100)
			end = size / 5;
		else if (size <= 500)
			end = size / 13;
		else
			end = size / 20;
		sort_large(&vars.stk, &end);
	}
	ft_exit(&vars, 0);
}
