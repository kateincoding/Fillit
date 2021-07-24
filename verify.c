/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 09:33:25 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/24 09:33:28 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_adj(char block[4][4], int i, int j)
{
	int adj;

	adj = 0;
	if (i + 1 < 4 && block[i + 1][j] == '#')
		adj++;
	if (i - 1 >= 0 && block[i - 1][j] == '#')
		adj++;
	if (j + 1 < 4 && block[i][j + 1] == '#')
		adj++;
	if (j - 1 >= 0 && block[i][j - 1] == '#')
		adj++;
	return (adj);
}

int	check_connections(char block[4][4])
{
	int	i;
	int	j;
	int	adj_and_hash[2];

	adj_and_hash[0] = 0;
	adj_and_hash[1] = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (block[i][j] == '#')
			{
				adj_and_hash[0] += count_adj(block, i, j);
				adj_and_hash[1]++;
			}
			j++;
		}
		i++;
	}
	i++;
	if (adj_and_hash[1] == 4 && adj_and_hash[0] >= 6)
		return (1);
	return (0);
}

int	verify_block(char block[21])
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (block[i] != '.' && block[i] != '#' && block[i] != '\n')
			return (0);
		if ((i + 1) % 5 == 0)
			if (block[i] != '\n')
				return (0);
		i++;
	}
	i++;
	if (block[i] != '\n' && block[i] != '\0')
		return (0);
	return (1);
}

int	verify_piece(char block[21])
{
	char	block2d[4][4];

	get_2d_block(block, block2d);
	if (!(check_connections(block2d)))
		return (0);
	return (1);
}
