/*
 Name:		FilesystemUtilities.cpp
 Created:	5/22/2023 6:00:55 PM
 Author:	jiaji
 Editor:	http://www.visualmicro.com
*/

#include "FilesystemUtilities.h"

DirectoryIterator::DirectoryIterator(FS& fs, const char* rootPath) :
	m_root(fs.open(rootPath)),
	m_entry(m_root.openNextFile())
{
}

DirectoryIterator::DirectoryIterator(File& root) :
	m_root(root),
	m_entry(m_root.openNextFile())
{
}

DirectoryIterator::reference DirectoryIterator::operator*()
{
	return m_entry;
}

DirectoryIterator::pointer DirectoryIterator::operator->()
{
	return &m_entry;
}

DirectoryIterator& DirectoryIterator::operator++()
{
	m_entry = m_root.openNextFile();
	return *this;
}

DirectoryIterator& DirectoryIterator::operator++(int)
{
	DirectoryIterator temp(*this);
	++(*this);
	return temp;
}

bool DirectoryIterator::operator==(const DirectoryIterator& other) const
{
	return other.m_entry == m_entry;
}

bool DirectoryIterator::operator!=(const DirectoryIterator& other) const
{
	return !operator==(other);
}

DirectoryIterator DirectoryIterator::begin()
{
	rewind();
	return DirectoryIterator(m_root);
}

DirectoryIterator DirectoryIterator::end()
{
	return DirectoryIterator();
}

void DirectoryIterator::rewind()
{
	m_root.rewindDirectory();
}
