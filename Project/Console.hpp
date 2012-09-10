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
#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <cstdarg>	    // for va_ functions
#include <conio.h>	    // fot getch (note: use ncurses on linux)
#include <stdio.h>	    // for fgetc, fgets

#include "String.hpp"	// for our own String implementation

namespace nonstd
{

	class Console
	{
		public:

			Console() {};
			~Console() {};

            // Simple printf wrapper to support format and parameters
            // In C++11 It would be better to use variadic templates for typesafe output
			static void Out( const char *format, ...)
			{
                // Note: Not safe :)
                va_list arglist;
                char buffer[1024];

                // concatenate input strings to buffer
                // Note: vsprintf is deprecated
                va_start(arglist, format);
                vsprintf(buffer, format, arglist);
                va_end(arglist);

                // finally write buffer to standard output
                printf( "%s", buffer );
			}

            // Get one line to internal buffer and output String class
			static String* GetLine(size_t maxlen = 256)
			{
				char* buffer = new char[maxlen];
				size_t i = 0;
            	buffer[i] = '\0';

				while ( true )
				{
					int c = fgetc(stdin);
					// do we have any more characters?
					if ( c == EOF )
						break;
					// was the char enter/return char?
					if ( c == '\n' )
						break;
					// was the char backspace?
					if ( c == '\b' )
					{
						// remove cur char
						buffer[i] = '\0';
						if ( i > 0 ) --i;
					}
					else
					{
						buffer[i] = (char)c;
						++i;
						buffer[i] = '\0';
						if ( i >= maxlen )
							break;
					}
				}

				// create new String from buffer
				String* text = new String();
				text->Set(buffer);

				delete[] buffer;

				// return String
				return( text );
			}

            // Get one char
			static int GetChar(void)
			{
                return ( _getch() );
			}

		protected:
		private:
	};
}

#endif // CONSOLE_HPP
