/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:18:42 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/06/03 10:40:33 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	used[255];
	int i;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 0;
		while (argv[2][i])
			used[(unsigned char)argv[2][i++]] = 1;
		i = 0;
		while (argv[1][i])
		{
			if (used[(unsigned char)argv[1][i]] == 1)
			{
				used[(unsigned char)argv[1][i]] = 2;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
