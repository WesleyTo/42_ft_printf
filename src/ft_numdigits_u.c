/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:01:33 by wto               #+#    #+#             */
/*   Updated: 2018/03/19 16:01:34 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns the number of digits in the unsigned number in base 10
*/

int	ft_numdigits_u(unsigned long long n)
{
	return (ft_numdigits_base_u(n, 10));
}
