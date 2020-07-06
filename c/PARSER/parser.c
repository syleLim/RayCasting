#include "parser.h"

t_bool	line_parser(char *line)
{
	char **flags;
	
	flags = ft_split(line, ' ');
	if (ft_strcmp("R", flags[0]))
		;
	if (ft_strcmp("NO", flags[0]))
		;
	if (ft_strcmp("WE", flags[0]))
		;
	if (ft_strcmp("EA", flags[0]))
		;
	if (ft_strcmp("S", flags[0]))
		;
	if (ft_strcmp("F", flags[0]))
		;
	if (ft_strcmp("C", flags[0]))
		;
}

t_bool	reader(int fd)
{
	char	*line;
	char	*trim_line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		
		free(line);
		line = NULL;
	}
}