/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:35 by naotegui          #+#    #+#             */
/*   Updated: 2024/03/12 11:44:22 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *e, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *) e)[count] = 0;
		count++;
	}
}

char	*reading_line(int fd, char *buf)
{
	char	*line;
	int		readcounter;

	readcounter = 1;
	line = ft_strdup(buf);
	while (!(ft_strchar(line, '\n')) && readcounter != 0)
	{
		readcounter = read(fd, buf, BUFFER_SIZE);
		if (readcounter == -1)
		{
			free(line);
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (NULL);
		}
		buf[readcounter] = '\0';
		line = ft_strjoin(line, buf, readcounter);
	}
	return (line);
}

void	moving_pointer(char *buf, char *line, char *newline)
{
	int	copy;

	if (newline != NULL)
	{
		copy = newline - line +1;
		ft_strlcopy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		copy = ft_strlen(line);
		ft_strlcopy(buf, "", BUFFER_SIZE + 1);
	}
	line[copy] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	line = reading_line(fd, buf);
	if (!line || ft_strlen(line) == 0)
	{
		return (free(line), NULL);
	}
	newline = ft_strchar(line, '\n');
	moving_pointer(buf, line, newline);
	return (line);
}
/*int main(void)
{
	int fd = open("song.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening the archive");
		return (1);
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/