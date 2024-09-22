set(TESTS
    test_behavior_flow_graph.cpp
)

set(TEST_DEPS
    ${BF_LIBRARY}
)

find_package(GTest REQUIRED)
enable_testing()

add_executable(${PROJECT_NAME}_test ${TESTS})

target_link_libraries(${PROJECT_NAME}_test
    ${TEST_DEPS}
    Threads::Threads
    GTest::gtest
    )

add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)