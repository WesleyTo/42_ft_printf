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
	s->z = FALSE;
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
	*str = ft_strjoin("0X", temp);
	free(temp);
}

static void		append_char(char c, char **str)
{
	char *temp;
	char *temp2;

	temp = *str;
	temp2 = ft_chrstr(c);
	*str = ft_strjoin(temp2, temp);
	free(temp2);
	free(temp);
}

static void		trimstr(char **str, int n)
{
	char *temp;

	temp = *str;
	*str = ft_strncpy(ft_strnew(n), temp, n);
	free(temp);
}

static char *handle_unum(t_print *f)
{
	if (f->hh)
		return (ft_itoa_base_u((unsigned char)f->data, f->base));
	else if (f->h)
		return (ft_itoa_base_u((unsigned short)f->data, f->base));
	else if (f->ll)
		return (ft_itoa_base_llu((unsigned long long)f->data, f->base));
	else if (f->l)
		return (ft_itoa_base_lu((unsigned long)f->data, f->base));
	else if (f->j)
		return (ft_itoa_base_lu((uintmax_t)f->data, f->base));
	else if (f->z)
		return (ft_itoa_l((size_t)f->data));
	else
		return (ft_itoa_base_u((unsigned int)f->data, f->base));
}

static char		*handle_di(t_print *f)
{
	if (f->hh)
		return (ft_itoa((signed char)f->data));
	else if (f->h)
		return (ft_itoa((short)f->data));
	else if (f->ll)
		return (ft_itoa_ll((long long)f->data));
	else if (f->l)
		return (ft_itoa_l((long)f->data));
	else if (f->j)
		return (ft_itoa_l((intmax_t)f->data));
	else if (f->z)
		return (ft_itoa_l((size_t)f->data));
	else
		return (ft_itoa((int)f->data));
}

static char		*handle_D(t_print *f)
{
	return (ft_itoa_l((long)f->data));
}

static char		*handle_xXuo(t_print *f)
{
	if (f->f == 'x' || f->f == 'X')
		f->base = 16;
	if (f->f == 'o')
		f->base = 8;
	if (f->f == 'u')
		f->base = 10;
	return (handle_unum(f));
}

static char		*handle_U(t_print *f)
{
	char *str;

	str = ft_itoa_lu((unsigned long)f->data);
	return (str);
}

static char		*handle_O(t_print *f)
{
	char *str;

	f->base = 8;
	str = ft_itoa_base_lu((unsigned long)f->data, f->base);
	return (str);
}

static char		*handle_sS(t_print *f)
{
	char *str;

	str = (char *)f->data;
	if (str)
		str = ft_strdup(str);
	else
		str = ft_strdup("(null)");
	return (str);
}

static char		*handle_p(t_print *f)
{
	char *str;

	if (sizeof(void *) > 4)
		str = ft_itoa_base_l((long)f->data, 16);
	else
		str = ft_itoa_base((int)f->data, 16);
	ft_strlower(str);
	return (str);
}

static char		*handle_c(t_print *f, t_bool *t)
{
	char *str;

	str = ft_chrstr((int)f->data);
	*t = (int)f->data ? FALSE : TRUE;
	f->printed += !(*t) ? 0 : 1;
	f->width += !(*t) ? 0 : -1;
	return (str);
}

static char *handle_format(t_print *f, t_bool *t)
{
	if (ft_strchr("Ss", f->f))
		return(handle_sS(f));
	else if (f->f == 'u')
		return(handle_xXuo(f));
	else if (f->f == 'U')
		return(handle_U(f));
	else if (f->f == 'o')
		return(handle_xXuo(f));
	else if (f->f == 'O')
		return(handle_O(f));
	else if (f->f == 'p')
		return(handle_p(f));
	else if (f->f == 'D')
		return(handle_D(f));
	else if (f->f == 'd' || f->f == 'i')
		return(handle_di(f));
	else if (ft_tolower(f->f) == 'x')
		return(handle_xXuo(f));
	else if (ft_strchr("Cc", f->f))
		return(handle_c(f, t));
	else if (f->f == '%')
		return(ft_chrstr('%'));
	else
		return(ft_strnew(0));
}

static void		padstr(char **str, t_bool left, char pad, int width)
{
	char	*temp;
	char	sign;
	int		move_sign;

	temp = *str;
	sign = **str;
	move_sign = (sign == '-' || sign == '+') && pad == '0';
	if (move_sign)
		(*str)[0] = '0';
	if (left)
		*str = ft_padstrl(temp, pad, width);
	else
		*str = ft_padstrr(temp, pad, width);
	(*str)[0] = move_sign ? sign : (*str)[0];
	free(temp);
}

static void		printhelp(t_print *f)
{
	char			*str;
	t_bool			null;

	null = FALSE;
	str = handle_format(f, &null);
	if (f->precision != -1 && ft_strchr("Ss", f->f))
		trimstr(&str, f->precision);
	if (f->precision != -1 && ft_strchr("diouxX", f->f) && (int)ft_strlen(str) < f->precision)
		padstr(&str, TRUE, '0', f->precision);
	if (f->precision == 0 && ft_strchr("diouxX", f->f))
		trimstr(&str, 0);
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

static void set_flags(char c, t_print *f)
{
	f->left_pad = c == '-' ? FALSE : f->left_pad;
	f->sign = c == '+' ? TRUE : f->sign;
	f->hex_prefix = c == '#' ? TRUE : f->hex_prefix;
	f->spaced = c == ' ' ? TRUE : f->spaced;
	f->spaced = f->sign ? FALSE : f->spaced;
	f->zero = c == '0' ? TRUE : f->zero;
	f->zero = !f->left_pad ? FALSE : f->zero;
	f->ll = c == 'l' && f->l ? TRUE : f->ll;
	f->l = c == 'l' ? TRUE : f->l;
	f->hh = c == 'h' && f->h ? TRUE : f->hh;
	f->h = c == 'h' ? TRUE : f->h;
	f->j = c == 'j' ? TRUE : f->j;
	f->z = c == 'z' ? TRUE : f->z;
}

static int		parseformat(const char **fmt, va_list ap)
{
	t_print *f;
	int		n;

	f = make_print_struct();
	while (**fmt)
	{
		if (ft_strchr("-+# 0lhjz", **fmt))
		{
			set_flags(**fmt, f);
			(*fmt)++;
		}
		else if (**fmt == '.')
		{
			if (ft_isdigit(*(++(*fmt))))
				f->precision = ft_atoi(*fmt);
			(*fmt) += f->precision == -1 ? 0 : ft_numdigits(f->precision);
			f->precision = f->precision == -1 ? 0 : f->precision;
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
			break ;
		}
		else
			break ;
	}
	n = f->printed;
	free(f);
	return (n);
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
