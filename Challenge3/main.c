#include <stdio.h>
#include <stdlib.h>

int main(){
	double h = 34.2;
	double w = 65.5;
	double a = 0.0;
	double c = 0.0;
	
	c = 2.0*(h + w);
	a = h*w;
	
	printf("area of rectangle: %f\n", a);
	printf("perimeter of rectangle: %f\n", c);
	
	return 0;
}