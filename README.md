# Chat
## Description
Just a program to study interprocess communication. It will including exercise such as `select function`,`signal handling`,`fifo`,`share memory` and so on.

## Basic Version

Boy and Girl can communication full duplex. And it is all functions. Implement it using `fifo` and `select function`.

### Run
compile it by running `make` in root directory of the project.And then run `./boy` in a session and run `./girl` in another session.

-------

## CatchSignal Version
The boy can catch SIGINIT signal and the girl can catch SIGQUIT signal. And there will be timeout tips both.

## FourWindows Version
+ Boy and Girl communicate with fifo(pipe);Boy and BoyStdOut communicate with shared memory(shmget);Girl and GirlStdOut communicate with message queue. 
+ using signal function to catch SIGINIT (2), and `<Ctrl + C>` in Girl Or Boy is the method to quit four windows together.
+ BoyStdOut is the screen of Boy; And so as the GirlStdOut to the Girl.

>Notes: exit() function will call ~AAA() function only when the object in the same stack with exit(). Using exit() in called function and in member function will not call ~AAA() function.
