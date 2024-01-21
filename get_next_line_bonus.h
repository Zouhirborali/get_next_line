/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:08:29 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/21 14:49:24 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
#define GET_NEXT_LINE_BONUS


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *src);
char	*ft_move_start(char *start);
char	*ft_strjoin(char *start, char *buff);

#endif