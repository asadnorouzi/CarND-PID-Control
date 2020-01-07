# A Self-Driving Car PID Control Project

## Overview

This project implements methods to calculate optimum values for PID control parameters. The Twiddle algorithm is used to tune the values for all three PID components.

The implementation is tested on a simulator provided by Udacity as part of the Udacity's Self-Driving Car Engineer Nanodegree Program!

There are three main steps to implement a good PID control:
1. Initializing the PID components
2. Updating the values based on the input received from the sensor fusion
3. Calculating the final value

## Discussion

The PID control comprised three components:
- P: This is the Proportional component which in this project attempts to keep the vehicle within the center point of the lane.
- I: This is the Integral component which in this project attempts to control the bias and adjust the error to remain consistent. This component can be seen to be specially useful in curved turns.
- D: This is the Derivative component which in this project attempts to prevent overshooting, thereby, reducing oscillation.

Unfortunately, I was unable to record videos to demonstrate the effects of PID on the car's movement. However, P tries to drive the car within the road and as close to the center point as possible. With only P enabled, the car starts to overshoot the center line and eventually leave the track! The I component controls the bias and helps the car to stay at the center specially at the curves. The D component is very helpful in controling the overshooting effect. If this control is disabled, you could see that the car easily overshoots the center line of the road.

## Twiddle

The Twiddle algorithm is used to tune the PID components achieving better results towards a smooth drive. This algorithm continuously iterates over each PID component until optimized/suitable values are found.

## Choosing the Parameters

This is the boring part where you have play around with the parameters to find some good values to start with. I started with enabling the P only such that it would drive at least a small portion of the track without leaving the track boundaries. Then I enabled D to reduce overshooting and have more smooth turns. Lastly, I enabled the I component to make the car follow the center line. It would also help with curved turns. After initialization, the twiddle algorithm is used to fint tune the initial values.
