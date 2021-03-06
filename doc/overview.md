# Programatic Flow

## Using boost::asio

2. Associate a ``work`` object with the service to indicate that the service has work to do.  As long as there is a a ``work`` object associated with the service, it will nto run out of work to do.  Use a ``shared_ptr`` to make sure that we can gracefully remove a ``work`` object from the service.
3. Create a thread pool for working doing work on multiple threads. 

```c++

void WorkerThread( boost::shared_ptr< boost::asio::io_service > io_service )
{
    // Use a mutex to make sure the std buffers don't step on each other
    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id()
          << "] Thread Start" << std::endl;
    global_stream_lock.unlock();

    // Kick off the thread with the run() function to listen
    // for events for the service to process
    io_service->run();
    
    // After the io_service is stopped, the thread will be released
    // and we will write to the console to indicate that the thread
    // has been properly released.
    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id()
              << "] Thread Finish" << std::endl;
    global_stream_lock.unlock();
}


// Just a nothing function to order some work...
void do_something(){
    
    std::cout << "[" << boost::this_thread::get_id() << "] Doing something now." 
              << std::endl;
}

int main(int argc, char *argv[]){
    
    // Wrap the io_service
    boost::shared_ptr< boost::asio::io_service > io_service(
        new boost::asio::io_service);
    
    // Assign work to do
    boost::shared_ptr< boost::asio::io_service::work > work(
        new boost::asio::io_service::work( *io_service ));
    
    // Create the thread group
    boost::thread_group worker_threads;

    for( int x = 0; x < 2; ++x )
    {
       worker_threads.create_thread( 
         boost::bind( &WorkerThread, io_service ));
    }

    // Give the service something to do...
    io_service->post(boost::bind( &do_something ));
    io_service->post(boost::bind( &do_something ));
    io_service->post(boost::bind( &do_something ));
    io_service->post(boost::bind( &do_something ));

    // Kill the pointer and indicate we want to exit when current work is complete
    work.reset();

    // Wait for all threads to finish current batch of work.
    worker_threads.join_all();
}
```

## Using boost::asio in polled device serial system


