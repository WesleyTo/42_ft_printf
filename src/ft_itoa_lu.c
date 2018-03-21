/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 23:31:49 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 23:31:50 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the unsigned long n given as argument. If the allocation fails,
** the function returns NULL
*/

char	*ft_itoa_lu(unsigned long n)
{
	return (ft_itoa_base_lu(n, 10));
}
