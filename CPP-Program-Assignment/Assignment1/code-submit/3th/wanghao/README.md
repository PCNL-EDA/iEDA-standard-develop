## Build
To build this project, please run the following command in shell:
```shell
bash build.sh ["binary_install_path"]  # set install path if you need, not necessarily
```
## Run
To run this program, please run the command which `build.sh` told you to run:
```shell
# (... build infomation ...)
# run './build/bin/hello' to execute the program!
./build/bin/hello
```

## Program structure
- Top level (main)  
  Main function executes the printing of a Eulerian Path.

- Middle level (class EulerianPath)  
  Class EulerianPath get data from People class and Euler class, and present them to the outside.

- Bottom level (class People and class Euler)  
  Class People stores one's id and name. Class Euler provides Eulerian Path algorithm.
