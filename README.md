# Unscented Kalman Filter
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)


This repository contains my solution to the Udacity Self-Driving Car NanoDegree Unscented Kalman Filter Project.

The repository contains the following notable files:

* [WRITEUP.md](WRITEUP.md) Project writeup report with additional details on my implementation.
* `src/ukf.cpp` : Implementation of sensor fusion for Lidar and Radar sensors using Unscented Kalman Filter
* `src/tools.cpp` : utility class containing methods conversions between polar and cartesian coordinates and RMSE on data samples
* `src/main.cpp` : file contains main function and interfaces with simulator websocket in for data in and output  
* [images/carnd-ukf.mp4](images/carnd-ukf.mp4) video file of the terminal window and simulator output on dataset 1
* [images/UKF_Dataset1_RMSE_final.png](images/UKF_Dataset1_RMSE_final.png) image showing final RMSE values of the UKF after running through dataset 1

## Compilation and Run Instructions

From the project root directory

1. Create a build directory: `mkdir build`
2. `cd build`
3. Run cmake generator: `cmake ..`
4. Run the executable with `./ExtendedKF`
