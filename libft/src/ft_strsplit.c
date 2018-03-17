/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:51:15 by wto               #+#    #+#             */
/*   Updated: 2018/02/21 20:51:16 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the character c as a delimiter. If the allocation fails the function returns
** NULL.
** Example:
**     ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array
**     ["hello", "fellow", "students"]
*/

static int	get_word_length(const char *str, int start, char d)
{
	int i;

	i = start;
	while (str[i] != '\0' && str[i] != d)
		i++;
	return (i - start);
}

static int	next_non_delimiter_index(const char *str, int start, char d)
{
	int i;

	i = start;
	while (str[i] != '\0' && str[i] == d)
		i++;
	return (i);
}

static int	get_num_words(const char *str, char d)
{
	int i;
	int num_words;

	i = next_non_delimiter_index(str, 0, d);
	num_words = 0;
	while (str[i] != '\0')
	{
		while (str[i] != d && str[i] != '\0')
			i++;
		num_words++;
		i = next_non_delimiter_index(str, i, d);
	}
	return (num_words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		wc;
	int		count;

	if (!s)
		return (NULL);
	wc = 0;
	count = get_num_words(s, c);
	i = next_non_delimiter_index(s, 0, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (tab)
	{
		tab[count] = 0;
		while (wc < count)
		{
			tab[wc] = ft_strsub(s, i, get_word_length(s, i, c));
			i = next_non_delimiter_index(s, i + ft_strlen(tab[wc]), c);
			wc++;
		}
		tab[wc] = (char *)'\0';
	}
	return (tab);
}
