/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition_lol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 01:02:28 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/16 01:02:39 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strrev_minus1(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '-' && str[i] != '\0')
		i++;
	return (i);
}

char		*ft_minus(char *str, int *preci1, int j, int k)
{
	int		i;
	char	temp;

	i = ft_strrev_minus1(str);
	if (k == 0 && str[i] == '-' && (*preci1 >= j))
	{
		temp = str[i];
		str[i] = str[0];
		str[0] = '0';
		if (str[0] == '0')
			str = ft_strjoin("-", str);
	}
	else if (str[i] == '-' && (*preci1 >= j))
	{
		temp = str[i];
		str[i] = str[k - 1];
		str[k - 1] = temp;
		str[i] = '0';
		if (str[0] == '0')
			str = ft_strjoin("-", str);
	}
	return (str);
}

void		ft_reset(void)
{
	g_widthh = 0;
	g_preci = 0;
	g_flag = 0;
	g_count = 0;
	g_point = 0;
	g_pourcent = 0;
}

int			ft_i(va_list arg, char *str, int preci1, int i)
{
	i = pourcent(arg, str, preci1, i);
	i = checkout_i(str, i);
	return (i);
}

int			ft_popo_pourcent(char *str, int preci1, int i)
{
	if (str[i] == '%')
		i = pourcent_pourcent(str, preci1, i);
	return (i);
}
