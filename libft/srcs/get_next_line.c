/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 10:46:55 by dnelson           #+#    #+#             */
/*   Updated: 2017/03/07 12:46:50 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

static int	realloc_str(char **copy, size_t size)
{
	char		*temp;
	size_t		old_size;

	old_size = ft_strlen(*copy);
	if (!(temp = ft_strnew(size)))
		return (-1);
	ft_memcpy(temp, *copy, old_size);
	free(*copy);
	*copy = ft_strdup(temp);
	free(temp);
	return (0);
}

static int	ft_strsub_newline(char **copy, char **line)
{
	char		*temp;
	size_t		line_len;
	size_t		read_len;

	if (*copy == NULL)
		*copy = ft_strnew(BUFF_SIZE);
	if (ft_strchr(*copy, '\n') == NULL)
		return (1);
	line_len = ((ft_strchr(*copy, '\n')) - *copy);
	read_len = ft_strlen(*copy);
	temp = ft_strsub(*copy, (line_len + 1), read_len);
	*line = ft_strsub(*copy, 0, line_len);
	free(*copy);
	*copy = ft_strdup(temp);
	free(temp);
	return (0);
}

static int	eof_exit(char **copy, char **buffer, char **line)
{
	if (ft_strlen(*copy))
	{
		if (!(*line = ft_strdup(*copy)))
			return (-1);
		ft_strdel(copy);
		ft_strdel(buffer);
		return (1);
	}
	return (0);
}

static int	process_read(char **copy, char **buffer)
{
	size_t		line_len;
	size_t		buff_len;
	char		*temp;

	line_len = ft_strlen(*copy);
	buff_len = ft_strlen(*buffer);
	if (!*copy || (realloc_str(copy, (line_len + buff_len + 1))) ||
			!(temp = ft_strjoin(*copy, *buffer)))
		return (-1);
	free(*copy);
	*copy = ft_strdup(temp);
	free(temp);
	ft_strdel(buffer);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		*buffer;
	static char	*fd_x[MAX_FD];
	int			ret;

	if (fd < 0 || fd > 1024 || !line || BUFF_SIZE < 1)
		return (-1);
	if ((ft_strsub_newline(&fd_x[fd], &(*line))) == 0)
		return (1);
	while ((ft_strchr(fd_x[fd], '\n')) == NULL)
	{
		buffer = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
			if (process_read(&fd_x[fd], &buffer) == -1)
				return (-1);
		if (ret == 0)
			return (eof_exit(&fd_x[fd], &buffer, &(*line)));
		if (ret == -1)
			return (-1);
	}
	ft_strsub_newline(&fd_x[fd], &(*line));
	return (1);
}
