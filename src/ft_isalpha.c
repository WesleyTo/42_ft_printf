/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:29:27 by wto               #+#    #+#             */
/*   Updated: 2018/02/19 14:31:41 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The isalpha() function tests for any character for which isupper(3) or
** islower(3) is true.
*/

int			ft_isalpha(int c)
{
	return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'));
}
