#pragma once

#include <map>
#include <optional>
#include <string>

using Cache = std::map<std::string, std::map<std::string, std::optional<double>>>;
