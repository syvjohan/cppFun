#pragma once


class UppgiftBase {
public:
	virtual ~UppgiftBase();

	template<typename Iterator, typename Predicate>
	virtual void Sort(Iterator begin, Iterator end, Predicate p) {
		// Implementz..
	}

	virtual void Run(void) = 0;

private:

};

// Lägg Gemensam kod här.