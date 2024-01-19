/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:55 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/19 20:09:07 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int check_n(char *str)
{
    int x =0;
    while (*(str+x))
    {
        if(*(str+x)=='\n')
            return 1;
            x++;
    }
    return 0;
    
}
int check_n2(char *str)
{
    int x =0;
    while (*(str+x))
    {
        if(*(str+x)=='\n')
            return 0;
            x++;
    }
    return 1;
}

char * tt(char * str)
{
    int x =0;
    char *t;
    char *re =NULL;
    while (*(str + x)!='\n'&&!str[x])
        x++;
    if(*(str + x)=='\0')
        return str;
    t =ft_calloc(x+1,1);
    x =0;
    while(*(str + x)!='\n'&&*(str + x)!='\0')
    {
        *(t + x) = *(str + x);
        x++;
    }
    t[x++]='\n';
    t[x]='\0';
    re =t;
  
    return t;
}
char * get_new_l(char *str)
{
    //printf("|%s|\n",str);
    int x =0;
    int x2 =0;
    char *t =NULL;
    char *re =NULL;
    while (*(str + x)!='\n'&&*(str + x)!='\0')
        x++;
    x2 =x+1;
    while (*(str + x2))
        x2++;
    t = ft_calloc(x2 -x,1);
    x2 =x+1;
    x =0;
    while (*(str + x2))
    {
        *(t + x) = *(str + x2);
        x2++;
        x++;
    }
    t[x]='\0';
    re= t;
 
    return t;
}
char *get_next_line(int fd)
{
    //BUFFER_SIZE
    int x =1;
    static char *str =NULL;
    char *re;
    char *str2 = NULL;
    if(!str)
        str = ft_strdup("");
    else
    {
         str =get_new_l(str);
    }
   
    str2 = ft_calloc(BUFFER_SIZE,1);

    while (x > 0 && !check_n(str2))
    {
         
        x = read(fd,str2,BUFFER_SIZE);
        if(x <= 0 && !str[0])
            return NULL;
         str2[x]='\0';
        str = ft_strjoin(str,str2);
    }
    
   
    re = tt(str);

    return re;
 }
int main() {
    int fb;
    int br;
    char buffer[11];

    // Open the file for reading
    fb = open("t.txt", O_RDONLY);


    printf("%s",get_next_line(fb));
   
  printf("%s",get_next_line(fb));
//  printf("%s",get_next_line(fb));
//    printf("%s",get_next_line(fb));
//  printf("%s",get_next_line(fb));
//    printf("%s",get_next_line(fb));
//  printf("%s",get_next_line(fb));
}