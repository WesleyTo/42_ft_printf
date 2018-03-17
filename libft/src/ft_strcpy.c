/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:05:28 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 19:05:38 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strcpy() function copies the string src to dst (including the
** terminating `\0' character.)
*/

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	while (i < len + 1)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
