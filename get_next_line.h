#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

char	*ft_strjoin(char *holder, char *buffer);
size_t	ft_strlen(char *str);
int		ft_check_newline(char *holder);
char	*ft_get_new_line(char *holder);
char	*ft_update_holder(char	*holder);
char	*get_next_line(int fd);

#endif