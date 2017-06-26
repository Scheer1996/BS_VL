
#include <stdio.h>
#include <pthread.h>

	pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

void* thread( void* notused ) {
	int tmp = 0;
	while( 1 ) {
		pthread_mutex_lock(&m1);
		pthread_mutex_lock(&m2);
		pthread_mutex_lock(&m3);


		pthread_mutex_unlock(&m3);
		pthread_mutex_unlock(&m2);
		pthread_mutex_unlock(&m1);
	}
	return 0;
}

int main() {
	pthread_create (NULL, NULL, thread, NULL);

	while( 1 ) {
		pthread_mutex_lock(&m1);
		pthread_mutex_lock(&m3);
		pthread_mutex_lock(&m2);


		pthread_mutex_unlock(&m3);
		pthread_mutex_unlock(&m2);
		pthread_mutex_unlock(&m1);
	}
	return 0;
}
