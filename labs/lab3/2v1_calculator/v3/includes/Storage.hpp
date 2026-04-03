#pragma once

#include <map>
#include <memory>
#include <string>
#include "Expression.hpp"

using Storage = std::map<std::string, std::shared_ptr<Expression>>;
