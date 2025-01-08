#include "behavior_flow_graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

namespace behaviorflow
{
  /**
   * @brief Interface for parsing a file representing a BehaviorFlowGraph and returning a BehaviorFlowGraph object.
   */
  class GraphFileParserInterface
  {
  public:
    GraphFileParserInterface() = default;
    virtual ~GraphFileParserInterface() = default;
    /**
     * @brief Parse a graph file and return a BehaviorFlowGraph object.
     * The default implementation reads the file into a string using getStringFromFile and then calls parseGraphString. This can be overridden if needed.
     */
    virtual std::unique_ptr<BehaviorFlowGraph> parseGraphFile(std::string graph_file_path);

    /**
     * @brief Parse a string representing a BehaviorFlowGraph and return a BehaviorFlowGraph object.
     */
    virtual std::unique_ptr<BehaviorFlowGraph> parseGraphString(std::string graph) = 0;

  private:
    std::string getStringFromFile(std::string graph_file_path);
  };
} // end namespace behaviorflow