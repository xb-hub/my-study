# my_study
1. [github教程](https://www.runoob.com/w3cnote/git-guide.html)
2. [apriltag库安装](https://github.com/AprilRobotics/apriltag)
3. [apriltag教程](http://book.openmv.cc/image/apriltag.html)
4. [Opencv安装](https://github.com/xb-hub/OpenCV_demo)


# op3-study
1. [ROS中文教程](http://wiki.ros.org/cn/ROS/Tutorials)
2. [op3官网](http://emanual.robotis.com/docs/en/platform/op3/introduction/)
3. [ROS包下载](http://emanual.robotis.com/docs/en/platform/op3/recovery/#installing-robotis-ros-packages)
4. [电机教程](http://emanual.robotis.com/docs/en/dxl/mx/mx-28/)

# ros-study
1. ros库安装
```
*   sudo apt install ros-kinetic-ros库名
```
2. catkin_make单独编译一个ros包
```
*   catkin_make -DCATKIN_WHITELIST_PACKAGES="需要单独编译的包名"
或  catkin_make --only-pkg-with-deps 需要单独编译的包名
````
3. catkin_make取消单独编译
```
*   catkin_make -DCATKIN_WHITELIST_PACKAGES=""
```

# c++-study
1. 类内部的变量名字最后加上"_"以区分全局变量和局部变量
2. 类方法在源文件中定义必须带作用域
3. 多种状态使用枚举定义，不会产生多余的情况