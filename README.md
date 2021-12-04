# bindshell

A little project to dig into socket programming.

## Socket example
```c
   Client               Server
--------------      --------------
|  socket()  |      |  socket()  |
--------------      --------------
      |                   |
      |             --------------
      |             |   bind()   |
      |             --------------
      |                   |
      |             --------------
      |             |  listen()  |
      |             --------------
      |                   |
--------------      --------------
|  connect() |      |  accept()  |
--------------      --------------
      |                   |
--------------      --------------
| Read/write | -->  | Read/write |
|    Data    |  <-- |    Data    |
--------------      --------------
      |                   |
--------------      --------------
|  close()   |      |  close()   |
--------------      --------------
```

## Compile
```c
gcc bindshell.c -o bindshell
```
## Usage
Server
```c
chmod +x bindshell
./bindshell
```
Client
```c
nc -nv 127.0.0.1 9001
```
