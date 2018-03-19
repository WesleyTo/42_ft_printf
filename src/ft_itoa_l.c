/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:47:38 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 19:47:39 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the long n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL
*/

char		*ft_itoa_l(long n)
{
	return (ft_itoa_base_l(n, 10));
}
