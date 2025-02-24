/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:01 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/24 09:04:27 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ansi.h"
# include "array.h"
# include "libft.h"
# include "stack.h"

typedef struct s_vars
{
	char	**arr;
	t_stack	*stk;
	t_stack	*tmp;
	int		ac;
	char	**av;
}			t_vars;

typedef enum e_action
{
	STK_SA,
	STK_SB,
	STK_SS,
	STK_PA,
	STK_PB,
	STK_RA,
	STK_RB,
	STK_RR,
	STK_RRA,
	STK_RRB,
	STK_RRR,
	STK_N,
}			t_action;

bool		ft_isnumber(char *str);
void		ft_strs_free(char ***strs);

void		ft_exit(t_vars *vars, int status);
void		ft_parse(t_vars *vars);

t_action	get_action(char *action);
void		exe_action(t_stack **stk_a, t_stack **stk_b, t_action action);

void		sort_small(t_stack **stk);
void		sort_large(t_stack **stk, size_t *end);

#endif // MAIN_H
