# op3-study
1. [ROS中文教程](http://wiki.ros.org/cn/ROS/Tutorials)
2. [op3官网](http://emanual.robotis.com/docs/en/platform/op3/introduction/)
3. [ROS包安装](http://emanual.robotis.com/docs/en/platform/op3/recovery/#installing-robotis-ros-packages)
4. [电机教程](http://emanual.robotis.com/docs/en/dxl/mx/mx-28/)

## Installing additional applications for ROBOTIS ROS Packages
- ROBOTIS-OP3 : libncurses5-dev, v4l-utils:
```
sudo apt install libncurses5-dev v4l-utils
```
- ROBOTIS-ROBOTIS-Optimization : scilab:
```
sudo apt install scilab
```
- ROBOTIS-Utility : madplay, mpg321
```
sudo apt install madplay mpg321
```
- ETC : g++, git
```
sudo apt install g++ git
```

## Installing ROS packages for ROBOTIS-OP3
- humanoid_navigation
```
sudo apt-get install ros-kinetic-map-server
sudo apt-get install ros-kinetic-humanoid-nav-msgs
sudo apt-get install ros-kinetic-nav-msgs
sudo apt-get install ros-kinetic-octomap
sudo apt-get install ros-kinetic-octomap-msgs
sudo apt-get install ros-kinetic-octomap-ros
sudo apt-get install ros-kinetic-octomap-server
```
