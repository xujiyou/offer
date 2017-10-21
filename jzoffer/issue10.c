#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//计算一个数字的二进制表示中1的个数
int count_1(int num){
		int count = 0;
		while (num != 0){
				num = num & (num-1);
				count += 1;
		}
		return count;
}

//计算一个数字二进制表示中0的个数
int count_0(int num){
		int i = 0;
		int zhi = 0;
		while (zhi < num){
				zhi = pow(2,i);
				i++;
		}
		num = num^(zhi-1);	//异或操作，相反则1，zhi-1为全q的值，二进制形式的位数与num的位数相同
		return count_1(num);
}

//求判断一个数字是不是2的整数次方
int is_2(int num){
		if (count_1(num) == 1){
				return 1;
		}
		return 0;
}

//获取两个数的二进制位形式中不同的位的个数，例如1010与1101不同的位为3
//跟据异或的规律，相反则1，所以先求异或，再计算其1的值
int get_diff(int num1, int num2){
		int num = num1^num2;
		return count_1(num);
}

int main(){
		int count = get_diff(10, 13);
		printf(" %d\n", count);
}
