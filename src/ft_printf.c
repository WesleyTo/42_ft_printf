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

typedef struct	s_print
{
	int		width;
	t_bool	left_align;
	char	pad;
	t_bool	hex_prefix;
	int		precision;
	int		printed;
	char	fmt;
	void	*data;
	int		base;
}				t_print;

static t_print	*make_print_struct(void)
{
	t_print	*s = (t_print *)malloc(sizeof(t_print));
	if (!s)
		return (s);
	s->data = 0;
	s->fmt = 0;
	s->printed = 0;
	s->width = -1;
	s->precision = -1;
	s->left_align = TRUE;
	s->hex_prefix = FALSE;
	s->pad = ' ';
	s->base = 0;
	return (s);
}

static int		valid_format(char c)
{
	return (c == 's' || c == 'S' || c == 'd' || c == 'i' || c == 'c' ||
		c == 'o' || c == 'x' || c == 'X' || c == 'u' || c == 'p' ||
		c == '%' || c == 'D' || c == 'O' || c == 'U');
}

static void		printhelp(t_print *f)
{
	char			*str;
	char			*temp;
	int				base;
	t_bool			null;

	null = FALSE;
	if (f->fmt == 's')
		str = ft_strdup((char *)f->data);
	else if (f->fmt == 'u')
		str = ft_itoa_u((unsigned int)f->data);
	else if (f->fmt == 'p')
	{
		if (sizeof(void *) > 4)
			str = ft_itoa_base_l((long)f->data, 16);
		else
			str = ft_itoa_base_l((int)f->data, 16);
		ft_strlower(str);
		ft_putstr("0x");
		f->printed += 2;
	}
	else if (ft_tolower(f->fmt) == 'd' || f->fmt == 'i')
		str = ft_itoa_l((long)f->data);
	else if (ft_tolower(f->fmt) == 'o' || ft_tolower(f->fmt) == 'x' || f->fmt == 'U')
	{
		f->base = ft_tolower(f->fmt) == 'o' ? 8 : 10;
		f->base = ft_tolower(f->fmt) == 'x' ? 16 : f->base;
		if (f->fmt == 'O' || f->fmt == 'U')
			str = ft_itoa_base_lu((unsigned long)f->data, f->base);
		else
			str = ft_itoa_base_u((unsigned int)f->data, f->base);
		if (f->fmt == 'x')
			ft_strlower(str);
		if (f->hex_prefix && (ft_tolower(f->fmt) == 'x'))
			ft_putstr("0x");
	}
	else if (f->fmt == 'c')
	{
		base = (int)f->data;
		str = ft_chrstr(base);
		null = base ? FALSE : TRUE;
		f->printed += base ? 0 : 1;
		f->width += base ? 0 : -1;
	}
	else if (f->fmt == '%')
		str = ft_chrstr('%');
	else
		str = ft_strnew(0);
	temp = str;
	str = f->left_align ? ft_padstrl(temp, f->pad, f->width) : ft_padstrr(temp, f->pad, f->width);
	ft_putstr(str);
	if (null)
		ft_putchar(0);
	f->printed += ft_strlen(str);
	free(str);
	free(temp);
}

static int		parseformat(const char **fmt, va_list ap)
{
	t_print *f;

	f = make_print_struct();
	while (**fmt)
	{
		if (**fmt == '-')
		{
			f->left_align = FALSE;
			(*fmt)++;
		}
		else if (**fmt == '#')
		{
			f->hex_prefix = TRUE;
			(*fmt)++;
		}
		else if (**fmt == ' ')
			(*fmt)++;
		else if (**fmt == '.')
		{
			f->precision = ft_atoi(++(*fmt));
			(*fmt) += ft_numdigits(f->precision);
		}
		else if (**fmt == '0')
		{
			f->pad = f->left_align ? '0' : ' ';
			(*fmt)++;
		}
		else if (ft_isdigit(**fmt))
		{
			f->width = ft_atoi(*fmt);
			(*fmt) += ft_numdigits(f->width);
		}
		else if (valid_format(**fmt))
		{
			f->fmt = **fmt;
			f->data = va_arg(ap, void *);
			printhelp(f);
			(*fmt)++;
			return (f->printed);
		}
		else
			break ;
	}
	return (f->printed);
}

int				ft_printf(const char *fmt, ...)
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
