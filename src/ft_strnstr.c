/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:18:01 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 23:18:02 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters are
** searched. Characters that appear after a `\0' character are not searched.
*/

static char	*helper(const char *h, const char *n, int nlen, size_t len)
{
	int i;
	int j;
	int found;
	int hlen;

	i = 0;
	hlen = ft_strlen(h);
	while ((i < hlen - nlen + 1) && (i <= (int)len - nlen))
	{
		j = 0;
		found = 1;
		while (j < nlen && h[j + i] != '\0' && n[j] != '\0')
		{
			if (h[j + i] != n[j])
			{
				found = 0;
				break ;
			}
			j++;
		}
		if (found)
			return ((char *)(h + i));
		i++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int nlen;
	int hlen;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen == 0)
		return ((char *)haystack);
	if (nlen > hlen || nlen > (int)len)
		return (NULL);
	if ((int)len >= hlen && (int)len >= nlen)
		return (ft_strstr(haystack, needle));
	return (helper(haystack, needle, nlen, len));
}
