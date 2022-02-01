#include <math.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initRandom() {
    srand(time(NULL));   
}

float randomFloat(float a) {
    return ((float)rand()/(float)(RAND_MAX)) * a;
}

// void main_impala(int);

// int main(int argc, const char** argv) {
//     int n = 0;
//     if (argc >= 2)
//         n = atoi(argv[1]);
//     main_impala(n);
// }

void print_char(char c) {
   printf("%c\n", (int)c);
}
void print_int(int i) {
   printf("%d", i);
}
void print_f32(float f) {
   printf("%.2f", f);
}
void print_f64(double d) {
   printf("%.9f", d);
}

void print_piece_mask(unsigned long long* a) {
    for (int i = 0; i < 12; ++i)
        printf("%lli ", a[i]);
    printf("\n");
}

void print_piece_def(char* a) {
    for (int i = 0; i < 40; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

// header for mandelbrot bitmap
void print_header(int w, int h) {
   printf("P4\n%d %d\n",w,h);
}

void put_u8(unsigned char ui) {
   putc(ui, stdout);
}

void* thorin_malloc(size_t size) { 
    void* p;
    posix_memalign(&p, 64, size);
    return p;
}

// meteor printing
void print_meteor_scnt(int cnt) {
   printf("%d solutions found\n\n", cnt);
}

void print_meteor_lines(char a0, char a1, char a2, char a3, char a4, char a5, char a6, char a7, char a8, char a9) {
   printf("%c %c %c %c %c \n %c %c %c %c %c \n", a0+'0', a1+'0', a2+'0', a3+'0', a4+'0', a5+'0', a6+'0', a7+'0', a8+'0', a9+'0');
}

void write(const char* line, size_t size) {
    fwrite(line, size, 1, stdout);
}

void print(const char* s) {
    printf("%s", s);
}

void printn(const char* s, int n) {
    fwrite(s, 1, n, stdout);
}

void println(const char* s) {
    printf("%s\n", s);
}

FILE* get_stdin() {
    return stdin;
}

void print_num_matches(const char* s, int count) {
    printf("%s %d\n", s, count);
}

void print_digits(unsigned long long i) {
    printf("\t:%llu\n", i);
}

void saveppm(const char *fname, int w, int h, unsigned char *img) {
    FILE *fp = fopen(fname, "wb");
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", w, h);
    fprintf(fp, "255\n");
    fwrite(img, w * h * 3, 1, fp);
    fclose(fp);
}

// reverse
int read(char* s, int bufsize) {
    return (fgets(s, bufsize, stdin)) ? 1 : 0;
}

void* impala_realloc(void* ptr, int size) {
    return realloc(ptr, size);
}

void impala_memmove(char* dest, const char* src, int size) {
    __builtin_memmove(dest, src, size);
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


void* anydsl_alloc(int grid, int size) {
    return malloc(size);
}