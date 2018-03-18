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
		c == 'o' || c == 'x' || c == 'X' || c == 'u' || c == 'p');
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

static int	printhelp(char f, va_list ap)
{
	char			*str;
	int				n;
	int				base;
	int				printed;
	long			nl;

	printed = 0;
	if (f == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr(str);
		printed = ft_strlen(str);
	}
	if (f == 'u')
	{
		nl = va_arg(ap, unsigned int);
		str = ft_itoa_base(nl, 10);
		ft_putstr(str);
		printed = ft_strlen(str);
		free(str);
	}
	if (f == 'p')
	{
		nl = va_arg(ap, long);
		str = ft_itoa_base(nl, 16);
		ft_strlower(str);
		ft_putstr(str);
		printed = ft_strlen(str);
		free(str);
	}
	if (f == 'd' || f == 'i' || f == 'o' || f == 'x' || f == 'X')
	{
		base = f == 'o' || f == 'O' ? 8 : 10;
		base = f == 'x' || f == 'X' ? 16 : base;
		n = va_arg(ap, int);
		str = ft_itoa_base(n, base);
		if (f == 'x')
			ft_strlower(str);
		ft_putstr(str);
		printed = ft_strlen(str);
		free(str);
	}
	if (f == 'c')
	{
		n = va_arg(ap, int);
		ft_putchar(n);
		printed = 1;
	}
	return (printed);
}

static int	parseformat(const char **fmt, va_list ap)
{
	int printed;

	printed = 0;
	if (**fmt && valid_format(**fmt))
	{
		printed = printhelp(**fmt, ap);
		(*fmt)++;

	}
	else if (**fmt && **fmt == '%')
	{
		ft_putchar('%');
		printed = 1;
	}
	return (printed);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*temp;
	int		printed;

	va_start(ap, fmt);
	printed = 0;
	while (*fmt)
	{
		temp = ft_strchr(fmt, '%');
		if (temp)
		{
			ft_putstr_n(fmt, temp - fmt);
			printed += temp - fmt;
			fmt = temp + 1;
			printed += parseformat(&fmt, ap);
		}
		else
		{
			ft_putstr(fmt);
			printed += ft_strlen(fmt);
			fmt += ft_strlen(fmt);
		}
	}
	va_end(ap);
	return (printed);
}
