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
	printf("\n--- GET CHAR LEN ---\n");
	size_t	i;

	i = 0;
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		i++;
		if (str[i] == c)
		{
			i++;
			return (i);
		}
	}
	return(0);
}

char	*ft_strdup(const char *str, size_t finish)
{
	printf("\n--- STRDUP ---\n");
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (finish + 1));
	if (!dst)
		return (NULL);
	while (finish--)
		*dst++ = *str++;
	*dst = '\0';
	return (dst);
}

char	*ft_update_holder(const char *str1, const char *str2)
{
	char	*dst;
	size_t	str1_len;
	size_t	str2_len;

	str1_len = ft_get_char_len(str1, '\0');
	str2_len = ft_get_char_len(str2, '\0');
	dst = (char *)malloc(sizeof(char) * (str1_len + str2_len + 1));
	if (!dst)
		return (NULL);
	while (*str1)
		*dst++ = *str1++;
	while (*str2)
		*dst++ = str2++;
	*dst = '\0';
	free(str1);
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

char	*ft_fill_next_line(const char *str, char **new_holder)
{
	char	*next_line;

	next_line = ft_strdup(str, ft_get_char_len(str, '\n'));
	*new_holder = ft_strdup(str + ft_get_char_len(str, '\n'), ft_get_char_len(str, '\0'));
	free(str);
	if (!next_line || !*new_holder)
	{
		free(next_line);
		free(*new_holder);
		return (NULL);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		next_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_check_line_break(holder))
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && ft_get_char_len(holder, '\0') == 0))
		{
			free(buffer);
			free(holder);
			return (NULL);
		}
		if (bytes < BUFFER_SIZE && ft_check_line_breal(buffer))
			return ();
		holder = ft_update_holder(holder, buffer);
	}
	return (ft_fill_next_line(holder, &holder));
}
