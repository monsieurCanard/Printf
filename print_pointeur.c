/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:23:38 by anthony           #+#    #+#             */
/*   Updated: 2023/11/27 23:35:20 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*point_to_hex(uint64_t n, char *hexa)
{
	int	cursor;

	cursor = 19;
	while (cursor >= 0)
	{
		hexa[cursor] = n % 16 + '0';
		n /= 16;
		cursor--;
	}
	return (hexa);
}

int	ft_putstr_pointeur(char *s, int nb_char)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '0' )
		i++;
	nb_char = i;
	putstr("0x");
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	free (s);
	return (i + count - nb_char + 2);
}

int	ft_point_hexa(uint64_t n, int mode)
{
	char	*hexa;
	int		i;

	i = 2;
	if (n == 0)
		return (putstr("(nil)"));
	hexa = malloc(21);
	if (!hexa)
	{
		free (hexa);
		return (0);
	}
	ft_bzero(hexa, 21);
	hexa = point_to_hex(n, hexa);
	while (hexa[i])
	{
		if (hexa[i] > '9' && mode == 1)
			hexa[i] += 39;
		else if (hexa[i] > '9' && mode == 0)
			hexa[i] += 7;
		i++;
	}
	i = ft_putstr_pointeur(hexa, i);
	return (i);
}
