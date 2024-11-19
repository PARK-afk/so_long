/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:31:15 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/25 21:37:28 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game, 1);
	else if (key_code == KEY_W)
		move_w(game);
	else if (key_code == KEY_A)
		move_a(game);
	else if (key_code == KEY_S)
		move_s(game);
	else if (key_code == KEY_D)
		move_d(game);
	if (game->chr.p_y == game->exi.p_y && \
			game->chr.p_x == game->exi.p_x && game->clt == 0)
		exit_game(game, 2);
	mlx_put_map(game, game->mlx_ptr, game->mlx_win);
	return (0);
}

void	move_w(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.p_y;
	i2 = game->chr.p_x;
	if (game->map[i - 1][i2] == '1')
		return ;
	if (game->map[i - 1][i2] == 'C')
		game->clt--;
	if (i == game->exi.p_y && i2 == game->exi.p_x)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i - 1][i2] = 'P';
	game->chr.p_y--;
	game->move_cnt++;
	move_count_print(game->move_cnt);
}

void	move_a(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.p_y;
	i2 = game->chr.p_x;
	if (game->map[i][i2 - 1] == '1')
		return ;
	if (game->map[i][i2 - 1] == 'C')
		game->clt--;
	if (i == game->exi.p_y && i2 == game->exi.p_x)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i][i2 - 1] = 'P';
	game->chr.p_x--;
	game->move_cnt++;
	move_count_print(game->move_cnt);
}

void	move_s(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.p_y;
	i2 = game->chr.p_x;
	if (game->map[i + 1][i2] == '1')
		return ;
	if (game->map[i + 1][i2] == 'C')
		game->clt--;
	if (i == game->exi.p_y && i2 == game->exi.p_x)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i + 1][i2] = 'P';
	game->chr.p_y++;
	game->move_cnt++;
	move_count_print(game->move_cnt);
}

void	move_d(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.p_y;
	i2 = game->chr.p_x;
	if (game->map[i][i2 + 1] == '1')
		return ;
	if (game->map[i][i2 + 1] == 'C')
		game->clt -= 1;
	if (i == game->exi.p_y && i2 == game->exi.p_x)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i][i2 + 1] = 'P';
	game->chr.p_x++;
	game->move_cnt++;
	move_count_print(game->move_cnt);
}
