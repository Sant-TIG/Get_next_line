#include "get_next_line.h"
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	//printf ("\n----- STRLEN ----\n");
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *holder, char *buffer)
{
	//printf ("\n----- STRJOIN ----\n");
	char	*dst;
	ssize_t	i;
	ssize_t	j;

	i = -1;
	if (!holder && !buffer)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(holder) + ft_strlen(buffer) + 1));
	if (!dst)
		return (NULL);
	while (holder[++i])
		dst[i] = holder[i];
	j = -1;	
	while (buffer[++j])
		dst[i++] = buffer[j];
	dst[i] = '\0';
	return (dst);
}

int	ft_check_line_break(char *holder)
{
	//printf ("\n----- CHECK LINE BREAK ----\n");
	//printf ("holder = |%s|\n", holder);
	if (!holder)
		return (0);
	while (*holder != '\n' && *holder)
		holder++;
	return (*holder == '\n');
}
