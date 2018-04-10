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

static t_print	*make_print_struct(void)
{
	t_print	*s = (t_print *)malloc(sizeof(t_print));
	if (!s)
		return (s);
	s->data = 0;
	s->f = 0;
	s->printed = 0;
	s->width = -1;
	s->precision = -1;
	s->left_pad = TRUE;
	s->hex_prefix = FALSE;
	s->zero = FALSE;
	s->base = 0;
	s->l = FALSE;
	s->ll = FALSE;
	s->h = FALSE;
	s->hh = FALSE;
	s->j = FALSE;
	s->spaced = FALSE;
	s->sign = FALSE;
	return (s);
}

static void		putformat(char *str, t_print *f)
{
	ft_putstr(str);
	f->printed += ft_strlen(str);
}

static void		hexify(char **str)
{
	char *temp;

	temp = *str;
	*str = ft_strjoin("0X", *str);
	free(temp);
}

static void	append_char(char c, char **str)
{
	char *temp;
	char *temp2;

	temp = *str;
	temp2 = ft_chrstr(c);
	*str = ft_strjoin(temp2, *str);
	free(temp2);
	free(temp);
}

static void		padstr(char **str, t_bool left, char pad, int width)
{
	char *temp;

	temp = *str;
	if (left)
		*str = ft_padstrl(temp, pad, width);
	else
		*str = ft_padstrr(temp, pad, width);
	free(temp);
}

static void		printhelp(t_print *f)
{
	char			*str;
	int				base;
	t_bool			null;

	null = FALSE;
	if (ft_strchr("Ss", f->f))
	{
		str = (char *)f->data;
		if (str)
			str = ft_strdup(str);
		else
			str = ft_strdup("(null)");
	}
	else if (f->f == 'u')
		str = ft_itoa_u((unsigned int)f->data);
	else if (f->f == 'p')
	{
		if (sizeof(void *) > 4)
			str = ft_itoa_base_l((long)f->data, 16);
		else
			str = ft_itoa_base((int)f->data, 16);
		ft_strlower(str);
	}
	else if (f->f == 'D')
		str = ft_itoa_l((long)f->data);
	else if (ft_strchr("di", f->f))
		str = ft_itoa((int)f->data);
	else if (ft_strchr("OoXxU", f->f))
	{
		f->base = ft_tolower(f->f) == 'o' ? 8 : 10;
		f->base = ft_tolower(f->f) == 'x' ? 16 : f->base;
		if (f->f == 'O' || f->f == 'U')
			str = ft_itoa_base_lu((unsigned long)f->data, f->base);
		else
			str = ft_itoa_base_u((unsigned int)f->data, f->base);
	}
	else if (ft_strchr("Cc", f->f))
	{
		base = (int)f->data;
		str = ft_chrstr(base);
		null = base ? FALSE : TRUE;
		f->printed += base ? 0 : 1;
		f->width += base ? 0 : -1;
	}
	else if (f->f == '%')
		str = ft_chrstr('%');
	else
		str = ft_strnew(0);
	if (f->hex_prefix && f->f == 'o')
		append_char('0', &str);
	if (!f->sign && f->spaced && str[0] != '-' && (f->f == 'd' || f->f == 'i'))
		append_char(' ', &str);
	if (f->sign && ft_strchr("dD", f->f) && str[0] != '-')
		append_char('+', &str);
	if (f->zero)
	{
		if (f->f == 'p' || (ft_tolower(f->f) == 'x' && f->hex_prefix && (int)f->data))
			f->width -= 2;
		padstr(&str, f->left_pad, '0', f->width);
		if (f->f == 'p' || (ft_tolower(f->f) == 'x' && f->hex_prefix && (int)f->data))
			hexify(&str);
	}
	else
	{
		if (f->f == 'p' || (ft_tolower(f->f) == 'x' && f->hex_prefix && (int)f->data))
			hexify(&str);
		padstr(&str, f->left_pad, ' ', f->width);
	}
	if (f->f == 'x')
		ft_strlower(str);
	putformat(str, f);
	if (null)
		ft_putchar(0);
	free(str);
}

static int		parseformat(const char **fmt, va_list ap)
{
	t_print *f;

	f = make_print_struct();
	while (**fmt)
	{
		if (ft_strchr("-+# 0lhj", **fmt))
		{
			f->left_pad = **fmt == '-' ? FALSE : f->left_pad;
			f->sign = **fmt == '+' ? TRUE : f->sign;
			f->hex_prefix = **fmt == '#' ? TRUE : f->hex_prefix;
			f->spaced = **fmt == ' ' ? TRUE : f->spaced;
			f->spaced = f->sign ? FALSE : f->spaced;
			f->zero = **fmt == '0' ? TRUE : f->zero;
			f->zero = !f->left_pad ? FALSE : f->zero;
			f->ll = **fmt == 'l' && f->l ? TRUE : f->ll;
			f->l = **fmt == 'l' ? TRUE : f->l;
			f->hh = **fmt == 'h' && f->h ? TRUE : f->hh;
			f->h = **fmt == 'h' ? TRUE : f->h;
			f->j = **fmt == 'j' ? TRUE : f->j;
			(*fmt)++;
		}
		else if (**fmt == '.')
		{
			if (ft_isdigit(*(++(*fmt))))
				f->precision = ft_atoi(*fmt);
			(*fmt) += f->precision == -1 ? 0 : ft_numdigits(f->precision);
		}
		else if (ft_isdigit(**fmt))
		{
			f->width = ft_atoi(*fmt);
			(*fmt) += ft_numdigits(f->width);
		}
		else if (ft_strchr("SsDdOoXxUuCcip%", **fmt))
		{
			f->f = **fmt;
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
