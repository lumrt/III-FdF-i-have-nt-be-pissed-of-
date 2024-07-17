/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:17:47 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/12 15:19:48 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	ssize_t			bytes_read;
	static char		buf[BUFFER_SIZE];

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	if (hasendl(buf))
	{
		trim_buf(buf);
		line = complete_line(line, buf);
		if (!line)
			return (NULL);
	}
	while (!hasendl(buf))
	{
		line = read_and_complete(line, buf, fd, &bytes_read);
		if (!line)
			return (NULL);
		if ((bytes_read > 0 && bytes_read < BUFFER_SIZE) || !bytes_read)
			return (line);
	}
	return (line);
}

//ugly
