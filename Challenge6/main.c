#include <stdio.h>

int main(){
	int hour;
	float grossPay = 0.0;
	float taxes = 0.0;
	float netPay = 0.0;
	
	printf("Please enter the number of hours worked in a week: ");
	scanf("%d", &hour);
	if (hour > 40){
		grossPay = (hour - 40)*18 + 40*12;
	}
	else {
		grossPay = hour*12;
	}
	
	if ((grossPay >= 0) && (grossPay <= 300)){
		taxes = grossPay*0.15;
	}
	else if ((grossPay > 300) && (grossPay <= 450)){
		taxes = 300*0.15 + (grossPay - 300)*0.2;
	} else if (grossPay > 450){
		taxes = 300*0.15 + 150*0.2 + (grossPay - 450)*0.25;
	}
	
	netPay = grossPay - taxes;
	
	printf("gross pay: %.2f\n", grossPay);
	printf("taxes: %.2f\n", taxes);
	printf("net pay: %.2f\n", netPay);
	
	
	
	
	return 0;
}