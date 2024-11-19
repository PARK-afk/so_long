/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:44:03 by junsepar          #+#    #+#             */
/*   Updated: 2023/06/14 23:50:15 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	allfree(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (new_map[j])
		j++;
	while (i < j)
	{
		free(new_map[i]);
		i++;
	}
	free(new_map);
}

void	ft_error(int i)
{
	write(2, "ERROR\n", 6);
	if (i == 2)
		write(2, "File Read Fail\n", 15);
	else if (i == 3)
		write(2, "Map Error\n", 10);
	exit(1);
}

void	*clear(char **result, char **ptr)
{
	while (result <= ptr)
	{
		free(*ptr);
		ptr--;
	}
	free(result);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	ft_bzero(tmp, size * count);
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	if (n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
