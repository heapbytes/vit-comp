#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 3
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (num_of_philosopher + 4) % N
#define RIGHT (num_of_philosopher + 1) % N

int state[N];
int phil[N] = {0, 1, 2};
sem_t mutex;
sem_t S[N];

void test(int num_of_philosopher){
  if (state[num_of_philosopher] == HUNGRY && state[LEFT] != EATING &&
    state[RIGHT] != EATING)
  {
    state[num_of_philosopher] = EATING;
    sleep(2);
    printf("Philosopher %d takes fork %d and %d\n", num_of_philosopher +
           1, LEFT + 1, num_of_philosopher + 1);
    printf("Philosopher %d is Eating\n", num_of_philosopher + 1);
    sem_post(&S[num_of_philosopher]);
  }
}

void take_fork(int num_of_philosopher){
  sem_wait(&mutex);
  state[num_of_philosopher] = HUNGRY;
  printf("Philosopher %d is Hungry\n", num_of_philosopher + 1);
  test(num_of_philosopher);
  sem_post(&mutex);
  sem_wait(&S[num_of_philosopher]);
  sleep(1);
}

void put_fork(int num_of_philosopher){
  sem_wait(&mutex);
  state[num_of_philosopher] = THINKING;
  printf("Philosopher %d putting fork %d and %d down\n", num_of_philosopher
         + 1, LEFT + 1, num_of_philosopher + 1);
  printf("Philosopher %d is thinking\n", num_of_philosopher + 1);
  test(LEFT);
  test(RIGHT);
  sem_post(&mutex);
}

void *philosopher(void *num){
  for(int j=0;j<=2;j++){
      int *i = (int *)num;
      sleep(1);
      take_fork(*i);
      sleep(0);
      put_fork(*i);
    }
}

int main(){
  int i;
  pthread_t thread_id[N];
  sem_init(&mutex, 0, 1);
  for (i = 0; i < N; i++){
    sem_init(&S[i], 0, 0);
  }

  for (i = 0; i < N; i++){
      pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
      printf("Philosopher %d is thinking\n", i + 1);
    }
  for (i = 0; i < N; i++){
      pthread_join(thread_id[i], NULL);
    }
  return 0;
}
