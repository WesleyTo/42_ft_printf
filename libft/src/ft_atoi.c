/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:12:37 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 18:12:38 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	has_sign(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		return (1);
	return (0);
}

static int	is_space(char c)
{
	int cond1;
	int cond2;

	cond1 = (c == '\t' || c == '\n' || c == '\v') ? 1 : 0;
	cond2 = (c == '\f' || c == '\r' || c == ' ') ? 1 : 0;
	return (cond1 || cond2);
}

static int	first_non_space_index(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	size_t	total;
	int		i;
	int		sign;
	size_t	max_pos_long;

	max_pos_long = 0x7FFFFFFFFFFFFFFF;
	total = 0;
	i = first_non_space_index(str);
	sign = has_sign(str, i);
	i += sign != 0 ? 1 : 0;
	while (str[i] >= '0' && str[i] <= '9')
		total = total * 10 + str[i++] - '0';
	if (sign != -1 && total > max_pos_long)
		return (-1);
	if (sign == -1 && total > max_pos_long + 1)
		return (0);
	total *= sign == 0 ? 1 : sign;
	return (total);
}
