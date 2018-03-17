/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:38:52 by wto               #+#    #+#             */
/*   Updated: 2018/02/23 20:38:53 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Given the address of a pointer to a list, reverse all elements of the list,
** and sets the pointer to the new list beginning.
*/

void	ft_lstrev(t_list **lst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	if (lst)
	{
		prev = NULL;
		curr = *lst;
		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		*lst = prev;
	}
}
