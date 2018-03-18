/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:40:53 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 23:40:53 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** strlcat() appends string src to the end of dst.  It will append at most
** dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is incorrect or that
** dst is not a proper string).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	actualdstsize;
	int		i;
	int		j;
	int		spacetocopy;

	i = 0;
	j = 0;
	spacetocopy = dstsize;
	while (spacetocopy-- != 0 && dst[i] != '\0')
		i++;
	actualdstsize = i;
	spacetocopy = dstsize - actualdstsize;
	if (spacetocopy != 0)
	{
		while (src[j] != '\0')
		{
			if (spacetocopy-- == 1)
				break ;
			dst[i++] = src[j++];
		}
		dst[i] = '\0';
	}
	return (actualdstsize + ft_strlen(src));
}
