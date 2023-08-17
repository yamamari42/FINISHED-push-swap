/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:05 by mmardere          #+#    #+#             */
/*   Updated: 2023/01/13 17:12:28 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_get_line(char *line);
char	*ft_remainder(char *line);
char	*ft_read_and_join(int fd, char *line);
char	*get_next_line(int fd);
char	*ftstrjoin(char *s1, char *s2);
char	*ftstrchr(char *s, int c);
size_t	ftstrlen(char *s);
#endif
