#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*int main(){
		char str1[] = "hello";
		char *str2 = str1;

		char *str3 = "hello";
		char *str4 = "hello";
		if (str1 == str2){
				printf("=\n");
		} else {
				printf("!=\n");
		}
		if (str3 == str4){
				printf("=\n");
		} else {
				printf("!=\n");
		}
		int i = 0;
		while( str1[i] != '\0' ){
				i++;
		}
		printf("%d\n",i);
		i = 0;
		while( str3[i] != '\0' ){
				i++;
		}
		printf("%d\n",i);
}*/

void str_encode(char *str){
		char newchar[50] = {'0'};
		int i = 0;
		int j = 0;
		while(str[i] != '\0'){
				if (str[i] == ' '){
						newchar[j++] = '%';
						newchar[j++] = '2';		
						newchar[j++] = '0';
				} 	else {
						newchar[j++] = str[i];
				}
				i++;
		}
		memcpy(str, newchar, 50*sizeof(char));
}

void str_encode2(char *str){
		int oldlength = 0;
		int jishu = 0;
		while (str[oldlength] != '\n'){
				if (str[oldlength] == ' '){
						jishu++;
				}
				oldlength++;
		}
		int length = oldlength + jishu * 2;
		for (int i = length,j = oldlength; i >= 0; i--,j--){
				if (str[j] == ' '){
						str[i--] = '0';
						str[i--] = '2';
						str[i] = '%';
				} else {
						str[i] = str[j];
				}
		}
}

int main(int argc, char *argv[]){
		char str[50];
		if (argv[1] != 0){
			memcpy(str,argv[1],50*sizeof(char));
		}
		str_encode(str);
		printf("%s\n",str);
}
