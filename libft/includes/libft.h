/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:19:38 by agouin            #+#    #+#             */
/*   Updated: 2025/01/23 18:24:35 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isascii(int i);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int i);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isalnum(int i);
int		ft_isprint(int i);
void	*ft_memset(void *s, int c, size_t n);
int		ft_tolower(int c);
int		ft_isalpha(int i);
int		ft_toupper(int c);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *f, const char *s, size_t l);
int		ft_memcmp(const void *p1, const void *p2, size_t n);
void	*ft_calloc(size_t c, size_t s);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t s);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
//22
int		ft_printf(const char *format, ...);
int		ft_putnbr2(unsigned int n);
int		ft_putnbrx(unsigned int n);
int		ft_putstr(unsigned char *s);
char	*ft_samitoa(unsigned int l);
int		ft_pointeur(void *w);
int		ft_str_isnumeric(char *str);

#endif
