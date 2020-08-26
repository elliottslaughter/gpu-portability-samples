#include <Kokkos_Core.hpp>

int main(int argc, char **argv) {
  Kokkos::initialize(argc, argv);

  size_t num_elements = 1 << 20;
  size_t buffer_size = num_elements * sizeof(float);

  float *x = (float *)malloc(buffer_size);
  float *y = (float *)malloc(buffer_size);
  float *z = (float *)malloc(buffer_size);

  const float alpha = 2.0f;

  for (size_t idx = 0; idx < num_elements; idx++) {
    x[idx] = 1.0f;
    y[idx] = 2.0f;
    z[idx] = 0.0f;
  }

  Kokkos::parallel_for(
      "saxpy", num_elements,
      KOKKOS_LAMBDA(size_t idx) { z[idx] += alpha * x[idx] + y[idx]; });

  float error = 0.0;
  for (size_t idx = 0; idx < num_elements; idx++) {
    error = fmax(error, fabs(z[idx] - 4.0f));
  }
  printf("error: %e\n", error);

  free(x);
  free(y);
  free(z);

  Kokkos::finalize();

  return 0;
}
