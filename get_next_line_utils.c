/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopereir <nopereir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:38:27 by nopereir          #+#    #+#             */
/*   Updated: 2022/08/02 17:31:54 by nopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*dup;
	size_t	i;
	int		aux_len;

	aux_len = ft_strlen(s) - start;
	i = 0;
	if (start > ft_strlen(s))
		aux_len = 0;
	else if (len < (size_t)aux_len)
		aux_len = len;
	dup = (char *)malloc(sizeof(char) * aux_len + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < (size_t)aux_len)
	{
		*(char *)(dup + i) = *(char *)(s + start);
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}
