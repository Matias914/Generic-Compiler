#include "syntax-analyzer/components/StringPool.h"

#include <string>
#include <vector>

namespace SyntaxAnalyzer::StringPool
{
    static std::vector<std::string*> pool;

    // Crear un nuevo string y devolver índice
    int create(const std::string& initial)
    {
        pool.push_back(new std::string(initial));
        return pool.size() - 1;
    }

    // Obtener puntero al string por índice
    std::string* get(const int index)
    {
        if (index < 0 || index >= static_cast<int>(pool.size()))
            return nullptr;
        return pool[index];
    }

    // Append de texto a un string interno
    void append(const int index, const std::string& extra)
    {
        if (index < 0 || index >= static_cast<int>(pool.size()))
            return;
        *pool[index] += extra;
    }

    // Liberar toda la memoria
    void clear()
    {
        for (const auto* s : pool)
            delete s;
        pool.clear();
    }
}
