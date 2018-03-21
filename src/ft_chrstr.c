/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:18:56 by wto               #+#    #+#             */
/*   Updated: 2018/03/19 21:18:57 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The ft_chrstr() takes in a character and returns a string of that character.
*/

char	*ft_chrstr(int c)
{
	char *s;

	s = ft_strnew(1);
	s[0] = c;
	return (s);
}
