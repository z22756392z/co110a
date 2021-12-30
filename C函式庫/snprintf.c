/* int snprintf ( char * s, size_t n, const char * format, ... );
Write formatted output to sized buffer
Composes a string with the same text that would be printed if format was used on printf, but instead of being printed, the content is stored as a C string in the buffer pointed by s (taking n as the maximum buffer capacity to fill).

If the resulting string would be longer than n-1 characters, the remaining characters are discarded and not stored, but counted for the value returned by the function.

A terminating null character is automatically appended after the content written.

After the format parameter, the function expects at least as many additional arguments as needed for format. */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int mysnprintf (char* s, size_t n, const char * format, ... ){
    printf("buffersize: %d\n",sizeof(s));
    char* buffer = s;
    char currentChar;
    int len = 0;
    va_list ap;
    va_start(ap,format);
    while(1){
        //取得當前字元
        currentChar = *(format++);
        //format是否到底
        if(currentChar == '\0'){
            *buffer = '\0';
            len++;
            va_end(ap);
            break;
        }
        //buffer存到剩下一個 用來裝'\0'
        if(n == 1){
            continue;
        }
        //處理%d,%c,%s
        if(currentChar == '%'){
            switch (*(format++))
            {
            case 'd':
            {
                int arg = va_arg(ap,int);
                char* str;
                itoa(arg,str,10);
                //printf("1:%d, 2:%d\n",n,arg);
                while(*str != '\0'){
                    *buffer++ = *str++;
                    len++;
                    if(--n == 1)
                        continue;
                }
                break;
            }
            case 'c':
            {
                int arg = va_arg(ap,int);
                *buffer++ = arg;
                n--;
                len++;
                break;
            }
            case 's':
            {
                char* arg = va_arg(ap,char*);
                while(*arg != '\0'){
                    *buffer++ = *arg++;
                    len++;
                    if(--n == 1)
                        continue;
                }
                break;
            }
            default:
                
                break;
            }
        }else{
            *buffer++ = currentChar;
            len++;
            n--;
        }
    }
    //printf("len: %d\n",len);
    return len;
}

/* snprintf example */
int main ()
{
    char buffer[100];
    int cx, dx;
    printf("size of bufffer: %d\n",sizeof(buffer));
    cx = mysnprintf (buffer, 100, "The half of %d is %d", 60, 60/2 );

    if (cx>=0 && cx<100)      // check returned value

        dx = mysnprintf (buffer+cx-1, 100-cx-1, ", and the half of that is %d.", 60/2/2 );
    
    // puts(buffer);
    printf("cx=%d dx=%d\n", cx, dx);
    return 0;
}

