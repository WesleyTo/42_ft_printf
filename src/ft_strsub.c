/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:58:18 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 19:58:19 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” substring from the string
** given as argument. The substring begins at indexstart and is of size len.
** If start and len aren’t refering to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start + len <= size)
	{
		str = (char *)malloc((len + 1) * sizeof(char));
		if (str)
		{
			i = 0;
			while (i < len)
			{
				str[i] = s[start + i];
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
