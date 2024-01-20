/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:35:00 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/20 20:23:15 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*((char *)(s + n)) = 0;
	}
}
void	*ft_calloc(size_t count, size_t size,	char	*re)
{
	re = malloc (count * size);
	if (!re)
		return (NULL);
	ft_bzero(re, size * count);
	return (re);
}
char	*ft_strdup(const char *s1)
{
	int		x;
	char *re;
	x = 0;
	re = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!re)
		return (NULL);
	while (s1[x])
	{
		re[x] = s1[x];
		x++;
	}
	re[x] = '\0';
	return (re);
}
char	*ft_strjoin(char const *s1, char const *s2,	char *re)
{

	int		xx;
	int		x;
	

	x = 0;
	xx = 0;
	
	re = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char),re);
	if (!re)
		return (NULL);
	while (s1[x])
	{
		re[xx] = s1[x];
		x++;
		xx++;
	}
	x = 0;
	while (s2[x])
	{
		re[xx] = s2[x];
		xx++;
		x++;
	}
	return (re);
}