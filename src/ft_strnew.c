/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:49:32 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 18:49:53 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at ’\0’. If the allocation fails
** the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char *str;

	size++;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	while (size != 0)
	{
		*(char *)(str + size - 1) = 0;
		size--;
	}
	return (str);
}
