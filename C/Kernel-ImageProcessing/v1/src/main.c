/*
 * Jared Bumgardner
 *
 * Final Homework
 * 
 */
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "kernel_func.h"
 #include "image.h"
 
 
 
 int main( int argc, char *argv[] ) {

	 
	 //declarations
	 FILE *imageListPTR;
	 FILE *fileNamePTR;
	 FILE *vkernelFilePTR; 
	 FILE *hkernelFilePTR;
	 FILE *smoothFilePTR;
	 char fileName[255] = {0x0}, line[255] = {0x0}, *tok;
	 uint8_t *array1, *array2, *array3;
	 int i, j, count = 0, isMotion;
	 image inputImage;
	 uint8_t motionThreshold;
	 
	 
	 //open the images list file and read the first image name
	 if(argc != 2){
		 printf("program name: %s filename", argv[0]);
	 }
	 else{
		 FILE *imageListPTR = fopen(argv[1], "r");
		 
		 if ( (imageListPTR) == NULL )
		 perror("Error");
	 }
	 
	 fgets(fileName, 30, imageListPTR);
	
	
	 //obtain the image size and allocate memory for 3-2d arrays
	 fileNamePTR = fopen(fileName, "rb");
	 if ( fileNamePTR == NULL ) {
		 perror("Open File Error");
	 }

	 fseek(fileNamePTR, 0, SEEK_SET);	//set pointer to file beginning
	 fgets(line, 255, fileNamePTR);
	 fgets(line, 255, fileNamePTR);
	 
	 tok = strtok(line, " ");
	 inputImage.rows = atoi(tok);
	 
	 tok = strtok(NULL, " ");
	 inputImage.cols = atoi(tok);

	 array1 = (uint8_t *)malloc(sizeof(uint8_t)*inputImage.rows*inputImage.cols);
	 array2 = (uint8_t *)malloc(sizeof(uint8_t)*inputImage.rows*inputImage.cols);
	 array3 = (uint8_t *)malloc(sizeof(uint8_t)*inputImage.rows*inputImage.cols);
	 
	 
	 //read the first image values from file header and assign to array1
	 fgets(line, 255, fileNamePTR);
 	 fgets(line, 255, fileNamePTR);
	 fgets(line, 255, fileNamePTR);
	 
	 fread(array1, sizeof(uint8_t), inputImage.cols * inputImage.rows, fileNamePTR);			//read image data into 1d array

	 uint8_t **image = (uint8_t **) malloc (inputImage.rows * sizeof(uint8_t *));
	 
	 for (i = 0; i < inputImage.rows; i++){														//allocate memory for a 2d array
		 image[i] = (uint8_t *)malloc (inputImage.cols * sizeof(uint8_t));
		 if (image[i] == NULL){
			 fprintf(stderr, "Not enough memory to allocate\n");
			 exit(1);
			 }
		}
		
	 for (i = 0; i < inputImage.rows; i++)				//populate 2d array with image info from 1d array
		 for (j = 0; j < inputImage.cols; j++)
			 image[i][j] = array1[count++];
	 
	 
	 //assign motion threshold and motion flag
	 motionThreshold = 50;
	 isMotion = 0;
	 
	 
	 //read the vertical and horizontal edge kernel from the files
	 if ((vkernelFilePTR = fopen(argv[2], "r")) == NULL)			//vertical kernel
		 perror("Error");
	 
	 kernel vkernel;
	 kernel *vkernelPTR = &vkernel;
	 getKernelSize(vkernelFilePTR, vkernelPTR);
	 int vkernelInfo[vkernel.rows][vkernel.cols];
	
	
	
	 if ((hkernelFilePTR = fopen(argv[3], "r")) == NULL)			//horizontal kernel
		 perror("Error");
	 
	 kernel hkernel;
	 kernel *hkernelPTR = &hkernel;
	 getKernelSize(hkernelFilePTR, hkernelPTR);
	 int hkernelInfo[hkernel.rows][hkernel.cols];


	 
	 //read the smoothing kernel from the given file
	 if ((smoothFilePTR = fopen(argv[4], "r")) == NULL)			//smoothing kernel
		 perror("Error");
	 
	 kernel smooth;	
	 kernel *smoothPTR = &smooth;
	 getKernelSize(smoothFilePTR, smoothPTR);
	 int smoothInfo[smooth.rows][smooth.cols];
	 
	 
	 
	 //compute the vertical, horizontal, and total edges
	 //trim all the edges arrays
	 //save all the edges arrays to PGM files
	 //smooth the image using correlation, normalize the array, and save to PGM file
	 //smooth the image using convolution, normalize the array, and save to PGM file
	 //			^flip kernel during convolution
	 //compute the image centroid and write it out to a file
	 //for (the rest of the images) do
	 //---read the next image into the array
	 //---do steps 8-14 above
	 //---compare the centroid with the previous image
	 //---if(centroid is outside tolerance values)
	 //---------flag the frame as containing motion
	 //---take the absolute value of the difference between two consecuutive images
	 //---compute the maximum value of the difference
	 //---if(maximum value is greater than the tolerance)
	 //---------flag the frame as containing motion
     //---swap the images (through use of arrays)
	 //end for loop
	 
	 
	 
	 //close files and free memory
	 fclose(imageListPTR);
	 fclose(fileNamePTR);
	 
	 for(i = 0; i < 10; i++){
		 free(image[i]);
	 }
	 
	 free(image);
	 
	 
	 //display to user closing statements
	 printf("\n\t***This is all for now...but there is much left to do!***");
	 
	 return(0);
 }