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
  Gtest or main function executes the given examples.

- Middle level (class Controller)  
  Class Controller gets data from GraphMatrix class and passes data to Class AstarSolver, and presents the result to outside.

- Bottom level (class GraphMatrix and class AstarSolver)  
  Class GraphMatrix stores Graph Matrix and Class AstarSolver provides Astar algorithm.
