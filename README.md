# Chat
---
## Description
Just a program to study interprocess communication. It will including exercise such as `select function`,`signal handling`,`fifo`,`share memory` and so on.

---------

## Basic Version

Boy and Girl can communication full duplex. And it is all functions. Implement it using `fifo` and `select function`.

### Run

compile it by running `make` in root directory of the project.And then run `./boy` in a session and run `./girl` in another session.


-------

## CatchSignal Version
The boy can catch SIGINIT signal and the girl can catch SIGQUIT signal. And there will be timeout tips both.

