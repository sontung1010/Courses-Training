#include <stdio.h>

int main(){
	double minutes = 0.0;
	double years = 0.0;
	double days = 0.0;
	
	printf("Please enter your value: ");
	scanf("%lf", &minutes);
	days = minutes/1440;
	years = minutes/525600;
	printf("You entered %f. This is equivalent to %f days or %f years.", minutes, days, years);
	
	return 0;
}