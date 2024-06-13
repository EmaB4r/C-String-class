#ifndef MYSTRING_H
#define MYSTRING_H

typedef struct private_string *_private_string;
typedef struct string_s *string;

typedef struct string_s{
    _private_string privates;

    /*
     INPUT: string self, char* str
     OUTPUT: string self
     function that appends to a string object a str
     */
    string (*fn_append_str)(string self, char* str);

    /*
     INPUT: string self, string other
     OUTPUT: string self
     function that appends to a string object another string object
     */
    string (*fn_append_string)(string self, string other);

    /*
     INPUT: string self, long long int i
     OUTPUT: string self
     function that appends to a string object an integer
     */
    string (*fn_append_int)(string self, long long int i);

    /*
     INPUT: string self, double f
     OUTPUT: string self
     function that appends to a string object a double
     */
    string (*fn_append_float)(string self, double f);

    /*
     INPUT: string self, char c
     OUTPUT: string self
     function that appends to a string object a char
     */
    string (*fn_append_char)(string self, char c);

    /*
     INPUT: string self
     OUTPUT: string self
     function that returns the contained string lenght
     */
    unsigned int (*fn_len)(string self);

    /*
     INPUT: string self
     OUTPUT: string self
     function that flips the contained string
     */
    string (*fn_flip)(string self);

    /*
     INPUT: string self
     OUTPUT: string self
     function that prints the contained string as a sequence of chars
     */
    string (*fn_print)(string self);

    /*
     INPUT: string self
     OUTPUT: NONE
     function that deletes a string object
     */
    void (*fn_delete)(string self);
}*string;


string string_init();

#endif