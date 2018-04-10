/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:42:12 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 19:42:13 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the long n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL
*/

static char	get_char(int n)
{
	char *str;

	str = "0123456789ABCDEF";
	return (str[n]);
}

char		*ft_itoa_base_l(long n, int base)
{
	int		len;
	char	*a;
	int		bound;
	int		sign;

	if (n == (long)0x8000000000000000)
		return (ft_strdup("-9223372036854775808"));
	sign = SIGN(n);
	n *= SIGN(n);
	len = ft_numdigits_base(n, base) + (base == 10 && sign < 0 ? 1 : 0);
	bound = (base == 10 && sign < 0 ? 1 : 0);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[len--] = '\0';
	a[0] = '-';
	while (len >= bound)
	{
		a[len--] = get_char(n % base);
		n /= base;
	}
	return (a);
}
