#include <stdlib.h>
#include <stdio.h>

//Bei Funktionsaufrufen von alloc_array oder alloc_mem
//soll das multidimensionale Array values
//auf dem Heap angelegt werden. Ergänze den folgenden Code

int* alloc_array(size_t dt, size_t dx, size_t dy, size_t dz) {
	// todo: allocate memory
	int (*values)[dx][dy][dz] = malloc(dt*dx*dy*dz* sizeof(int));
	for(size_t t = 0; t < dt; ++t) {
		for(size_t x = 0; x < dx; ++x) {
			for(size_t y = 0; y < dy; ++y) {
				for(size_t z = 0; z < dz; ++z) {
					values[t][x][y][z] = t*1000 + x*100 + y*10 + z*1;
				}
			}
		}
	}
	return (int*) values;
}

int* alloc_mem(size_t dt, size_t dx, size_t dy, size_t dz) {
	// todo: allocate memory
	int *values = (int *) malloc(dt*dx*dy*dz* sizeof(int));
	for(size_t t = 0; t < dt; ++t) {
		for(size_t x = 0; x < dx; ++x) {
			for(size_t y = 0; y < dy; ++y) {
				for(size_t z = 0; z < dz; ++z) {
					size_t idx = dx*dy*dz*t + dy*dz*x + dz*y + z;
					values[idx] = t*1000 + x*100 + y*10 + z*1;
				}
			}
		}
	}
	return values;
}

int main (int argc, char** argv) {
	// Allocation
	size_t dt = 10, dx = 10, dy = 10, dz = 10;
	int* values_a = alloc_array(dt, dx, dy, dz);
	int* values_p = alloc_mem(dt, dx, dy, dz);

	// Verification
	for (size_t i = 0; i < dt*dx*dy*dz; ++i) {
		printf("%03ld = %04d %04d\n", i, values_a[i], values_p[i]);
	}

	// Cleanup
	// todo: release allocated memory
	free(values_a);
	free(values_p);

  return 0;
}
