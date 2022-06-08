/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gml2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:29:04 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/06/07 13:18:48 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	else
		while (s[i])
			i++;
	return (i);
}

int	search_newline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1 || ! s2)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
	free(s1);
	return (str);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		count;

	count = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!(search_newline(stash)) && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *line_in)
{
	int	len, i;
	char	*line;

	len = 0;
	if (line_in && !(line_in[len]))
		return (NULL);
	while (line_in[len] && line_in[len] != '\n')
		len++;
	if (line_in[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = line_in[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_up(char *line_in)
{
	int len, i;
	char *cleaned_line;

	len = 0;
	if (!line_in)
		return (NULL);
	while (line_in[len] && line_in[len] != '\n')
		len++;
	if (line_in[len] == '\n')
	{
		len++;
		cleaned_line = malloc(sizeof(char) * (ft_strlen(line_in + len) + 1));
		if (cleaned_line)
		{
			i = 0;
			while (line_in[len])
			{
				cleaned_line[i] = line_in[len];
				i++;
				len++;
			}
			cleaned_line[i] = '\0';
		}
		free(line_in);
		return (cleaned_line);
	}
	free(line_in);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		*line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	line = extract_line(stash);
	stash = clean_up(stash);
	return (line);
}
