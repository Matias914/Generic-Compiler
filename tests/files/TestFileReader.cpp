#include "gtest/gtest.h"
#include "files/FileReader.h"

/*
 * @brief crea un archivo y un string para su contenido.
 * Compara caracter a caracter para ver si el FileReader
 * devuelve el mismo resultado que el string.
 *
 */
TEST(TestFileReader, FileReader)
{
    std::string filecontent = "Hola mundo\n123\n";
    std::ofstream tmp("testfile.txt");
    tmp << filecontent;
    tmp.close();

    FileReader f;
    f.set("testfile.txt");

    char c; int index = 0;
    while (f.get(c))
    {
        EXPECT_EQ(c, filecontent[index]);
        index++;
    }
    EXPECT_EQ(f.yylineno, 3);
    std::remove("testfile.txt");
}
