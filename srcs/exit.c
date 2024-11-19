/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:45:36 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/28 18:56:33 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	exit_game(t_game *game, int i)
{
	if (i == 1)
		write(1, "Game Over\n", 10);
	if (i == 2)
		write(1, "Game Clear\n", 11);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(1);
}

int	exit_game2(t_game *game)
{
	write(1, "Game EXIT\n", 10);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(1);
}
