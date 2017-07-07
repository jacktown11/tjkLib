#include <stdio.h>
#include "alloc_m.h"

static char allocbuf[ALLOCSIZE];	//���ڷ���Ĵ洢 
static char *allocp = allocbuf;	//��һ������λ��ָ�� 

char *alloc_m(int n){
	if(allocbuf + ALLOCSIZE - allocp >= n){
		//���㹻���пռ� 
		allocp += n;
		return allocp - n;	//����ǰ��һ������λ�� 
	}else{
		return NULL;
	}
}

void afree_m(char *p){
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
		allocp = p;
	}
}
