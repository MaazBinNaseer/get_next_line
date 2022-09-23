/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:33:35 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/23 19:14:24 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

//Definition of the buffer to store characters 
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *ft_strchr(char *main_str, int c);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(char *str);



#endif