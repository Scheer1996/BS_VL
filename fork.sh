#!/bin/bash

while (TRUE) {
	type_prompt();
	read_command(&command, &params);
	
	
	PIDstatus = fork();
	
	if(PIDstatus < 0) {
		printf("Unable to fork");
		continue;
	}
	
	if(PIDstatus > 0) {
		waitpid(PIDstatus, &status, 0); /*Elternprozess wartet auf Kind */	
	} else {
		execve(command, params, 0);		/* Kind-Programm ausführen */
	}
}