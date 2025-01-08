/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryner <ryner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:29:53 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/13 18:04:06 by ryner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_keep(int fd, char *buffer, ssize_t *bytes_read)
{
	char	*buf;
	char	*temp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*bytes_read = 1;
	while (*bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		*bytes_read = read(fd, buf, BUFFER_SIZE);
		if (*bytes_read < 0)
			return (free(buf), free(buffer), NULL);
		buf[*bytes_read] = '\0';
		temp = ft_strjoin(buffer, buf);
		if (!temp)
			return (free(buf), free(buffer), NULL);
		free(buffer);
		buffer = temp;
	}
	free(buf);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*pos_nl;
	char	*line;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	pos_nl = ft_strchr(buffer, '\n');
	if (pos_nl)
	{
		len = (pos_nl + 1) - buffer;
		line = ft_substr(buffer, 0, len);
	}
	else
	{
		line = ft_strdup(buffer);
	}
	if (!line)
		return (NULL);
	return (line);
}

static char	*update_static(char *buffer)
{
	char	*nl_pos;
	char	*buffer_static;
	size_t	len;

	if (!buffer || !*buffer)
	{
		free(buffer);
		return (NULL);
	}
	nl_pos = ft_strchr(buffer, '\n');
	if (nl_pos)
	{
		len = ft_strlen(nl_pos + 1);
		buffer_static = ft_substr(nl_pos + 1, 0, len);
	}
	else
	{
		buffer_static = NULL;
	}
	free(buffer);
	return (buffer_static);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_keep(fd, buffer, &bytes_read);
	if (!buffer || (bytes_read == 0 && !*buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line(buffer);
	buffer = update_static(buffer);
	return (line);
}
/* #include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texto", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
