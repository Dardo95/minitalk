/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryner <ryner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:29:53 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/14 11:05:39 by ryner            ###   ########.fr       */
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

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[MAX_FD];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = read_keep(fd, buffer[fd], &bytes_read);
	if (!buffer[fd] || (bytes_read == 0 && !*buffer[fd]))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = get_line(buffer[fd]);
	buffer[fd] = update_static(buffer[fd]);
	return (line);
}

/* #include <stdio.h>
int main() {
	int fd1 = open("texto", O_RDONLY);
	int fd2 = open("text.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0) {
		perror("Error opening ");
		return (1);
	}
	char *line1 = get_next_line_bonus(fd1);
	char *line2 = get_next_line_bonus(fd2);
	while ((line1) != NULL || (line2) != NULL)
	{
		if (line1) {
			ft_printf("FD1: %s", line1);
			free(line1);
		}
		if (line2) {
			ft_printf("FD2: %s", line2);
			free(line2);
		}
		line1 = get_next_line_bonus(fd1);
		line2 = get_next_line_bonus(fd2);
	}

	close(fd1);
	close(fd2);
	return (0);
} */