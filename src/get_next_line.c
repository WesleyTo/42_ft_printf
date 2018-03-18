/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:46:21 by wto               #+#    #+#             */
/*   Updated: 2018/03/02 16:46:21 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		free_str_and_return(char **str, int ret)
{
	ft_strdel(str);
	return (ret);
}

static int		free_lstnode_and_return(t_list **lst, int fd, int ret)
{
	t_list *prev;
	t_list *curr;

	curr = *lst;
	prev = NULL;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
		{
			ft_strdel((char **)(&(curr->content)));
			if (prev == NULL)
				*lst = curr->next;
			else
				prev->next = curr->next;
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (ret);
}

static t_list	*get_fd(t_list **lst, int fd)
{
	t_list *node;

	node = *lst;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	node = ft_lstnew("", 1);
	node->content_size = fd;
	ft_lstadd(lst, node);
	return (node);
}

static void		read_to_nl(t_list *fd_in, const int fd)
{
	char	*buff;
	char	*temp;
	int		ret;

	buff = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		temp = fd_in->content;
		fd_in->content = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(fd_in->content, '\n'))
			break ;
	}
	ft_strdel(&buff);
}

int				get_next_line(const int fd, char **line)
{
	char			*content;
	char			*nl;
	static t_list	*fds;
	int				n;
	t_list			*fd_in;

	content = ft_strnew(0);
	if (fd < 0 || !line || read(fd, content, 0) < 0)
		return (free_str_and_return(&content, -1));
	fd_in = get_fd(&fds, fd);
	read_to_nl(fd_in, fd);
	free(content);
	content = (char *)fd_in->content;
	if (!(*content))
		return (free_lstnode_and_return(&fds, fd, 0));
	nl = ft_strchr(content, '\n');
	n = (nl ? nl - content : ft_strlen(content));
	*line = ft_strsub(content, 0, n);
	ft_strcpy(content, content + n + (nl ? 1 : 0));
	if (nl && !(*content))
		return (free_lstnode_and_return(&fds, fd, 1));
	return (1);
}
