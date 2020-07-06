#ifndef STR_H
# define STR_H
# include <stdlib.h>
# include <unistd.h>
# include "DB.h"

t_bool	ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str, int *i, int len);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);

#endif
