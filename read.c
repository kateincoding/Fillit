/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 09:33:03 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/24 09:33:06 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_2d_block(char *str, char block[4][4])
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			block[i][j] = str[k];
			j++;
			k++;
		}
		i++;
		k++;
	}
	return (1);
}

t_etris	*add_points(char *str, int id)
{
	t_etris		*piece;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(piece = (t_etris*)malloc(sizeof(t_etris))))
		return (NULL);
	piece->id = id;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			piece->points[j].x = i % 5;
			piece->points[j].y = i / 5;
			j++;
		}
		i++;
	}
	ft_bzero(str, 20);
	return (piece);
}

int		reader(char *file, t_etris **pieces)
{
	int			fd;
	int			bytes_read;
	int			final_reading;
	int			i;
	char		temp[21];

	fd = open(file, O_RDONLY);
	i = 0;
	while ((bytes_read = read(fd, temp, 21)) > 0)
	{
		final_reading = bytes_read;
		if (bytes_read < 20)
			return (0);
		if (!(verify_block(temp)))
			return (0);
		if (!(verify_piece(temp)))
			return (0);
		pieces[i] = add_points(temp, i + 1);
		i++;
	}
	if (final_reading != 20)
		return (0);
	pieces[i] = NULL;
	return (1);
}
