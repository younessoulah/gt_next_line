/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youllah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:32:59 by youllah           #+#    #+#             */
/*   Updated: 2022/11/07 15:59:30 by youllah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == 10)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	k;

	i = 0;
	k = start;
	if (!s)
		return (NULL);
	if (k >= ft_strlen(s, 0))
		return (ft_strdup(""));
	if (k + len > ft_strlen(s, 0))
		len = ft_strlen(s, 0) - k;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len && s[k])
	{
		p[i] = s[k];
		k++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	l;
	char	*p;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	l = ft_strlen(s1, 0) + ft_strlen(s2, 0);
	p = malloc(l + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[l] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*p;

	i = 0;
	l = 0;
	l = ft_strlen(s1, 0);
	p = malloc (sizeof(char) * l + 1);
	if (!p)
		return (NULL);
	while (i < l)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
