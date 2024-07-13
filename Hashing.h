#include <stdio.h>
#include <string.h>

// 해싱 이해하기
char FirstRepeatedChar(char* str) {
    int i, len = strlen(str);
    int count[256]; // 부가적인 배열
    
    for (i = 0; i < 256; i++) 
        count[i] = 0;
    for (i = 0; i < len; i++) {
        if (count[str[i]] == 1) {   // str[i]: 아스키 코드를 통해 문자가 숫자로 변환됨
            printf("%c", str[i]);
            break;
        } else {
            count[str[i]]++;
        }
    }
    if (i == len) printf("No Repeated Charaters");
    return 0;
}