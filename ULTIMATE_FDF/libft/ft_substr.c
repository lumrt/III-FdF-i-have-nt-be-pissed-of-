/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:08:53 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/19 16:46:26 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*mem;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s + start);
	mem = ft_calloc(len + 1, sizeof(char));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s + start, len);
	mem[len] = '\0';
	return (mem);
}
