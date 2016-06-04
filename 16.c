#include <stdio.h>
#define MAXSEN 40
#define ASCIILIM 128
#define MAXALLOWED 10


// longest string length and individual character along with words with lengths using array indices
int Countword(int A[], int n);
int LargestSent(int C[], int n);
int WordCount(int D[], int n);

int main()
{	int i, j, k, c, wordlen, sentlen, blank, words;
	int asciiTAB[ASCIILIM], SentChar[MAXSEN], NumSent[MAXALLOWED], WordChar[MAXSEN] ;

	for(i=0; i < MAXSEN-1; i++)				//
	{	SentChar[i]=0;					//
	}							//
	for(i=0; i < ASCIILIM-1; i++)				//
	{	asciiTAB[i]=0;					// Memory Allocation
	}							//
	for(i=0; i<MAXALLOWED-1; i++)				//
	{	NumSent[i]=0;					//
	}							//
	for(i=0; i<MAXSEN-1; i++)				//
	{	WordChar[i]=0;					//
	}							//
	
	c = getchar();
	for(j=0; c!= EOF; j++)
	{	for( i=0; c!= '\n'; i++)                     // here we do not have to worry about EOF because \n comes before \0 always
		{	SentChar[i]=c;
			//putchar(c);
			c = getchar();
		}
		putchar(c);
		SentChar[i+1] = '\n';
		words = WordCount(SentChar, i+2);
		printf("%dth line has %d words \n",j+1, words);
		printf("Recent line has %d characters \n", i+1);
		sentlen = i+1;
		NumSent[j]=sentlen;
		printf("%d line has %d Characters \n", j+1, sentlen);
	//	printf("%d line has %d words in it \n", j+1, Countword(SentChar, i+1));
	c = getchar();
	}

for(i=0; i<j; i++)
{	printf("%d Line contains %d characters\n\n", i+1, NumSent[i]);
}	
printf("Largest sentence has characters = %d \n", LargestSent(NumSent,j+1));
}			
			


int LargestSent(int C[], int n)
{	int i, max;
	max = C[0];
	for(i = 0; i < n; i++)
	{	
		if (C[i]>max)
		{	max=C[i];
		}
	}
return max;
}

int WordCount(int A[], int n)
{	int i, j, k ,l;
	int words[n-1];

	for(i =0; i<n-1; i++)
	{	words[i] =0;
		printf("words value %d at %d \n", words[i], i);
	}
	printf("done");					// Debugging resolved
	for( l =0; A[j] !='\n' || A[j] != EOF; j++ )
		for(i = 0, j = 0 ; i<n , A[i] != ' ' || A[i] != '\t'|| A[i] != '\n' ; i++, j++)
		{	words[i] = A[j];			
		}
		words[i+1] =' ';
		for(k = 0; words[k] != ' '; k++)
		{	printf("words are %c \n", words[k]);
		}
		l++;
return l;
}	


