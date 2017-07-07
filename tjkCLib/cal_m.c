#include <stdio.h>
#include <ctype.h>
#include "cal_m.h"

#define MAXVAL 100	//栈的最大深度

static int sp = 0;	//当前栈下一个空闲位置
static double val[MAXVAL];	//存放值的栈

//把值f压入栈中 
void push_m(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
	}else{
		printf("error in push_m: 栈满，无法压入%g\n",f);
	}
} 

//从栈中弹出一个值
double pop_m(void){
	if(sp>0){
		return val[--sp];
	}else{
		printf("error in pop_m: 栈中无有效值，无法弹出\n");
		return 0.0;
	}
}

//取下一个运算符或数值操作数 
int getop_m(char s[]){
	int i,c;
	while((s[0] = c = getch_m()) == '\t' || c == ' ');
	if(!isdigit(c) && c != '.'){
		s[1] = '\0';
		return c;	//不是数字 
	}
	i=0;
	if(isdigit(c)){
		while( isdigit(s[++i] = c = getch_m()) );	//取整数部分 
	} 
	if(c == '.'){
		while( isdigit(s[++i] = c =getch_m()) );	//取小数部分 
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

static char buff[BUFSIZE];	//供ungetch函数使用的缓冲取 
static int bufp = 0;	//buff中的下一个空闲位置 

//取一个字符,可能是压回的字符 
int getch_m(void){
	return (bufp>0)?buff[--bufp]:getchar();
}

//将字符压回输入中 
void ungetch_m(int c){
	if(bufp < BUFSIZE){
		buff[bufp++] = c;
	}else{
		printf("error in ungetch: 压回字符过多\n"); 
	}
}


