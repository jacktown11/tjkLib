#include <stdio.h>
#include "alloc_m.h"
#include "base_m.h"
#include "cal_m.h"

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array)/sizeof(array[0]));}

void testShellsort_m(void);
void testQsort_m(void);
void testItoa_mv2(void);

int main(){
	
	//testShellsort_m();
	
	//testQsort_m();
	
	testItoa_mv2();
	
	/*
	//test atof_m
	char s[100];
	getLine_m(s,100);
	printf("%8.0f\n",atof_m(s));
	*/
	
	return 0;
}

void testShellsort_m(void){
	int v[] = {9,3,7,6,5,4,2,8},
		n = 0,
		*p = v;	
	GET_ARRAY_LEN(v,n);
	
	shellsort_m(v,n);
	while(n-->0){
		printf("%2d ",*p++);
	}
	printf("\n");
}

void testQsort_m(void){
	int v[] = {9,3,7,6,5,4,2,8},
		n = 0,
		*p = v;	
	GET_ARRAY_LEN(v,n);
	qsort_m(v,0,n-1);
	while(n--){
		printf("%d ",*p++);
	}
	putchar('\n');
	
}

void testItoa_mv2(void){
	char s1[20],s2[20];
	int n = -2576;
	itoa_mv2(n,s1);
	printf(s1);
	putchar('\n');
	itoa_mv2(n,s2);	
	//because of remained i's value, s2's first 5 chars are all seen as '\0'
	//which makes s2 actually an empty string. 
	printf(s2);
}

