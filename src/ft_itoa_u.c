/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 23:31:26 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 23:31:27 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the unsigned integer n given as argument. If the allocation
** fails, the function returns NULL
*/

char	*ft_itoa_u(unsigned int n)
{
	return (ft_itoa_base_u(n, 10));
}
