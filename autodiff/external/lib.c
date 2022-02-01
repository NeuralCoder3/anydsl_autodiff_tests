#include <math.h>
#include <stdio.h>
#include <stdbool.h>

void read_gmm_size(
    char* file,
    int* d,
    int* k,
    int* n
)
{
  FILE* fid = fopen(file, "r");

  if (!fid) {
    return;
  }

  fscanf(fid, "%i %i %i", d, k, n);
  fclose(fid);
}


void read_gmm(
    char* file,
    int* d,
    int* k,
    int* n,
    int* wishartM,
    double* wishartGamma,
    double* alphas,
    double* means,
    double* icf,
    double* x
    )
{
    FILE* fid = fopen(file, "r");

    if (!fid) {
        return;
    }

    fscanf(fid, "%i %i %i", d, k, n);

    int d_ = *d, k_ = *k, n_ = *n;

    int icf_sz = d_ * (d_ + 1) / 2;

    for (int i = 0; i < k_; i++)
    {
        fscanf(fid, "%lf", &alphas[i]);
    }

    for (int i = 0; i < k_; i++)
    {
        for (int j = 0; j < d_; j++)
        {
            fscanf(fid, "%lf", &means[i * d_ + j]);
        }
    }

    for (int i = 0; i < k_; i++)
    {
        for (int j = 0; j < icf_sz; j++)
        {
            fscanf(fid, "%lf", &icf[i * icf_sz + j]);
        }
    }

    for (int i = 0; i < n_; i++)
    {
      for (int j = 0; j < d_; j++)
      {
        fscanf(fid, "%lf", &x[i * d_ + j]);
      }
    }

    fscanf(fid, "%lf %i", wishartGamma, wishartM);

    fclose(fid);
}

void printFloat(float i) {
  printf("%f\n", i);
}
void printDouble(double i) {
  printf("%lf\n", i);
}
void printInteger(int i) {
  printf("%d\n", i);
}

float pow_arr(float x[2]) {
  return pow(x[0],x[1]);
}