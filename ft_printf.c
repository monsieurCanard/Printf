/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:17:44 by anthony           #+#    #+#             */
/*   Updated: 2023/11/29 10:13:52 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		i;
	int		nb_char;

	i = 0;
	nb_char = 0;
	if (!str)
		return (-1);
	va_start (p, str);
	while (str[i])
	{
		if (str[i] == '%' && verif_arg(str[i + 1] == 0))
		{
			nb_char += dispatch(str[i + 1], p);
			i++;
		}	
		else if (str[i] == '%' && verif_arg(str[i + 1] == 1))
			return (-1);
		else
			nb_char += ft_putchar(str[i]);
		i++;
	}
	va_end(p);
	return (nb_char);
}

int	dispatch(char c, va_list p)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += putnbr(va_arg(p, int), 0);
	else if (c == 'c')
		count += ft_putchar(va_arg(p, int));
	else if (c == 's')
		count += putstr(va_arg(p, char *));
	else if (c == 'p')
		count += ft_point_hexa(va_arg(p, uint64_t), 1);
	else if (c == 'X')
		count += ft_putnbr_hexa(va_arg(p, int), 0);
	else if (c == 'x')
		count += ft_putnbr_hexa(va_arg(p, int), 1);
	else if (c == 'u')
		count += putnbr_unsigned(va_arg(p, unsigned int), 0);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	verif_arg(char c)
{
	if (c == '%' || c == 'c' || c == 's'
		|| c == 'u' || c == 'x' || c == 'X'
		|| c == 'd' || c == 'i' || c == 'p')
		return (0);
	else
		return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int main (void)
// {
// 	// char *p = NULL;
// 	// void *str = "...peut etre pas...";
// 	// unsigned int nb = 4294967295;
//  	ft_printf("%p", NULL);
// 	return 0;
// }