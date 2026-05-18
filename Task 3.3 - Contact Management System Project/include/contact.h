#ifndef CONTACT_H
#define CONTACT_H

typedef struct
{
    char name[50];
    char phone[15];
    char email[50];
} Contact;

int contact_init(Contact *contact);
void contact_display(Contact *contact);
int contact_validate(Contact *contact);

#endif /* CONTACT_H */