#include <optional>
#include <charconv>
#include <string>

int Fibo(int n)
{
    if (n <= 1)
        return n;
    else
        return Fibo(n - 1) + Fibo(n - 2);
}

std::optional<double> ConvertStringToDouble(std::string_view token)
{
    double d;
    auto [ptr, ec] = std::from_chars(token.data(), token.data() + token.size(), d);
    if (ec == std::errc{})
        return d;
    return std::nullopt;
    // try d = stod(num);
    // catch(const std::exception& e) return nullopt;
    // return d;
}


