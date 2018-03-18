/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:46:48 by wto               #+#    #+#             */
/*   Updated: 2018/02/22 00:46:49 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Outputs the integer n to the file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long			newn;
	int				i;
	unsigned char	arr[10];

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		newn = ((long)n) * (SIGN(n));
		i = 0;
		if (n < 0)
			ft_putchar_fd('-', fd);
		while (newn > 0)
		{
			arr[i++] = (unsigned char)(newn % 10);
			newn /= 10;
		}
		while (--i >= 0)
			ft_putchar_fd('0' + arr[i], fd);
	}
}
