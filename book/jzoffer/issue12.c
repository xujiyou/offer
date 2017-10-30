#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

/*面试题12：输入整数n，打印1到n，考虑到n是一个大数，所以这里使用字符串来实现这个题目*/


//将str需要进位，递归进位
void add_one(char *str, int n){
		if (n >= 0) {
				if (str[n] == '9'){
						str[n] = '0';
						add_one(str, n-1);
				} else {
						str[n] = str[n] + 1;
				}
		}
}

//将str表示的整数加一
int increment(char *str){
		int result = false;
		size_t len = strlen(str);
		for (size_t i = 0; i < len; i++) {
				if (str[i] != '9') {
						result = true;
						break;
				}
		}
		if (result == true) {
				int last = len -1;
				if (str[last] != '9') {
						str[last] = str[last] + 1;
				} else {
						add_one(str, last);
				}
		}
		return result;
}

//打印str表示的整数，去掉前面的0
void print_number(char *str){
		int begen = false;
		size_t len = strlen(str);
		for (size_t i = 0; i < len; i++) {
				if (!begen) {
						if (str[i] != '0'){
								begen = true;
								i--;
						}
				} else {
						printf("%c", str[i]);
				}
		}
}

void print_to_max(int n){
		char str[n+1];
		memset(str,'0',n);
		str[n] = '\0';
		while (increment(str)) {
				//printf(" %s ",str);
				print_number(str);
				printf(" ");
		}
		printf("\n");
}

/*面试题12扩展：实现两个整数的加法，考虑到大数，这里也使用字符串代表整数，并且要考虑负数问题*/

//将整数转换为字符串，考虑负数
char *int_to_str(int num){
		int n = num;
		int order = 1;
		int position = 1;
		if (num < 0) {
				n = ~num + 1;
		}
		while (true) {
				if (n / order < 10) {
						position++;
						break;
				} 
				order *= 10;
				position++;
		}
		char *str = (char *)malloc(position * sizeof(char));
		memset(str, '0', position);
		str[position - 1] = '\0';
		for (int i = 0; i < position - 1; i++){
				str[i] = n / order + '0';
				n %= order;
				order /= 10;
		}
		if (num < 0){
				char *newStr = (char *)malloc((position + 1) * sizeof(char));
				newStr[0] = '-';
				for(int i = 0; i < position; i++){
						newStr[i+1] = str[i];
				}
				return newStr;
		}
		return str;
}


int add_int(int one, int two){
		char *str1 = int_to_str(one);
		char *str2 = int_to_str(two);

		return 0;
}

int main(){
		print_to_max(1);
		add_int(99,999);
}
