# 功能

该程序的主要功能是判断给定的有向图是否是欧拉图或欧拉路径，如果是则会输出该欧拉图或欧拉路径。输出的形式为一个顶点序列。


# 输入

程序会从两个文件中分别读取关于顶点和边的信息。程序读时采用相对路径来查找文件。包含顶点和边信息的文件应该放在上级目录下的data目录下，即  ../data/relationship.txt  和  ../data/person.txt

输入文件内容的格式:  
可见项目下data文件夹中文件格式


# 编译

在项目目录下新建一个build目录，进入该目录使用cmake工具编译该项目。

命令如下：

```shell
mkdir build
cd build
cmake ..
make 
sudo make install
```

编译后生成的可执行文件存放在build/bin文件夹下。

sudo make install将该可执行文件安装到系统中，可以在build目录下直接运行该可执行文件。
