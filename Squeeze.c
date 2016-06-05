#include <stdio.h>

void Squeeze(char Sone[], char Stwo[]);

int main()
{	unsigned int i,j ;	
	unsigned int c;
	char CharIndex1[30];
	char CharIndex2[30];
	
	for (i =0; i<30; i++)
	{	CharIndex1[i] = 0;
	}
	for (i =0; i<30; i++)
	{	CharIndex2[i] = 0;
	}

	i = 0;
	while( (c = getchar()) != '\n')
	{	putchar(c);
		CharIndex1[i] = c;
		i++;
	}
	CharIndex1[i] ='\n';
	CharIndex1[++i] = '\0';
//	for(i=0 ; CharIndex1[i] != '\n'; i++)	
//		printf("%c\n", CharIndex1[i]);
	printf("\n");
	j = 0;
	while((c=getchar()) != '\n')
	{	putchar(c);
		CharIndex2[j] =c;
		j++;
	}
	CharIndex2[j] = '\n';
	CharIndex2[++j] = '\0';

	printf("strings saved\n");
//	for(j=0; CharIndex2[j] != '\n'; j++)
//	printf("%c\n", CharIndex2[j]);

	Squeeze(CharIndex1, CharIndex2);

}
	
void Squeeze(char Index1[] , char Index2[])
{	int loop1, loop2;
	char FinalStr[30];
	printf("entered the loop \n");
	for(loop1 = 0; loop1<30; loop1++)
	{	FinalStr[loop1] = 0;
	}
	printf("memory allocation completed\n\n");
	for(loop1=0; Index1[loop1] !='\n'; loop1++)
	{	for(loop2=0; Index2[loop2] != '\n'; loop2++)
		{	if (Index2[loop2] == Index1[loop1])
			{	FinalStr[loop2] ='*';	//Index2[loop2]='';
			}
			else
			{	if(FinalStr[loop2] == '*')
				{	;
				}
				else
				{	FinalStr[loop2] = Index2[loop2];
				}
			}
		}
	}
	FinalStr[loop2]='\n';
	FinalStr[++loop2]='\0';
	printf("double for loop are resolved \n");

	for (loop1 =0 ; loop1 < 30; loop1++)
	{	printf("%c", FinalStr[loop1]);
	}	

	printf("\n");
}
