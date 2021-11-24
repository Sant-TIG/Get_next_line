#include "get_next_line.h"
#include <unistd.h>

static char	*ft_update_holder(char *holder, char *buffer)
{
	char	*new_holder;
	size_t	holder_len;
	size_t	buffer_len;

	if (!holder || !buffer)
		return(NULL);
	holder_len = ft_get_char_len(holder, '\0');
	buffer_len = ft_get_char_len(buffer, '\0');
	new_holder = (char *)malloc(sizeof(char) * (holder_len + buffer_len + 1));
	if (!new_holder)
	{
		free(holder);
		holder = NULL;
		return (NULL);
	}
	ft_strcpy(new_holder, holder, holder_len + 1);
	ft_strcpy(new_holder + holder_len, buffer, buffer_len + 1);
	free(holder);
	holder = NULL;
	return (new_holder);
}

static char	*ft_line_break_case(char *holder, char **new_holder)
{
	char	*next_line;
	size_t	nl_len;
	size_t	null_len;

	nl_len = ft_get_char_len(holder, '\n');
	null_len = ft_get_char_len(holder, '\0');
	next_line = ft_strdup(holder, nl_len);
	*new_holder = ft_strdup(holder + nl_len, null_len - nl_len);
	free(holder);
	if (!next_line || !*new_holder)
	{
		free(next_line);
		free(*new_holder);
		*new_holder = NULL;
		return (NULL);
	}
	return (next_line);
}

static char	*ft_read_file(int fd, char **holder, char *buffer)
{
	ssize_t	bytes;

	while (!ft_check_char(*holder, '\n') )
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0 || (bytes == 0 && (ft_get_char_len(*holder, '\0') == 0)))
		{
			free(buffer);
			free(*holder);
			*holder = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (bytes == 0)
			break;
		*holder = ft_update_holder(*holder, buffer);
	}
	return (*holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder)
		holder = ft_strdup("", 0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	holder = ft_read_file(fd, &holder, buffer);
	if (!holder)
		return (NULL);
	free(buffer);
	if (ft_check_char(holder, '\n'))
		return (ft_line_break_case(holder, &holder));
	next_line = ft_strdup(holder, ft_get_char_len(holder, '\0'));
	free(holder);
	holder = NULL;
	return (next_line);
}