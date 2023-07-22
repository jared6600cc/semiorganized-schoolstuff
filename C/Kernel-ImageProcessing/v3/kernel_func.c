/*
 * Jared Bumgardner
 * 
 * 'Implementation' of Kernel header
 *
 */
 
 #include <stdio.h>
 #include <string.h>
 #include "kernel_func.h"
 
 /*
  *	Implementation of kernel functions
  */
  
  void getKernelSize(FILE *kernelFile, kernel *outputKernel){
	 //declarations
	 char line[255] = {0x0};
	 char *tok = 0; 
	 int kernColCount = 0, kernRowCount = 0;
	 
	 //determine dimensions of kernel
	 fgets(line, 255, kernelFile);
	 
	 tok = strtok(line, " ");
	 while( fgets(line, sizeof(line), kernelFile) != NULL) {
		 while(tok != '\0'){				//count tokens in row (columns)
			 tok = strtok(NULL, " ");
		 kernColCount++;
		 }
		 
		 kernRowCount++;
	}
	 kernRowCount++;

	 //set kernel structure values according to findings
	 (*outputKernel).rows = kernRowCount;
	 (*outputKernel).cols = kernColCount;
 }
 
  void writeKernelData(FILE *kernelFile, kernel *kernelStruct){
	 //TODO IMPLEMENT
 }