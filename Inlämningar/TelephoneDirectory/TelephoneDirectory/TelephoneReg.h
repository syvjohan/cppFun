#ifndef TELEPHONEREG_H
#define TELEPHONEREG_H

#include <string.h>

struct contact {
	std::string number;
	std::string name;
};

class TeleReg {
public:
	explicit TeleReg(int maxSize); // konstruktor som tar en parameter ska alltid vara explicit.
	~TeleReg();

	void AddContact(const std::string &number, const std::string &name);
	void DelContact(const std::string &number, const std::string &name);
	void RemoveName(const std::string &number, const std::string &name);
	void RemoveNumber(const std::string &number, const std::string &name);
	bool FindName(const std::string	&number, std::string &name) const;
	void PrintReg();

private:
	int size;
	contact *reg;
	int nextIndex;
};

#endif //!TELEPHONEREG_H