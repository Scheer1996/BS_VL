/*
 * Fork.c
 *
 *  Created on: 26.06.2017
 *      Author: Philip
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int i;
	int status;
	int pid = fork();

	for (i=0;i<3; i++) {
		if(pid == 0) {
			printf("Hier ist Kind %d\n", i);
		}
	}

}
