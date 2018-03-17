/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:26:51 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 19:26:56 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Applies the function f to each character of the string given as argument to
** create a “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*str;
	int		i;

	if (!f || !s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (i < len)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
