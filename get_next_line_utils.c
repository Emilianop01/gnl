/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:18:07 by epiacent          #+#    #+#             */
/*   Updated: 2024/03/13 15:33:18 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ftcalloc(size_t size, size_t buf)
{
	size_t	i;
	void	*str;

	str = (void *)malloc(size * buf);
	if (!str)
		return (str);
	i = 0;
	while (i < size * buf)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

int	nlin(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ceck(char *buf)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (buf[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

void	*wbuf(char *buf)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * sizeb(buf));
	if (!ret)
		return (NULL);
	while (buf[i] == 0)
		i++;
	while (i <= BUFFER_SIZE)
		ret[j++] = buf[i++];
	return (ret);
}

void	*ftrealloc(char *line, char *buf)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ftsize(line) + sizeb(buf) + 1));
	if (!ret)
		return (NULL);
	while (line[i] != '\0')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	free(line);
	return (ret);
}
