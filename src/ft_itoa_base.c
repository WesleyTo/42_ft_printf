/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:30:28 by wto               #+#    #+#             */
/*   Updated: 2018/03/17 14:30:28 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL
*/

static int	logbasen(long n, int base)
{
	int log;

	log = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		log++;
	}
	return (log);
}

char		*ft_itoa_base(int n, int base)
{
	int		len;
	char	*a;
	int		bound;
	long	newn;
	char	*str;

	str = "0123456789ABCDEF";
	newn = ((long)n) * (SIGN(n));
	len = logbasen(newn, base);
	len += (base == 10 && n < 0 ? 1 : 0);
	bound = (base == 10 && n < 0 ? 1 : 0);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[len--] = '\0';
	a[0] = '-';
	while (len >= bound)
	{
		a[len--] = str[newn % base];
		newn /= base;
	}
	return (a);
}
