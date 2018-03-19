/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padstrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:02:45 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 21:02:46 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns a fresh string created by left-padding the input string with
** character c up to width w. If w is less than or equal to the length of the
** input string, ft_padstrl returns an exact copy of the input.
*/

char	*ft_padstrl(const char *str, char c, int width)
{
	int		pad;
	int		i;
	char	*s;

	pad = width - ft_strlen(str);
	if (pad > 0)
	{
		s = ft_strnew(width);
		i = 0;
		while (i < pad)
			s[i++] = c;
		ft_strcpy(s + i, str);
		return (s);
	}
	else
		return (ft_strdup(str));
}
