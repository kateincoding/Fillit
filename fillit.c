/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 09:35:07 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/24 09:35:10 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(t_etris **pieces, char **map, int mapsize, int i)
{
	t_point pos;

	if (pieces[i] == NULL)
		return (1);
	pos.x = 0;
	pos.y = 0;
	while (pos.y < mapsize)
	{
		while (pos.x < mapsize)
		{
			if ((fit_piece(pieces[i], map, pos, mapsize)))
			{
				place_tetr(pieces[i], map, pos.x, pos.y);
				if (fillit(pieces, map, mapsize, i + 1))
					return (1);
				else
					clear_piece(pieces[i], map, mapsize);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return (0);
}

void	error_handler(char **map, t_etris **pieces)
{
	mem_free(map, pieces);
	ft_putstr("error\n");
}

void	mem_free(char **map, t_etris **pieces)
{
	int x;

	if (map)
	{
		x = 0;
		while (map[x])
		{
			ft_strdel(&map[x]);
			x++;
		}
		free(map);
	}
	if (pieces)
	{
		x = 0;
		while (pieces[x])
		{
			free(pieces[x]);
			x++;
		}
		free(pieces);
	}
}

int		main(int argc, char **argv)
{
	t_etris	**pieces;
	char	**map;
	int		mapsize;

	if (argc == 2)
	{
		pieces = malloc(sizeof(t_etris) * 27);
		map = malloc(sizeof(char *) * 11);
		create_map(map, 10);
		mapsize = 2;
		if (reader(argv[1], pieces) > 0)
		{
			while (fillit(pieces, map, mapsize++, 0) == 0)
				clear_map(map, mapsize);
			print_map(map, mapsize - 1);
			mem_free(map, pieces);
		}
		else
			error_handler(map, pieces);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
