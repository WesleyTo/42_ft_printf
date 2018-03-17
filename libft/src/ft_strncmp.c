/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:24:32 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 22:24:33 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strncmp() function compares not more than n characters. Because strncmp()
** is designed for comparing strings rather than binary data, characters that
** appear after a '\0' character are not compared.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
	else if (s1[i] == '\0' && s2[0] == '\0')
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
	return (0);
}
