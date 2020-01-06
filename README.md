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

## Twiddle

The Twiddle algorithm is used to tune the PID components achieving better results towards a smooth drive. This algorithm continuously iterates over each PID component until optimized/suitable values are found.    
