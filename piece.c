/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 09:32:48 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/24 09:32:51 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fit_piece(t_etris *piece, char **map, t_point pos, int mapsize)
{
	int	i;
	int	dx;
	int	dy;

	i = -1;
	dx = pos.x;
	dy = pos.y;
	if (map[dy][dx] == '.')
	{
		while (++i <= 3)
		{
			if (i > 0)
			{
				dy += piece->points[i].y - piece->points[i - 1].y;
				dx += piece->points[i].x - piece->points[i - 1].x;
				if (dx >= mapsize || dy >= mapsize || (dx < 0 || dy < 0))
					return (0);
			}
			if (map[dy][dx] != '.')
				return (0);
		}
		return (1);
	}
	return (0);
}

void	place_tetr(t_etris *piece, char **map, int x, int y)
{
	int	i;
	int	dx;
	int	dy;

	i = 0;
	dx = x;
	dy = y;
	while (i <= 3)
	{
		if (i > 0)
		{
			dy += piece->points[i].y - piece->points[i - 1].y;
			dx += piece->points[i].x - piece->points[i - 1].x;
		}
		map[dy][dx] = piece->id + '0' + 16;
		i++;
	}
}

void	clear_piece(t_etris *piece, char **map, int size)
{
	int		x;
	int		y;
	char	letter;

	x = 0;
	y = 0;
	letter = piece->id + '0' + 16;
	while (y < size)
	{
		while (x < size)
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}
