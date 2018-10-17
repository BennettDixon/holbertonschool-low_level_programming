#ifndef _FUNC_POINTERS_
#define _FUNC_POINTERS_
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
#endif /* _FUNC_POINTERS_ */
