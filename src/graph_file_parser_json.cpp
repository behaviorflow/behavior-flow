#include "graph_file_parser_json.h"

namespace behaviorflow {

std::unique_ptr<BehaviorFlowGraph> GraphFileParserJson::parseGraphString(std::string graph) {
  return std::make_unique<BehaviorFlowGraph>();
}

}  // namespace behaviorflow
