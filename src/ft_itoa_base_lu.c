/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 23:31:45 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 23:31:46 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the unsigned long n given as argument. If the allocation fails,
** the function returns NULL
*/

static char	get_char(int n)
{
	char *str;

	str = "0123456789ABCDEF";
	return (str[n]);
}

char		*ft_itoa_base_lu(unsigned long n, int base)
{
	int		len;
	char	*a;

	a = NULL;
	if (base >= 2)
	{
		len = ft_numdigits_base_u(n, base);
		a = (char *)malloc(sizeof(char) * (len + 1));
		if (!a)
			return (NULL);
		a[len--] = '\0';
		a[0] = '-';
		while (len >= 0)
		{
			a[len--] = get_char(n % base);
			n /= base;
		}
	}
	return (a);
}
