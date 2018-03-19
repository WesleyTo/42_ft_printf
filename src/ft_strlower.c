/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:05:11 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 19:05:13 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** ft_strlower takes in a pointer to a string and changes the uppercase
** alphabetic characters in the string to their lowercase equivalent.
*/

void	ft_strlower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}
