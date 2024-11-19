/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:46:12 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/25 21:38:02 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;

	if (ac != 2)
		ft_error(1);
	if (check_mapname(av[1], ".ber") == 1)
		ft_error(3);
	game = (t_game *)malloc(sizeof(t_game));
	fd = open(av[1], O_RDONLY);
	game->map = map_maker(fd);
	close (fd);
	check(game);
	game->move_cnt = 0;
	mlx_start(game);
	return (0);
}

int	check_mapname(char	*map_name, char *ber)
{
	int	i;
	int	map_len;

	i = 0;
	map_len = 0;
	while (map_name[map_len])
		map_len++;
	i = ft_strncmp(map_name + (map_len - 4), ber, 4);
	if (i != 0)
		return (1);
	return (0);
}

char	**map_maker(int fd)
{
	char	*line;
	char	*backup;
	char	*gnl;
	char	**map;

	backup = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		gnl = backup;
		backup = ft_strjoin(gnl, line);
		free (gnl);
		free (line);
	}
	map = ft_split(backup, '\n');
	free (line);
	free (backup);
	return (map);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
