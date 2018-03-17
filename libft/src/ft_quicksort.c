/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:48:43 by wto               #+#    #+#             */
/*   Updated: 2018/02/23 21:48:44 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Performs an in-place quicksort on an integer array
*/

static void	swap(int *arr, int a, int b)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

static void	ft_quicksort_help(int *arr, int lo, int hi)
{
	int pivot;
	int swap_index;
	int curr;

	if (lo < hi)
	{
		curr = lo;
		swap_index = lo;
		pivot = arr[hi];
		while (curr < hi)
		{
			if (arr[curr] < pivot)
				swap(arr, curr, swap_index++);
			curr++;
		}
		swap(arr, hi, swap_index);
		ft_quicksort_help(arr, lo, swap_index - 1);
		ft_quicksort_help(arr, swap_index + 1, hi);
	}
}

void		ft_quicksort(int *arr, int len)
{
	ft_quicksort_help(arr, 0, len - 1);
}
