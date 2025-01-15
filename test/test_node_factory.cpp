// Copyright (c) 2024, Mitch Adams

#include <gtest/gtest.h>
#include <typeinfo>
#include <memory>
#include "node_factory.h"
#include "nodes_for_testing.h"

using namespace behaviorflow;

class NodeFactoryTest : public ::testing::Test
{
protected:
	NodeFactory factory;
	void SetUp() override
	{
		factory = NodeFactory();
	}
};

TEST_F(NodeFactoryTest, RegisterNodeClass)
{
	factory.registerNodeType<TestNodeSimple>("TestNode");
	auto node = factory.createNodeInstance("TestNode", "TestNodeInstance");
	EXPECT_NE(node, nullptr);
	EXPECT_EQ(typeid(*node), typeid(TestNodeSimple));
	EXPECT_EQ(node->getTypeName(), "TestNode");
	EXPECT_EQ(node->getInstanceName(), "TestNodeInstance");
}

TEST_F(NodeFactoryTest, RegisterNodeClassWithParams)
{
	factory.registerNodeType<TestNodeWithConstructorParams>("TestNodeWithParams", 5, "hello");
	auto node = factory.createNodeInstance("TestNodeWithParams", "TestNodeWithParamsInstance");
	EXPECT_NE(node, nullptr);
	EXPECT_EQ(typeid(*node), typeid(TestNodeWithConstructorParams));
	auto testNode = static_cast<TestNodeWithConstructorParams*>(node.get());
	EXPECT_EQ(testNode->getParam1(), 5);
	EXPECT_EQ(testNode->getParam2(), "hello");
}

TEST_F(NodeFactoryTest, MultipleNodeInstances)
{
	factory.registerNodeType<TestNodeSimple>("TestNode");
	auto node1 = factory.createNodeInstance("TestNode", "TestNodeInstance1");
	auto node2 = factory.createNodeInstance("TestNode", "TestNodeInstance2");
	EXPECT_NE(node1, nullptr);
	EXPECT_NE(node2, nullptr);
	EXPECT_EQ(typeid(*node1), typeid(TestNodeSimple));
	EXPECT_EQ(typeid(*node2), typeid(TestNodeSimple));
}

TEST_F(NodeFactoryTest, UnregisteredNodeTypeName)
{
	EXPECT_EQ(factory.createNodeInstance("TestNode", "TestNodeInstance"), nullptr);
}

TEST_F(NodeFactoryTest, RepeatedNodeTypeNameRegistration)
{
	factory.registerNodeType<TestNodeSimple>("TestNode");
	EXPECT_THROW(factory.registerNodeType<TestNodeSimple>("TestNode"), std::runtime_error);
}

TEST_F(NodeFactoryTest, RepeatedNodeInstanceName)
{
	// todo
	// what do we want to do about this? Maybe this is the graph's responsibility to validate this? 
	// Do we even want to create different objects for different "node instances"?
}
