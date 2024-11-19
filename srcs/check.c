/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:31:54 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/25 21:29:38 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	check(t_game *game)
{
	check_map(game->map);
	game->chr = check_player(game->map);
	game->exi = check_exit(game->map);
	game->clt = check_collectible(game->map);
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	if (map[0] == NULL)
		ft_error(3);
	size = (int)ft_strlen(map[0]);
	while (map[++i])
	{
		if (i == 0 || map[i + 1] == 0)
		{
			j = -1;
			while (++j < size)
				if (map[i][j] != '1')
					ft_error(3);
		}
		else
			if (map[i][0] != '1' || map[i][size -1] != '1')
				ft_error(3);
		if (map[i][size] != '\0')
			ft_error(3);
	}
	if (100 < i || 50 < j)
		ft_error(3);
}

t_position	check_player(char **map)
{
	t_position	chr;
	int			y;
	int			x;
	int			current_p;

	current_p = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				chr.p_x = x;
				chr.p_y = y;
				current_p++;
			}
			x++;
		}
		y++;
	}
	if (current_p != 1)
		ft_error(3);
	return (chr);
}

t_position	check_exit(char **map)
{
	t_position	out;
	int			y;
	int			x;
	int			current_out;

	y = -1;
	current_out = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
			{
				do_dfs(map, y, x);
				out.p_x = x;
				out.p_y = y;
				current_out++;
			}
		}
	}
	if (current_out != 1)
		ft_error(3);
	return (out);
}

int	check_collectible(char **map)
{
	int	x;
	int	y;
	int	clt;

	clt = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				do_dfs(map, y, x);
				clt++;
			}
			x++;
		}
		y++;
	}
	if (clt == 0)
		ft_error(3);
	return (clt);
}
