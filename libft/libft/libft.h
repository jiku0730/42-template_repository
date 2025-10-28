/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:55:13 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 10:08:21 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

/*════════════════════════════════════════════════════════════════════════════*/
/*                           TYPE DEFINITIONS                                */
/*════════════════════════════════════════════════════════════════════════════*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*════════════════════════════════════════════════════════════════════════════*/
/*                            CTYPE FUNCTIONS                                */
/*════════════════════════════════════════════════════════════════════════════*/

/* Character classification functions */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

/* Character conversion functions */
int		ft_tolower(int c);
int		ft_toupper(int c);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           STRING FUNCTIONS                                */
/*════════════════════════════════════════════════════════════════════════════*/

/* Standard string functions */
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncat(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* String manipulation functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* Additional string functions */
int		ft_strrcmp(const char *s1, const char *s2);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           MEMORY FUNCTIONS                                 */
/*════════════════════════════════════════════════════════════════════════════*/

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memrchr(const void *s, int c, size_t n);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           BSD STRINGS FUNCTIONS                            */
/*════════════════════════════════════════════════════════════════════════════*/

/* BSD string functions */
int		ft_bcmp(const void *s1, const void *s2, size_t n);
void	ft_bcopy(const void *src, void *dst, size_t n);

/* Bit manipulation */
int		ft_ffs(int i);

/* String search functions (legacy) */
char	*ft_index(const char *s, int c);
char	*ft_rindex(const char *s, int c);

/* Case-insensitive string comparison */
int		ft_strcasecmp(const char *s1, const char *s2);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           LIST FUNCTIONS                                   */
/*════════════════════════════════════════════════════════════════════════════*/

/* Linked list functions */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*════════════════════════════════════════════════════════════════════════════*/
/*                           OUTPUT FUNCTIONS                                 */
/*════════════════════════════════════════════════════════════════════════════*/

/* File descriptor output functions */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           CONVERSION FUNCTIONS                             */
/*════════════════════════════════════════════════════════════════════════════*/

/* Number conversion functions */
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           UTILITY FUNCTIONS                                */
/*════════════════════════════════════════════════════════════════════════════*/

/* Mathematical utility functions */
int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_swap(int *a, int *b);

/*════════════════════════════════════════════════════════════════════════════*/
/*                           GET_NEXT_LINE FUNCTION                           */
/*════════════════════════════════════════════════════════════════════════════*/

/* File reading function */
char	*get_next_line(int fd);

#endif
