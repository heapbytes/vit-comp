import threading
import time
import random

queue = []
queue_max_size = 10
queue_mutex = threading.Semaphore(1)
queue_not_empty = threading.Semaphore(0)
queue_not_full = threading.Semaphore(queue_max_size)

def producer(id):
    for i in range(4):
        item = random.randint(1, 100)
        queue_not_full.acquire()
        queue_mutex.acquire()
        queue.append(item)
        queue_mutex.release()
        queue_not_empty.release()
        print(f"Producer {id} added item {item}. Queue size: {len(queue)}")
        time.sleep(1)

def consumer(id):
    for i in range(4):
        queue_not_empty.acquire()
        queue_mutex.acquire()
        item = queue.pop(0)
        queue_mutex.release()
        queue_not_full.release()
        print(f"Consumer {id} consumed item {item}. Queue size: {len(queue)} \n")
        time.sleep(1)


if __name__ == '__main__':
    producer1 = threading.Thread(target=producer, args=(1,))
    producer2 = threading.Thread(target=producer, args=(2,))
    consumer1 = threading.Thread(target=consumer, args=(1,))
    consumer2 = threading.Thread(target=consumer, args=(2,))

    producer1.start()
    producer2.start()
    consumer1.start()
    consumer2.start()

    producer1.join()
    producer2.join()
    consumer1.join()
    consumer2.join()

