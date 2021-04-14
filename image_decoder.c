#include <stdio.h>
#include <stdlib.h>
#include "files.h"

void main()
{
	char path[13]="./sample.bmp";
	image_file image;
	
	image.path=path;
	
	read_bm_header(&image);
	read_dib_header(&image);
	read_image_data(&image);


	printf("BM HEADER\n");
	printf("signature: %c%c\n",image.bm_header.signature,image.bm_header.signature>>8);
	printf("file size: %x\n",image.bm_header.file_size);
	printf("reserved1 reserved2:%x %x\n",image.bm_header.reserved1,image.bm_header.reserved2);
	printf("offset: %x\n",image.bm_header.offset);
	printf("DIB HEADER\n");
	printf("size: %d\n",image.d_header.size);
	printf("width: %d\n",image.d_header.width);
	printf("height: %d\n",image.d_header.height);
	printf("planes: %d\n",image.d_header.planes);
	printf("Bits per pixel: %d\n",image.d_header.bits_per_pixel);
	printf("compression: %d\n",image.d_header.compression);
	printf("image size: %d\n",image.d_header.image_size);
	printf("no of colours: %d\n",image.d_header.ncol);
	printf("no of important colours: %d\n",image.d_header.nimpcol);

}