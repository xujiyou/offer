#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//书上的方式，不错的方式
void permutation(char *pStr, char *head){
		if (*head == '\0') {
				printf("%s\n", pStr);
		} else {
				for (char *ch = head; *ch != '\0'; ch++) {
						char temp = *ch;
						*ch = *head;
						*head = temp;
						permutation(pStr, head + 1);
						temp = *ch;
						*ch = *head;
						*head = temp;
				}
		}
}

int main(){
		char str[] = "abc";
		permutation(str, str);

}
