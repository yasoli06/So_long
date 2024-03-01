/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:59:29 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/29 17:13:58 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>


//GNL.C//
char	*ft_free(char **ptr, char **ptr2, int flag);
char	*ft_reading(int fd, char *storage);
char	*get_lines(char *storage);
char	*ft_clean_storage(char *storage);
char	*get_next_line(int fd);

//UTILS //
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strdup(const char *s1);

#endif
