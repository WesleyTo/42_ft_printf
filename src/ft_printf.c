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
		c == 'o' || c == 'x' || c == 'X' || c == 'u' || c == 'p' || c == '%');
}

static int	printhelp(char f, va_list ap, int width)
{
	char			*str;
	char			*temp;
	int				base;
	int				printed;

	printed = 0;
	if (f == 's')
		str = ft_strdup(va_arg(ap, char *));
	if (f == 'u')
		str = ft_itoa_base_l(va_arg(ap, unsigned int), 10);
	if (f == 'p')
	{
		if (sizeof(void *) > 4)
			str = ft_itoa_base_l(va_arg(ap, long), 16);
		else
			str = ft_itoa_base_l(va_arg(ap, int), 16);
		ft_strlower(str);
		ft_putstr("0x");
		printed += 2;
	}
	if (f == 'd' || f == 'i' || f == 'o' || f == 'x' || f == 'X')
	{
		base = f == 'o' || f == 'O' ? 8 : 10;
		base = f == 'x' || f == 'X' ? 16 : base;
		str = ft_itoa_base(va_arg(ap, int), base);
		if (f == 'x')
			ft_strlower(str);
	}
	if (f == 'c')
	{
		str = ft_strnew(1);
		str[0] = va_arg(ap, int);
	}
	if (f == '%')
	{
		str = ft_strnew(1);
		str[0] = '5';
	}
	temp = str;
	str = ft_padstrl(temp, ' ', width);
	ft_putstr(str);
	printed += ft_strlen(str);
	free(str);
	free(temp);
	return (printed);
}

static int	parseformat(const char **fmt, va_list ap)
{
	int printed;
	int	width;

	printed = 0;
	width = -1;
	while (**fmt)
	{
		if (ft_isdigit(**fmt))
		{
			width = ft_atoi(*fmt);
			(*fmt) += ft_numdigits(width);
		}
		else if (valid_format(**fmt))
		{
			printed = printhelp(**fmt, ap, width);
			(*fmt)++;
			return (printed);
		}
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
