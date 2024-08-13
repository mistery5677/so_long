/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:04:31 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 23:12:18 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	clean_buffer(char *buffer)
{
	int	flag;
	int	i;
	int	j;

	j = 0;
	i = 0;
	flag = 0;
	while (buffer[i])
	{
		if (flag == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i] = '\0';
		i++;
	}
	return (flag);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[++j] && s2[j] != '\n')
		str[i + j] = s2[j];
	if (s2[j] == '\n')
	{
		str[i + j] = '\n';
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!buffer[fd][0])
		read(fd, buffer[fd], BUFFER_SIZE);
	str = NULL;
	while (buffer[fd][0])
	{
		str = ft_strjoin_gnl(str, buffer[fd]);
		if (!str)
			return (NULL);
		if (clean_buffer(buffer[fd]) == 1)
			break ;
		read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (str);
}
