enable_testing()

find_package(GTest
    REQUIRED
)

# Node Test
add_executable(NodeTest
    NodeTest.cpp    
)

target_link_libraries(NodeTest
    PRIVATE
    Node
    GTest::GTest
    GTest::Main
)

add_test(NodeTest
    NodeTest
)

# Graph Test
add_executable(GraphTest
    GraphTest.cpp    
)

target_link_libraries(GraphTest
    PRIVATE
    Graph
    GTest::GTest
    GTest::Main
)

add_test(GraphTest
    GraphTest
)

# Weighted Graph Test
add_executable(WeightedGraphTest
    WeightedGraphTest.cpp    
)

target_link_libraries(WeightedGraphTest
    PRIVATE
    WeightedGraph
    GTest::GTest
    GTest::Main
)

add_test(WeightedGraphTest
    WeightedGraphTest
)
