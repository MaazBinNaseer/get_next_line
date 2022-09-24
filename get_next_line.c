/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:34:07 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/25 00:53:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*------------------------READ FILE FUNCTION----------------------------
• Creating a readline function that reads the line from the file fd
• Then store the read line function from fd to the buffer variable 
• Read_bytes will run and read the lines untill the conditions are fullfilled. 
• Error handling if the read_bytes reads -1 somewhere and come out of the 
   loop.
• The buffer then keeps adding it to the str_store variable  
--------------------------------------------------------------------*/
 char	*read_line_of_file(int fd, char *str_store)
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

/*---------GET THE LINE FROM THE FD AND EXTRACT FUNCTION------------
• Creating a fucntion that gets the line
• Buffer is reading untill the end of the line 
• The buffer is storing whatever is read intially to temp(line)
• If the EOF or EOL is found then replace EOL by \n
--------------------------------------------------------------------*/
char *get_line(char *buffer)
{
	int i; 
	char *line; 
	
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	
	line = (char *)malloc(sizeof(char)*(i + 2)); 
	if(!line)
		return (NULL);
	i = 0; 
	while(buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if(buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/*-----FREEING THE BUFFER VARIABLE AND MOVING TO NEXT LINE------------
• Find the length of the line 
• Free the buffer line once everything has been shifted or not found
• The buffer gets free and then shifts to other lines 
--------------------------------------------------------------------*/
char *find_next_line_and_free(char *buffer)
{
	int i;
	int k;
	char *line;

	i = 0; 
	while(buffer[i] && buffer[i] != '\n')
		i++;
	if(!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	i++;
	if(!line)
		return (NULL);
	k = 0;
	while(buffer[i])
	{
		line[k] = buffer[i];
		k++;
		i++;
	}
	free (buffer);
	return (line);
}

/*--------------------GET NEXT LINE FUNCTION--------------------------
• The main function which calls the other function to read the line
• Error handling if anything goes wrong 
• Call the read function to read from the file 
• Call the get line function to store the line from fd
• Call the static function to store the line 
--------------------------------------------------------------------*/
char	*get_next_line(int fd)
{
	static char *buffer; 
	char *line;

	buffer = read_line_of_file(fd ,buffer);
	line = get_line(buffer);
	buffer = find_next_line_and_free(buffer);	
	return (line);
}
