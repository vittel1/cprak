#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int cars_speed[50] = {4, 4, 7, 7, 8, 9, 10, 10, 10, 11, 11, 12, 12, 12,
  12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 16, 16, 17, 17,
  17, 18, 18, 18, 18, 19, 19, 19, 20, 20, 20, 20, 20, 22, 23, 24,
  24, 24, 24, 25};

  int car_dist[50] = {2, 10, 4, 22, 16, 10, 18, 26, 34, 17, 28, 14, 20,
  24, 28, 26, 34, 34, 46, 26, 36, 60, 80, 20, 26, 54, 32, 40, 32,
  40, 50, 42, 56, 76, 84, 36, 46, 68, 32, 48, 52, 56, 64, 66, 54,
  70, 92, 93, 120, 85};

  int min = 0;
  int max = 0;
  int mittelwert = 0;
  double mean = 0.0;
  double median = 0.0;

  int *min_ptr = &min;
  int *max_ptr = &max;
  int *mittelwert_ptr = &mittelwert;
  double *mean_ptr = &mean;
  double *median_ptr = &median;

  int *speed_ptr = cars_speed;
  int *dist_ptr = car_dist;

  //Speed
  printf("Car Distance: \n");
  summary(dist_ptr, (sizeof(car_dist)/sizeof(car_dist[0])), max_ptr, min_ptr, mean_ptr, median_ptr);

  printf("Car Speed: \n");
  summary(speed_ptr, (sizeof(cars_speed)/sizeof(cars_speed[0])), max_ptr, min_ptr, mean_ptr, median_ptr);

  return 0;

}

void summary (int *arr, size_t size, int *max, int *min, double *mean, double *median) {
  *min=*arr;
  *max=*arr;
  *mean=0;
  *median=0;

  for(int i=0; i < size; i++) {

    if(*min > *(arr+i)) {
      *min = *(arr+i);
    }
    else if(*max < *(arr+i)) {
      *max = *(arr+i);
    }

    *mean += *(arr+i);

    if(size%2 == 0) {
      //-1 noch zusätzlich weil das Array bei 0 anfängt zu zählen
      *median = 0.5*( *(arr+size/2-1) + *(arr+size/2) );
    }

  }
  printf("Min: %d\n", *min);
  printf("Max: %d\n", *max);
  printf("Mean: %f\n", *mean/size);
  //printf("x1: %d\n", *(arr+size/2));
  //printf("x2: %d\n", *(arr+size/2+1));
  printf("Median: %f\n", *median);
}
