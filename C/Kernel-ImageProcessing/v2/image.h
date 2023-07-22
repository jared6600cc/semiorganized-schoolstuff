#ifndef IMAGE
#define IMAGE

   typedef struct
 {
	 uint16_t rows, cols;
	 uint8_t **image;
 } image;

  //calculates the centroid of a supplied image
  void calc_centroid();

  //trim edges of a supplied image matrix
  void trim_new_image();

#endif
