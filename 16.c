#include <stdio.h>
#define MAXSEN 40
#define ASCIILIM 128
#define MAXALLOWED 10


// longest string length and individual character along with words with lengths using array indices
int Countword(int A[], int n);
//int CountSentChar(int B[]);
int LargestSent(int C[], int n);

int main()
{	int i, j, k, c, wordlen, sentlen, blank;
	int asciiTAB[ASCIILIM], SentChar[MAXSEN], NumSent[MAXALLOWED] ;

	for(i=0; i < MAXSEN-1; i++)
	{	SentChar[i]=0;
	}
	for(i=0; i < ASCIILIM-1; i++)
	{	asciiTAB[i]=0;
	}
	for(i=0; i<MAXALLOWED-1; i++)
	{	NumSent[i]=0;
	}
	
	c = getchar();
	for(j=0; c!= EOF; j++)
	{	for( i=0; c!= '\n'; i++)                     // here we do not have to worry about EOF because \n comes before \0 always
		{	SentChar[i]=c;
			
			// Words part
			for ( k = 0; c==' ' || c == '\t' ; k++)
			{	blank++;
				c = getchar();
				i++;
				if (blank < 2)		
				{	break;
				}
			}

			putchar(c);
			// end words part
			c = getchar();
		}
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
/*
int Countword(int A[], int n)
{	int i, j;
	
	for(i =0; i<n; i++)
	{	for(j = 0; A[i] != '\n' || A[i] != '\t' || A[i] != ' '; j++)
		{	j+= 1;
		}
	}
return j;
}	

*/
