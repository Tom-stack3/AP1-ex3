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

### Running the Servers
go to `./build/server` folder.
inside choose one of the following commands:
```c
// Compiling the servers script
g++ Server.cpp Udp.cpp Tcp.cpp Socket.cpp Reader.cpp Writer.cpp Classified.cpp Flower.cpp KNNClassifier.cpp Algorithm.cpp -o ser.out

// Running the TCP server
./ser.out Tcp

// To run the UDP server
./Server Udp
```
### Running the Client
```c
// Compiling the Client script
g++ Client.cpp Udp.cpp Tcp.cpp Socket.cpp Flower.cpp Classified.cpp Reader.cpp Writer.cpp -o cl.out

// Running a client
./cl.out
```

Have Fun Classifying!