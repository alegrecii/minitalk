/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:30:28 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/05 10:36:46 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (!big)
		return (NULL);
	if (little[b] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		b = 0;
		while (big[i + b] == little[b] && i + b < len)
		{
			b++;
			if (little[b] == '\0')
			{
				return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
