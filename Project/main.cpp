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
#ifdef _MSC_VER
	#ifdef _DEBUG
	// We are using Visual Studio so enable memory debugging
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
	#endif
#endif

/**
 *
 * Standard C libraries are allowed
 *
 */
#include <string.h>     // for strlen
#include <stdlib.h>     // for malloc
#include <assert.h>		// for assert macro
#include <stdio.h>		// for printf

/**
 *
 * C++ libraries are not allowed, except for exception handling
 *
 */
// TODO: Remove these..
#include <iostream>     // for cout and endl
#include <string>


#include <stdexcept>

#include "List.hpp"		// for our own Linked-List container
#include "String.hpp"	// for our own String implementation
#include "Pair.hpp"		// for our own Pair impelementation
#include "Console.hpp"	// for our own input from and output to console

#include "Dictionary.hpp"	// for our own Dictionary implementation

using std::cout;
using std::endl;

using namespace nonstd;

#define ARROW_KEY_LEFT 75
#define ARROW_KEY_RIGHT 77
#define ARROW_KEYS 224

// Prototypes
void displayHeader(void);

int main(void)
{
	// If we are on windows we can set the console output codepage to ansi
	setlocale(LC_ALL, "");

	// Start new scope
	{
		Dictionary dictionary;

        // load directly from file
		dictionary.load( (char*)"dictionary.txt" );

        // add bunch of words to the list
        WordPair word01( (char*)"a school", (char*)"koulu" );
        WordPair word02( (char*)"a class", (char*)"luokka" );
        WordPair word03( (char*)"is playing", (char*)"pelaa" );
        WordPair word04( (char*)"a game", (char*)"peli" );
        WordPair word05( (char*)"a laptop", (char*)"kannettava tietokone" );
        dictionary.push_back( word01 );
        dictionary.push_back( word02 );
        dictionary.push_back( word03 );
        dictionary.push_back( word04 );
        dictionary.push_back( word05 );

        // sort
        dictionary.sort();

		// save sorted list back
		dictionary.save( (char*)"dictionary.txt" );

        /*
		std::cout << "** After sorting **" << std::endl;
		// Read one line from console (must be ended by return char)
		auto text1 = nonstd::Console::GetLine();
		// Read one char from console
		std::cout << text1 << std::endl;
		std::cout << ch << std::endl;
		// Print contents using C++11 for_each syntax
		for( auto item : dictionary )
		{
			std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
		}
		std::cout << std::endl;
		while ( true )
		{


			if ( wordpair ) {
				std::cout << std::endl << "First match:" << std::endl;
				std::cout << wordpair->getSecondType() << " = " << wordpair->getFirstType() << std::endl;
			}
			else
				std::cout << "Error: No match!" << std::endl;

		}
		*/

        String mytext("Hello World");

        std::cout << mytext << endl;

        bool bRunning = true;

        displayHeader();

		while ( bRunning )
        {

            int ch = nonstd::Console::GetChar();

            if ( ch == ARROW_KEYS )
            {
                int ch2 = nonstd::Console::GetChar();
                if ( ch2 == 75 )
                    std::cout << "Left arrow!" << std::endl;
                if ( ch2 == 77 )
                    std::cout << "Right arrow!" << std::endl;
            }
            else
            {
                //std::cout << "You pressed: " << (char)ch << endl;
                switch ( (char)ch )
                {
                    // < and > too
                    case '<':
                        std::cout << "Previous word!" << std::endl;
                        break;
                    case '>':
                        std::cout << "Next word!" << std::endl;
                        break;
                    // Search
                    case 's':
                    case 'S':
                        {
                            // ToDo: Change to use own console class -> getline
                            std::cout << "Enter word to be searched: ";
                            std::string text;
                            std::getline(std::cin, text);

                            // Find one item from list
                            WordPair* wordpair = dictionary.find(
                                [&]( WordPair* tempwordpair ) -> bool {
                                    if ( strstr( tempwordpair->getFirstType(), text.c_str() ) != nullptr || strstr( tempwordpair->getSecondType(), text.c_str() ) != nullptr )
                                        return ( true );
                                    else
                                        return ( false );
                                }
                            );
                            if ( wordpair )
                            	std::cout << "Found word: " << wordpair->getFirstType() << " = " << wordpair->getSecondType() << std::endl;
                            else
                            	std::cout << "Sorry, no word found in dictionary." << std::endl;
                            break;
                        }
                    // Add a word to dictionary
                    case 'a':
                    case 'A':
                        {
                            std::cout << "Enter english word: ";
                            std::string textEng;
                            std::getline(std::cin, textEng);
                            std::cout << "Enter finnish meaning: ";
                            std::string textFin;
                            std::getline(std::cin, textFin);
                            String text1(textEng.c_str());
                            String text2(textFin.c_str());
                            WordPair newWord( text1, text2 );
                            dictionary.push_back( newWord );
                        }
                        break;
                    // Quit
                    case 'q':
                    case 'Q':
                        bRunning = false;
                        break;
                    default:
                        std::cout << "Unknown command!" << std::endl;
                        break;
                }
            }
        }

        /*
		std::cout << "** Without sorting **" << std::endl;
		// Print contents using C++11 for_each syntax
		for( auto item : dictionary )
		{
			std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
		}
		std::cout << endl;

		dictionary.sort();

		std::cout << "** After sorting **" << std::endl;
		// Print contents using C++11 for_each syntax
		for( auto item : dictionary )
		{
			std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "** Popping items out **" << std::endl;
		// Get items out
		while ( WordPair* word = dictionary.front() ) {
			std::cout << word->getFirstType() << " = " << word->getSecondType() << std::endl;
			dictionary.pop_front();
		}
		*/
	}


    // dictionary.debug_print();

    // dictionary.sort(WordComparer);

    /*
    cout << "Using for each: " << endl;
    for ( auto& word : stdlist )
    {
        cout << "  Word:" << endl;
        cout << "    Fin: " << word.GetFinnishWord() << endl;
        cout << "    Eng: " << word.GetEnglishWord() << endl;
    }

    cout << endl;

    cout << "Word1: " << endl;
    cout << "  " << word1.GetEnglishWord() << endl;
    cout << "  " << word1.GetFinnishWord() << endl;
    cout << "Word2: " << endl;
    cout << "  " << word2.GetEnglishWord() << endl;
    cout << "  " << word2.GetFinnishWord() << endl;
    */

	#ifdef _CRTDBG_MAP_ALLOC
	_CrtDumpMemoryLeaks();
	#endif

    return 0;
}

void displayHeader(void)
{
        // TODO, change to use Console class
        std::cout << std::endl
            << "*******************************************************************" << std::endl
            << "* D I C T I O N A R Y                                             *" << std::endl
            << "*******************************************************************" << std::endl
            << "S : Search for a word" << std::endl
            << "A : Add word" << std::endl
            << "Q : Quit" << std::endl
            << "< : Previous word" << std::endl
            << "> : Next word" << std::endl << std::endl;
}
