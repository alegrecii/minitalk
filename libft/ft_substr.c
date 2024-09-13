/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:30:19 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/05 17:16:05 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	b;
	char	*substr;

	i = start;
	b = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) - start < len)
	{
		len = ft_strlen(s) - start;
	}
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (b < len && s[i])
	{
		substr[b] = s[i];
		i++;
		b++;
	}
	substr[b] = '\0';
	return (substr);
}
