/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printintarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:05:39 by wto               #+#    #+#             */
/*   Updated: 2018/02/23 22:05:43 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Formats and prints an integer array
** Example:
**     Input: 1, 2, 3, 4, 5
**     Output: [1, 2, 3, 4, 5]
*/

void	ft_printintarr(int *arr, size_t len)
{
	size_t i;

	i = 0;
	ft_putchar('[');
	while (i < len)
	{
		ft_putnbr(arr[i++]);
		if (i + 1 != len)
			ft_putstr(", ");
	}
	ft_putchar(']');
}
