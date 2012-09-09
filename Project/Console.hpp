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

#include <stdio.h>	// for fgetc, fgets
#include <conio.h>	// fot getch
#include "String.hpp"

namespace nonstd
{

	class Console
	{
		public:

			Console() {};
			~Console() {};

			static String* GetLine(void)
			{
				String* text = new String();
				text->Set("Hello World!");
				return( text );
			}

			static int GetChar(void)
			{
				return ( _getch() );
			}

			// http://stackoverflow.com/questions/314401/how-to-read-a-line-from-console-in-c/

			// Printf type function?
			//
			// Stream support??
			//
			// char << Console::In;
			// String*(?) << Console::In;
			//
			// Console::Out << "Hello World";
			// Console::Out << (char)
			// Console::Out << (String)

		protected:
		private:
	};
}

#endif // CONSOLE_HPP
