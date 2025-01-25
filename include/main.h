/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:01 by ielyatim          #+#    #+#             */
/*   Updated: 2025/01/25 18:09:57 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "ansi.h"

typedef enum e_stack
{
	STACK_A = 'a',
	STACK_B = 'b',
}					t_type;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				stk_push(t_stack **stk, int value);
void				stk_clear(t_stack **stk);
bool				stk_issorted(t_stack *stk);

void				stk_rotate(t_stack **stk, t_type type);
void				stk_rrotate(t_stack **stk, t_type type);
void				stk_swap(t_stack **stk, t_type type);

#endif // MAIN_H
