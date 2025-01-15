// Copyright (c) 2024, Mitch Adams

#ifndef BEHAVIOR_FLOW__NODE_FACTORY_H_
#define BEHAVIOR_FLOW__NODE_FACTORY_H_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "behavior_flow_node.h"

namespace behaviorflow {

class NodeFactory {
 public:
  NodeFactory() = default;

  template <typename T, typename... Args>
  void registerNodeType(std::string node_type_name, Args &&...node_constructor_args) {
    static_assert(std::is_base_of<BehaviorFlowNode, T>::value,
                  "Registered node type classes must derive from BehaviorFlowNode");
    if (node_type_map_.find(node_type_name) != node_type_map_.end()) {
      throw std::runtime_error("A node type with name '" + node_type_name + "' is already registered.");
    }
    node_type_map_[node_type_name] =
        [&](std::string node_type_name,
            std::string node_instance_name) -> std::unique_ptr<BehaviorFlowNode> {
      auto node = std::make_unique<T>(std::forward<Args>(node_constructor_args)...);
      node->init(node_type_name, node_instance_name);
      return std::move(node);
    };
  }

  std::unique_ptr<BehaviorFlowNode> createNodeInstance(std::string node_type_name,
                                                       std::string node_instance_name);

 private:
  std::unordered_map<std::string,
                     std::function<std::unique_ptr<BehaviorFlowNode>(std::string, std::string)>>
      node_type_map_;
};

}  // end namespace behaviorflow

#endif  // BEHAVIOR_FLOW__NODE_FACTORY_H_