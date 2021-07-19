#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
	pthread_t id;
	pthread_mutex_t mutex;
} data_proses;

void *proses_sendiri(void *data) {
	data_proses *dt;
	dt = (data_proses*)data;

	printf("Mutex %d Lock %d\n", dt->id, dt->mutex);
	pthread_mutex_lock(&dt->mutex);
	printf("Mutex %d Unlock %d\n", dt->id, dt->mutex);
	pthread_mutex_unlock(&dt->mutex);

	free(data);

	return NULL;
}

void buatPutaran(pthread_mutex_t mutex) {
	data_proses *dt;
	dt = malloc(sizeof(data_proses));
	memset(dt, 0, sizeof(data_proses));

	dt->mutex = mutex;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_create(&dt->id, &attr, proses_sendiri, dt);
	pthread_attr_destroy(&attr);
}

int main() {
	char buffer[64];
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);

	buatPutaran(mutex);
	buatPutaran(mutex);
	buatPutaran(mutex);

	pthread_mutex_lock(&mutex);
	printf("Lock Master Mutex %d\n", mutex);
	gets(buffer);
	printf("Unlock Master Mutex %d\n", mutex);
	pthread_mutex_unlock(&mutex);
	gets(buffer);
	return 0;
}