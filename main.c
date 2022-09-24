/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:29 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/25 00:50:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main(int argc, char **argv)
{
    int fd;
    char *line;
    (void)argc;
    fd = open(argv[1], O_RDONLY);
    line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("line is being printed\n %s", line);
    }    
    fd = close(fd);
    return (0);
}