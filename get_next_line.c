#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_update_holder(char	*holder)
{
	ssize_t	i;
	ssize_t	j;
	char	*dst;

	i = 0;
	j = 0;
	if (!holder)
		return (NULL);
	while (holder[i] != '\n' && holder[i])
		i++;
	while (holder[i + j])
		j++;
	dst = (char *)malloc(sizeof(char) * (j + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (holder[i])
		dst[j++] = holder[i++];
	dst[j] = '\0';
	return (dst);
}

char	*ft_get_new_line(char *holder)
{
	ssize_t	i;
	char	*dst;

	i = 0;
	if (!holder)
		return (NULL);
	while (holder[i] != '\n' && holder[i])
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (holder[i] != '\n' && holder[i])
	{
		dst[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		dst[i] = holder[i];
	dst[i++] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	char		*line;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_check_newline(holder) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		holder = ft_strjoin(holder, buffer);
	}
	free(buffer);
	line = ft_get_new_line(holder);//coger linea que vamos a imprimir
	holder = ft_update_holder(holder); //actualizar el holder quitandole la linea
	return (line);
}