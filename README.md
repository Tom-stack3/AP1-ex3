# AP1 - Ex2
Second assignment in Course "Advanced Programming 1".

## UML Diagram
![image](https://user-images.githubusercontent.com/60852129/131017192-32ef935b-f1b3-4523-8fcf-731d1b662397.png)

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
```c
// Compiling the servers script
g++ Server.cpp Udp.cpp Tcp.cpp Socket.cpp Reader.cpp Writer.cpp Classified.cpp Flower.cpp KNNClassifier.cpp Algorithm.cpp -o ser.out

// Running the TCP server
./ser.out Tcp

// Running the UDP server
./ser.out Udp
```
### Running the Client
```c
// Compiling the Client script
g++ Client.cpp Udp.cpp Tcp.cpp Socket.cpp Flower.cpp Classified.cpp Reader.cpp Writer.cpp -o cl.out

// Running a client
./cl.out
```

Have Fun Classifying!

<sup>*sus*</sup>
