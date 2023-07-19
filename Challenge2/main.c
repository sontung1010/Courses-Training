#include <stdio.h>

int main(){
	enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
	
	enum Company company1 = XEROX;
	enum Company company2 = GOOGLE;
	enum Company company3 = EBAY;
	
	printf("%d\n", company1);
	printf("%d\n", company2);
	printf("%d\n", company3);
	
	
	return 0;
}