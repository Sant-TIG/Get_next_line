#include "get_next_line.h"

char	*ft_strdup(const char *str, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, str, len + 1);
	return (dst);
}

size_t	ft_get_char_len(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i] != c)
		i++;
	return (i + 1);
}

size_t	ft_check_char(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str && *str != c)
		str++;
	return (*str == c);
}

char	*ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
