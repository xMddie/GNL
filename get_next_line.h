/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:39:13 by mnau              #+#    #+#             */
/*   Updated: 2022/11/29 15:06:10 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int searchedc);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_useless(char *s1, char *s2);
char	*ft_free_and_join(char *s1, char *s2);

#endif