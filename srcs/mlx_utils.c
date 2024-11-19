/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:18:18 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/10 16:21:06 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	move_count_print(int i)
{
	write(1, "Move count : ", 13);
	move_count(i);
	write(1, "\n", 1);
}

void	move_count(int i)
{
	char	a;

	if (i > 9)
	{
		move_count(i / 10);
		a = (i % 10) + '0';
		write(1, &a, 1);
	}
	else
	{
		a = i + '0';
		write(1, &a, 1);
	}
}
