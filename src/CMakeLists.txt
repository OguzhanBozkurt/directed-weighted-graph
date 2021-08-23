add_library(Node
    Node.cpp
)

add_library(Graph
    Graph.cpp
)

add_library(WeightedGraph
    Graph.cpp
    WeightedGraph.cpp
)

target_link_libraries(Graph
    Node
)

target_link_libraries(WeightedGraph
    Node
    Graph
)

target_include_directories(Node
    PUBLIC
    "include"
)

target_include_directories(Graph
    PUBLIC
    "include"
)

target_include_directories(WeightedGraph
    PUBLIC
    "include"
)
