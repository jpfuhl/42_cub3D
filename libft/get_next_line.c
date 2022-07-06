/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:50:08 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/05 20:21:55 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_check_remainder(char **remainder, char **line);
static void	gnl_modify_remainder(char *nl, char **remainder);
static char	*gnl_read_text(int fd, char *line, char *nl, char **remainder);
static char	*gnl_exit_function(char **line, char **buf);

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;
	char		*nl;

	if (fd < 0 || 10240 < fd || BUFFER_SIZE <= 0)
		return (NULL);
	nl = gnl_check_remainder(&remainder, &line);
	line = gnl_read_text(fd, line, nl, &remainder);
	return (line);
}

static char	*gnl_check_remainder(char **remainder, char **line)
{
	char	*nl;

	nl = NULL;
	if (*remainder == NULL)
	{
		*line = malloc(1 * sizeof(char));
		if (*line == NULL)
			return (NULL);
		*line[0] = '\0';
	}
	else if (*remainder)
	{
		*line = gnl_strdup(*remainder);
		nl = gnl_strchr(*line, '\n');
		free(*remainder);
		gnl_modify_remainder(nl, remainder);
	}
	return (nl);
}

static void	gnl_modify_remainder(char *nl, char **remainder)
{
	if (nl)
	{
		if (*(nl + 1) != '\0')
			*remainder = gnl_strdup(nl + 1);
		else
			*remainder = NULL;
		*nl = '\0';
	}
	else
		*remainder = NULL;
}

static char	*gnl_read_text(int fd, char *line, char *nl, char **remainder)
{
	char	*buf;
	int		bytes_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	while (!nl && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && line[0] == '\0'))
			return (gnl_exit_function(&line, &buf));
		buf[bytes_read] = '\0';
		line = gnl_strjoin(line, buf);
		nl = gnl_strchr(line, '\n');
		gnl_modify_remainder(nl, remainder);
	}
	gnl_free_memory(&buf);
	return (line);
}

static char	*gnl_exit_function(char **line, char **buf)
{
	gnl_free_memory(line);
	gnl_free_memory(buf);
	return (NULL);
}
