/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:21:33 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/17 18:07:46 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **buffer, char *tmp)
{
	free(*buffer);
	*buffer = tmp;
	return (NULL);
}

static char	*get_new_line(char **stash)
{
	char	*line;
	size_t	newline_index;
	char	*tmp;

	line = NULL;
	tmp = NULL;
	if (*stash && **stash)
	{
		if (ft_strchr(*stash, '\n'))
		{
			newline_index = ft_strchr(*stash, '\n') - *stash;
			line = ft_substr(*stash, 0, newline_index + 1);
			if (!line)
				return (NULL);
			tmp = ft_strdup(*stash + newline_index + 1);
			if (!tmp)
				return (ft_free(&line, NULL));
		}
		else
			line = ft_strdup(*stash);
	}
	ft_free(stash, tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*tmp;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (ft_free(&buffer, NULL), ft_free(&stash, NULL));
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		ft_free(&stash, tmp);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	ft_free(&buffer, NULL);
	return (get_new_line(&stash));
}
