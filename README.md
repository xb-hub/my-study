# op3-study
1. [ROS中文教程](http://wiki.ros.org/cn/ROS/Tutorials)
2. [op3官网](http://emanual.robotis.com/docs/en/platform/op3/introduction/)
3. [ROS包下载](http://emanual.robotis.com/docs/en/platform/op3/recovery/#installing-robotis-ros-packages)
4. [电机教程](http://emanual.robotis.com/docs/en/dxl/mx/mx-28/)
5. [github教程](https://www.runoob.com/w3cnote/git-guide.html)

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

# OpenCV安装
## 安装依赖
* 编辑/etc/apt/source.list，取消屏蔽的src源
* sudo apt-get update
* sudo apt-get build-dep opencv
* sudo apt-get install libeigen3-dev ffmpeg doxygen liblapacke-dev libgoogle-glog-dev libgstreamer1.0-dev libgstreamer0.10-dev libavresample-dev libopenblas-dev libgphoto2-dev libgtk-3-dev libv4l-dev python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev liblapacke-dev libgflags-dev libjpeg-dev libtiff-dev libpng-dev ccache libprotobuf-dev libgoogle-glog-dev libharfbuzz-dev

## 从源码安装opencv4.1.0，并安装opencv_contrib4.1.0贡献包
```
cd ~/libsrc/opencv-4.1.0/
mkdir build
cd build
cmake -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.1.0/modules ..
make -j4 #如果安装了matlab，速度可能会非常慢，大约一小时左右
vim unix-install/opencv.pc #编辑该文件，搜索-lippicv，将其删除
sudo make install
sudo ldconfig #库文件立即生效，不用重启
 
#删除
sudo make uninstall
 
#添加编译参数
-Dxxxxx=ON为依赖该模块
-Dxxxxx=OFF为不编译该模块
如想让videoio支持openni2，可加上-DWITH_OPENNI2=ON参数
cmake -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules -DWITH_OPENNI2=ON ..
关于更多编译参数，查看opencv源码根目录下CMakelist.txt中的[OpenCV cmake options]段
```

## 卸载
```
在build目录下：
* sudo make uninstall
* cd ..
* sudo rm -r build