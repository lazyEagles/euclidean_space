
#include <euclidean_space.h>
#include <string.h>
#include <math.h>

struct point *init_point(struct point *p) {
  if (!p) {
    return NULL;
  }
  memset(p, 0, MAX_DIMENSION * sizeof(double));
  p->dimension = 0;
  return p;
}

struct point *set_point_2d(struct point *p, double x, double y) {
  if (!p) {
    return NULL;
  }
  p->dimension = 2;
  p->coordinate[0] = x;
  p->coordinate[1] = y;
  return p;
}

struct point *set_point_3d(struct point *p, double x, double y, double z) {
  if (!p) {
    return NULL;
  }
  p->dimension = 3;
  p->coordinate[0] = x;
  p->coordinate[1] = y;
  p->coordinate[2] = z;
  return p;
}

struct vector *init_vector(struct vector *v) {
  if (!v) {
    return NULL;
  }
  memset(v, 0, MAX_DIMENSION * sizeof(double));
  v->dimension = 0;
  return v;
}

struct vector *set_vector_2d(struct vector *v, double x, double y) {
  if (!v) {
    return NULL;
  }
  v->dimension = 2;
  v->coordinate[0] = x;
  v->coordinate[1] = y;
  return v;
}

struct vector *set_vector_3d(struct vector *v, double x, double y, double z) {
  if (!v) {
    return NULL;
  }
  v->dimension = 3;
  v->coordinate[0] = x;
  v->coordinate[1] = y;
  v->coordinate[2] = z;
  return v;
}

struct vector *calc_vector_between_2_point(struct vector *v, struct point *initial_p, struct point *terminal_p) {
  if (!v || !initial_p || !terminal_p) {
    return NULL;
  }
  long i;
  v->dimension = (terminal_p->dimension > initial_p->dimension) ? terminal_p->dimension : initial_p->dimension;
  for (i = 0; i < v->dimension; i++) {
    v->coordinate[i] = terminal_p->coordinate[i] - initial_p->coordinate[i];
  }
  return v;
}

double calc_mag_square_vector(struct vector *v) {
  if (!v) {
    return 0.0;
  }
  double sum = 0.0;
  long i;
  for (i = 0; i < v->dimension; i++) {
    sum += (v->coordinate[i] * v->coordinate[i]);
  }
  return sum;
}

double calc_mag_vector(struct vector *v) {
  return sqrt(calc_mag_square_vector(v));
}

double calc_distance_between_2_point(struct point *pi, struct point *pj) {
  struct vector v;
  init_vector(&v);
  calc_vector_between_2_point(&v, pi, pj);
  return calc_mag_vector(&v);
}
