/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:32:48 by junsepar          #+#    #+#             */
/*   Updated: 2023/06/15 01:12:47 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	get_x_size(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

int	get_y_size(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}
