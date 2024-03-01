/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:50:17 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/29 17:16:52 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **ptr, char **ptr2, int flag)
{
	if (flag == 1)
	{
		free (*ptr);
		free (*ptr2);
		*ptr = NULL;
		*ptr2 = NULL;
	}
	if (flag == 2)
	{
		free (*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

char	*ft_reading(int fd, char *storage)
{
	int		nread;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage, &storage, 2));
	buffer[0] = '\0';
	nread = 1;
	while (nread > 0 && !gnl_strchr(buffer, '\n'))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (ft_free(&storage, &buffer, 1));
		buffer[nread] = '\0';
		if (nread > 0)
		{
			storage = gnl_strjoin(storage, buffer);
			if (!storage)
				return (ft_free(&storage, &storage, 2));
		}
	}
	free(buffer);
	return (storage);
}

char	*get_lines(char *storage)
{
	char	*ptr;
	char	*s;

	if (storage[0] == '\0')
		return (NULL);
	ptr = gnl_strchr(storage, '\n');
	if (!ptr)
		ptr = gnl_strchr(storage, '\0');
	s = gnl_substr(storage, 0, ((ptr - storage) + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_clean_storage(char *storage)
{
	int		i;
	char	*new_storage;
	char	*ptr;

	new_storage = gnl_strchr(storage, '\n');
	if (!new_storage)
	{
		ptr = NULL;
		return (ft_free(&storage, &storage, 2));
	}
	i = (new_storage - storage) + 1;
	if (storage[i] == '\0')
		return (ft_free(&storage, &storage, 2));
	ptr = gnl_substr(storage, i, gnl_strlen(storage) - i);
	ft_free(&storage, &storage, 2);
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_reading(fd, storage);
	if (!storage)
		return (ft_free(&storage, &storage, 2));
	line = get_lines(storage);
	if (!line)
		return (ft_free(&storage, &storage, 2));
	storage = ft_clean_storage(storage);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	//int i = 0;
	fd = open("tester.txt", O_RDONLY);
	line = "hola";
	while (line)
	{
		line = get_next_line(fd);
		printf("teste---->%s\n", line);
		 if (line)
		 {
		 	printf("teste---->%s\n", line);
		 	free(line);
			line = get_next_line(fd);
		}
	}
	return (0);
}*/
