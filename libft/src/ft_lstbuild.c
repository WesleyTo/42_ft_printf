/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:54:36 by wto               #+#    #+#             */
/*   Updated: 2018/02/23 20:55:36 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Converts an array of data into a 'fresh' linked list of the same copied data
*/

t_list	*ft_lstbuild(void *arr, size_t content_size, size_t len)
{
	size_t	i;
	t_list	*lst;
	t_list	*temp;

	i = 0;
	lst = NULL;
	if (!arr)
		return (NULL);
	while (len != 0)
	{
		temp = lst;
		lst = ft_lstnew((unsigned char *)(arr) + (len - 1) * content_size,
			content_size);
		ft_lstadd(&temp, lst);
		len--;
	}
	return (lst);
}
