#pragma once

#include <map>
#include <string>
#include "Expression.hpp"

using Storage = std::map<std::string, std::unique_ptr<Expression>>;

