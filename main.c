#include "lib/tga/tga.h"

void line(int x0, int y0, int x1, int y1, struct TGAImage *image, struct TGAColor color) { 
    for (float t=0.; t<1.; t+=.01) { 
        int x = x0 + (x1-x0)*t; 
        int y = y0 + (y1-y0)*t; 
		set(image, x, y, color);
    } 
}

int main(void) {

	/* Colors */
	struct TGAColor red = make_color_rgb(0, 0, 255, 255);
	struct TGAColor white = make_color_rgb(255, 255, 255, 255);

	/* Create an image context */
	struct TGAImage image = make_image_size(100, 100, RGBA);

	/* Draw some lines */
	line(13, 20, 80, 40, &image, white); 
	line(20, 13, 40, 80, &image, red); 

	/* Do some transform on the image */
	flip_h(&image);

	/* Output the TGA image file */
	write_tga_file(&image, "out.tga", false);

	/* PNG is a more widely utilized format thus github will display the image
	 * properly if it's in PNG, eventually I wanted to write my own
	 * implementation of PNG or JPEG or something but that's sort of a waste when
	 * I can just do this for now, this requires imagemagick be installed
	 */
	system("convert out.tga out.png && rm out.tga");

	return 0;
}
