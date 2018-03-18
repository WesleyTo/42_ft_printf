/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:27:02 by wto               #+#    #+#             */
/*   Updated: 2018/02/19 16:27:04 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The isascii() function tests for an ASCII character, which is any character
** between 0 and octal 0177 inclusive.
*/

int	ft_isascii(int c)
{
	return ((c <= 0177) && (c >= 0));
}
