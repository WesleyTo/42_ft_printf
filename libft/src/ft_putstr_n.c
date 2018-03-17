/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:46:44 by wto               #+#    #+#             */
/*   Updated: 2018/03/16 16:46:46 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Outputs up to n characters of the string s to the standard output.
** If n is greater than the length of s, ft_putstr_n outputs all of s up
** until the nul-terminator.
** ft_putstr_n returns the number of characters actually outputted.
*/

int	ft_putstr_n(char const *s, int n)
{
	int i;

	i = 0;
	while (*s && i < n)
	{
		ft_putchar_fd(*s++, 1);
		i++;
	}
	return (i);
}