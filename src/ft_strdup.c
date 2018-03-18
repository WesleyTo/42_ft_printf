/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:53:03 by wto               #+#    #+#             */
/*   Updated: 2018/02/19 22:53:04 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it.
*/

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*newstr;
	int		i;

	len = ft_strlen(s1);
	newstr = (char *)malloc(len * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		newstr[i] = s1[i];
		i++;
	}
	return (newstr);
}
