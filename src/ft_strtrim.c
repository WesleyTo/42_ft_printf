/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:18:38 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 20:18:39 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string. Will be
** considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s
** has no whitespaces at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL.
*/

static int	is_whitespace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	first_nonspace_index(char const *s)
{
	int start;

	start = 0;
	while (is_whitespace(s[start]) && s[start] != '\0')
		start++;
	return (start);
}

static int	last_nonspace_index(char const *s)
{
	int	end;

	end = ft_strlen(s) - 1;
	while (is_whitespace(s[end]) && end > 0)
		end--;
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	start = first_nonspace_index(s);
	end = last_nonspace_index(s);
	if (start > end)
		return (ft_strnew(0));
	str = (char *)malloc((end + 2 - start) * sizeof(char));
	if (str)
	{
		len = 0;
		while (start <= end)
			str[len++] = s[start++];
		str[len] = '\0';
	}
	return (str);
}
