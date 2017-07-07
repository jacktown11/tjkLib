#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "base_m.h"
#include "cal_m.h"

/*=============
base functions 
don't guarantee correctness
===============*/


int power_m(int base, int n){
//from example1.7 
//计算base的n次幂 
	int p = base;
	while(--n > 0){
		p *= base;
	}
	return p;
}

void swap_m(int v[], int x, int y){
/*===========
from example 4.10
swap values in v at x and y
=============*/
	int temp = 0;
	temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}

void swap_mv1(int *x, int *y){
/*===========
from example 5.2
swap int values at x and y
=============*/
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int binsearch_m(int x, int v[], int n){
/*===========
from example 3.3
find the place of x in v whose length is n;
if can't find x, return -1
=============*/
	int low = 0,
		high = n-1,
		mid = (low + high) / 2;
	while(low <= high){
		mid = (low + high) /2;
		if(x < v[mid]){
			high = mid -1;
		}else if( x > v[mid]){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}

void shellsort_m(int v[],int n){
/*===========
from example 3.5
an agrithom invented by D.L.shell in 1959
=============*/
	int i = 0,
		j = 0,
		temp = 0,
		gap = 0;
	for(gap = n/2;gap > 0; gap /= 2){
		for(i = gap; i < n; i++){
			for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}
}

void qsort_m(int v[],int left, int right){
/*===========
from example 4.10
quick sort, invented by C.A.R hoare in 1962
=============*/
	int last = left,
		i = left;
	if(left >= right){
		return ;
	}
	swap_m(v,left,(left + right) / 2);
	for(i++;i<=right;i++){
		if(v[i] < v[left]){
			swap_m(v,++last,i);
		}
	}
	swap_m(v,left,last);
	qsort_m(v,left,last-1);
	qsort_m(v,last+1,right);
}

void printd_m(int n){
/*===========
from example 4.10
printd an integer
=============*/
	if(n<0){
		putchar('-');
	}
	if(n/10){
		printd_m(abs(n/10));
	}
	putchar(abs(n%10)+'0');
}

int getint_m(int *pn){
/*===========
from example 5.2
get an integer and save it at pn
return -1 if meet EOF,return 0 if it's not a number;
retrun a positive int if it's a number
=============*/
	int c = '\0',
		sign = 1;
	while(isspace(c = getch_m()));
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch_m(c);
		return 0;
	}
	if(c == '+' || c == '-'){
		sign = (c == '-')? -1 : 1;
		c = getch_m();
	}
	for(*pn = 0;isdigit(c);getch_m(c)){
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if(c != EOF){
		ungetch_m(c);
	}
	return c;
}



int atoi_mv1(char s[]){
/*===========
from example 2.7
convert a string to integer
=============*/
	int i,n=0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; i++){
		n = n * 10 + s[i] - '0';
	}
	return n;
}

int atoi_mv2(char s[]){
/*===========
from example 3.5
convert a string to an integer
=============*/
	int n = 0,
		sign = 1,
		i = 0;
	for(;!isspace(s[i]);i++);
	if(s[i] == '+'){
		i++;
	}else if(s[i] == '-'){
		sign = -1;
		i++;
	}
	for(;isdigit(s[i]);i++){
		n = n * 10 + s[i] - '0'; 
	}
	n = n * sign;
	
	return n;
}

int atoi_m(char s[]){
/*===========
from example 3.5
convert a string to an integer
=============*/
	double atof_m(char s[]);
	
	return (int) atof_m(s);
}

double atof_mv1(char s[]){
/*===========
from example 4.2
convert a string to a float
=============*/
	double f = 0.0,
		   power = 1.0;
	int i = 0,
		sign = 1;
	while(isspace(s[i++]));	//skip space 
	if(s[i] == '+' || s[i] == '-'){
		//get the sign if exist
		sign = (s[i] == '-')?-1:1;
		i++;
	}
	for(;isdigit(s[i]);i++){
		//get the integer part
		f = f * 10.0 + (s[i] - '0');
	}
	if(s[i] == '.'){
		i++;
	}
	for(;isdigit(s[i]);i++){
		//get the fractional part
		f = f * 10.0 + (s[i] - '0');
		power *= 10.0;
	}
	f = f * sign / power;
	
	return f;

}

double atof_m(char s[]){
/*===========
from exercise 4.2
convert a string to a float
=============*/
	double f = 0.0,
		   power = 1.0;
	int i = 0,
		exp = 0,
		sign = 1;
	while(isspace(s[i])){
		//skip space 
		i++;
	}	
	if(s[i] == '+' || s[i] == '-'){
		//get the sign if exist
		sign = (s[i] == '-')?-1:1;
		i++;
	}
	for(;isdigit(s[i]);i++){
		//get the integer part
		f = f * 10.0 + (s[i] - '0');
	}
	if(s[i] == '.'){
		i++;
	}
	for(;isdigit(s[i]);i++){
		//get the fractional part
		f = f * 10.0 + (s[i] - '0');
		power *= 10.0;
	}
	f = f * sign / power;
	if(s[i] == 'e' || s[i] == 'E'){
		i++;
		sign = 1;
		if(s[i] == '-' || s[i] == '+'){
			sign = (s[i] == '-')?-1:1;
			i++;
		}
		while(isdigit(s[i])){
			exp = exp * 10.0 + (s[i] - '0');
			i++;
		}
		if(sign == 1){
			while(exp--){
				f *= 10.0;
			}
		}else{
			while(exp--){
				f /= 10.0;
			}
		}
	}
	return f;
}

void itoa_mv1(int n, char s[]){
/*===========
from example 3.6
convert an integer to a string
can't handle -2^(sizeof(int)*8-1)
=============*/
	int i = 0,
		neg = 0;
	if(n < 0){
		n = -n;
		neg = 1;
	}
	do{
		s[i++] = n % 10 + '0';
	}while((n /= 10) > 0);
	if(neg){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse_m(s);
}

void itoa_mv2(int n, char s[]){
/*===========
from exercise 4.12
convert an integer to a string
recuision edition, a bug: if call it the second time in one program, as i
is static, the second receive string's first char is saved at place i which
should be zero. 
=============*/
	static int i = 0;
	if(n/10){
		itoa_mv2(n/10,s);
	}else if(n<0){
		s[i++] = '-';
	}
	s[i++] = abs(n%10) + '0';
	s[i] = '\0';
}

void itoa_m(int n, char s[]){
/*===========
from exercise 3.4
convert an integer to a string
=============*/
	int i = 0,
		neg = (n<0)?1:0;
		
	do{
		s[i++] = abs(n%10) + '0';
	}while(n /= 10);
	if(neg){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse_m(s);
}



int lower_mv1(int c){
/*===========
from example 2.7
convert a character to its lower case, only for ASCII code
=============*/
	if(c >= 'A' && c <= 'Z'){
		return c + 'a' - 'A';
	}else{
		return c;
	}
}

int getLine_mv1(char s[],int lim){
//from example1.9
//获取包括结束字符在内长度不超过lim的一个输入行，放在字符数组s中 
	int c = '\0',
		i= 0;
	for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n';i++){
		//有空间，文件未结束，非换行符 
		s[i] = c;
	} 
	if(c == '\n'){
		//如果是以换行结束，加上换行符 
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int getLine_mv2(char s[], int lim){
/*===========
from example 4.1
get a line whose length is no more than lim-1
return its length
=============*/
	int c = '\0',
		i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
		s[i++] = c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int getLine_m(char *s, int lim){
	int c;
	char *s_start = s;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
		*s++ = c;
	}
	if(c == '\n'){
		*s++ = c;
	}
	*s = '\0';
	
	return s - s_start;
}

int lower_m(int c){
/*===========
from exercise 2.10
convert a character to its lower case, only for ASCII code
=============*/
	return (c >= 'A' && c <= 'Z')?c + 'a' - 'A':c;
}

void squeeze_mv1(char s[], int c){
/*===========
from example 2.7
delete all char c in s
=============*/
	int i,j;
	for(i = j = 0; s[i]; i++){
		if(s[i] != c){
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

void squeeze_m(char s[], char t[]){
/*===========
from exercise 2.4
delete all chars which t contains in s
=============*/
	int i,j,k;
	for(i = k = 0;s[i] != '\0';i++){
		for(j = 0; s[i] != t[j] && t[j] != '\0'; j++);
		if(t[j] = '\0'){
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

int any_m(char s[], char t[]){
/*===========
from exercise 2.5
return the place where any char in t appear in s for the first time
if no char is satisfied ,return -1
=============*/
	int i,j;
	for(i = 0; s[i] != '\0' ;i++){
		for(j = 0; t[j] != '0'; j++){
			if(t[j] == s[i]){
				return i;
			}
		}
	}
	
	return -1;
}

int strindex_m(char s[], char t[]){
/*===========
from example 4.1
find the position where the whole t appears in s for the first time
if can't find, return -1
=============*/
	int i = 0,
		j = 0,
		k = 0;
	for (;s[i] != '\0';i++){
		//test whether t appear at position i
		for(j = i;s[k] != '\0' && s[j] == t[k];j++,i++);
		if(k > 0 && t[k] == '\0'){
			//t is not empty, and the whole t match
			return i;
		}
	}
	return -1;
}

void strcat_m(char s[], char t[]){
/*===========
from example 2.7
catenate t to s
=============*/
	int i=0,j=0;
	while(s[i] != '\0'){
		i++;
	}
	while((s[i++] = t[j++]) != '\0');
}

void copy_m(char to[], char from[]){
//from example1.9
//将字符串from复制到字符串to中，默认有足够空间 
	int i = 0;
	while(to[i] = from[i]){
		i++;
	}
} 

void reverse_mv1(char s[]){
//from exercise1.19
//翻转字符串，一行文本翻转时，保持换行符在最后 
	int i=0,j=0;
	char temp;
	while(s[i]){
		i++;
	} 
	i--;
	if(s[i] == '\n'){
		i--;	
		//换行符只出现在本行末尾，这个通用情况下应该去掉，这里只是为了处理题目问题需求 
	}
	while(j<i){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		j--;
		i++;
	}
}

void reverser_m(char s[], int start, int end){	
	char temp = '\0';
	
	if(start < end){
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		reverser_m(s,start+1,end-1);
	}

}

void reverse_mv2(char s[]){
/*===========
from exercise 4.13
reverse the string s
recuision edition
=============*/
	reverser_m(s,0,strlen(s)-1);
	
}

void reverse_m(char s[]){
/*===========
from example3.5
reverse string s
=============*/
	int i = 0,
		j = strlen(s)-1,
		c = '\0';
	for(;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


