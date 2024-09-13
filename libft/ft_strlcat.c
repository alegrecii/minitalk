/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:02:33 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/03 16:04:52 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_s;
	size_t	l_d;
	size_t	result;
	char	*s;

	if (!dst)
		return (0);
	s = (char *)src;
	l_d = ft_strlen(dst);
	l_s = ft_strlen(src);
	result = 0;
	i = 0;
	result = l_s + size;
	if (size > l_d)
		result = l_s + l_d;
	while (s[i] && (l_d + 1) < size)
	{
		dst[l_d] = s[i];
		l_d++;
		i++;
	}
	if (l_d < size)
		dst[l_d] = '\0';
	return (result);
}
