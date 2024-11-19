/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:40:54 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/10 14:56:47 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	sr;

	sr = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == sr)
			break ;
		i++;
	}
	if (s[i] == '\0' && sr != '\0')
		return (0);
	return ((char *)s + i);
}

char	*ft_strjoin(char const *s1, char const*s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat((str + s1_len), s2, s2_len + 1);
	return (str);
}

int	ft_strlcpy(char *dest, const char *src, int dstsize)
{
	int	idx;
	int	len;

	idx = 0;
	len = 0;
	while (src[len])
		len++;
	while (src[idx] && idx + 1 < dstsize)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (dstsize)
		dest[idx] = '\0';
	return (len);
}

int	ft_strlcat(char *dst, \
		const char *src, int dstsize)
{
	int	len;
	int	i;
	int	j;

	if ((int)ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}
