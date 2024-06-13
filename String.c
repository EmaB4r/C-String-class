//
// Created by emanuele on 13/06/24.
//

#include "String.h"
#include <stdlib.h>
#include <stdio.h>



typedef struct private_string{
    char* str;
    unsigned int str_len;
}*_private_string;


int mystrlen(char* s){
    int i=0;
    for(i; *s!='\0'; i++, s++);
    return i;
}

void mystrcpy(char*dest, char*source){
    while(*source!='\0'){
        *dest=*source;
        dest++;
        source++;
    }
}

void mystrcat(char*dest, char*source, unsigned int dest_end_len){
    int src_len= mystrlen(source);
    int starting_point=dest_end_len-src_len;
    for(int i=0; i<src_len; i++){
        dest[starting_point+i]=source[i];
    }
}

string string_insert(string self, char* str){
    self->privates->str_len+=mystrlen(str);
    if(self->privates->str==NULL){
        self->privates->str=malloc(self->privates->str_len);
        mystrcpy(self->privates->str, str);
    }
    else{
        self->privates->str=realloc(self->privates->str, self->privates->str_len);
        mystrcat(self->privates->str, str, self->privates->str_len);
    }
    return self;
}

string string_insert_int(string self, long long int i){
    string number=string_init();
    char c;
    while(i!=0){
        c=i%10+'0';
        number->fn_append_char(number, c);
        i=i/10;
    }
    number->fn_flip(number);
    self->fn_append_string(self, number);
    number->fn_delete(number);
    return self;
}

string string_insert_char(string self, char c){
    self->privates->str_len+=1;
    if(self->privates->str==NULL){
        self->privates->str=malloc(self->privates->str_len);
    }
    else{
        self->privates->str=realloc(self->privates->str, self->privates->str_len);
    }
    self->privates->str[self->privates->str_len-1]=c;
    return self;
}


string string_print(string self){
    for(int i=0; i< self->privates->str_len; i++){
        printf("%c", self->privates->str[i]);
    }
    return self;
}

unsigned int string_len(string self){
    return self->privates->str_len;
}

string string_merge(string self, string other){
    if(other->fn_len(other)!=0){
        int start=self->privates->str_len;
        self->privates->str_len+=other->privates->str_len;
        if(self->privates->str==NULL){
            self->privates->str=malloc(self->privates->str_len);
        }
        else{
            self->privates->str=realloc(self->privates->str, self->privates->str_len);
        }
        for(int i=0; i<other->privates->str_len; i++){
            self->privates->str[start+i]=other->privates->str[i];
        }
    }
    return self;
}

string string_flip(string self){
    int l=0, r=self->privates->str_len-1;
    char tmp;
    while(l<r){
        tmp=self->privates->str[l];
        self->privates->str[l]=self->privates->str[r];
        self->privates->str[r]=tmp;
        l++;
        r--;
    }
    return self;
}

void string_delete(string self){
    free(self->privates->str);
    free(self->privates);
    free(self);
}

string string_init(){
    string s=malloc(sizeof(*s));
    s->privates=malloc(sizeof(struct private_string));
    s->privates->str_len=0;
    s->fn_append_str=string_insert;
    s->fn_append_int=string_insert_int;
    s->fn_append_char=string_insert_char;
    s->fn_print=string_print;
    s->fn_len=string_len;
    s->fn_append_string=string_merge;
    s->fn_flip=string_flip;
    s->fn_delete=string_delete;
    return s;
}