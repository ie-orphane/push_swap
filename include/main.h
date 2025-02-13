/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:01 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/13 08:47:39 by ielyatim         ###   ########.fr       */
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
	int		ac;
	char	**av;
}			t_vars;

bool		ft_isnumber(char *str);
void		ft_strs_free(char ***strs);

void		sort_three(t_stack **stk_ptr);
void		sort_five(t_stack **stk);
void		sort_large(t_stack **stk);

#endif // MAIN_H
