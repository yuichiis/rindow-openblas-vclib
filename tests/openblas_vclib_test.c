#include <math.h>
#include <stdio.h>
#include <cblas.h>

int main(void)
{
    const float x[] = {1.0f, 2.0f, 3.0f};
    float y[] = {10.0f, 20.0f, 30.0f};

    cblas_saxpy(3, 2.0f, x, 1, y, 1);

    if (fabsf(y[0] - 12.0f) > 1e-6f ||
        fabsf(y[1] - 24.0f) > 1e-6f ||
        fabsf(y[2] - 36.0f) > 1e-6f) {
        fprintf(stderr, "cblas_saxpy returned unexpected values: %g, %g, %g\n",
                y[0], y[1], y[2]);
        return 1;
    }
    return 0;
}
