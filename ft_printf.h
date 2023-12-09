/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:38:08 by anthony           #+#    #+#             */
/*   Updated: 2023/11/29 10:13:16 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>

int		ft_printf(const char *placeholder, ...);
int		ft_putchar(char c);
int		putnbr_unsigned(unsigned int n, int key);
int		putstr(char *s);
int		putnbr(int n, int key);
int		dispatch(char c, va_list p);
int		ft_putchar(char c);
char	*ft_uitoa(unsigned int n);
int		ft_point_hexa(uint64_t n, int mode);
int		ft_putnbr_hexa(int n, int mode);
int		putnbr(int n, int key);
int		putstr(char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		verif_arg(char c);
int		dispatch(char c, va_list p);
char	*ft_strdup(const char *src);
#endif