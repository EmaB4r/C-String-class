# C-String-class

simple and probably work in progress String library

you can create a string with `string s = string_init();`

and then call methods on it like:
```
string s1=string_init();
string s2=string_init();
s2->fn_append_str(s2, " World");
s1->fn_append_str(s1, "Hello")
  ->fn_append_string(s1, s2)
  ->fn_append_char(s1, '!')
  ->fn_append_int(s1, 15)
  ->fn_print(s1);

s2->fn_delete(s2);
s1->fn_delete(s1);
```
