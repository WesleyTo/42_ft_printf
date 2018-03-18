/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:54:02 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 19:54:03 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long. The memcmp() function returns
** zero if the two strings are identical, otherwise returns the difference
** between the first two differing bytes (treated as unsigned char values)
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	t1;
	unsigned char	t2;

	i = 0;
	while (i < n)
	{
		t1 = *((unsigned char *)(s1 + i));
		t2 = *((unsigned char *)(s2 + i));
		if (t1 != t2)
			return ((int)t1 - (int)t2);
		i++;
	}
	return (0);
}
