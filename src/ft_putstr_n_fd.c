/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:47:01 by wto               #+#    #+#             */
/*   Updated: 2018/03/16 16:47:02 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Outputs up to n characters of the string s to the to the file descriptor fd.
** If n is greater than the length of s, ft_putstr_n outputs all of s up
** until the nul-terminator.
** ft_putstr_n returns the number of characters actually outputted.
*/

int	ft_putstr_n_fd(char const *s, int n, int fd)
{
	int i;

	i = 0;
	while (*s && i < n)
	{
		ft_putchar_fd(*s++, fd);
		i++;
	}
	return (i);
}
