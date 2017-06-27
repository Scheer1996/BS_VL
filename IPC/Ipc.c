#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define PUFFER_SIZE 10

	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	sem_t b;
	sem_t f;


void* erzeuger( void* notused ) {
	while(1) {
		sem_wait(&f);				// f - 1  sonst warten
		pthread_mutex_lock(&mutex);
		printf("Erzeuger:    Element hinzugefügt\n");
		pthread_mutex_unlock(&mutex);
		sem_post(&b);				// b + 1

		int b_val;
		int f_val;
		sem_getvalue(&b, &b_val);
		sem_getvalue(&f, &f_val);
		printf("Erzeuger:    B: %d, F: %d \n", b_val, f_val);

		sleep(1);
	}
}


void* verbraucher( void* notused ) {
	while(1) {
		sem_wait(&b);				// b - 1 sonst warten
		sem_wait(&b);				// b - 1 sonst warten
		sem_wait(&b);				// b - 1 sonst warten
		pthread_mutex_lock(&mutex);
		printf("Verbraucher: Element entfernt \n");
		pthread_mutex_unlock(&mutex);
		sem_post(&f);				// f + 1
		sem_post(&f);				// f + 1
		sem_post(&f);				// f + 1
		sleep(1);
	}
}

/*
void* verbraucher2( void* notused ) {
	while(1) {
		sem_wait(&b);				// b - 1 sonst warten
		pthread_mutex_lock(&mutex);
		printf("Verbraucher: Element entfernt \n");
		pthread_mutex_unlock(&mutex);
		sem_post(&f);				// f + 1
		sleep(2);
	}
}*/

int main() {
	pthread_mutex_init(&mutex, NULL);
	sem_init(&f, 0, PUFFER_SIZE);
	sem_init(&b, 0, 0);
	pthread_t dummy;
	pthread_create(&dummy, NULL, erzeuger, NULL);
	pthread_create(&dummy, NULL, verbraucher, NULL);

	sleep(60);
	return 0;
}
