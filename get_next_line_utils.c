/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:08 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/24 13:39:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//A function that reads the \n character inside the string 
char *ft_strchr(char *main_str, int c)
{
    unsigned char ch;
    ch = c;
    while(*main_str && (unsigned char)*main_str != ch)
        main_str++;
    if(ch == (unsigned char)*main_str)
        return ((char *)main_str);
    else 
        return (NULL);
}

//A function to join all the data to the tmp variable
char *ft_strjoin(char *s1, char *s2)
{
    char *result; 
    size_t i;
    size_t j; 
    
    if(!s1 || !s2)
        return (NULL);
    result = malloc(sizeof(char)*(ft_strlen(s1) + ft_strlen(s2) + 1));
    if(!result)
        return (NULL);
    i = 0;
    j = 0;
    while(s1[j] != '\0')
        result[i++] = s1[j++];
    j = 0;
    while(s2[j] != '\0')
        result[i++] = s1[j++];
    result[i++] = '\0';
    return (result);
}


//A function to read the length inside the strings
size_t ft_strlen(char *str)
{
    size_t length;
    
    length = 0;
    while(str[length]!= '\0')
        str++;
    return (length);
}