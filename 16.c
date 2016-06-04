/*******************************************************************************
 *  Put a nice big block comment at the top of your code
 * 
 * Filename:
 * Archive:
 * Author:
 * Date:
 * Description:
 * Version:
 * 
 *
 */


// Header file includes
#include <stdio.h>

// Pre-processor directives (before the code is compiled, the preprocessor goes
//  through and eliminates whitespace, and also looks for any instance of a
//  Macro defined and replaces its value.)



//#define MAXSEN 40 // ??????

// Typically, constants are all UPPER CASE and separated by '_' (underscores)
#define MAX_SENT 40     // max number of sentences???
#define ASCII_LIMIT 128     // ASCII Limit??
#define MAX_ALLOWED 10      // Max What allowed?



/*******************************************************************************
 *
 * Function Prototypes
 * 
 */

// longest string length and individual character along with words with lengths using array indices
int Countword(int A[], int n);
// Start to use a convention regarding casing, like use camel case for functions
// int wordCount(int data_in[], int length);

int LargestSent(int C[], int n);
int WordCount(int D[], int n);



int main() {
    
    /*************************************************************
     *  
     * Variable declaration
     * 
     */
    
    // group similarly used variables together!
    int i, j, k, c;
    int word_len, sent_len;
    int blank, words;
    int asciiTAB[ASCII_LIMIT];
    int SentChar[MAX_SENT]; 
    int NumSent[MAX_ALLOWED];
    int WordChar[MAX_SENT];

    
    // Instead of doing the following, try your hand at this function...
    // memset(&SentChar[0], 0, sizeof(SentChar));
    //      Google it's usage!  it comes in handy!
    
    for (i=0;i< (MAX_SENT-1); ++i)
    {
        SentChar[i] = 0;
    }
    
    for (i = 0; i < (ASCII_LIMIT-1); i++) //
    {
        asciiTAB[i] = 0; // Memory Allocation
    } //
    for (i = 0; i < (MAX_ALLOWED-1); i++) //
    {
        NumSent[i] = 0; //
    } //
    for (i = 0; i < (MAX_SENT-1); i++) //
    {
        WordChar[i] = 0; //
    } //

    
    
    c = getchar();
    
    // So...it is a poor idea to mix variables in conditional block of a for-
    //  loop,   I would suggest changing the conditional statement; "c!= EOF",
    // to something that is monitoring the variable you are initializing and 
    //  incrementing.  (the variable, j, is what im referring too)
    for (j = 0; c != EOF; j++) {
        for (i = 0; c != '\n'; i++) // here we do not have to worry about EOF because \n comes before \0 always
        {
            SentChar[i] = c;
            //putchar(c);
            c = getchar();
        }
        putchar(c);
        SentChar[i + 1] = '\n';
        words = WordCount(SentChar, i + 2);
        printf("%dth line has %d words \n", j + 1, words);
        printf("Recent line has %d characters \n", i + 1);
        sent_len = i + 1;
        NumSent[j] = sent_len;
        printf("%d line has %d Characters \n", j + 1, sent_len);
        //	printf("%d line has %d words in it \n", j+1, Countword(SentChar, i+1));
        c = getchar();
    }

    for (i = 0; i < j; i++) {
        printf("%d Line contains %d characters\n\n", i + 1, NumSent[i]);
    }
    printf("Largest sentence has characters = %d \n", LargestSent(NumSent, j + 1));
}

int LargestSent(int C[], int n) {
    int i, max;
    max = C[0];
    for (i = 0; i < n; i++) {
        if (C[i] > max) {
            max = C[i];
        }
    }
    return max;
}



/********************************************************
 *  Function:   Word Count
 * 
 * Description:
 * 
 * @param:
 * 
 * @return:
 * 
 * Author:
 * Date:
 * Version: 
 */
int WordCount(int A[], int n) {
    int i, j, k, l;
    int words[n - 1];

    for (i = 0; i < n - 1; i++) {
        words[i] = 0;
        printf("words value %d at %d \n", words[i], i);
    }
    printf("done"); // Debugging resolved
    for (l = 0; A[j] != '\n' || A[j] != EOF; j++)
        for (i = 0, j = 0; i < n, A[i] != ' ' || A[i] != '\t' || A[i] != '\n'; i++, j++) {
            words[i] = A[j];
        }
    if (i < 1)
        break;
    words[i + 1] = ' ';
    for (k = 0; words[k] != ' '; k++) {
        printf("words are %c \n", words[k]);
    }
    l++;
    return l;
}

