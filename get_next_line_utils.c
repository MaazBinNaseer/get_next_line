/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:19:55 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/09/27 18:46:22 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//A function to read the number of characters in the string
size_t	ft_strlen(char *string)
{
	size_t	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] != '\n')
		i++;
	return (i);
}

//A function to find the \n or \0
char	*ft_strchr(char *string, int search_char)
{
	int	i;

	i = 0;
	if (!string)
		return (NULL);
	if (i == '\0')
		return ((char *)&string[ft_strlen(string)]);
	while (string[i] != '\0')
	{
		if (string[i] == search_char)
			return ((char *)&string[i]);
		i++;
	}
	return (0);
}

// A function that joins everthing to the end of tmp_buffer variable
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*store_str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	store_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (store_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i++] != '\0')
			store_str[i] = s1[i];
	while (s2[j] != '\0')
		store_str[i++] = s2[j++];
	store_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(store_str);
	return (store_str);
}
