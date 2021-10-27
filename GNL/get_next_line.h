#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);

#endif
