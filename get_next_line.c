/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:55 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/20 20:31:42 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re;
	int		x;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	re = malloc((len + 1));
	if (!re)
		return (NULL);
	x = 0;
	while (len)
	{
		re[x++] = s[start++];
		len--;
	}
	re[x] = '\0';
	return (re);
}
int check_n(char *str)
{
    int x =0;
    while (str[x])
    {
        if(str[x]=='\n')
            return x+1;
        x++;
    }
    return x;
    
}


char *get_txt(int fd ,char *str)////////
{
    char buff[BUFFER_SIZE+1];
    int x=1;

    str =ft_strdup("");
    if(*str == '\0')
    {
        while (x > 0 )
        {
            x = read(fd,buff,BUFFER_SIZE);
            buff[x]='\0';
            str = ft_strjoin(str,buff);
        }
    }
    return str;
}
char *get_next_line(int fd)
{
    static char *str =NULL;
    char *re;

    
    if(!str)
    {
        //printf("1");
        str = get_txt(fd, str);
       
    }
   // printf("1");
   //printf("|%s|",str);
    if(*str == '\0')
        return NULL;
    re =ft_substr(str,0,check_n(str));
    str+=check_n(str);
        //
    return re;
}
// int main() {
//     int fb;
//     int br;
//     char buffer[11];

//     // Open the file for reading
//     fb = open("t.txt", O_RDONLY);


//     printf("%s",get_next_line(fb));
   
//   printf("%s",get_next_line(fb));
// //  printf("%s",get_next_line(fb));
//    // printf("%s",get_next_line(fb));
// //  printf("%s",get_next_line(fb));
// //    printf("%s",get_next_line(fb));
// //  printf("%s",get_next_line(fb));
// //system("leaks a.out");
// }