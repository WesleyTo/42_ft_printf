/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wto <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:31:50 by wto               #+#    #+#             */
/*   Updated: 2018/02/19 14:32:43 by wto              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define ABS(x)		x < 0 ? -1 * x : x
# define SIGN(x)	x < 0 ? -1 : 1
# define BUFF_SIZE 32
# define MAX_T_SIZE sizeof(intmax_t)
# define SIZE_T_SIZE sizeof(size_t)
# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_print
{
	int		width;
	int		precision;
	int		printed;
	int		base;
	char	f;
	void	*data;
	t_bool	zero;
	t_bool	sign;
	t_bool	spaced;
	t_bool	left_pad;
	t_bool	hex_prefix;
	t_bool	l;
	t_bool	ll;
	t_bool	h;
	t_bool	hh;
	t_bool	j;
	t_bool	z;
}				t_print;

int				ft_atoi(const char *str);
void			*ft_bzero(void *s, size_t len);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int n);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(wchar_t c);
void			ft_putchar_fd(wchar_t c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

t_list			*ft_lstbuild(void *arr, size_t content_size, size_t len);
void			ft_lstinsert(t_list **l, size_t n, void const *c, size_t s);
void			ft_lstrev(t_list **lst);
void			ft_printintarr(int *arr, size_t len);
void			ft_putbits(unsigned char c);
void			ft_quicksort(int *arr, int len);

int				ft_putstr_n(char const *s, int n);
int				ft_putstr_n_fd(char const *s, int n, int fd);
int				get_next_line(const int fd, char **line);
char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_base(int n, int base);
char			*ft_itoa_base_u(unsigned int n, int base);
void			ft_strupper(char *str);
void			ft_strlower(char *str);
char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_l(long n);
char			*ft_itoa_ll(long long n);
char			*ft_itoa_lu(unsigned long n);
char			*ft_itoa_llu(unsigned long long n);
char			*ft_itoa_base_l(long n, int base);
char			*ft_itoa_base_ll(long long n, int base);
char			*ft_itoa_base_lu(unsigned long n, int base);
char			*ft_itoa_base_llu(unsigned long long n, int base);
int				ft_numdigits(long long n);
int				ft_numdigits_base(long long n, int base);
int				ft_numdigits_u(unsigned long long n);
int				ft_numdigits_base_u(unsigned long long n, int base);
char			*ft_padstrl(const char *str, char c, int width);
char			*ft_padstrr(const char *str, char c, int width);
char			*ft_chrstr(int c);
int				ft_printf(const char *fmt, ...);

#endif
