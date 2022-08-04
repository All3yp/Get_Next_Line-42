/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopereir <nopereir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:02:42 by nopereir          #+#    #+#             */
/*   Updated: 2022/08/04 08:40:22 by nopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_call_read_until_linebreak(int fd, char *line);
static char	*ft_split_line(char *line);
static char	*ft_restline(char *res);
char		*get_next_line(int fd);

static char	*ft_call_read_until_linebreak(int fd, char *line)
{
	char	*buffer;
	int		read_buffer;

	read_buffer = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (read_buffer && (ft_strchr(line, '\n')) == NULL)
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_buffer] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*ft_restline(char *res)
{
	char	*tmp;
	int		idx;

	idx = 0;
	while (res[idx] != '\n' && res[idx])
		idx++;
	if (res[idx] == '\0')
	{
		free(res);
		return (NULL);
	}
	tmp = ft_substr(res, ++idx, ft_strlen(res));
	free(res);
	return (tmp);
}

static char	*ft_split_line(char *line)
{
	int	idx;

	idx = 0;
	if (line[idx] == '\0')
		return (NULL);
	while (line[idx] != '\n' && line[idx])
		idx++;
	return (ft_substr(line, 0, ++idx));
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*tmp;

	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_call_read_until_linebreak(fd, res);
	if (res == NULL)
		return (NULL);
	tmp = ft_split_line(res);
	res = ft_restline(res);
	return (tmp);
}
