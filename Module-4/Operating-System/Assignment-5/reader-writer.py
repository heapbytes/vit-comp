import threading
import time

resource_lock = threading.Semaphore(1)
readers_counter = 0
readers_counter_lock = threading.Lock()
resource = "This is a shared resource"

def reader():
    global readers_counter
    with readers_counter_lock:
        readers_counter += 1
        if readers_counter == 1:
            resource_lock.acquire()

    print(f"Reader is reading the resource: {resource}")
    time.sleep(1)

    with readers_counter_lock:
        readers_counter -= 1
        if readers_counter == 0:
            resource_lock.release()

def writer():
    resource_lock.acquire()
    resource = "This is a shared resource, updated by the writer"
    print(f"Writer is writing to the resource: {resource}")
    time.sleep(1)
    resource_lock.release()

readers = [threading.Thread(target=reader) for i in range(2)]
writers = [threading.Thread(target=writer) for i in range(2)]

if __name__ == '__main__':
    for reader in readers:
        reader.start()
    for writer in writers:
        writer.start()

    for reader in readers:
        reader.join()
    for writer in writers:
        writer.join()

