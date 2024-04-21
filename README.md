# CPPND: Program a Concurrent Traffic Simulation

<img src="data/traffic_simulation.gif"/>

This project is a traffic simulation in which vehicles are moving along streets and are crossing intersections. With increasing traffic in the city, traffic lights are needed for road safety. Each intersection is equipped with a traffic light. This project builds a suitable and thread-safe communication protocol between vehicles and intersections to complete the simulation. 

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone the project repository: `git clone https://github.com/pouyasophia/Concurrency.git`

2. Build the project: 
	`mkdir build`
	`cd build`
	`cmake ..`
	`make`

3. Run the resulting executable: `./traffic_simulation`
