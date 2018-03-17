/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:07:25 by wto               #+#    #+#             */
/*   Updated: 2018/02/22 14:07:30 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The variables
** content and content_size of the new link are initialized by copy of the
** parameters of the function. If the parameter content is nul, the variable
** content is initialized to NULL and the variable content_size is initialized
** to 0 even if the parameter content_size isn’t. The variable next is
** initialized to NULL. If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	if (content)
	{
		lst->content = (void *)malloc(content_size);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	else
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	lst->next = NULL;
	return (lst);
}
