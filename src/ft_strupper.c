/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:05:05 by wto               #+#    #+#             */
/*   Updated: 2018/03/18 19:05:07 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** ft_strupper takes in a pointer to a string and changes the lowercase
** alphabetic characters in the string to their uppercase equivalent.
*/

void	ft_strupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
