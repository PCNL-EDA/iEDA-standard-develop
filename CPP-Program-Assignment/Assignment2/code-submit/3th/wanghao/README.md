## Build
To build this project, please run the following command in shell:
```shell
bash build.sh [release/debug] ["binary_install_path"]  # set install path if you need, not necessarily
```
## Run
To run this program, please run the command which `build.sh` told you to run:
```shell
# (... build infomation ...)
# run './build/bin/hello' to execute the program!
./build/bin/hello
```

## Program structure
- Top level (gtest/main)  
  **Gtest** or **main function** executes the given examples.

- Middle level (class Controller)  
  The class **Controller** is able to get data from the outside and pass data to Class GridMap and AstarSolver, then present the result to outside.

- Bottom level (data structure and algorithm)  
  - data structure:  
  A class **GridMap** instance stores a 2D grid map with x,y axes  
  A class **Path** instance stores path in a GridMap  
  - algorithm:  
  The class **AstarSolver** provides Astar algorithm  


寻路问题：
- 坐标, 2D图邻接矩阵  
- 地图（基于上一行） 
- 寻路算法（基于上一行） 
- 前端展示