/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 00:23:30 by wto               #+#    #+#             */
/*   Updated: 2018/03/17 00:24:02 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Just A Regular String\n");
	printf("Just A Regular String\n");
	;
	ft_printf("Char test:\t%c\n", 'S');
	printf("Char test:\t%c\n", 'S');
	;
	ft_printf("String test:\t%s\n", "Success");
	printf("String test:\t%s\n", "Success");
	;
	ft_printf("Int (d) test:\t%d\n", 2147483647);
	printf("Int (d) test:\t%d\n", 2147483647);
	;
	ft_printf("Int (i) test:\t%i\n", 2147483647);
	printf("Int (i) test:\t%i\n", 2147483647);
	;
	ft_printf("Int (o) test:\t%o\n", 2147483647);
	printf("Int (o) test:\t%o\n", 2147483647);
	;
	ft_printf("Int (x) test:\t%x\n", 2147483647);
	printf("Int (x) test:\t%x\n", 2147483647);
	;
	ft_printf("Int (X) test:\t%X\n", 2147483647);
	printf("Int (X) test:\t%X\n", 2147483647);
	return (0);
}
