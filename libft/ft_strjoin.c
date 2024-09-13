/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:43:20 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/05 17:31:28 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	s = (char *) malloc(sizeof(*s1) * (total +1));
	if (!s)
		return (NULL);
	while (s1[j] != '\0')
	{
		s[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}
