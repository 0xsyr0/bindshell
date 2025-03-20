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

```console
$ gcc bindshell.c -o bindshell
```

## Usage

Server

```console
$ chmod +x bindshell
$ ./bindshell
```

Client

```console
$ nc -nv 127.0.0.1 9001
```
