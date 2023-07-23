/*
 * Jared Bumgardner
 *
 * HW01
 *
 * Compute the volume of a cube with given
 * width, height, and length.
 *
 * Compile : gcc -o cube_volume.x cube_volume.c
 * Run : ./cube_volume.x
 * 
 */
 
 #include <stdio.h>
 
int main(void) {
	
//declare variables
double width_cube;
double height_cube;
double length_cube;
double volume_cube;
 
//introduce program
printf("\n***Cube Volume Computer***\n");
 
//prompt user for cube dimensions
printf("Please enter the width of the cube: ");
scanf("%lf", &width_cube); 

printf("Please enter the height of the cube: ");
scanf("%lf", &height_cube);

printf("Please enter the length of the cube: ");
scanf("%lf", &length_cube);
 
//compute & display volumn of a cube
volume_cube = width_cube * height_cube * length_cube;
printf("\nThe volume is equal to %f.\a\n", volume_cube);
 
 return 0;
}
 
