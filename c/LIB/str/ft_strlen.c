#include "str.h"

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}