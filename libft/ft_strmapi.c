/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:57:43 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/06 15:38:47 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*final;
	unsigned int	i;

	str = (char *) s;
	i = 0;
	final = (char *) malloc(sizeof(*final) * ft_strlen(s) + 1);
	while (str[i] != '\0')
	{
		final[i] = (*f)(i, str[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
