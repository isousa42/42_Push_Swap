#include "checker.h"

static int	ft_strsave(int fd, char **line, char **store)
{
	int			i;
	char		*temp;

	i = 0;
	while (store[fd][i] != '\n' && store[fd][i] != '\0')
		i++;
	if (store[fd][i] == '\n')
	{
		*line = ft_substr(store[fd], 0, i);
		temp = ft_substr(store[fd], i + 1, ft_strlen(store[fd]) - i);
		free(store[fd]);
		store[fd] = temp;
		return (1);
	}
	else
	{
		*line = ft_strdup(store[fd]);
		free(store[fd]);
		store[fd] = 0;
		return (0);
	}
}

static int	ft_returns(int fd, char **line, char **store, int readcount)
{
	if (readcount == -1)
		return (-1);
	if (!(readcount) && store[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_strsave(fd, line, store));
}

int	get_next_line(int fd, char **line)
{
	int			buffer_size;
	static char	*store[100000];
	char		buff[32];
	char		*temp;
	int			readcount;

	buffer_size = 31;
	readcount = 1;
	if (fd < 0 || !line || buffer_size <= 0)
		return (-1);
	while (readcount > 0)
	{
		readcount = read(fd, buff, buffer_size);
		buff[readcount] = '\0';
		if (!store[fd])
			store[fd] = ft_strdup("");
		temp = ft_strjoin(store[fd], buff);
		free(store[fd]);
		store[fd] = temp;
		if (ft_strchr(store[fd], '\n'))
			break ;
	}
	return (ft_returns(fd, line, store, readcount));
}
