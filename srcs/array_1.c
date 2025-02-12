/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:15:45 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/12 16:43:41 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_arr	*arr_new(size_t size, int _value)
{
	t_arr	*arr;

	arr = ft_calloc(size, sizeof(t_arr));
	arr->size = size;
	arr->all = ft_calloc(size, sizeof(int));
	if (_value)
		ft_memset(arr->all, _value, size * sizeof(int));
	return (arr);
}

int	arr_get(t_arr *arr, size_t index)
{
	return (arr->all[index]);
}

int	arr_set(t_arr *arr, size_t index, int _new)
{
	int	_old;

	_old = arr->all[index];
	arr->all[index] = _new;
	return (_old);
}

void	arr_show(t_arr *arr)
{
	size_t	i;

	ft_printf("[");
	i = 0;
	while (i < arr->size)
	{
		if (i == arr->size - 1)
			ft_printf("%d", arr_get(arr, i++));
		else
			ft_printf("%d, ", arr_get(arr, i++));
	}
	ft_printf("]\n");
}

void	arr_clear(t_arr **arr)
{
	if (!arr || !*arr)
		return ;
	free((*arr)->all);
	free(*arr);
	*arr = NULL;
}
