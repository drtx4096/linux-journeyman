// MUST define for RTLD_NEXT to be defined and work!
#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>

typedef int (*original_puts_function_type)(const char *str);

#if 1
/* Our custom version that will override the libc version: */
int puts(const char *str)
{
/* Load the original puts(): */
original_puts_function_type original_puts;
original_puts = (original_puts_function_type) dlsym(RTLD_NEXT,"puts");
/* Call it twice: */
original_puts(str);
return original_puts(str);
}
#endif

__attribute__((constructor))
void load_message()
{
    printf("doubleputs library was loaded!\n");
}
