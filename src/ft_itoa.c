/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:54:57 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 21:55:05 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL
*/

static int	logbase10(long n)
{
	int log;

	log = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		log++;
	}
	return (log);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*a;
	int		bound;
	long	newn;

	newn = ((long)n) * (SIGN(n));
	len = logbase10(newn);
	len += (n < 0 ? 1 : 0);
	bound = (n < 0 ? 1 : 0);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[len--] = '\0';
	a[0] = '-';
	while (len >= bound)
	{
		a[len--] = '0' + (newn % 10);
		newn /= 10;
	}
	return (a);
}
