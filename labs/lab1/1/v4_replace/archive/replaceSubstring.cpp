string replaceSubstring(const string& pattern, const string& filler, const string& token)
{
    string result = "";
    result.reserve(token.length());

    string buf = "";
    buf.reserve(pattern.length());

    //код если паттерн и филлер = "" and if only filler == ""

    for (size_t i = 0; i < token.length();)
    {
        if (pattern[0] == token[i])
        {
            buf += token[i];
            ++i;
            for (size_t j = 1; j < pattern.length(); ++j)
            {
                if (pattern[j] != token[i]) 
                {
                    result += buf;
                    break;
                }
                buf += token[i];
                ++i;
            }
            if (buf.length() == pattern.length()) 
                result += filler;
            buf = "";
        }
        else 
        {
            result += token[i]; 
            ++i;
        }    
    }
    return result;
}
