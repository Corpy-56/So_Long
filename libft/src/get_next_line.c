/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:02:36 by agouin            #+#    #+#             */
/*   Updated: 2025/06/10 18:02:37 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

char	*long_line(char *temp, char *buffer, int fd)
{
	int	k;

	k = 1;
	while (k != 0 && !ft_strchr(buffer, '\n'))
	{
		k = read(fd, buffer, BUFFER_SIZE);
		if ((k == 0 && temp[0] == '\0') || k == -1)
		{
			if (temp)
				free(temp);
			temp = NULL;
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[k] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*print_line(char *join, char *temp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	join = ft_calloc(i + 2, sizeof(char));
	if (!join)
		return (NULL);
	while (temp[j] != '\0' && temp[j] != '\n')
	{
		join[j] = temp[j];
		j++;
	}
	if (temp[j] == '\n')
	{
		join[j] = temp[j];
		j++;
	}
	join[j] = '\0';
	return (join);
}

char	*next_line(char *temp)
{
	char		*swap;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	swap = ft_calloc(ft_strlen(temp) - i + 1, sizeof(char));
	if (!swap)
		return (NULL);
	if (temp[i] == '\n')
		i++;
	j = 0;
	while (temp[i] != '\0')
	{
		swap[j] = temp[i];
		i++;
		j++;
	}
	swap[j] = '\0';
	free(temp);
	return (swap);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	char		*join;

	join = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	if (!temp)
		temp = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !temp)
		return (NULL);
	temp = long_line(temp, buffer, fd);
	if (temp)
	{
		join = print_line(join, temp);
		temp = next_line(temp);
	}
	return (join);
}
