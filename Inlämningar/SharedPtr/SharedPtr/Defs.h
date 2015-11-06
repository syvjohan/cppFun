#ifndef DEFS_H
#define DEFS_H

#include <crtdbg.h>

#ifdef _DEBUG
	#define DBG_NEW new(1, __FILE__, __LINE__) //Observe: replace new with DBG_NEW.
#else
	#define DBG_NEW new
#endif


#endif //!DEFS_H



