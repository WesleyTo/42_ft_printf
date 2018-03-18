/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:25:38 by wto               #+#    #+#             */
/*   Updated: 2018/02/23 21:25:39 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Writes the bit representation of the input (as an unsigned char) to stdin
*/

void	ft_putbits(unsigned char c)
{
	int n;

	n = 7;
	while (n >= 0)
		ft_putchar('0' + (1 & (c >> n--)));
}
