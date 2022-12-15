/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:39:11 by mnau              #+#    #+#             */
/*   Updated: 2022/11/29 19:54:47 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{	
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_nextline(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (0);
	i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free (str);
	return (line);
}

static char	*ft_read(int fd, char *str)
{
	int		count;
	char	*s;

	count = 1;
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (0);
	while (count != 0)
	{
		if (ft_strchr(str, '\n'))
			break ;
		count = read(fd, s, BUFFER_SIZE);
		if (count == -1)
		{
			free (s);
			free (str);
			return (0);
		}
		s[count] = '\0';
		str = ft_free_and_join(str, s);
	}
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stock[1025];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stock[fd])
			free (stock[fd]);
		stock[fd] = NULL;
		return (0);
	}
	stock[fd] = ft_read(fd, stock[fd]);
	if (!stock[fd])
		return (0);
	line = ft_line(stock[fd]);
	stock[fd] = ft_nextline(stock[fd]);
	return (line);
}
