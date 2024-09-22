// Copyright (c) 2024, Mitch Adams

#include <gtest/gtest.h>
#include "behavior_flow_graph.h"

using namespace bf;

class BehaviorFlowGraphTest : public ::testing::Test {
  protected:
    BehaviorFlowGraph bf_graph;
    void SetUp() override {
        bf_graph = BehaviorFlowGraph();
    }  
}

TEST(BehaviorFlowGraphTest, EmptyGraph) {

}

TEST(BehaviorFlowGraphTest, SingleNode) {

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}