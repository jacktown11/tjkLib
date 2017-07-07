#include <stdio.h>
#include <ctype.h>
#include "cal_m.h"

#define MAXVAL 100	//ջ��������

static int sp = 0;	//��ǰջ��һ������λ��
static double val[MAXVAL];	//���ֵ��ջ

//��ֵfѹ��ջ�� 
void push_m(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
	}else{
		printf("error in push_m: ջ�����޷�ѹ��%g\n",f);
	}
} 

//��ջ�е���һ��ֵ
double pop_m(void){
	if(sp>0){
		return val[--sp];
	}else{
		printf("error in pop_m: ջ������Чֵ���޷�����\n");
		return 0.0;
	}
}

//ȡ��һ�����������ֵ������ 
int getop_m(char s[]){
	int i,c;
	while((s[0] = c = getch_m()) == '\t' || c == ' ');
	if(!isdigit(c) && c != '.'){
		s[1] = '\0';
		return c;	//�������� 
	}
	i=0;
	if(isdigit(c)){
		while( isdigit(s[++i] = c = getch_m()) );	//ȡ�������� 
	} 
	if(c == '.'){
		while( isdigit(s[++i] = c =getch_m()) );	//ȡС������ 
	}
	s[i] = '\0';
	if(c != EOF){ 
		ungetch_m(c);
	}
	return NUMBER;
}

void ungets_m(char *s){
	while(*s){
		ungetch_m(*s++);
	} 
}


#define BUFSIZE 100

static char buff[BUFSIZE];	//��ungetch����ʹ�õĻ���ȡ 
static int bufp = 0;	//buff�е���һ������λ�� 

//ȡһ���ַ�,������ѹ�ص��ַ� 
int getch_m(void){
	return (bufp>0)?buff[--bufp]:getchar();
}

//���ַ�ѹ�������� 
void ungetch_m(int c){
	if(bufp < BUFSIZE){
		buff[bufp++] = c;
	}else{
		printf("error in ungetch: ѹ���ַ�����\n"); 
	}
}


