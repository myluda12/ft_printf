/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:22:04 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 06:22:06 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strrev_minus(char *str, int *preci1)
{
	int		k;
	int		j;
	int		i;

	i = ft_strrev_minus1(str);
	k = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	j = j - i;
	while (str[k] == ' ')
		k++;
	if (str[i] == '\0')
		return (str);
	str = ft_minus(str, preci1, j, k);
	return (str);
}

char		*ft_print_zero(char *s, int count)
{
	char	*str;

	str = malloc(sizeof(char) * g_preci + 2);
	str[g_preci + 1] = 0;
	while (count >= 0)
	{
		str[g_preci--] = s[count--];
	}
	while (g_preci >= 0)
	{
		str[g_preci--] = '0';
	}
	return (str);
}

char		*ft_trololo(char *str, int *preci1)
{
	str = ft_strrev_minus(str, preci1);
	str = ft_print_flags_minus(str, preci1);
	return (str);
}

char		*ft_print_spaces(char *s, int *preci1, int i, char *str1)
{
	char	*str;
	int		d;
	int		remaind;

	remaind = g_widthh;
	d = ft_strlen(s);
	if (d > g_widthh)
		g_widthh = d;
	str = malloc(sizeof(char) * g_widthh + 1);
	while (d >= 0)
	{
		str[g_widthh] = s[d];
		d--;
		g_widthh--;
	}
	while (g_widthh >= 0)
		str[g_widthh--] = ' ';
	if (remaind >= 2)
	{
		if (str[remaind - 1] == '0' && (str[remaind - 2] < '0'
			|| str[remaind - 2] > '9') && *preci1 == 0 && str1[i] == '.')
			str[remaind - 1] = ' ';
	}
	str = ft_trololo(str, preci1);
	return (str);
}

char		*ft_only_zero(char *s)
{
	int		d;
	int		i;
	char	*str;

	i = 0;
	d = ft_strlen(s);
	str = malloc(sizeof(char) + 1);
	if (s[0] == '0' && s[1] == '\0')
	{
		str[0] = '0';
	}
	str[1] = '\0';
	return (str);
}
