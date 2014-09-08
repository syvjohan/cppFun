#ifndef PETERSTRING_H
#define PETERSTRING_H

#define NULL 0
#define MIN(A,B) ( A < B ? A : B)
#include <memory>

class PString {
public:
	explicit PString(int reserve = 20) {
		m_Memory = NULL;
		m_StrLen = 0;
		m_MemLen = 0;
		AllocArray(reserve);
	}

	PString(const char *str) {
		m_Memory = NULL;
		m_StrLen = strlen(str) + 1;
		m_MemLen = 0;
		AllocArray(m_StrLen);
		memcpy(m_Memory, str, m_StrLen);
	}

	PString(const PString &copy) {
		m_Memory = NULL;
		m_MemLen = 0;
		m_StrLen = 0;
		CopyHelper(copy);
	}

	~PString(void) {
		delete[] m_Memory;
	}

	int Length(void) const { 
		return m_StrLen;
	}

	const PString& operator=(const PString &copy) {
		CopyHelper(copy);
		return *this;
	}

	const char& operator[](int index) const {
		return m_Memory[index];
	}

	char& operator[](int index) {
		return m_Memory[index];
	}

	PString& Append(const PString &str)
	{
		if (m_MemLen < (m_StrLen + str.m_StrLen - 1))  {
			AllocArray(m_StrLen + str.m_StrLen - 1);
		}

		memcpy(m_Memory + m_StrLen - 1, str.m_Memory, str.m_StrLen);
		m_StrLen += str.m_StrLen - 1;
		return *this;
	}

	PString& Insert(const PString &source, int index) {

		//int newSize = m_StrLen + source.m_StrLen - 1;
		//char *buffer = new char[newSize];

		//memcpy(buffer, m_Memory, index);
		//memcpy(buffer + index, source.m_Memory, source.m_StrLen - 1);
		//memcpy(buffer + index + source.m_StrLen, m_Memory + index, m_StrLen - index);

		//delete[] m_Memory;
		//m_Memory = buffer;
		//m_StrLen += source.m_StrLen;
		//m_MemLen = newSize;

		PString n = SubString(0, index).Append(source).Append(m_Memory + index);
		*this = n;
		return *this;
	}


	PString SubString(int index, int length) {
		PString str(length + 1);
		memcpy(str.m_Memory, m_Memory + index, length);
		str[length] = '\0';
		str.m_StrLen = length + 1;
		return str;
	}


	const char *CString() const { return m_Memory; }

private:
	// Re-allocate our array.
	void AllocArray(int size)
	{
		if (m_Memory)
		{
			// Copy old array
			char *tmp = m_Memory;

			m_StrLen = MIN(m_StrLen, size);

			m_Memory = new char[size];
			memcpy(m_Memory, tmp, m_StrLen);
			delete[] tmp;

			m_MemLen = size;
		}
		else 
		{
			m_Memory = new char[size];
			//m_StrLen = 0;
			m_MemLen = size;
		}

	}

	void CopyHelper(const PString &copy) {
		if (copy.m_StrLen > m_MemLen) {
			AllocArray(copy.m_StrLen);
		}

		memcpy(m_Memory, copy.m_Memory, copy.m_StrLen);
		m_StrLen = copy.m_StrLen;
	}


	char *m_Memory;
	int m_StrLen;
	int m_MemLen;
};

#endif // !PETERSTRING_H