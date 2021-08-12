Explanation of algorithm: 
This algorithm is not the A* algorithm. Because I can not prove that the path found by \
  the A* algorithm is the best one, I tried anothor strategy. 
This algorithm is not the Dijkstra algorithm, either. 
The complexity of the Dijkstra algorithm is O(n^2), So I didn't use it. 
I can show that my algorithm is faster than the Dijkstra algorithm in many cases.
My strategy is to find the distance generation by generation.


Step1:definition of around vector of each point.
The around vector of a point consists of points which are white \
    and can jump to the point by one step.


Step2: definition of generations.
The first generation consists of the start point.
The nth generation consists of points which are in the around vector of \
    a point in the (n-1)th generation and not in previous generations.

Step3: assign distance to each points:
1: the distance of start point with start point is ofcouse 0.
2: Suppose we have assigned the distance for each points in the (n-1)th generation.
Next, we need to compute the distance of each point in the nth generation. 
To make the distance small enough, we start from the points which are connected to \
    the point with the minimum distance in the (n-1)th generation.

Step4: search path reversly.
We begin with the end point. We consider the around vector of the end point and \
    choose the point which has the minimum distance in the around vector. 
Let this point be the new end point. 
After that we begin with the new end point and consider it around vector.
We continue to do this procejure untail we find the start point.
There is one special case. Note that the initialization of distance is -1.
If the distance of the end point is -1, it means that it hasn't been reached. 
In this case the path is set to be empty.



How to begin:
If you want to execute the main function:
step1: cd build
step2: ./myexe
The main function will give you the result of the given example.

If you want to execute the google test:
step1: cd gtest
step2: cd gbuild
step3: ./gexe
"gexe" will show you some tests of functions in this project. 