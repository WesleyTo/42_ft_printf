/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits_base_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:01:39 by wto               #+#    #+#             */
/*   Updated: 2018/03/19 16:01:41 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns the number of digits in the unsigned number in the specified base
*/

int	ft_numdigits_base_u(unsigned long n, int base)
{
	int log;

	log = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		log++;
	}
	return (log);
}
