/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youllah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:50:11 by youllah           #+#    #+#             */
/*   Updated: 2022/11/07 16:07:12 by youllah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	chrchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
	while (i <= ft_strlen(s, 0))
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*theline(char *s)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s, 10);
	str = malloc(i + 1);
	if (!str)
		return (0);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = 0;
	return (str);
}

char	*aline(int fd, char *rest)
{
	int		num_read;
	char	buff[BUFFER_SIZE + 1];
	int		nb;

	num_read = 1;
	nb = 0;
	while (chrchr(rest + nb, 10) && num_read)
	{
		nb += num_read;
		num_read = read(fd, buff, BUFFER_SIZE);
		if (num_read == -1)
		{
			free(rest);
			return (0);
		}
		buff[num_read] = 0;
		if (!num_read)
			return (rest);
		rest = ft_strjoin(rest, buff);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[10024];
	char		*line;
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest[fd] = aline(fd, rest[fd]);
	if (!rest[fd])
		return (0);
	line = theline(rest[fd]);
	p = rest[fd];
	if (ft_strlen(rest[fd], 0) > ft_strlen(line, 0))
		rest[fd] = ft_substr(rest[fd], ft_strlen(line, 0),
				ft_strlen(rest[fd], 0) - ft_strlen(line, 0) + 1);
	else
		rest[fd] = NULL;
	free (p);
	return (line);
}

system()
