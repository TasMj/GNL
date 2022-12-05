/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:05:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/06/14 14:04:46 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_resize(char *dest, char *src);
int		check_end(char *buf);
char	*ft_strcpy(char *dest, char *src);
char	*stock_end(char *stockage);
char	*read_the_line(int fd, char *stockage);
char	*gestion_final_line(char *final_line);
char	*get_next_line(int fd);

#endif