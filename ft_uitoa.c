/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:58 by anthony           #+#    #+#             */
/*   Updated: 2023/11/27 23:18:56 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_div(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	cpy = malloc((src_len * sizeof(char)) + 1);
	if (cpy == NULL)
		return (NULL);
	while ((src)[i])
	{
		((char *)cpy)[i] = ((char *)src)[i];
		i++;
	}
	((char *)cpy)[i] = '\0';
	return (cpy);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	i = _div(n);
	str = malloc (sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i -= 1;
	while (i >= 0 && n > 0)
	{
		str[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (str);
}
