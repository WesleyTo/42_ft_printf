/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llu.c                                      :+:      :+:    :+:   */
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
** representing the unsigned long long n given as argument. If the allocation
** fails, the function returns NULL
*/

char	*ft_itoa_llu(unsigned long long n)
{
	return (ft_itoa_base_llu(n, 10));
}
