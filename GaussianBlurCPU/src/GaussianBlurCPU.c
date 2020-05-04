#include <stdio.h>
#include <stdint.h>

#include "Maxfiles.h"
#include "ppmIO.h"

// Input and output array size
#define SIZE 8

int main(void) {

	printf("Running DFE\n");
	int width=0;
	int height=0;
	int32_t* inImage;
	printf("Loading..");
	loadImage("Picture.ppm",&inImage,&width,&height,0);

	int32_t* outImage=malloc(width*height*sizeof(int));

	for (int i = 1; i < 1000; i++)
		printf("dataOut[%d] = %d\n", i, inImage[i]);

	GaussianBlurDFE(width*height,5, width,inImage, width*height*sizeof(int32_t),outImage, width*height*sizeof(int32_t));
	printf("Writing..");
	writeImage("GaussianBlur.ppm",outImage,width, height,0);
	return 0;


	//uint32_t dataIn[SIZE] = { 1, 0, 2, 0, 4, 1, 8, 3 };
    //uint32_t dataOut[SIZE];

    // This is just a stub for a SLiC call
    // to use the SLiC call, please change the function name
    // to the SLiC call you need.
    // GaussianBlurCPU(SIZE, dataIn, SIZE * sizeof(uint32_t), dataOut, SIZE * sizeof(uint32_t));

   // for (int i = 0; i < SIZE; i++) { // Ignore edge values
   //     printf("dataOut[%d] = %d\n", i, dataOut[i]);
   // }

    //for (int i = 0; i < SIZE; i++) { // Ignore edge values
//        if(dataIn[i] != dataOut[i]) {
//            printf("Test FAILED!\n");
//            return 1;
//        }
//    }
//    printf("Test passed!\n");

//    return 0;
}
