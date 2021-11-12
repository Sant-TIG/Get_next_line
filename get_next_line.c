#include "get_next_line.h"
#include <unistd.h>
/*
char	*ft_get_new_holder(char *holder)
{
	//printf ("\n----- GET NEW HOLDER ----\n");
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	while (holder[i] != '\n' && holder[i])
		i++;
	j = 0;
	while (holder[i + j])
		j++;
	dst = (char *)malloc(sizeof(char) * (j + i));
	if (!dst)
		return (NULL);
	j = 0;
	while (holder[++i])
		dst[j++] = holder[i];
	dst[j] = '\0';
	free(holder);
	return (dst);
}

char	*ft_get_new_line(const char *holder)
{
	//printf ("\n----- GET NEW LINE ----\n");
	char	*dst;
	ssize_t	i;

	i = 0;
	if (!holder)
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (holder[++i])
	{
		dst[i] = holder[i];
		if (dst[i] == '\n')
			break;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	////printf ("\n----- GET NEXT LINE ----\n");
	static char	*holder;
	char		*buffer;
	char		*new_line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = (char	*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!holder)
	{
		holder = (char *)malloc(sizeof(char) * 1);
		*holder = '\0';
	}
	while (!ft_check_line_break(holder) && bytes > 0)
	{
		//printf("\nno line break\n");
		bytes = read(fd, buffer, BUFFER_SIZE);
		//printf("bytes = |%ld|\n", bytes);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		//printf("BUFFER = |%s|\n", buffer);
		holder = ft_strjoin(holder, buffer);
		//printf("HOLDER = |%s|\n", holder);
	}
	free(buffer);
	new_line = ft_get_new_line((const char *)holder);
	holder = ft_get_new_holder(holder);
	if (bytes == 0 || !new_line)
		return (NULL);
	return (new_line);
}*/
size_t	ft_get_char_len(const char *str, char c)
{
	size_t	i;
	
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
		if (str[i] == c)
		{
			i++;
			break;
		}
	return (i);
}

char	*ft_nosenombre(char *holder, size_t start, size_t finish)
{
	char	*dst;
	
	dst = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dst)
		return (NULL);
	while (start < finish)
		*dst++ = holder[start++]
	*dst = '\0';
	return (dst);
}

size_t	ft_check_char(const char *str, char c)
{
	if (!str)
		return (0);
	while (*str != c && *str)
		str++;
	return (*str == c);
}

char	*noseelnombre(char *str, size_t start, char c)
{
	char	*dst;
	size_t	i;
	
	i = ft_get_char_len(holder, c);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	while (i--)
		*dst++ = *str++;
	*dst = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char *holder;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder)
		holder = noseelnombre(holder, '\0');
	while (!ft_check_char(holder, '\n'));
	{
	}
	next_line = noseelnombre(holder, 0, '\n');
	holder = ft_noseelnombre(holder, ft_get_char_len(holder, '\n') - 1, '\0');
	return (next_line);
}
