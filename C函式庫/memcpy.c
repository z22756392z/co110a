//C庫函數 void *memcpy(void *str1, const void *str2, size_t n) 拷貝n個字符從存儲區str2中內存區域到str1。
#include <stdio.h>
#include <string.h>
void *memcpy(void *strl, const void *str2, unsigned int n){
    char* dest = (char*)strl;
    const char* src = (const char*)str2;
    
    if(dest != NULL && src != NULL){
        while(n--){
            *(dest++) = *(src++);
        }
    }
} 

int main(){
    const char src[50] = "Hello world";
    char dest[50];

    printf("Before memcpy dest = %s", dest);
    memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s", dest);
    return 0;
}