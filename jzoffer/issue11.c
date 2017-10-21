#include <stdio.h>
#include <string.h>
/*
 *实现power函数，求base的exponent次方，问题简单，但要考虑边界及越界值问题，比如次方为负或0。
 *求负数次方时base为0要有除数不能为0的提示。
 *另外实现atoi函数，将字符串转换为数字，要过滤字符，要考虑负数。
 * */


int errno = 0;

double just(double base, int ex){
		if (ex == 1){
				return base;
		} else if (ex == 0){
				return 1;
		}
		double result = just(base, ex >> 1);
		result *= result;
		if ((ex & 0x1) == 1){
				result *= base;
		}
		return result;
}

double Power(double base, int exponent){
		double result = 1.0;
		if (exponent == 0){
				if (base == 0){
					return 0.0;
				}
				return 1.0;
		} else if (exponent > 0){
				//for (int i = 0; i < exponent; i++){
				//		result *= base;
				//}
				result = just(base, exponent);
		} else {
				if (base == 0){
						errno = -1;
				}
				exponent = ~exponent + 1;
				//for (int i = 0; i < exponent; i++){
				//		result *= base;
				//}
				result = just(base, exponent);
				result = 1 / result;				
		}
		return result;
}

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

int main(int argc, char *argv[]){
		double result = Power(strtoint(argv[1]),strtoint(argv[2]));
		if (errno == -1){
				printf("base is not 0\n");
				return 0;
		}
		printf("%f\n", result);
}
