#ifndef DEFS_H
#define DEFS_H

#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new(1, __FILE__, __LINE__)
#else
#define DBG_NEW new
#endif

//typedef float T;


#endif //!DEFS_H

