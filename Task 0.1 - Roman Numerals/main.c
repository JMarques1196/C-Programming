#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation functions

int romanValue(char c) { // function to determine the value of a given char.
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;

    }
} 

 int validOperation(char actual, char next){
    if(actual == 'I' && (next =='V' || next=='X')) return 1;
    if(actual == 'X' && (next =='L' || next=='C')) return 1;
    if(actual == 'C' && (next =='D' || next=='M')) return 1;
    return 0;
} 


int repeat(char c) {
    return (c == 'I' || c == 'X' || c == 'C' || c == 'M');
}

/* NOTES 
    "/" - Escape sequence. When using "\", the next character won't appear in the string and has a special meaning, like new line, tab, etc..
    "%" - Format Specifier. Specifies the type of data to print. 
        "%c" - A single char
        "%d" - Int
        "%f" - Float
        "%lf" - Long Float
        "s" - String

        We can also add safety for the number of read characters, by adding a specific number, like "%99s"
        
*/

int main(void) {
    char s[100];

    printf("Insert a value in roman numerals:");
    scanf("%99s",s);
    // Validate the string / Roman numerals
    int repeatCounter = 1;
    for(int i = 0; i<strlen(s); i++){
        int actual = romanValue(s[i]); // Check if the char is a valid roman numeral and get its value
        if(actual == -1){
            printf("Invalid symbol: %c\n", s[i]);
            return 1;
        }


    if (i > 0 && s[i] == s[i - 1]) {
        repeatCounter++;
            // V, L e D não podem repetir
        if (s[i] == 'V' || s[i] == 'L' || s[i] == 'D') {
                printf("ErroR: simbol '%c' may not repeat(sequence '%c%c')\n",
                       s[i], s[i - 1], s[i]);
                return 1;
        }

            // I, X, C, M no máximo 3 vezes
        if (repeat(s[i]) && repeatCounter > 3) {
                // Ex.: 'IIII', 'XXXX', 'CCCC', 'MMMM'
                printf("Error: too many repetitions of symbol '%c'\n", s[i]);
                return 1;
            }
        } else {
            // reset counter
             repeatCounter = 1;
        
        }
        if(i < strlen(s)-1){
            int next = romanValue(s[i+1]);
            if(next == -1){
                printf("Invalid symbol: %c\n", s[i+1]);
                return 1;
            }
            if(actual < next && !validOperation(s[i], s[i+1])){
                printf("Invalid operation: %c cannot be subtracted from %c\n", s[i], s[i+1]);
                return 1;
            }
        }
    }
    // If we reach this point, all symbols are valid. Convert the roman numeral to an integer
    int total = 0;
    for(int i = 0; i < strlen(s); i++){
        int actual = romanValue(s[i]);
        if(i < strlen(s)-1){
            int next = romanValue(s[i+1]);
            if(actual < next){
                total += next - actual;
                i++; // Skip the next character since it's already been processed
            } else {
                total += actual;
            }
        } else {
            total += actual;
        }
    }

    printf("The integer value is: %d\n", total);
    return 0;  // return 0 → terminou com sucesso

}