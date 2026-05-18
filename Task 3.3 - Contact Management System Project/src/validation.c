#include "../include/validation.h"
#include <stddef.h>
#include <string.h>

int validate_phone(char *phone)
{
    // Verify if [0] is a + and if the rest are digits
    if (phone == NULL)
        return 0; // Invalid if null pointer
    if (phone[0] != '+' && (phone[0] < '0' || phone[0] > '9'))
        return 0; // Invalid if it doesn't start with + or a digit
    for (int i = 1; phone[i] != '\0'; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            return 0; // Invalid if it contains non-digit characters
    }
    return 1; // Valid phone number
}

int validate_email(char *email)
{
    if (email == NULL)
        return 0; // Invalid if null pointer

    char *at = strchr(email, '@');
    if (at == NULL || at == email) // at is a pointer and email is a pointer.
                                   // When we compare them we are comparing their addresses, not their contents. If at is NULL, it means that the '@' character was not found in the email string. If at is equal to email, it means that the '@' character is the first character in the email string, which is also invalid.
        return 0;                  // Invalid if no '@' or if '@' is the first character

    char *dot = strchr(at + 1, '.');                        // Look for a dot after the '@' character, else it can find a dot in the username part and consider it valid
    if (dot == NULL || dot == at + 1 || *(dot + 1) == '\0') // dot needs to be at least 2 characters after the '@'
        return 0;

    return 1; // Valid email
}