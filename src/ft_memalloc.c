/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:28:42 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 18:28:42 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area. The memory
** allocated is initialized to 0. If the allocation fails, the function returns
** NULL.
*/

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (size != 0)
		*(unsigned char *)(ptr + (size--) - 1) = 0;
	return (ptr);
}
