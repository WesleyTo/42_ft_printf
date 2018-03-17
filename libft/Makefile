#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wto <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 19:35:45 by wto               #+#    #+#              #
#    Updated: 2018/02/20 19:35:47 by wto              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a
HSRC		=	includes/libft.h
GCHSRC		=	includes/libft.h.gch
CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm
CDIR		=	src/
SRC			=	ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
ft_isprint ft_itoa ft_lstadd ft_lstbuild ft_lstdel ft_lstdelone ft_lstinsert \
ft_lstiter ft_lstmap ft_lstnew ft_lstrev ft_memalloc ft_memccpy ft_memchr \
ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_printintarr ft_putbits \
ft_putchar_fd ft_putchar ft_putendl_fd ft_putendl ft_putnbr_fd ft_putnbr \
ft_putstr_fd ft_putstr_n ft_putstr_n_fd ft_putstr ft_quicksort ft_strcat \
ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ \
ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr \
ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper get_next_line

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(addprefix $(CDIR), $(addsuffix .c, $(SRC))) $(HSRC)
	ar -rc $(NAME) $(addsuffix .o, $(SRC))
	ranlib $(NAME)

clean:
	$(RM) -rf $(addsuffix .o, $(SRC))
	$(RM) -rf $(GCHSRC)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
