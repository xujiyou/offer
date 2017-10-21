#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
		struct termios term;
		long vdisable;
		if (isatty(STDIN_FILENO) == 0){
				printf("error");
				return 0;	
		}
		if ( (vdisable = fpathconf(STDIN_FILENO, _PC_VDISABLE)) < 0 ){
				printf("error");
				return 0;
		}
		if (tcgetattr(STDIN_FILENO, &term) < 0){
				printf("error");
				return 0;
		}
		term.c_cc[VINTR] = vdisable;
		term.c_cc[VEOF] = 2;
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term), 0){
				printf("error");
				return 0;
		}
}
