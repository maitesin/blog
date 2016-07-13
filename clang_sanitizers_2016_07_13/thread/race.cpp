#include <iostream>
#include <pthread.h>

int GLOBAL;

void * SetGlobalTo2(void * x) {
  GLOBAL = 2;
  return x;
}

void * SetGlobalTo3(void * x) {
  GLOBAL = 3;
  return x;
}

int main()
{
  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, SetGlobalTo2, NULL);
  pthread_create(&thread2, NULL, SetGlobalTo3, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  std::cout << GLOBAL << std::endl;
  return 0;
}
