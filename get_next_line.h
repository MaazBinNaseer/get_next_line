/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:33:35 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/25 00:46:37 by marvin           ###   ########.fr       */
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

// ----------HELPER FUNCTION------------------------
char *ft_strchr(char *main_str, int c);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(char *str);

//----------------MAIN FUNCTION-------------------- 
char *read_line_of_file(int fd, char *str_store);
char *get_line(char *buffer);
char *find_next_line_and_free(char *buffer);
char	*get_next_line(int fd);

#endif