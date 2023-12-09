/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:07:53 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 16:07:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_custom(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		count++;
	}
	free (s);
	return (count);
}

static char	*int_to_hex(uint64_t n, char *hexa)
{
	int	i;
	int	cursor;

	i = 0;
	cursor = 7;
	while (i < 8)
	{
		hexa[i] = '0';
		i++;
	}
	hexa[8] = '\0';
	while (n > 0 && cursor >= 0)
	{
		hexa[cursor] = n % 16 + '0';
		n /= 16;
		cursor--;
	}
	return (hexa);
}

int	ft_putnbr_hexa(int n, int mode)
{
	char		*hexa;
	int			i;
	uint64_t	nb;

	nb = n;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	hexa = malloc(9);
	if (!hexa)
	{
		free (hexa);
		return (0);
	}
	hexa = int_to_hex(nb, hexa);
	while (hexa[i])
	{
		if (hexa[i] > '9' && mode == 1)
			hexa[i] += 39;
		else if (hexa[i] > '9' && mode == 0)
			hexa[i] += 7;
		i++;
	}
	i = ft_putstr_custom(hexa);
	return (i);
}
