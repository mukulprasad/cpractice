/*
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

algorithm:

    
    take first character of substring and compare with characters in mainstring, starting from 0 till N. 
    if a match is found, then 


    while (substring[j] != NULL){
        

*/
#include <stdio.h>
#include <string.h>

int count = 0;

int search_substr( char *main, char*sub, int lm, int ls)
{
    
    int i, j;
    int count = 0;
    int found = 0;

    for (j = 0; j < ls; j++){
        for (i = 0; i < lm; i++) {
            if (main[i] == sub[j]){ // character is found
                found = 1; 
                // add evaluation if we have searched the whole of substring
                // if j == ls -1 then it means we have searched the whole of
                // substring. 
                //  in this case we need not call search_subsr again, and
                //  increment count. 
                //
                if (j == ls -1){
                    count += 1;
                    return (1);
                }else {
                    search_substr (main + i+1, sub+j+1, lm -i, ls -j);
                }
            }
        }
        if (found == 0) {
            return (0);
        }else {
            return (1);
        }
    }
}


int main ()
{
    char *A = "jaishreeram"; 
    char *B = "ram";
    
    int na = strlen(A);
    int nb = strlen(B);    
    int found;

    found = search_substr(A, B, na, nb);

    printf("%d\n", count);
}
    

