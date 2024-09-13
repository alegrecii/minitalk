/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:35:44 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/05 18:27:45 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	words_counter(char const *s, char c)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*words_creator(char const *s, char c, int start)
{
	char	*newword;
	int		i;
	int		startcpy;

	i = 0;
	startcpy = start;
	while (s[start] != c && s[start] != '\0')
	{
		i++;
		start++;
	}
	newword = malloc (sizeof(char) * i + 1);
	i = 0;
	if (!newword)
		return (NULL);
	while (s[startcpy] != c && s[startcpy] != '\0')
	{
		newword[i] = s[startcpy];
		i++;
		startcpy++;
	}
	newword[i] = '\0';
	return (newword);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		i;
	int		b;
	int		flag;

	final = (char **)malloc(sizeof(char *) * (words_counter(s, c) + 1));
	if (!final)
		return (NULL);
	i = 0;
	b = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			final[b] = words_creator(s, c, i);
			b++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	final[b] = NULL;
	return (final);
}
