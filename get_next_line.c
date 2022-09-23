/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:34:07 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/23 19:14:17 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*------------------------------------------------------------------

--------------------------------------------------------------------*/
char *get_line()
{
}



/*------------------------------------------------------------------
(1)Creating a readline function that reads the line from the file fd
(2)Then store the read line function from fd to the buffer variable 
(3)Read_bytes will run and read the lines untill the conditions are fullfilled. 
(4)Error handling if the read_bytes reads -1 somewhere and come out of the 
   loop.
(5)The buffer then keeps adding it to the str_store variable  
--------------------------------------------------------------------*/
char	*read_line_and_save(int fd, char *str_store)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str_store, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str_store = ft_strjoin(str_store, buffer);
	}
	free(buffer);
	return (str_store);
}

/*------------------------------------------------------------------

--------------------------------------------------------------------*/
char	*get_next_line(int fd)
{
}
