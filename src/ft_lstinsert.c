/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:08:00 by wto               #+#    #+#             */
/*   Updated: 2018/02/23 21:08:01 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Inserts the content into a new link at the nth link, or at the end of the
** list, if n exceeds the length of the list
*/

static void	insert_beginning(t_list **lst, void const *content,
	size_t content_size)
{
	t_list *temp;

	temp = (*lst);
	*lst = ft_lstnew(content, content_size);
	(*lst)->next = temp;
}

void		ft_lstinsert(t_list **lst, size_t n, void const *content,
	size_t content_size)
{
	t_list *temp;
	t_list *curr;

	if (lst)
	{
		if (n == 0)
			insert_beginning(lst, content, content_size);
		else if (*lst)
		{
			curr = *lst;
			while (curr->next && (n > 1))
			{
				curr = curr->next;
				n--;
			}
			temp = curr->next;
			curr->next = ft_lstnew(content, content_size);
			curr->next->next = temp;
		}
		else
			(*lst) = ft_lstnew(content, content_size);
	}
	else
		(*lst) = ft_lstnew(content, content_size);
}
