/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:28:10 by seolim            #+#    #+#             */
/*   Updated: 2020/07/01 10:34:37 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include <stdlib.h>
# include "str.h"
# include "DB.h"
# define BUFFER_SIZE	32
# define MAX_FD			500

int		find_n(char *file);
int		get_next_line(int fd, char **line);

#endif
