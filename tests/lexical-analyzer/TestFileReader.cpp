#include "gtest/gtest.h"
#include "lexical-analyzer/FileReader.h"

/*
 * @brief crea un archivo y verifica que no tenga
 * líneas.
 */
TEST(TestFileReader, yylinenoZero)
{
    const FileReader f;
    EXPECT_EQ(f.yylineno, 0);
}

/*
 * @brief crea un archivo y verifica que tenga al
 * menos una línea.
 */
TEST(TestFileReader, setFile)
{
    FileReader f;
    // Crates File
    std::string filecontent = "Hola mundo\n123\n";
    std::ofstream tmp("testfile.txt");
    tmp << filecontent;
    tmp.close();
    // Set Files and EXPECTS 1
    f.set("testfile.txt");
    EXPECT_EQ(f.yylineno, 1);
}

/*
 * @brief crea un archivo a partir de un string.
 * Luego, verifica que el contenido del archivo
 * se pueda leer como el de un string (caracter
 * a caracter).
 */
TEST(TestFileReader, getCharacter)
{
    // Same Logic
    FileReader f;
    std::string filecontent = "Hola mundo\n123\n";
    std::ofstream tmp("testfile.txt");
    tmp << filecontent;
    tmp.close();
    f.set("testfile.txt");
    // Verifies get() function
    char c; int index = 0;
    while (f.get(c))
    {
        EXPECT_EQ(c, filecontent[index]);
        index++;
    }
    EXPECT_EQ(f.yylineno, 3);
}

/*
 * @brief crea un archivo y verifica que tenga al
 * menos una línea, aun haciendo unget().
 */
TEST(TestFileReader, ungetWithNoCharacters)
{
    // Same Logic
    FileReader f;
    std::string filecontent = "Hola mundo\n123\n";
    std::ofstream tmp("testfile.txt");
    tmp << "";
    tmp.close();
    f.set("testfile.txt");
    // unget with empty file
    f.unget();
    f.unget();
    EXPECT_EQ(f.yylineno, 1);
}

/*
 * @brief crea un archivo y lo recorre usando get().
 * Luego, verifica que el unget() devuelva los resultados
 * leidos.
 */
TEST(TestFileReader, ungetCharacter)
{
    // Same Logic
    FileReader f;
    std::string filecontent = "Hola mundo\n123\n";
    std::ofstream tmp("testfile.txt");
    tmp << filecontent;
    tmp.close();
    f.set("testfile.txt");
    // Verifies unget() function
    char c;
    while (f.get(c)) {}
    EXPECT_EQ(f.yylineno, 3);
    f.unget();
    EXPECT_EQ(f.yylineno, 2);
    f.get(c);
    EXPECT_EQ(c, '\n');
    f.unget();
    f.unget();
    f.get(c);
    EXPECT_EQ(c, '3');
}
