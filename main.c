/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:46:30 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/29 15:41:18 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    fd = open("test.txt" ,O_RDONLY);
    line = get_next_line(fd);
    while(line != NULL)
    {
        printf("%s", line);

        free(line);
        line = get_next_line(fd);
           
    }
    return (0);
}