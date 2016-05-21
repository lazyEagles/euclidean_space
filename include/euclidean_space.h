
#ifndef EUCLIDEAN_SPACE_H
#define EUCLIDEAN_SPACE_H

#define MAX_DIMENSION 16

struct point {
  double coordinate[MAX_DIMENSION];
  long dimension;
};

struct vector {
  double coordinate[MAX_DIMENSION];
  long dimension;
};

struct point *init_point(struct point *p);
struct point *set_point_2d(struct point *p, double x, double y);
struct point *set_point_3d(struct point *p, double x, double y, double z);
struct vector *init_vector(struct vector *v);
struct vector *set_vector_2d(struct vector *v, double x, double y);
struct vector *set_vector_3d(struct vector *v, double x, double y, double z);

struct vector *calc_vector_between_2_point(struct vector *v, struct point *initial_p, struct point *terminal_p);
double calc_mag_square_vector(struct vector *v);
double calc_mag_vector(struct vector *v);
double calc_distance_between_2_point(struct point *pi, struct point *pj);
#endif
