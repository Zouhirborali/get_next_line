/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:55 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/22 15:24:16 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str)
{
	int		i;
	int		x;
	char	*line;

	x = 0;
	if (!str[0])
		return (NULL);
	i = get_n(str);
	line = malloc(1 + i);
	if (!line)
		return (NULL);
	while (i > x)
	{
		line[x] = str[x];
		x++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char	*str)
{
	char	*new_str;
	int		i;
	int		j;

	i = get_n(str);
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(1 + ft_strlen(str) - i);
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		new_str[j] = str[i + j];
		j++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			x;
	static char	*str;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	x = 1;
	buff = malloc(1 + BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (!(chek_n(str)) && x > 0)
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x < 0)
			return (free(buff), NULL);
		buff[x] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (buff = read_line(str),
		str = next_line(str), buff);
}

// int main() {
//     int fb;
//     int br;
//     char buffer[11];
//     // Open the file for reading
//     fb = open("t.txt", O_RDONLY);
//     printf("%s",get_next_line(fb));
//    //printf("01234567890123456789012345678901234567890");
//  //printf("%s",get_next_line(fb));
//  // printf("%s",get_next_line(fb));
//  //   printf("%s",get_next_line(fb));
// //  printf("%s",get_next_line(fb));
// //    printf("%s",get_next_line(fb));
// //  printf("%s",get_next_line(fb));
// //system("leaks a.out");
// }