/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_classic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:01:27 by anthony           #+#    #+#             */
/*   Updated: 2023/11/29 10:12:47 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{		
	write (1, &c, 1);
	return (1);
}

int	putnbr_unsigned(unsigned int n, int key)
{
	int		i;
	char	*s;

	i = 0;
	if (key == 0)
	{
		s = ft_uitoa(n);
		i = ft_strlen(s);
		key = 1;
		free (s);
	}
	if (n > 9)
		putnbr_unsigned(n / 10, 1);
	ft_putchar ('0' + n % 10);
	return (i);
}

int	putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	putnbr(int n, int key)
{
	int		i;
	char	*s;

	if (key == 0)
	{
		s = ft_itoa(n);
		i = ft_strlen(s);
		key = 1;
		free (s);
	}
	if (n == -2147483648)
	{
		putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		putnbr(n / 10, 1);
	ft_putchar('0' + n % 10);
	return (i);
}
