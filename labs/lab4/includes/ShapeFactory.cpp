#include <charconv>
#include "ShapeFactory.hpp"
#include "CCircle.hpp"
#include "CTriangle.hpp"
#include "CRectangle.hpp"
#include "CLineSegment.hpp"

// #include <iostream>

bool IsValidNumber(const std::string& input, double& num)
{
    if (input.empty()) return false;
    auto [ptr, err] = std::from_chars(input.data(), input.data() + input.size(), num);
    return err == std::errc{};// && ptr == input.data() + input.size();
}

bool IsValidColor(const std::string& input, uint32_t& out)
{
    if (input.empty()) return false;
    auto [ptr, err] = std::from_chars(input.data(), input.data() + input.size(), out, 16);
    return err == std::errc{} && ptr == input.data() + input.size();
}

bool IsValidCircleArguments(const std::vector<std::string>& args, double& x, double& y, double& r,
    uint32_t& oc, uint32_t& sc)
{
    if (args.size() != 6) return false;
    if (IsValidNumber(args[1], x) &&
        IsValidNumber(args[2], y) &&    
        IsValidNumber(args[3], r) && r > 0 &&   
        IsValidColor(args[4], oc) && oc <= 0x00ff'ffff &&  
        IsValidColor(args[5], sc) && sc <= 0x00ff'ffff)
    {
        return true;
    }
    return false;
}

bool IsValidTriangleArguments(const std::vector<std::string>& args, double& x1, double& y1, double& x2, double& y2, double& x3, double& y3, uint32_t& oc, uint32_t& sc)
{
    if (args.size() != 9) return false;
    if (IsValidNumber(args[1], x1) &&
        IsValidNumber(args[2], y1) &&    
        IsValidNumber(args[3], x2) &&    
        IsValidNumber(args[4], y2) &&    
        IsValidNumber(args[5], x3) &&    
        IsValidNumber(args[6], y3) &&    
        IsValidColor(args[7], oc) && oc <= 0x00ff'ffff &&  
        IsValidColor(args[8], sc) && sc <= 0x00ff'ffff)
    {
        return true;
    }
    return false;
}

bool IsValidRectangleArguments(const std::vector<std::string>& args, double& l, double& t, double& w, double& h, uint32_t& oc, uint32_t& sc)
{
    if (args.size() != 7) return false;
    if (IsValidNumber(args[1], l) &&
        IsValidNumber(args[2], t) &&    
        IsValidNumber(args[3], w) && w > 0 &&
        IsValidNumber(args[4], h) && h > 0 &&
        IsValidColor(args[5], oc) && oc <= 0x00ff'ffff &&  
        IsValidColor(args[6], sc) && sc <= 0x00ff'ffff)
    {
        return true;
    }
    return false;
}

bool IsValidLineSegmentArguments(const std::vector<std::string>& args, double& sx, double& sy, double& ex, double& ey, uint32_t& oc)
{
    if (args.size() != 6) return false;
    if (IsValidNumber(args[1], sx) &&
        IsValidNumber(args[2], sy) &&
        IsValidNumber(args[3], ex) &&
        IsValidNumber(args[4], ey) &&
        IsValidColor(args[5], oc) && oc <= 0x00ff'ffff)
    {
        return true;
    }
    return false;
}

std::unique_ptr<IShape> ShapeFactory::CreateShape(const std::vector<std::string>& args)
{
    uint32_t oc = 0, sc = 0;
    if (args[0] == "circle")
    {
        double x{}, y{}, r{};
        if (IsValidCircleArguments(args, x, y, r, oc, sc))
        {
            return std::make_unique<CCircle>(x, y, r, oc, sc);
        }
    }
    else if (args[0] == "triangle")
    {
        double x1{}, y1{}, x2{}, y2{}, x3{}, y3{};
        if (IsValidTriangleArguments(args, x1, y1, x2, y2, x3, y3, oc, sc))
            return std::make_unique<CTriangle>(x1, y1, x2, y2, x3, y3, oc, sc);
    }
    else if (args[0] == "rectangle")
    {
        double left{}, top{}, w{}, h{};
        if (IsValidRectangleArguments(args, left, top, w, h, oc, sc))
            return std::make_unique<CRectangle>(left, top, w, h, oc, sc);
    }
    else if (args[0] == "line")
    {
        double startX{}, startY{}, endX{}, endY{};
        if (IsValidLineSegmentArguments(args, startX, startY, endX, endY, oc))
            return std::make_unique<CLineSegment>(startX, startY, endX, endY, oc);
    }
    return nullptr;
}
