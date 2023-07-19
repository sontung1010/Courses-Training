#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	time_t t;
	int guess = 5;
	int guessNumber;
	srand((unsigned) time(&t));
	int number = rand()%31;
//	int number = 14;
	
	printf("This is a guessing game.\n");
	printf("I have chosen a number between 0 and 30 which you must guess.\n");
	
	do {
		if (guess == 0){
			printf("You failed to guess the number. The number is %d.\n", number);
			break;
		}
		
		printf("You have %d guess left\n", guess);
		printf("Enter a guess: ");
		scanf("%d", &guessNumber);
		if (guessNumber > number){
			printf("Sorry, %d is wrong. My number is less than that.\n", guessNumber);
		} else if (guessNumber < number){
			printf("Sorry, %d is wrong. My number is greater than that.\n", guessNumber);
		}
		
		guess--;
		
		
	} while((guessNumber != number) && (guess >= 0));
	
	
	
	if ((guessNumber == number) && (guess >= 0)){
		printf("'Congratulations. You guessed it!\n");
	}
	
	return 0;
}