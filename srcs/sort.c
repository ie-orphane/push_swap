/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:45:07 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/24 09:04:49 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_sort_mini(t_stack **stk)
{
	int	max;

	if (stk_size(*stk) > 2)
	{
		max = stk_max((*stk));
		if ((*stk)->value == max)
			stk_rotate(stk, STACK_A);
		if ((*stk)->next->value == max)
			stk_rrotate(stk, STACK_A);
	}
	if ((*stk)->value > (*stk)->next->value)
		stk_swap(stk, STACK_A);
}

void	sort_small(t_stack **stk)
{
	int		min;
	t_stack	*tmp;
	int		size;

	tmp = NULL;
	while (true)
	{
		size = stk_size(*stk);
		if (size <= 3)
			break ;
		min = stk_min(*stk);
		if ((*stk)->value == min)
			stk_push(stk, &tmp, STACK_B);
		else if (stk_index(*stk, min) <= size / 2)
			stk_rotate(stk, STACK_A);
		else
			stk_rrotate(stk, STACK_A);
	}
	if (!stk_issorted(*stk))
		_sort_mini(stk);
	while (stk_size(tmp) > 0)
		stk_push(&tmp, stk, STACK_A);
	stk_clear(&tmp);
}

static void	_update_range(size_t *start, size_t *end, size_t index, size_t size)
{
	if (index > (*end))
		return ;
	if ((*end) < size - 1)
		(*end)++;
	if ((*start) < (*end) - 1)
		(*start)++;
}

static void	_sort_large(t_stack **stk, t_stack **tmp, size_t *end)
{
	t_arr	*arr;
	size_t	start;
	size_t	index;

	arr = arr_fromstk(*stk);
	arr_sort(arr);
	start = 0;
	*tmp = NULL;
	while (*stk)
	{
		index = arr_index(arr, ((*stk)->value));
		if (index < start)
		{
			stk_push(stk, tmp, STACK_B);
			stk_rotate(tmp, STACK_B);
		}
		else if (index <= (*end))
			stk_push(stk, tmp, STACK_B);
		else
			stk_rotate(stk, STACK_A);
		_update_range(&start, end, index, arr->size);
	}
	arr_clear(&arr);
}

void	sort_large(t_stack **stk, size_t *end)
{
	t_stack	*tmp;
	size_t	index;
	size_t	size;

	_sort_large(stk, &tmp, end);
	while (tmp)
	{
		index = stk_index(tmp, stk_max(tmp));
		size = stk_size(tmp);
		if (index <= size / 2)
		{
			while (index--)
				stk_rotate(&tmp, STACK_B);
		}
		else
		{
			index = size - index;
			while (index--)
				stk_rrotate(&tmp, STACK_B);
		}
		stk_push(&tmp, stk, STACK_A);
	}
	stk_clear(&tmp);
}
