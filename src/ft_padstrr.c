/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padstrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:02:37 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 21:02:38 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns a fresh string created by right-padding the input string with
** character c up to width w. If w is less than or equal to the length of the
** input string, ft_padstrl returns an exact copy of the input.
*/

char	*ft_padstrr(const char *str, char c, int width)
{
	int		pad;
	int		i;
	char	*s;

	i = ft_strlen(str);
	pad = width - i;
	if (pad > 0)
	{
		s = ft_strnew(width);
		ft_strcpy(s, str);
		while (i < width)
			s[i++] = c;
		return (s);
	}
	else
		return (ft_strdup(str));
}
