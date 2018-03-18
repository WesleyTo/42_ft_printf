/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:37:59 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 23:38:00 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Outputs the string s to the standard output.
*/

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}