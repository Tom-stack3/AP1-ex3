# AP1 - Ex3
Third assignment in the Course *Advanced Programming 1*, Written by Tommy Zaft and Idan Turkenits.

## Project Structure
### UML Diagram
The UML diagram of the project in a PDF format can be found [here](./UML/black_color_sketch.pdf). There is also a SVG format, which can be found [here](./UML/uml.svg) (better to view it raw).

### Special Parameters
```c
// Server port number
port = 55556

// Buffer size
size = 16384

// Server timeout length in Seconds
timeout = 120
```

## Building and Running
To build both Client and Server:
```shell
git clone https://github.com/Tom-stack3/AP1-ex3.git
cd AP1-ex3
mkdir build
cd build
cmake ..
make
```

### Running the Server
Go to `./build/server` folder.
Inside run the following:
```c
// Running the server
./Server
```
### Running the Client
Go to `./build/client` folder.
Inside run the following:
```c
// Running a client
./Client
```
<br>

**Have Fun Classifying!**

<img src="https://user-images.githubusercontent.com/76645845/136801258-4bf542dc-567e-411b-9192-d87014f20d20.gif" height="250">
