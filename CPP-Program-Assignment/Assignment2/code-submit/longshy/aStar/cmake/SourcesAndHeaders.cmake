set(sources
    src/astar.cpp
    src/pathsolver.cpp
    src/map2d.cpp
    test/src/tmp_test.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/project/astar.h
    include/project/map2d.h
    include/project/pathsolver.h
)
