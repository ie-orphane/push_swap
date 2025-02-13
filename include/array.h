/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:47:49 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/12 21:43:20 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "int.h"
# include "libft.h"
# include "stack.h"

typedef struct s_arr
{
	size_t	size;
	int		*all;
}			t_arr;

t_arr		*arr_new(size_t size, int _value);
int			arr_get(t_arr *arr, size_t index);
int			arr_set(t_arr *arr, size_t index, int _new);
void		arr_show(t_arr *arr);
void		arr_clear(t_arr **arr);

t_arr		*arr_from(int *_arr, size_t size);
void		arr_copy(t_arr *from, t_arr *to);
int			arr_max(t_arr *arr);
t_arr		*arr_clone(t_arr *_arr);
void		arr_op(t_arr *arr, char operation, int operator);

size_t		arr_countif(t_arr *arr, bool (*cmp)(int));
t_arr		*arr_cloneif(t_arr *_arr, bool (*cmp)(int));
void		arr_sort(t_arr *arr);

t_arr		*arr_fromstk(t_stack *stk);
size_t		arr_index(t_arr *arr, int value);

#endif // ARRAY_H