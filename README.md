# AP1 - Ex2
Second assignment in Course "Advanced Programming 1".

## UML Diagram
![image](https://user-images.githubusercontent.com/60852129/130918680-d34cee15-b90f-4fc3-9f38-f027c857dfd0.png)

### Special Parameters
```c
// TCP server port number
port = 54269

// UDP server port number
port = 56942

// Buffer size
size = 1000
```

## Building and Running
To build both Client and Server:
```c
git clone https://github.com/Tom-stack3/AP1-ex2.git
cd AP1-ex2
mkdir build
cd build
cmake ..
make
```

### Running the Servers
go to `./build/server` folder.
inside choose one of the following commands:
```c
// To run the TCP server
./Server Tcp

// To run the UDP server
./Server Udp
```
### Running the Client
go to `./build/client` folder.
```c
// Running a client
./Client
```

Have Fun Classifying!