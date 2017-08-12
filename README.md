# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 





## Implementation:-

PID controller consists of below three parameters
1) proportional gain (Kp)
2) integral gain (Ki)
3) derivative gain (Kd)


I started with manual tuning and with first parameter Kp. Idea was to increase Kp in such way that it will induce continuos Car oscillations. 
Once we see oscillations, I focused on tuning parameter Kd to lower down oscillations. After doing this Car at least strarted running straight but I noticed increase in error 
as it  travelled more time steps. This effect points to the role of Ki. Ki controls accumulation of error for long time and hence it's role increases as car passes more disctance. 
Hence to supress dominant effect of accumulated error we have to  set it to sufficiently large value than other two parameters. I tried multiple values and it worked well for below three final values. 
[.15 , .0001 , 0.8] 


I tried implementing twiddle code but could not complete it succesfully so decided to do manual tuning. I intialised each parameter value to 0.5 at start and tried to change it by +-0.05 until I gain desired result. I also studied resuls by fellow students to get tips of manual tuning. 
 
## Reflection:-

## Initial Values:

## P-Value

The proportaional gain is directly porportional to the cross track error and has a tendancy to induce an oscillating effect near the reference line.  I observed same while tuning it's value.  

## I-Value

The I-Value points to accumulated CTE errors the steering angle. It is simply the sum of all the previous values which are publised approx every 0.1s, the I-value is expected to be ten times smaller than the P-value, with an order of magnitude of 0.01.

## D-Value

The D-Value points to the conversion from the derivative CTE errors to the steering angle. As the derivataive CTE error is approximated by the difference between the last two values which are handed with a difference of approx. 0.1s, the D-value is expected to be ten times bigger than the P-value, with an order of magnitude of 1.  
