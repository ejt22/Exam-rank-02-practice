/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:03:07 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/06/07 11:14:11 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	used[255];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && used[(unsigned char)argv[i][j]] == 0)
				   used[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && used[(unsigned char)argv[i][j]] ==1)
				{
					used[(unsigned char)[i][j]] == 2;
					write(1, &argv[i][j], 1);
				}	
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0)
}
