/*
 * Jared Bumgardner
 *
 * Final Homework
 * 
 */
 
 #include <stdio.h>
 
 void calc_centroid(){
	 //input: image name or array
	 //output: position (x,y) of the centroid
	 
	 //read the image into an array (unless array is given)
	 //compute the sum of all the pixels in the image
	 //compute the x value of the centroid
	 //compute the y value of the centroid
	 //print results
 }
 
 void trim_new_image(){
	 //input: original image, image size, modified image
	 
	 //loop through the image values (pixels)
	 //if pixel > 255 then
	 //--pixel = 255
	 //end
	 //if pixel < 0 then
	 //--pixel = 0
	 //end
 }
 
 int main(void) {
	 
	 //declarations
	 FILE *inputImagePTR;
	 char fileName[30];
	 
	 //open the images list file and read the first image name
	 if ( (inputImagePTR = fopen("images.txt","r+")) == NULL)
		 printf("Error: File not opened.\n");
	 
	 fgets(fileName, 30, inputImagePTR);
	 printf("inputImagePTR: %s",inputImagePTR);
	 
	 //obtain the image size and allocate memory for 3-2d arrays
	 //read the first image values and assign to array1
	 //assign a threshold value for motion detection
	 //read the vertical and horizontal edge kernel from the files
	 //read the smoothing kernel from the given file
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
	 
	 fclose(inputImagePTR);
	 
 }