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
./build/bin/hello {data_path.txt}
```
# unfinished yet

## Program structure
- Top level (gtest/main)  
  **Gtest** or **main function** executes the given examples.

- Middle level (class PathFindingSolver)  
  The class **PathFindingSolver** is able to get data from the outside and present the result to outside.

- Bottom level (data structure and algorithm)  
  - data structure:  
  A class **AstarData** instance stores a 2D grid map with x,y axes
  - algorithm:  
  The class **AstarSolver** provides Astar algorithm  