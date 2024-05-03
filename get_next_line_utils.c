/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:55 by naotegui          #+#    #+#             */
/*   Updated: 2024/03/12 12:04:45 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_strchar(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}

size_t	ft_strlcopy(char *destiny, const char *source, size_t size)
{
	size_t	counter;
	size_t	j;

	counter = ft_strlen(source);
	j = 0;
	if (size > 0)
	{
		while (source[j] && j < size - 1)
		{
			destiny[j] = source[j];
			j++;
		}
		destiny[j] = '\0';
	}
	return (counter);
}

char	*ft_strdup(const char *srce)
{
	char	*str;
	int		size;
	int		i;
	
	i = 0;
	size = 0;
	while (srce[size])
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	while (srce[i])
	{
		str[i] = srce[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2, size_t len)
{
	size_t	lenght1;
	size_t	lenght2;
	char	*final;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	lenght1 = ft_strlen(s1);
	lenght2 = len;
	final = (char *)malloc ((lenght1 + lenght2 + 1) * sizeof(char));
	if (!final)
	{
		return (NULL);
	}
	ft_strlcopy(final, s1, lenght1 + 1);
	ft_strlcopy((final + lenght1), s2, lenght2 + 1);
	free(s1);
	return (final);
}
