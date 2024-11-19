/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:31:39 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/25 16:54:06 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	do_dfs(char **map, int y, int x)
{
	int		i;
	char	**new_map;

	new_map = dfs_mapinit(map);
	i = check_valid(new_map, y, x);
	allfree(new_map);
	if (i == 0)
		ft_error(3);
}

char	**dfs_mapinit(char **map)
{
	char	**smap;
	int		ai;
	int		ai2;
	int		i;
	int		i2;

	i = 0;
	i2 = (int)ft_strlen(map[0]);
	while (map[i])
		i++;
	smap = (char **)malloc(sizeof(char *) * (i + 1));
	ai = -1;
	while (++ai < i)
	{
		ai2 = -1;
		smap[ai] = malloc(sizeof(char) * (i2 + 1));
		while (++ai2 < i2)
			smap[ai][ai2] = map[ai][ai2];
		smap[ai][ai2] = '\0';
	}
	smap[ai] = 0;
	return (smap);
}

int	check_valid(char **map, int y, int x)
{
	int	i;

	i = 0;
	map[y][x] = '1';
	if (map[y - 1][x] == 'P')
		return (1);
	else if (map[y][x - 1] == 'P')
		return (1);
	else if (map[y + 1][x] == 'P')
		return (1);
	else if (map[y][x + 1] == 'P')
		return (1);
	if (map[y - 1][x] != '1' && i == 0)
		i = check_valid(map, y - 1, x);
	if (map[y][x - 1] != '1' && i == 0)
		i = check_valid(map, y, x - 1);
	if (map[y + 1][x] != '1' && i == 0)
		i = check_valid(map, y + 1, x);
	if (map[y][x + 1] != '1' && i == 0)
		i = check_valid(map, y, x + 1);
	if (i == 1)
		return (1);
	return (0);
}
