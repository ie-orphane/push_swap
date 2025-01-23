/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:01 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/23 13:50:49 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				ft_stkpush(t_stack **stk, int value);
void				ft_stkclear(t_stack **stk);
void				ft_stkrotate(t_stack **stk);
void				ft_stkrrotate(t_stack **stk);
void				ft_stkswap(t_stack **stk);

#endif // MAIN_H
