/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:59 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/11 21:43:52 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flag
{
	char		*str;
	int			conv;
	int			zero;
	int			width;
	int			space;
	int			precis;
	int			lefted;
	int			sign;
	int			diez;
	int			llhh;
	int			lenght;
	int			size;
	int			bigl;
}				t_flag;

int				spe_atoi(char *str);
int				spe_size(char *str);
int				check_base(char *base);
t_flag			*init_flag(void);
void			free_flag(t_flag *flag);
t_flag			*convert_flag(char *str, va_list list);
t_flag			*check_flag(char *str);
int				is_ok(char c);
int				is_flag(char c);
int				is_option(char c);
int				assign_llhh(int nb, char *str);
int				assign_flag(t_flag *flag, char *str);
char			*assign_nohdioux(t_flag *flag, va_list list);
char			*assign_hdioux(t_flag *flag, va_list list);
char			*assign_hhdioux(t_flag *flag, va_list list);
char			*assign_ldioux(t_flag *flag, va_list list);
char			*assign_lldioux(t_flag *flag, va_list list);
char			*assign_dioux(t_flag *flag, va_list list);
char			*assign_csp(t_flag *flag, va_list list);
char			*assign_float(t_flag *flag, va_list list);
char			*ft_strjoinchar(char *str, char c);
char			*ft_joinzeros(char *str, int size);
char			*ft_strjoinsign(char *str);
char			*ft_strjoinright(char *str, int size);
char			*ft_strjoinleft(char *str, int size);
char			*strjoin_flag(char *buffer, t_flag *flag);
char			*ft_strjoin_free(char const *s1, char const *s2, char *to_free);
char			*ft_strdup_free(const char *src, char *to_free);
char			*ft_strnew_free(int size, char *to_free);
char			*ft_precis(t_flag *flag, char *str);
int				xnotnull(char *str);
int				ft_printf(const char *ptr, ...);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *as);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *str, char (*f)(char));
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *str, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin2(char const *s1, char const *s2, char const *s3);
char			*ft_strtrim(char const *s);
char			*ft_strtrimc(char const *s, int c);
char			**ft_strsplit(char const *s, char c);
int				ft_llisneg(long long n);
int				ft_sizell(long long n);
int				ft_sizeull_base(unsigned long long n, char *base);
int				ft_lisneg(long n);
int				ft_sizel(long n);
int				ft_sizeul_base(unsigned long n, char *base);
int				ft_hisneg(short n);
int				ft_sizeh(short n);
int				ft_sizeuh_base(unsigned short n, char *base);
int				ft_hhisneg(signed char n);
int				ft_sizehh(signed char n);
int				ft_sizeuhh_base(unsigned char n, char *base);
char			*ft_ftoa(float n, int precis);
char			*ft_itoa(int n);
char			*ft_itoa_base(unsigned int n, char *base);
char			*ft_ltoa(long n);
char			*ft_ultoa_base(unsigned long n, char *base);
char			*ft_lltoa(long long n);
char			*ft_ulltoa_base(unsigned long long n, char *base);
char			*ft_htoa(int n);
char			*ft_uhtoa_base(unsigned int n, char *base);
char			*ft_hhtoa(int n);
char			*ft_uhhtoa_base(unsigned int n, char *base);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
