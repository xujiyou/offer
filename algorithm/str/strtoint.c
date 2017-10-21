#include <stdio.h>
#include <string.h>

int strtoint(char *str){
	int num = 0;
	int fu = 1;
	int begen = 0;
	for(size_t i = 0; i < strlen(str);i++) { //strlen计算字符串的实际长度，不算结尾的\0
			if ( str[i] > 48 && str[i] < 58 ) {
				num = num * 10 + str[i] - '0'; 
				if (begen == 0) {
					begen = 1;
				}
			} else {
				if (begen == 0 && str[i] == '-') {
					fu = -1;
				}
			}
	}
	num = num * fu;
	return(num);
}

int main(){
	char *str = "abc- 146a9 aq";
	int result = strtoint(str);
	printf("result=%d\n", result);
	return(0);
}
