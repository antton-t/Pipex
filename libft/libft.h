/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 02:28:59 by antton-t          #+#    #+#             */
/*   Updated: 2021/06/29 20:00:13 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
char			*ft_rmv_tab(char *str);
int			ft_intlength(int n);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstnew(void *content);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char		*ft_get_next_line(int fd, int buffer_size);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			*ft_calloc(size_t num, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_isupper(int c);
int             ft_check_argv(char *str, char *end);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
double				ft_atof(char *str, int *str_length);
double				ft_atof_1(char **str);
int				ft_tolower(int c);
void			ft_swap(int *a, int *b);
int				ft_doublength(double nb);
int				ft_toupper(int c);
int				ft_atoi(const char *nptr);
int				ft_atoi_1(char **nptr);
int				ft_atoi_count(const char *nptr, int *count);
int				ft_isspace(const char s);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *big, const char *little,
		size_t len);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			ft_joinstr(char** str, char **buff);
void			ft_free_split(char **split, int i);
#endif
