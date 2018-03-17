/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:45:52 by wto               #+#    #+#             */
/*   Updated: 2018/02/19 22:45:53 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The bzero() function writes n zeroed bytes to the string s.  If n is zero,
** bzero() does nothing.
*/

void	*ft_bzero(void *s, size_t len)
{
	size_t	i;
	size_t	bound;

	i = 0;
	bound = len - len % 8;
	while (i < bound)
	{
		*(unsigned long *)(s + i) = 0;
		i += 8;
	}
	while (i < len)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return (s);
}
