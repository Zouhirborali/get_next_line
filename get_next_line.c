/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:55 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/21 17:17:57 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chek_n(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
int get_n(char *str)
{
	int i =0;
	if (!str[0])
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
char	*ft_readed_line(char *start)
{
	int		i;
	int x;
	char	*line;

	x = 0;
	if (!start[0])
		return (NULL);
	i = get_n(start);
	line = malloc(1 + i );
	if (!line)
		return (NULL);
	while (i>x)
	{
		line[x] = start[x];
		x++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_move_start(char	*start)
{
	char	*new_str;
	int		i;
	int		j;

	i = get_n(start);
	if (i == 0)
	{
		free(start);
		return (NULL);
	}
	new_str = malloc(1 + ft_strlen(start) - i);
	if (!new_str)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_str[j] = start[i + j];
		j++;
	}
	new_str[j] = '\0';
	free(start);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			x;
	static char	*start_str;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
    {
        free(start_str);
		start_str = NULL;
		return (NULL);
    }
	x = 1;
	buff = malloc(1 + BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (!(chek_n(start_str)) && x > 0)
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[x] = '\0';
		//printf("5");
		start_str = ft_strjoin(start_str, buff);
	}
	free(buff);
	//printf("|%s|",start_str);
	buff = ft_readed_line(start_str);
	start_str = ft_move_start(start_str);
	return (buff);
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