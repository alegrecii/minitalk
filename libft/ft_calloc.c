/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:50 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/05 11:12:28 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*newarr;
	size_t	x;

	x = nmemb * size;
	if (nmemb != 0 && x / nmemb != size)
		return (NULL);
	newarr = (void *)malloc(x);
	if (!newarr)
		return (NULL);
	ft_bzero(newarr, x);
	return (newarr);
}
