#ifndef KERNEL_FUNC
#define KERNEL_FUNC

 #include <stdio.h>

  typedef struct
 {
	 uint16_t rows, cols;
	 int *kernelInfo;
	 
 } kernel;

  //gets the number of rows and columns of a supplied kernel
  void getKernelSize(FILE *kernelFile, kernel *outputKernel);

  //writes data from kernel file to array
  void writeKernelData(FILE *kernelFile, kernel *kernelStruct);

#endif
