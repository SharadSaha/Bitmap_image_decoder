#include <stdio.h>
#include <stdint.h>

typedef struct{
	unsigned short int  signature;
	unsigned int file_size;
	unsigned short int reserved1;
	unsigned short int reserved2;
	unsigned int  offset;

}BMP_header;

typedef struct{
	unsigned int size;
	unsigned int height;
	unsigned int width;
	unsigned short int planes;
	unsigned short int bits_per_pixel;
	unsigned int compression;
	unsigned int image_size;
	 //int hres;
	 //int vres;
	unsigned int ncol;
	unsigned int nimpcol;
}dib_header;

typedef struct{
	BMP_header bm_header;
	dib_header d_header;
	char *path;
}image_file;


void read_bm_header(image_file *image);
void read_dib_header(image_file *image);
void read_image_data(image_file *image);
