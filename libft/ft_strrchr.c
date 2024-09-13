/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:48:37 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/04 16:54:38 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	if (c == 0)
		return (str + i);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
