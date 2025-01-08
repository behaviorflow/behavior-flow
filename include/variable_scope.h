// includes variables and global variables for a given scope, mapped by key



#include <vector>
#include <string>
#include <map>
#include <any>

namespace behaviorflow {

class VariableScope {
  public:
    VariableScope() = default;
    VariableScope(std::map<std::string, std::any> local_vars, std::shared_ptr<std::map<std::string, std::any>> global_vars);

    VariableScope getSubScope(std::vector<std::string> local_var_names);

    <typename T>
    getLocalVariable(std::string var_name) {

    }

    <typename T>
    getGlobalVariable(std::string var_name) {

    }


  private:
    std::map<std::string, std::any> local_vars_;
    std::shared_ptr<std::map<std::string, std::any>> global_vars_;
    

};

} // end namespace behaviorflow