import threading
import time

philosophers = [i for i in range(2)]
forks = [threading.Semaphore(1) for i in range(2)]

def philosopher(id):
    for i in range(4):
        print(f"Philosopher {id} is thinking...")
        time.sleep(1)

        left_fork = id
        right_fork = (id + 1) % 2
        if id % 2 == 0:
            forks[left_fork].acquire()
            forks[right_fork].acquire()
        else:
            forks[right_fork].acquire()
            forks[left_fork].acquire()

        print(f"\nPhilosopher {id} is eating...")
        time.sleep(1)

        forks[left_fork].release()
        forks[right_fork].release()

if __name__ == '__main__':
    philosopher_threads = [threading.Thread(target=philosopher, args=(i,)) for i in philosophers]

    for thread in philosopher_threads:
        thread.start()

    for thread in philosopher_threads:
        thread.join()

