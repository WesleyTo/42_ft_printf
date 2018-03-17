/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:33:48 by wto               #+#    #+#             */
/*   Updated: 2018/02/19 16:33:50 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The isprint() function tests for any printing character, including space.
*/

int	ft_isprint(int c)
{
	return (c <= 0176 && c >= 040);
}
