#include <stdio.h>
#include <stdlib.h>
#include "files.h"

void read_bm_header(image_file *image)
{
FILE *stream=fopen(image->path,"rb");
if(stream==NULL)
	printf("wrong path");
	//fread(&image->bm_header,sizeof(image->bm_header),1,stream);
	fread(&image->bm_header.signature,sizeof(image->bm_header.signature),1,stream);
	fread(&image->bm_header.file_size,sizeof(image->bm_header.file_size),1,stream);
	fread(&image->bm_header.reserved1,sizeof(image->bm_header.reserved1),1,stream);
	fread(&image->bm_header.reserved2,sizeof(image->bm_header.reserved2),1,stream);
	fread(&image->bm_header.offset,sizeof(image->bm_header.offset),1,stream);
	fclose(stream);
}

void read_dib_header(image_file * image)
{
	FILE *stream=fopen(image->path,"rb");
	if(stream==NULL)
		printf("wrong path");
	fseek(stream,14,SEEK_CUR);
	fread(&image->d_header.size,sizeof(image->d_header.size),1,stream);
	fread(&image->d_header.width,sizeof(image->d_header.width),1,stream);
	fread(&image->d_header.height,sizeof(image->d_header.height),1,stream);
	fread(&image->d_header.planes,sizeof(image->d_header.planes),1,stream);
	fread(&image->d_header.bits_per_pixel,sizeof(image->d_header.bits_per_pixel),1,stream);
	fread(&image->d_header.compression,sizeof(image->d_header.compression),1,stream);
	fread(&image->d_header.image_size,sizeof(image->d_header.image_size),1,stream);
	//fread(&image->d_header.hres,sizeof(image->d_header.hres),1,stream);
	//fread(&image->d_header.vres,sizeof(image->d_header.vres),1,stream);
	fread(&image->d_header.ncol,sizeof(image->d_header.ncol),1,stream);
	fread(&image->d_header.nimpcol,sizeof(image->d_header.nimpcol),1,stream);
	fclose(stream);
}

void read_image_data(image_file * image)
{
	FILE *stream=fopen(image->path,"rb");
	if(stream==NULL)
		printf("wrong path");
	fseek(stream,image->bm_header.offset,SEEK_CUR);
	int array_size=(image->d_header.width)*(image->d_header.height);
	unsigned char arr[array_size];
	fread(arr,1,array_size,stream);

	FILE * textfile=fopen("pixel_file.txt","w");
	for(int i=1;i<array_size+1;i++)
	{
		fwrite(&arr[i],1,1,textfile);
		if(i%image->d_header.width==0)
			fwrite("\n",1,1,textfile);
			
	}
	
	fclose(stream);

}