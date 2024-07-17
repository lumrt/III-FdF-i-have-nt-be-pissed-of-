/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:17:53 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/17 12:32:04 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		hasendl(char *s);
void	trim_buf(char *buf);
char	*complete_line(char *s, char *buf);
char	*read_and_complete(char *line, char *buf, int fd, ssize_t *bytes_read);

char	*get_next_line(int fd);

#endif
