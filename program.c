#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define BILLION 1000000000L

long X = 1000000000L; // 1 second
long T = 0;

void *SAMPLE(void *vargp) {
    struct timespec start, end;
    while (1) {
        clock_gettime(CLOCK_REALTIME, &start);
        T = start.tv_sec * BILLION + start.tv_nsec;
        usleep(X/1000);
    }
}

void *INPUT(void *vargp) {
    long new_X;
    FILE *file;
    while (1) {
        file = fopen("freq.txt", "r");
        if (file) {
            fscanf(file, "%ld", &new_X);
            fclose(file);
            if (new_X != X) {
                X = new_X;
            }
        }
        sleep(1);
    }
}

void *LOGGING(void *vargp) {
    long old_T = 0;
    FILE *file;
    while (1) {
        if (old_T != T) {
            file = fopen("time_and_interval.txt", "a");
            if (file) {
                fprintf(file, "T: %ld, Interval: %ld\n", T, T - old_T);
                fclose(file);
                old_T = T;
            }
        }
        usleep(1000);
    }
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, SAMPLE, NULL);
    pthread_create(&thread_id, NULL, INPUT, NULL);
    pthread_create(&thread_id, NULL, LOGGING, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}

