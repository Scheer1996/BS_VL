/*
 * Mutex.c
 *
 *  Created on: 26.06.2017
 *      Author: Philip
 */
#include <stdio.h>
#include <pthread.h>

	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	int count = 0;

void* thread1( void* notused ) {
	int tmp = 0;
	while( 1 ) {
		/* Begin critical section */
		pthread_mutex_lock( &mutex );
		tmp = count++;
		pthread_mutex_unlock( &mutex );
		/* End critical section */
		printf( "Count is %d\n", tmp );
		sleep( 1 );
	}
	return 0;
}

void* thread2( void* notused ) {
	int tmp = 0;
	while( 1 ) {
		/* Begin critical section */
		pthread_mutex_lock( &mutex );
		tmp = count--;
		pthread_mutex_unlock( &mutex );
		/* End critical section */
		printf( "** Count is %d\n", tmp );
		sleep( 2 );
	}
	return 0;
}

int main() {
	pthread_t dummy;
	pthread_create (&dummy, NULL, thread1, NULL);
	pthread_create (&dummy, NULL, thread2, NULL);

	sleep(60);
	return 0;
}
