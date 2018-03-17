/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:06:10 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 20:06:11 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The memmove() function copies len bytes from string src to string dst. The
** two strings may overlap; the copy is always done in a non-destructive manner.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;
	int	overlap;
	int	bound;
	int	dir;

	overlap = dst - src;
	if (ABS(overlap) < (int)len)
	{
		dir = SIGN(overlap);
		i = dir < 0 ? 0 : len - 1;
		bound = dir < 0 ? len : -1;
		while (i != bound)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i -= dir;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
