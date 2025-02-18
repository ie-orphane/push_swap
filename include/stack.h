/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:38:21 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/18 14:54:05 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef enum e_stack
{
	STACK_N = 'n',
	STACK_A = 'a',
	STACK_B = 'b',
}					t_type;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				stk_append(t_stack **stk, int value);
void				stk_pop(t_stack **stk);
bool				stk_issorted(t_stack *stk);
void				stk_clear(t_stack **stk);
void				stk_show(t_stack *stk);

int					stk_max(t_stack *stk);
int					stk_min(t_stack *stk);
int					stk_size(t_stack *stk);
int					stk_index(t_stack *stk, int value);
bool				stk_exists(t_stack *stk, int value);

void				stk_rotate(t_stack **stk, t_type type);
void				stk_rrotate(t_stack **stk, t_type type);
void				stk_swap(t_stack **stk, t_type type);
void				stk_push(t_stack **stk1, t_stack **stk2, t_type type);

#endif // STACK_H
