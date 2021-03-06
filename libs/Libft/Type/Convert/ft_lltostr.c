/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:55:04 by fgalaup           #+#    #+#             */
/*   Updated: 2021/01/25 10:28:56 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltostr(long long number)
{
	char	*str;
	int		digits;
	int		i;
	int		is_negative;

	i = 0;
	is_negative = (number < 0);
	digits = ft_count_digits(number);
	if (!(str = ft_managed_malloc((digits + is_negative + 1) * sizeof(char))))
		return (NULL);
	i = digits + is_negative;
	while (i)
	{
		str[--i] = '0' + (number % 10) * ((is_negative * -2) + 1);
		number /= 10;
	}
	if (is_negative)
		str[0] = '-';
	str[digits + is_negative] = '\0';
	return (str);
}
