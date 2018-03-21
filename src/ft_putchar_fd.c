/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:41:36 by wto               #+#    #+#             */
/*   Updated: 2018/02/22 00:41:38 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Outputs the char c to the file descriptor fd.
*/

static int	uni_to_utf8(unsigned char *buff, wchar_t c)
{
	int size;

	size = 0;
	if (c <= 0x7F && (size = 1))
		buff[0] = c;
	else if (c <= 0x7FF && (size = 2))
	{
		buff[0] = 0xC0 | (c >> 6);
		buff[1] = 0x80 | (c & 0x3F);
	}
	else if (c <= 0xFFFF && (size = 3))
	{
		buff[0] = 0xE0 | (c >> 12);
		buff[1] = 0x80 | ((c >> 6) & 0x3F);
		buff[2] = 0x80 | (c & 0x3F);
	}
	else if (c <= 0x10FFFF && (size = 4))
	{
		buff[0] = 0xF0 | (c >> 18);
		buff[1] = 0x80 | ((c >> 12) & 0x3F);
		buff[2] = 0x80 | ((c >> 6) & 0x3F);
		buff[3] = 0x80 | (c & 0x3F);
	}
	return (size);
}

void		ft_putchar_fd(wchar_t c, int fd)
{
	int				size;
	unsigned char	buf[4];

	size = uni_to_utf8((unsigned char *)buf, c);
	write(fd, buf, size);
}
