# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## PID Controller

Udacity has provided a simulatior which give us the cross track error (CTE) and the velocity (mph). Goalof the project is to implement a PID Controller in C++ which allow the Car to drive safely around the track.


### P - Controller

Gain "P" controlls the error proportionaly. CTE depends from the distance of the vehicle to the middle of the road. If the coefficient set to high, the vehicle starts to oscillate around the middle lane, because the car will continiously correct hte steering angle and overshoot the middle. If the coefficient is to low, the car reacts to slowly and has issues in the curves.

### I - Controller

"I" Gain controlls the accumulating error. Addition of the "I" part reduces the steady state error. This part is mostly helpful if there is a bias in the system

### D - Controller

The "D" for derivate is the change in CTE from one value to the next. Addition of this term reduces the oscillary effect in the system.Too high coefficient leads to almost constant steering angle changes of large degrees, so the car becomes hardly to move.

### Parameter Tuning

During the lessong "Twiddle" algorithm was presented. In the first step I've applied the algorithm, but I was not realy happy with the driving performace of the vehicle after the modification of the coeeficients.
So in the next step I've tried the manual tuning of the parameters as discribed in the Wikipedia article.

Following steps are described and recommended in Wikipedia and were done by me for the definition of the coefficients:

- Set all gains to zero.
- Increase the P gain until the response to a disturbance is steady oscillation.
- Increase the D gain until the the oscillations go away (i.e. it's critically damped).
- Repeat steps 2 and 3 until increasing the D gain does not stop the oscillations.
- Set P and D to the last stable values.
- Increase the I gain until it brings you to the setpoint with the number of oscillations desired.

I#ve noted that the bias is very low so the implementation of the I" controller is not mandatory. So i've set the $Ki$ to a very low value.

As a outcome I've finished with following coefficients: $ [Kp = , Ki =, Kd =] $
