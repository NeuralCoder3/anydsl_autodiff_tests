// gcc -lm newton_test.c libbmp.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include "libbmp.h"

void* initImage(int w, int h) {
	bmp_img* img=malloc(sizeof(bmp_img));
	bmp_img_init_df (img, w, h);
	return img;
}

void setBlackPixel(void* img, int x, int y) {
	bmp_pixel_init (&((bmp_img*)img)->img_pixels[y][x], 0,0,0);
}

void setRGBPixel(void* img, int x, int y, int r, int g, int b) {
	bmp_pixel_init (&((bmp_img*)img)->img_pixels[y][x], r,g,b);
}

void setPixel(void* img, int x, int y, int rgb[3]) {
	bmp_pixel_init (&((bmp_img*)img)->img_pixels[y][x], rgb[0],rgb[1],rgb[2]);
}

// void setPixelDefault(void* img, int x, int y, double x, double y) {
// 	double ix=(x+1)/2;
// 	double iy=(y+1)/2;

// 	int rgb[3]={ix*255,iy*255,0};
// 	setPixel(img, ix*w, iy*h, rgb);
// }

void writeImage(void* img, const char* filename) {
	bmp_img_write (img, filename);
}

void close(void* img) {
	bmp_img_free (img);
	// free(img);
}


// int main ()
// {
// 	int w=512,h=512;
// 	void* img=initImage(w,h);

// 	for (size_t y = 0, x; y < h; y++)
// 	{
// 		double yc=(double)y/h;
// 		yc=2*yc-1;
// 		for (x = 0; x < w; x++)
// 		{
// 			double xc=(double)x/w;
// 			xc=2*xc-1;

// 			double ix=(xc+1)/2;
// 			double iy=(yc+1)/2;

// 			int rgb[3]={ix*255,iy*255,0};
// 			setPixel(img,x,y,rgb);
// 		}
// 	}

// 	writeImage(img,"newton.bmp");
// 	close(img);
	
// 	return 0;
// }