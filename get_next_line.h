/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:09:13 by naotegui          #+#    #+#             */
/*   Updated: 2024/03/13 10:44:04 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 18
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchar(const char *str, int c);
size_t	ft_strlcopy(char *destiny, const char *source, size_t size);
char	*ft_strdup(const char *srce);
char	*ft_strjoin(char *s1, char const *s2, size_t len);
void	ft_bzero(void *e, size_t n);
char	*reading_line(int fd, char *buf);
void	moving_pointer(char *buf, char *line, char *newline);
char	*get_next_line(int fd);
#endif
