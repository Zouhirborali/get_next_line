/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:35:00 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/21 12:24:33 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*re;
	int		xx;
	int		x;

	x = 0;
	xx = 0;
	if (!start)
	{
		start = malloc(1);
		start[0] = '\0';
	}
	if (!start || !buff)
		return (0);
	re = malloc(ft_strlen(start) + ft_strlen(buff) + 1);
	if (!re)
		return (NULL);
	while (start[x])
		re[xx++] = start[x++];
	x = 0;
	while (buff[x])
		re[xx++] = buff[x++];
	re[xx] = '\0';
	free(start);
	return (re);
}
