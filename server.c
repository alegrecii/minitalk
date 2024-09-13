/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:50:09 by alegreci          #+#    #+#             */
/*   Updated: 2022/12/07 16:52:56 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	static int	i = 8;
	static char	c = 0;

	if (i--)
	{
		if (sig == SIGUSR1)
			c |= 1 << i;
	}
	if (i <= 0)
	{
		write(1, &c, 1);
		i = 8;
		c = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*str;

	pid = getpid();
	str = ft_itoa(pid);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free (str);
	while (1)
	{
		if (signal(SIGUSR1, ft_handler) == SIG_ERR)
			write(1, "fail\n", 5);
		if (signal(SIGUSR2, ft_handler) == SIG_ERR)
			write(1, "fail\n", 5);
	}
	return (0);
}
