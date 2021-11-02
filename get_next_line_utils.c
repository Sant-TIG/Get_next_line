#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strjoin(char *holder, char *buffer)
{
	char	*dst;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(holder) + BUFFER_SIZE + 1));
	if (!dst)
		return (NULL);
	if (holder)
	{
		while (holder[i++])
			dst[i] = holder[i];
	}
	j = 0;
	while (buffer[j])
		dst[i++] = buffer[j++];
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_newline(char *holder)
{
	size_t	i;

	i = 0;
	if (!holder)
		return (0);
	while (holder[i] != '\n' && holder[i])
		i++;
	return (holder[i] == '\n');
}