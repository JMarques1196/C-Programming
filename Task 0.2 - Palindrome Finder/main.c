#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation functions
#include <ctype.h> // tolower, isalnum


int isPal(const char *s){
    
    // size_t is an unsigned integer type for sizes/indices and is portable across systems.
    size_t i = 0;
    size_t j = strlen(s);   // strlen counts characters before the '\0' terminator.

    // Check if string is empty

    if(j==0){
        return 1;
    }

    j--; // Length to Index conversion

    while(i<j){
        // isalnum() Checks if a string consists of only alphanumeric chars (a-z, A-Z, 0-0)
        // Returns true or false
        while(i<j && !isalnum((unsigned char)s[i])){
            i++;
        }
        while (i < j && !isalnum((unsigned char)s[j])){ 
            j--;
        }
        if (i >= j) break;    


        unsigned char left  = (unsigned char)s[i];
        unsigned char right = (unsigned char)s[j];

        // Normalise case
        left  = (unsigned char)tolower(left);
        right = (unsigned char)tolower(right);

        if (left != right){
            return 0;
        }

        i++;
        j--;


    }
    return 1;
}

int main(void){
    char buff[100];
    printf("Enter a string: \n");

    // Read input
    /*  fgets will read from stdin up to buff size, or untill a new line is encountered
        It then stores it in buff
        fgets returns the pointer to buff is successful or NULL if an error or EOF is reached
    */
    if(!fgets(buff, sizeof buff, stdin)){
        return 1; // return a non-zero code if reading fails
    }
    
    // Remove newline
    size_t len = strlen(buff);

    if (len > 0 && buff[len-1] == '\n'){
        buff[len-1]='\0';
    }

    printf("%s\n", isPal(buff)? "It is a palindrome": "It is not a palindrome");
    printf("%s\n", buff);

    return 0;
}