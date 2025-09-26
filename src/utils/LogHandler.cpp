#include "utils/LogHandler.h"
#include "utils/LiteralTable.h"
#include "utils/SymbolTable.h"
#include "utils/resources/string_builder_dispatcher.h"

extern SymbolTable SYMBOL_TABLE;
extern LiteralTable LITERAL_TABLE;

void LogHandler::add(const Log& log)
{
    this->logs.push_back(log);
}

bool LogHandler::generateReport() const
{
    std::ofstream archivo_salida(output);
    if (!archivo_salida.is_open()) return false;
    std::string mssg = "";
    using namespace StringBuilderDispatcher;
    bool first = true;
    for (const auto& [type, code, line, content] : this->logs) {
        if (!first) mssg.append("\n");
        first = false;
        const StringBuilder builder = getStringBuilder(type, code);
        mssg.append("Line ").append(std::to_string(line));
        mssg.append("\t\t- ").append(builder(content));
    }
    archivo_salida << mssg << "\n\n";
    archivo_salida << SYMBOL_TABLE.toString() << "\n\n";
    archivo_salida << LITERAL_TABLE.toString() << "\n\n";
    archivo_salida.close();
    return true;
}
