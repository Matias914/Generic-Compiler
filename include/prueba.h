#ifndef TPE_PRUEBA_H
#define TPE_PRUEBA_H

int indexMapping(const char& c)
{
    // Casting char to integer
    const unsigned int asc = static_cast<unsigned char>(c);
    // Mapping
    // 26 Possibilities 
    if (asc >= 65 && asc <= 90)
    {
        if (asc == 85) return 3; // U
        if (asc == 73) return 2; // I
        if (asc == 70) return 1; // F
        return 0; // Upper Case Letter
    }
    // 26 Possibilities 
    if (asc >= 97 && asc <= 122)
    {
        if (asc == 116) return 6; // t
        if (asc == 110) return 5; // n
        return 4; // Lower Case Letter
    }
    // 10 Possibilities
    if (asc >= 48 && asc <= 57)
        return 7; // Number
    // 3 Possibilities
    if (asc >= 40 && asc <= 42)
        return 8; // Special Character: '(, ), *'
    if (asc == 44 | asc == 47 || asc == 59 || asc == 95 || asc == 123 || asc == 125)
        return 8; // Also Special Character: ', /  ;  _  {  }'
    //  1 Possibility
    if (asc == 32)
        return 9; // space
    if (asc == 33)
        return 10; // !
    if (asc == 34)
        return 11; // "
    if (asc == 35)
        return 12; // #
    if (asc == 37)
        return 13; // %
    if (asc == 43)
        return 14; // +
    if (asc == 45)
        return 15; // -
    if (asc == 46)
        return 16; // .
    if (asc == 58)
        return 17; // :
    if (asc == 60)
        return 18; // <
    if (asc == 61)
        return 19; // =
    if (asc == 62)
        return 20; // >
    if (asc == 92)
        return 21; // \
    // Others
    return 22;
}

#endif //TPE_PRUEBA_H