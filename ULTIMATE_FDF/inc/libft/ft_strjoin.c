/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:40:07 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/10 12:44:59 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		sizeofnew;

	if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	if (s2 && s1 == NULL)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	sizeofnew = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	new = malloc(sizeof(char) * sizeofnew + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (new);
}
