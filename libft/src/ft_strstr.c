/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:28:53 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 22:28:53 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack. If needle is an empty
** string, haystack is returned; if needle occurs nowhere in haystack, NULL is
** returned; otherwise a pointer to the first character of the first occurrence
** of needle is returned.
*/

static char	*helper(const char *h, int hlen, const char *n, int nlen)
{
	int i;
	int j;
	int found;

	i = 0;
	while (i < hlen - nlen + 1)
	{
		j = 0;
		found = 1;
		while (j < nlen)
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

char		*ft_strstr(const char *haystack, const char *needle)
{
	int nlen;
	int hlen;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen == 0)
		return ((char *)haystack);
	if (nlen > hlen)
		return (NULL);
	return (helper(haystack, hlen, needle, nlen));
}
