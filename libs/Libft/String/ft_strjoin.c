/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:59:21 by fgalaup           #+#    #+#             */
/*   Updated: 2021/01/24 14:08:33 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str1_lenght;
	size_t	str2_lenght;

	str1_lenght = ft_strlen(s1);
	str2_lenght = ft_strlen(s2);
	if (!(str = ft_calloc(str1_lenght + str2_lenght + 1, sizeof(char))))
		return (NULL);
	ft_strlcat(str, s1, str1_lenght + 1);
	ft_strlcat(str, s2, str1_lenght + str2_lenght + 1);
	return (str);
}
