// gcc -lm newton_test.c libbmp.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libbmp.h"

int min(int a,int b) {
	if(a<b) 
		return a;
	return b;
}
int max(int a,int b) {
	if(a>b) 
		return a;
	return b;
}

struct wrap {
    double content[2];
};


struct wrap f(double x[2]){
	// z^3-1
	double a=x[0];
	double b=x[1];
	double res[2];
	res[0]=a*a*a-3.0*a*b*b-1;
	res[1]=3*a*a*b-b*b*b;
    return((struct wrap) {
        .content = {res[0], res[1]}
    });
}

struct wrap deriv(double x[2]){
	// 3z^2
	double a=x[0];
	double b=x[1];
	double res[2];
	res[0]=3.0*a*a-3.0*b*b;
	res[1]=6.0*a*b;
    return((struct wrap) {
        .content = {res[0], res[1]}
    });
}

struct wrap newton(double z[2]){
	for(int i=0;i<10;i++) {
		// z ↦ z-f(z)/f'(z)
		struct wrap fz = f(z);
		double a = fz.content[0];
		double b = fz.content[1];
		if(a*a+b*b<0.01)
			break;
		struct wrap dz = deriv(z);
		double c = dz.content[0];
		double d = dz.content[1];
		double norm=c*c+d*d;
		z[0]-=(a*c+b*d)/norm;
		z[1]-=(b*c-a*d)/norm;
	}
    return((struct wrap) {
        .content = {z[0], z[1]}
    });
}


int main ()
{
	bmp_img img;
	int w=512,h=512;
	bmp_img_init_df (&img, w, h);

	for (size_t y = 0, x; y < h; y++)
	{
		double yc=(double)y/h;
		yc=2*yc-1;
		for (x = 0; x < w; x++)
		{
			double xc=(double)x/w;
			xc=2*xc-1;

			double z[2]={xc,yc};
			struct wrap res = newton(z);

			double ix=(res.content[0]+1)/2;
			double iy=(res.content[1]+1)/2;

			int r=ix*255;
			int g=iy*255;
			int b=0;
			// r=min(max(r,0),255);
			// r=min(r,255);
			// r=500;
			// g=min(max(g,0),255);
			// b=min(max(b,0),255);

			bmp_pixel_init (&img.img_pixels[y][x], r,g,b);
			// if ((y % 128 < 64 && x % 128 < 64) ||
			//     (y % 128 >= 64 && x % 128 >= 64))
			// {
			// 	bmp_pixel_init (&img.img_pixels[y][x], 250, 250, 250);
			// }
			// else
			// {
			// 	bmp_pixel_init (&img.img_pixels[y][x], 0, 0, 0);
			// }
		}
	}
	
	bmp_img_write (&img, "newton.bmp");
	bmp_img_free (&img);
	return 0;
}