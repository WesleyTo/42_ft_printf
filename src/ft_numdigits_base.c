/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:44:45 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 20:44:47 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns the number of digits in the number in the specified base
*/

int	ft_numdigits_base(long n, int base)
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
