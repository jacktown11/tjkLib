#ifndef BASE_M
#define BASE_M

/*functions relating to math and agrithom*/
int power_m(int base, int n); 

void swap_m(int v[], int x, int y);

void swap_mv1(int *x, int *y);

int binsearch_m(int x, int v[], int n);

void shellsort_m(int v[],int n);

void qsort_m(int v[],int left, int right);

void printd_m(int n);

int getint_m(int *pn);


/*functions converting between number and string*/
int atoi_mv1(char s[]);

int atoi_mv2(char s[]);

int atoi_m(char s[]);

double atof_mv1(char s[]);

double atof_m(char s[]);

void itoa_mv1(int n, char s[]);

void itoa_mv2(int n, char s[]);

void itoa_m(int n, char s[]);


/*functions handling string*/
int getLine_mv1(char s[],int lim);

int getLine_mv2(char s[], int lim);
 
int getLine_m(char *s, int lim);

int lower_mv1(int c);

int lower_m(int c);

void squeeze_mv1(char s[], int c);

void squeeze_m(char s[], char t[]);

int any_m(char s[], char t[]);

int strindex_m(char s[], char t[]);

void strcat_m(char s[], char t[]);

void copy_m(char s[], char t[]);
 
void reverse_mv1(char s[]);

void reverser_m(char s[], int start, int end);

void reverse_mv2(char s[]); 

void reverse_m(char s[]);

#endif
