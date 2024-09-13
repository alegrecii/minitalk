/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:48:18 by alegreci          #+#    #+#             */
/*   Updated: 2022/12/07 16:49:47 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check(int pid, int cpid)
{
	char	*sp;
	char	*cp;

	cp = ft_itoa(cpid);
	sp = ft_itoa(pid);
	if (strlen(cp) == ft_strlen(sp))
		write(1, "\nMessaggio ricevuto :)\n", 23);
	free(sp);
	free(cp);
}

void	sender(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 8;
		while (i--)
		{
			if (str[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	cpid;

	if (argc != 3)
		return (0);
	cpid = getpid();
	pid = ft_atoi(argv[1]);
	sender(pid, argv[2]);
	check(pid, cpid);
}
