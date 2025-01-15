// Copyright (c) 2024, Mitch Adams

#ifndef BEHAVIOR_FLOW__GRAPH_FILE_PARSER_H_
#define BEHAVIOR_FLOW__GRAPH_FILE_PARSER_H_

#include "graph_file_parser_interface.h"
#include <memory>

namespace behaviorflow
{
  class GraphFileParserJson : public GraphFileParserInterface
  {
  public:
    GraphFileParserJson() = default;
    std::unique_ptr<BehaviorFlowGraph> parseGraphString(std::string graph) override;
  };
} // end namespace behaviorflow

#endif  // BEHAVIOR_FLOW__GRAPH_FILE_PARSER_H_