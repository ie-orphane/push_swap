/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:15:45 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/12 16:08:42 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_arr	*arr_from(int *_arr, size_t size)
{
	t_arr	*arr;
	size_t	i;

	arr = arr_new(size, 0);
	i = 0;
	while (i < size)
	{
		arr_set(arr, i, _arr[i]);
		i++;
	}
	return (arr);
}

void	arr_copy(t_arr *from, t_arr *to)
{
	size_t	i;

	i = 0;
	while (i < from->size && i < to->size)
	{
		arr_set(to, i, arr_get(from, i));
		i++;
	}
}

int	arr_max(t_arr *arr)
{
	int		max;
	size_t	i;
	int		value;

	i = 0;
	max = INT_MIN;
	while (i < arr->size)
	{
		value = arr_get(arr, i);
		if (value > max)
			max = value;
		i++;
	}
	return (max);
}

t_arr	*arr_clone(t_arr *_arr)
{
	size_t	i;
	t_arr	*arr;

	i = 0;
	arr = arr_new(_arr->size, 0);
	while (i < _arr->size)
	{
		arr_set(arr, i, arr_get(_arr, i));
		i++;
	}
	return (arr);
}

void	arr_op(t_arr *arr, char operation, int operator)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
	{
		if (operation == '-')
			arr_set(arr, i, arr_get(arr, i) - operator);
		else if (operation == '+')
			arr_set(arr, i, arr_get(arr, i) + operator);
		else if (operation == '*')
			arr_set(arr, i, arr_get(arr, i) * operator);
		else if (operation == '/')
			arr_set(arr, i, arr_get(arr, i) / operator);
		else if (operation == '%')
			arr_set(arr, i, arr_get(arr, i) % operator);
		i++;
	}
}
