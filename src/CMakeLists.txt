add_library(Node
    Node.cpp
)

add_library(WeightedGraph
    Graph.cpp
    WeightedGraph.cpp
)

target_link_libraries(WeightedGraph
    Node
)

target_include_directories(Node
    PUBLIC
    "include"
)

target_include_directories(WeightedGraph
    PUBLIC
    "include"
)

add_executable(test
    test.cpp
)

target_link_libraries(test
    PRIVATE
    Node
    WeightedGraph
)