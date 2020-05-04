/*
 * ppmIO.h
 *
 *  Created on: Mar 21, 2020
 *      Author: maxeler
 */

void loadImage(
		char* filename,
		int **dest,
		int *width,
		int *height,
		int grayscale);
void writeImage(
		char* filename,
		int*data,
		int width,
		int height,
		int grayscale);