/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:15:45 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/12 16:14:04 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

size_t	arr_countif(t_arr *arr, bool (*cmp)(int))
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < arr->size)
	{
		if (cmp(arr_get(arr, i)))
			count++;
		i++;
	}
	return (count);
}

t_arr	*arr_cloneif(t_arr *_arr, bool (*cmp)(int))
{
	size_t	i;
	size_t	j;
	t_arr	*arr;
	size_t	size;

	size = arr_countif(_arr, cmp);
	arr = arr_new(size, 0);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (cmp(arr_get(_arr, j)))
		{
			arr_set(arr, i, arr_get(_arr, j));
			i++;
		}
		j++;
	}
	return (arr);
}

static void	count_sort(t_arr *arr, t_arr *_arr)
{
	int		i;
	t_arr	*tmp;
	t_arr	*lst;

	tmp = arr_new(10, 0);
	lst = arr_clone(arr);
	i = 0 - 1;
	while (++i < (int)_arr->size)
		arr_set(tmp, arr_get(_arr, i), arr_get(tmp, arr_get(_arr, i)) + 1);
	i = 1 - 1;
	while (++i < 10)
		arr_set(tmp, i, arr_get(tmp, i) + arr_get(tmp, i - 1));
	i = _arr->size;
	while (--i >= 0)
		arr_set(lst, arr_set(tmp, arr_get(_arr, i), arr_get(tmp, arr_get(_arr,
						i)) - 1) - 1, arr_get(arr, i));
	arr_copy(lst, arr);
	arr_clear(&lst);
	arr_clear(&tmp);
}

static void	radix_sort(t_arr *arr)
{
	size_t	len;
	t_arr	*_arr;
	size_t	j;
	size_t	k;

	len = int_len(arr_max(arr));
	k = 0;
	while (k < len)
	{
		_arr = arr_clone(arr);
		j = 0;
		while (j < k)
		{
			arr_op(_arr, '/', 10);
			j++;
		}
		arr_op(_arr, '%', 10);
		count_sort(arr, _arr);
		arr_clear(&_arr);
		k++;
	}
}

void	arr_sort(t_arr *arr)
{
	size_t	i;
	t_arr	*pos_arr;
	t_arr	*neg_arr;

	pos_arr = arr_cloneif(arr, int_ispos);
	neg_arr = arr_cloneif(arr, int_isneg);
	arr_op(neg_arr, '*', -1);
	radix_sort(pos_arr);
	radix_sort(neg_arr);
	i = neg_arr->size;
	while (i--)
		arr_set(arr, neg_arr->size - i - 1, -arr_get(neg_arr, i));
	i = pos_arr->size;
	while (i--)
		arr_set(arr, pos_arr->size - i - 1 + neg_arr->size, arr_get(pos_arr,
				pos_arr->size - i - 1));
	arr_clear(&pos_arr);
	arr_clear(&neg_arr);
}
