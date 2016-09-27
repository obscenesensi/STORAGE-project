#include <stdio.h>

#define C_SIZE 3

typedef enum {
  X,
  Y,
  Z
} coordinate;

const char *C_NAME[C_SIZE] = {"x", "y", "z"};

typedef struct {
  char *name;
  int x[C_SIZE];
} point;

void
print_points(point points[], int length)
{
  point *p;
  int i;

  puts(
    "Name   x   y   z\n"
    "----------------"
  );

  for (i = 0; i < length; i++) {
    p = &points[i];
    printf("%-4s%4d%4d%4d\n", p->name, p->x[X], p->x[Y], p->x[Z]);
  }
}

void
sort_points_by(coordinate c, point points[], int length)
{
  point temp;
  int last_element = length - 1;
  int i = 0;

  while (i < last_element) {
    int last_sorted = last_element;
    int j;

    for (j = last_element; j > i; j--) {
      if (points[j - 1].x[c] > points[j].x[c]) {
        temp = points[j - 1];
        points[j - 1] = points[j];
        points[j] = temp;

        last_sorted = j;
      }
    }

    i = last_sorted;
  }
}

int
main(void)
{
#define N 5

  int i;

  point points[N] = {
    {"A", {1, 2, 3}},
    {"B", {4, 3, 1}},
    {"C", {2, 8, 5}},
    {"D", {6, 4, 8}},
    {"O", {0, 0, 0}}
  };

  print_points(points, N);

  for (i = 0; i < C_SIZE; i++) {
    printf("\n[%s でソート]\n", C_NAME[i]);
    sort_points_by(i, points, N);
    print_points(points, N);
  }

  return 0;
}
