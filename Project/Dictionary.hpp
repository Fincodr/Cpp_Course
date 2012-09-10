/*
 *     _/_/_/_/  _/                                      _/
 *    _/            _/_/_/      _/_/_/    _/_/      _/_/_/  _/  _/_/
 *   _/_/_/    _/  _/    _/  _/        _/    _/  _/    _/  _/_/
 *  _/        _/  _/    _/  _/        _/    _/  _/    _/  _/
 * _/        _/  _/    _/    _/_/_/    _/_/      _/_/_/  _/
 *
 * Copyright (c) 2012 Mika Luoma-aho <fincodr@mxl.fi>
 *
 * This source code and software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this source code or software.
 *
 * Permission is granted to anyone to use this software (and the source code when its released from the author)
 * as a learning point to create games, including commercial applications.
 *
 * You are however subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.
 *    If you use this software's source code in a product,
 *    an acknowledgment in the product documentation would be appreciated but is not required.
 * 2. Altered versions must be plainly marked as such, and must not be misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any distribution.
 *
 */
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string.h>	// for strstr

#include "List.hpp"
#include "Pair.hpp"
#include "String.hpp"
#include "Console.hpp"
#include "File.hpp"

using nonstd::List;
using nonstd::String;
using nonstd::Pair;
using nonstd::Console;
using nonstd::File;

static const int kFORMAT_WORDS = 10;
static const int kFORMAT_STRINGS = 11;

typedef Pair<String, String> WordPair;

class Dictionary : public List<WordPair>
{
	public:
		Dictionary() : m_format(kFORMAT_STRINGS) {};
		virtual ~Dictionary() {};
		virtual void load(char*);
		virtual void save(char*);
	protected:
	private:
		int m_format;
};

void Dictionary::load(char* filename)
{
	File file( filename, (char*)"r" );
	if ( file.Valid() )
	{
		// read header
		auto* header = file.ReadLine();
		if ( header->c_str() )
		{
			// check header version
			bool bStrings = false;
			if ( strstr( header->c_str(), "1.1" ) != nullptr ) {
				// file contains strings separated by tab character.
				bStrings = true;
				m_format = kFORMAT_STRINGS;
			}
			else
			{
				m_format = kFORMAT_WORDS;
			}
			// read word
			while ( file.Valid() )
			{
				String* textEng;
				if ( bStrings )
					textEng = file.ReadString();
				else
					textEng = file.ReadString(' ');
				String* textFin = file.ReadLine();
				if ( textEng && textFin )
				{
					WordPair wordpair( *textEng, *textFin );
					push_back( wordpair );
				}
				delete textEng;
				delete textFin;
			}
			sort();
		}
		delete header;
	}
}

void Dictionary::save(char* filename) {
	File file( filename, (char*)"w" );
	if ( file.Valid() )
	{
		// write header
		if ( m_format == kFORMAT_WORDS )
			file.Write( "[Dictionary FileFormat version 1.0]\n");
		else
			file.Write( "[Dictionary FileFormat version 1.1]\n");
		if ( count() > 0 )
		{
			// write dictionary contents to file
			for ( auto it = begin(); it != end(); ++it )
			{
				auto* wordpair = *it;
				if ( m_format == kFORMAT_WORDS )
					file.Write( "%s %s\n", wordpair->getFirstType(),  wordpair->getSecondType() );
				else
					file.Write( "%s\t%s\n", wordpair->getFirstType(),  wordpair->getSecondType() );
			}
		}
	}
}

#endif // DICTIONARY_HPP