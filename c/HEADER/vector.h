#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include "DB.h"

double	get_rad(double angle);
double	vec_len(double vec[2]);
double	vec_cos(double v1[2], double v2[2]);
double	vec_rot(double vec[2], double angle);

#endif