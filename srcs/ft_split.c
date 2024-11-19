/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:54:50 by junsepar          #+#    #+#             */
/*   Updated: 2023/07/10 14:48:52 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_l;
	char	*str;

	if (s == NULL )
		return (0);
	if (len <= 0 || (unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	s_l = ft_strlen(s + start);
	if (s_l < len)
		len = s_l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*word;

	if (!s || !*s)
		return (ft_calloc(sizeof(char *), 1));
	ptr = (char **)ft_calloc(sizeof(char *), word_count(s, c) + 1);
	if (!ptr)
		return (NULL);
	word = find_word(s, c);
	return (word_dup(ptr, word, s, c));
}

char	**word_dup(char **ptr, char *word, char const *s, char c)
{
	char	**result;

	result = ptr;
	while (*s)
	{
		if (*s == c && s > word)
		{
			*ptr = ft_substr(word, 0, s - word);
			if (!*ptr)
				return (clear(result, ptr));
			word = find_word(s, c);
			ptr++;
		}
		s++;
	}
	if (*word)
	{
		*ptr = ft_substr(word, 0, s - word);
		if (!*ptr)
			return (clear(result, ptr));
		ptr++;
	}
	*ptr = NULL;
	return (result);
}

char	*find_word(char const *s, char c)
{
	while (*s == c)
		s++;
	return ((char *)s);
}

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 1;
	while (*s)
	{
		if (*s != c && flag == 1)
		{
			flag = 0;
			i++;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	return (i);
}
