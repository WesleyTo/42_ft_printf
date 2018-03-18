/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:49:14 by wto               #+#    #+#             */
/*   Updated: 2018/03/15 22:49:27 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	valid_format(char c)
{
	return (c == 's' || c == 'S' || c == 'd' || c == 'i' || c == 'c' ||
		c == 'o' || c == 'x' || c == 'X');
}

void		ft_strupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

void		ft_strlower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}

static void	printhelp(char type, va_list ap)
{
	char	*str;
	int		n;
	int		base;

	if (type == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr(str);
	}
	if (type == 'd' || type == 'i' || type == 'o' || type == 'x' || type == 'X')
	{
		base = type == 'o' || type == 'O' ? 8 : 10;
		base = type == 'x' || type == 'X' ? 16 : base;
		n = va_arg(ap, int);
		str = ft_itoa_base(n, base);
		if (type == 'x')
			ft_strlower(str);
		ft_putstr(str);
		free(str);
	}
	if (type == 'c')
	{
		n = va_arg(ap, int);
		ft_putchar(n);
	}
}

void		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*temp;

	va_start(ap, fmt);
	while (*fmt)
	{
		temp = ft_strchr(fmt, '%');
		if (temp)
		{
			ft_putstr_n(fmt, temp - fmt);
			fmt = temp + 1;
			if (*fmt && valid_format(*fmt))
			{
				printhelp(*fmt, ap);
				fmt++;
			}
		}
		else
		{
			ft_putstr(fmt);
			fmt += ft_strlen(fmt);
		}
	}
	va_end(ap);
}
