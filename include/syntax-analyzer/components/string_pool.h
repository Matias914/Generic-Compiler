#ifndef GC_STRINGPOOL_H
#define GC_STRINGPOOL_H

#include <string>

namespace SyntaxAnalyzer::StringPool
{
     int create(const std::string& initial);

     std::string* get(int index);

     void append(int index, const std::string& extra);
     void clear();
}

#endif //GC_STRINGPOOL_H