#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

size_t	ft_check_char(const char *str, int c);
size_t	ft_get_char_len(const char *str, int c);
char	*ft_strcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str, size_t len);
char	*get_next_line(int fd);

#endif