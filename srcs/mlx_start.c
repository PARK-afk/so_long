/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:33:23 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/25 21:37:08 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	mlx_start(t_game *game)
{
	int		*i;

	if (game->map == NULL)
		return ;
	i = size_of_window(game->map);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, i[1] * 32, \
			i[0] * 32, "so_long");
	game->mlx_img = mlx_map_init(game->mlx_ptr);
	mlx_put_map(game, game->mlx_ptr, game->mlx_win);
	mlx_hook(game->mlx_win, 2, 0, &press_key, game);
	mlx_hook(game->mlx_win, 17, 0, &exit_game2, game);
	mlx_loop(game->mlx_ptr);
	return ;
}

void	**mlx_map_init(void *mlx)
{
	void	**images;
	int		img_width;
	int		img_height;

	images = malloc(sizeof(void *) * 6);
	images[0] = mlx_xpm_file_to_image(mlx, "./images/water.xpm", \
			&img_width, &img_height);
	images[1] = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", \
			&img_width, &img_height);
	images[2] = mlx_xpm_file_to_image(mlx, "./images/banana.xpm", \
			&img_width, &img_height);
	images[3] = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", \
			&img_width, &img_height);
	images[4] = mlx_xpm_file_to_image(mlx, "./images/openexit.xpm", \
			&img_width, &img_height);
	images[5] = mlx_xpm_file_to_image(mlx, "./images/monkey.xpm", \
			&img_width, &img_height);
	return (images);
}

void	mlx_put_map(t_game *game, void *mlx, void *win)
{
	int	i;
	int	i2;
	int	a;

	i = 0;
	while (game->map[i])
	{
		i2 = 0;
		while (game->map[i][i2])
		{
			mlx_put_image_to_window(mlx, win, game->mlx_img[0], \
					i2 * 32, i * 32);
			if (game->map[i][i2] != '0')
			{
				a = img_check(game->map[i][i2], game->clt);
				mlx_put_image_to_window(mlx, win, \
						game->mlx_img[a], i2 * 32, i * 32);
			}
			i2++;
		}
		i++;
	}
}

int	*size_of_window(char **map)
{
	int	*i;

	i = malloc(sizeof(int) * 2);
	i[0] = 0;
	while (map[i[0]])
		i[0]++;
	i[1] = 0;
	while (map[0][i[1]])
		i[1]++;
	return (i);
}

int	img_check(char c, int clt)
{
	int		i;

	i = 7;
	if (c == '1')
		i = 1;
	else if (c == 'C')
		i = 2;
	else if (c == 'E' && clt != 0)
		i = 3;
	else if (c == 'E' && clt == 0)
		i = 4;
	else if (c == 'P')
		i = 5;
	if (i == 7)
		ft_error(3);
	return (i);
}
