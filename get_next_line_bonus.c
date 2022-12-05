/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:18:40 by tmejri            #+#    #+#             */
/*   Updated: 2022/06/14 14:17:32 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*stock_end(char *stockage)
{
	int		i;
	char	*dest;

	i = 0;
	while (stockage[i] != '\n' && stockage[i] != '\0')
		i++;
	if (!stockage[i])
	{
		free(stockage);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(stockage) - i + 1));
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, stockage + i + 1);
	free (stockage);
	return (dest);
}

char	*read_the_line(int fd, char *stockage)
{
	char			*buf;
	int				rd;

	rd = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (check_end(stockage) == 0 && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{	
			free (buf);
			return (NULL);
		}
		buf[rd] = 0;
		stockage = ft_strjoin(stockage, buf);
	}
	free (buf);
	return (stockage);
}

char	*gestion_final_line(char *stockage)
{
	int		i;
	char	*dest;

	i = 0;
	if (!stockage[0])
		return (NULL);
	while (stockage[i] != '\n' && stockage[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * i + 2);
	if (!dest)
		return (NULL);
	dest = ft_resize(dest, stockage);
	return (dest);
}

char	*get_next_line(int fd)
{
	char			*final_line;
	static char		*stockage[1025];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stockage[fd] = read_the_line(fd, stockage[fd]);
	if (!stockage[fd])
		return (NULL);
	final_line = gestion_final_line(stockage[fd]);
	stockage[fd] = stock_end(stockage[fd]);
	return (final_line);
}

// #include <stdio.h>
// int    main()
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*str;

// 	fd1 = open("text.txt", O_RDONLY);
// 	str = get_next_line(fd1);
// 	printf("[%s]", str);
// 	free(str);

// 	fd2 = open("gui.txt", O_RDONLY);
// 	str = get_next_line(fd2);
// 	printf("[%s]", str);
// 	free(str);

// 	fd3 = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd3);
// 	printf("[%s]", str);
// 	free(str);

// 	str = get_next_line(fd1);
// 	printf("[%s]", str);
// 	free(str);
// 	str = get_next_line(fd2);
// 	printf("[%s]", str);
// 	free(str);
// 	str = get_next_line(fd3);
// 	printf("[%s]", str);
// 	free(str);
// 	str = get_next_line(fd1);
// 	printf("[%s]", str);
// 	free(str);
// 	str = get_next_line(fd2);
// 	printf("[%s]", str);
// 	free(str);
// 	str = get_next_line(fd3);
// 	printf("[%s]", str);
// 	free(str);
// }
