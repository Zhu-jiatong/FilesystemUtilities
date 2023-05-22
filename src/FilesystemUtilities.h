/*
 Name:		FilesystemUtilities.h
 Created:	5/22/2023 6:00:55 PM
 Author:	jiaji
 Editor:	http://www.visualmicro.com
*/

#ifndef _FilesystemUtilities_h
#define _FilesystemUtilities_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include<FS.h>

class DirectoryIterator
{
public:
	using iterator_category = std::input_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = File;
	using pointer = value_type*;
	using reference = value_type&;

	DirectoryIterator(FS& fs, const char* rootPath);
	DirectoryIterator(File& root);
	DirectoryIterator() = default;

	reference operator*();
	pointer operator->();
	DirectoryIterator& operator++();
	DirectoryIterator& operator++(int);
	bool operator==(const DirectoryIterator& other) const;
	bool operator!=(const DirectoryIterator& other) const;

	DirectoryIterator begin();
	DirectoryIterator end();

	void rewind();

private:
	value_type m_root;
	value_type m_entry;
};

#endif
