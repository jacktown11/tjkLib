#include <stdio.h>
#include "alloc_m.h"

static char allocbuf[ALLOCSIZE];	//用于分配的存储 
static char *allocp = allocbuf;	//第一个空闲位置指针 

char *alloc_m(int n){
	if(allocbuf + ALLOCSIZE - allocp >= n){
		//有足够空闲空间 
		allocp += n;
		return allocp - n;	//分配前第一个空闲位置 
	}else{
		return NULL;
	}
}

void afree_m(char *p){
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
		allocp = p;
	}
}
