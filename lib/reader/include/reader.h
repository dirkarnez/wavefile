#ifndef _READER_H_
#define _READER_H_

#include <iostream>

class Reader {
public:
    Reader();
    bool read(const std::string file_name);
};

#endif
