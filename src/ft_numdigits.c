/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:44:06 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 20:44:07 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns the number of digits in the number in base 10
*/

int	ft_numdigits(long n)
{
	return (ft_numdigits_base(n, 10));
}
