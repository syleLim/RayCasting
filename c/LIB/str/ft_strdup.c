#include "str.h"

char	*ft_strdup(char *str, int *i, int len)
{
	char *new;

	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (++(*i) < len)
		new[*i] = str[*i];
	new[*i] = 0;
	return (new);
}