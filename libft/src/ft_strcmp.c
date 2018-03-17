/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:14:01 by wto               #+#    #+#             */
/*   Updated: 2018/02/20 22:14:02 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strcmp() functions lexicographically compare the null-terminated
** strings s1 and s2.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
	else if (s1[i] == '\0' && s2[0] == '\0')
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		i++;
	}
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
