#include<iostream>

#include<algorithm>

#include<vector>

#define Maxwords 100 /* ��Źؼ����������󳤶� */

#define Nword 8

struct key {
	
	char *wordstal; /* ����ַ��� */
	
	int count; /* ����ַ����ĸ��� */
	
} keytab[Nword] = { /* ��ʼ��һ���ṹ������ (�ɽṹ�幹�ɵ�����)N �ؼ��ʵĸ��� ����keytab[i].word*/
	
	{"auto", 0},
	
	{"break", 0},
	
	{"case", 0},
	
	{"char", 0},
	
	{"const", 0},
	
	{"continue", 0},
	
	{"default", 0},
	
	/* ������ */
	
	{"while", 0}
	
};

int getword(char *word, int n);

int binsearch(char *word, struct key *keytab, int n);

void writeword( struct key *keytab);

int main()

{
	
	int type;
	
	int n;
	
	char word[Maxwords];
	
	while( (type = getword(word, Maxwords)) != EOF ) {
		
		if(isalpha(type))
			
			if( (n = binsearch(word, keytab, Nword)) >= 0) {
			
			keytab[n].count++;
			
		}
		
	}
	
	writeword(keytab);
	
	return 0;
	
}

#define Maxbuf 10

static int buf[Maxbuf];

int sp = 0;

void ungetch(int c)

{
	
	if(sp)
		
		buf[sp++] = c;
		


else
	
	printf("Error");

	}
	
	int getch(void)
	
	{
		
		return (sp>0) ? buf[--sp] : getchar();
		
	}
	

	
	int getword(char *word, int n)
	
	{
		
		int c;
		
		while( isspace(c = getch()) )
			
			;
		
		if( (*word++ = c) == EOF ) /*�������е㲻һ��P119*/
			
			return c;
		
		if( !isalpha(c) ) {
			
			word[0] = '\0';
			
			return c;
			
		}
		
		while( isalnum(*word++ = c =getch()) && --n)
			
			;
		
		ungetch(c);
		
		*word = '\0';
		
		return word[0];
		
	}

	
	int strcmp(char *s, char *t)
	
	{
		
		while( *s == *t ) {
			
			if(*s == '\0')
				
				return 0;
			
			s++;
			
			t++;
			
		}
		
		return *s - *t;
		
	}
	

	
	int binsearch(char *word, struct key *keytab, int n)
	
	{
		
		int low = 0, high = n-1, mid;
		
		while(low <= high) {
			
			mid = (low + high)/2;
			
			if(strcmp(word, keytab[mid].wordstal) > 0)
				
				low = mid + 1;
			
			else if(strcmp(word, keytab[mid].wordstal) < 0)
				
				high = mid - 1;
			
			else
				
				return mid;
			
		}
		
		return -1; /*û����ȵ��ַ�*/
		
	}
	
	void writeword( struct key *keytab )
	
	{
		
		int i = 0;
		
		for(i=0; i<5;i++)
			
			printf("%s\t%d", keytab[i].wordstal, keytab[i].count);
			
	}
