/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:26:43 by mmardere          #+#    #+#             */
/*   Updated: 2023/01/13 16:34:57 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_remainder(char *line)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	remainder = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!remainder)
		return ((NULL));
	i++;
	j = 0;
	while (line [i])
		remainder[j++] = line[i++];
	remainder[j] = '\0';
	free(line);
	return (remainder);
}

char	*ft_read_and_join(int fd, char *line)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			return (free(buff), NULL);
		}
		buff[read_bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*line[1024];

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = ft_read_and_join(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	ret = ft_get_line(line[fd]);
	line[fd] = ft_remainder(line[fd]);
	return (ret);
}
/*int    main(void)
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("textfile.txt", O_RDONLY);
    char    *line;
    while (1)
    {
        line = get_next_line(fd1);
        printf("fd1 == '%s'", line);
        free(line);
        line = get_next_line(fd2);
        printf("fd2 == '%s'", line);
        free(line);
        line = get_next_line(fd3);
        printf("fd3 == '%s'", line);
        if (!line)
            break;
        free(line);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}*/
