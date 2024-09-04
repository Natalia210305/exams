#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 100000

//fuction to find the max common substring from two DNA's
void findMaxCommonSubstring(char *str1, char *str2, int len1, int len2) {
    int maxLength = 0; 
    int endIdx1 = 0;   
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int k = 0;
            while (i + k < len1 && j + k < len2 && str1[i + k] == str2[j + k]) {
                k++;
            }
            if (k > maxLength) {
                maxLength = k;
                endIdx1 = i;
            }
        }
    }
    if (maxLength > 0) {
        //if there is a max common substring, we print it  
        printf("Maximum Common Substring: ");
        for (int i = endIdx1; i < endIdx1 + maxLength; i++) {
            printf("%c", str1[i]);
        }
        printf("\n");
    } else {
        //if there is no max common substring we print the suitable message
        printf("No common substring found.\n");
    }
}

int main(int argc , char *argv[]) {
    if (argc!=3) {
        return 1;
    }
    //we open the necessary files which contain the dna's substrings 
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    if (!file1 || !file2) {
        return 1;
    }
    int sum1=0;
    int sum2=0;
    char c1, c2;
    //we count the size of the content of the files
    while((c1=getc(file1))!=EOF) {
        sum1++;
    }
    fseek(file1, 0, SEEK_SET);
    while((c2=getc(file2)) !=EOF) {
        sum2++;
    }
    fseek(file2, 0, SEEK_SET);
    //we reserve the appropriate memory space
    char *array1 = malloc((sum1+1) * sizeof(char));
    char *array2 = malloc((sum2+1) * sizeof(char));
    size_t bytesRead1 = fread(array1, sizeof(char), sum1, file1);
    //we put at the last table setting '\0'
    array1[bytesRead1] = '\0';
    size_t bytesRead2 = fread(array2, sizeof(char), sum2, file2);
    array2[bytesRead2] = '\0';
    if ((sum1 +1) > max_size && (sum2 +1) > max_size ) {
        return 1;
    }
    //we call the fuction findMaxCommonSubstring to find the max substring
    findMaxCommonSubstring(array1, array2, sum1 + 1, sum2 + 1);
    //we release the memory from the arrays 
    free(array1);
    free(array2);
    //we close the files
    fclose(file1);
    fclose(file2);
    return 0;
}