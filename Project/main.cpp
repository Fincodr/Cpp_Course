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

/*
#if __cplusplus < 201103L
#define nullptr NULL
#endif
*/

#include "Console.hpp"      // for our own input from and output to console
#include "String.hpp"       // for our own String implementation
#include "Pair.hpp"         // for our own Pair impelementation
#include "List.hpp"         // for our own Linked-List container
#include "Dictionary.hpp"   // for our own Dictionary implementation

using nonstd::Console;
using nonstd::String;
using nonstd::kMAX_STRING_LEN;

static const int kARROW_KEY_LEFT = 75;
static const int kARROW_KEY_RIGHT = 77;
static const int kARROW_KEYS = 224;
static const int kESC_KEY = 27;

// Prototypes
void displayHeader(void);
void displayMenu(void);
void displayWord(Dictionary& dict, Dictionary::iterator& it);

int main(void)
{
	// If we are on windows we can set the console output codepage to ansi
	setlocale(LC_ALL, "");

	// Start new scope
	{
		Dictionary dictionary;

        // load directly from file
		dictionary.load( (char*)"dictionary.txt" );

        bool bRunning = true;

        displayHeader();
        displayMenu();

        auto curWord = dictionary.begin();

        Console::Out( "Words in dictionary: %d\n\n", dictionary.count() );

        displayWord( dictionary, curWord );

		while ( bRunning )
        {
            Console::Out( "Your option: " );
            // Wait for keypress and the keycode
            int ch = Console::GetChar();
            Console::Out( "\r             \r" );

            // Browse words by using arrow keys
            if ( ch == kARROW_KEYS )
            {
                int ch2 = Console::GetChar();
                if ( dictionary.count() > 0 )
                {
                    if ( ch2 == kARROW_KEY_LEFT )
                    {
                        // Previous word
                        if ( curWord != nullptr ) --curWord;
                        if ( curWord == nullptr )
                        {
                            Console::Out( "No more words.\n\n");
                            curWord = dictionary.begin();
                        }
                        displayWord( dictionary, curWord );
                    }
                    if ( ch2 == kARROW_KEY_RIGHT )
                    {
                        // Next word
                        if ( curWord != nullptr ) ++curWord;
                        if ( curWord == nullptr )
                        {
                            Console::Out( "No more words.\n\n");
                            curWord = dictionary.last();
                        }
                        displayWord( dictionary, curWord );
                    }
                }
                else
                {
                    Console::Out( "No words.\n\n" );
                }
            }
            else
            {
                switch ( (char)ch )
                {
                    // Browse words by using keys < and > too
                    case '<':
                        if ( curWord != nullptr )
                        {
                            // Previous word
                            if ( curWord != nullptr ) --curWord;
                            if ( curWord == nullptr )
                            {
                                Console::Out( "No more words.\n\n");
                                curWord = dictionary.begin();
                            }
                        }
                        displayWord( dictionary, curWord );
                        break;
                    case '>':
                        if ( curWord != nullptr )
                        {
                            // Next word
                            if ( curWord != nullptr ) ++curWord;
                            if ( curWord == nullptr )
                            {
                                Console::Out( "No more words.\n\n");
                                curWord = dictionary.last();
                            }
                        }
                        displayWord( dictionary, curWord );
                        break;
                    // List
                    case 'l':
                    case 'L':
                        {
							if ( dictionary.count() > 0 )
							{
								Console::Out( "Words in dictionary: %d\n\n", dictionary.count() );
								for ( auto it = dictionary.begin(); it != dictionary.end(); ++it )
								{
									auto* wordpair = *it;
									Console::Out( "%s (eng) = %s (fin)\n", wordpair->getFirstType(),  wordpair->getSecondType() );
								}
								Console::Out( "\n" );
							}
							else
							{
								Console::Out( "No words.\n\n" );
							}
                        }
                        break;
                    // Search
                    case 's':
                    case 'S':
                        {
                            // ToDo: Change to use own console class -> getline
                            Console::Out( (char*)"Enter word to be searched (you can enter partial word): " );
                            String* text = Console::GetLine(kMAX_STRING_LEN);
                            // Find one item from list
                            Dictionary::Node* node = dictionary.find(
                                [&]( WordPair* tempwordpair ) -> bool {
                                    if ( strstr( tempwordpair->getFirstType(), *text ) != nullptr || strstr( tempwordpair->getSecondType(), *text ) != nullptr )
                                        return ( true );
                                    else
                                        return ( false );
                                }
                            );
                            delete text;
                            if ( node )
                            	Console::Out( "Found word: %s (eng) = %s (fin)\n\n", node->item->getFirstType(),  node->item->getSecondType() );
                            else
                            	Console::Out( "Sorry, word not found in dictionary.\n\n" );
                            break;
                        }
                    // Delete
                    case 'd':
                    case 'D':
                        {
                            // ToDo: Change to use own console class -> getline
                            Console::Out( "Enter word to be deleted (you can enter partial word): " );
                            String* text = Console::GetLine(kMAX_STRING_LEN);
							if ( text->length() == 0 )
							{
								Console::Out( "Sorry. Empty word not accepted. Please try again.\n\n" );
							}
							else
							{
								// Find one item from list
								Dictionary::Node* node = dictionary.find(
									[&]( WordPair* tempwordpair ) -> bool {
										if ( strstr( tempwordpair->getFirstType(), *text ) != nullptr || strstr( tempwordpair->getSecondType(), *text ) != nullptr )
											return ( true );
										else
											return ( false );
									}
								);
								if ( node )
								{
                            		Console::Out( "Deleted word: %s (eng) = %s (fin)\n\n", node->item->getFirstType(), node->item->getSecondType() );
                            		dictionary.erase(node);
									if ( curWord == node ) curWord = dictionary.begin();
								}
								else
                            		Console::Out( "Sorry, word not found in dictionary.\n\n" );
							}
                            delete text;
                            break;
                        }
                    // Add a word to dictionary
                    case 'i':
                    case 'I':
                        {
                            Console::Out( "Enter english word: " );
                            String* textEng = Console::GetLine(kMAX_STRING_LEN);

							if ( textEng->length() == 0 )
							{
								Console::Out( "Sorry. Empty english word not accepted. Please try again.\n\n" );
							}
							else
							{
								// Find one item from list
								Dictionary::Node* node = dictionary.find(
									[&]( WordPair* tempwordpair ) -> bool {
										if ( strcmp( tempwordpair->getFirstType(), *textEng ) == 0 )
											return ( true );
										else
											return ( false );
									}
								);
								if ( node )
								{
                            		Console::Out( "Sorry. Word: %s (eng) = %s (fin) already exists in the dictionary. Please remove it first if you want to replace it.\n\n", node->item->getFirstType(), node->item->getSecondType() );
								}
								else
								{
									Console::Out( "Enter finnish meaning: " );
									String* textFin = Console::GetLine(kMAX_STRING_LEN);
									if ( textFin->length() == 0 )
									{
										Console::Out( "Sorry. Empty finnish word not accepted. Please try again.\n\n" );
									}
									else
									{
										WordPair newWord( *textEng, *textFin );

										// insert new word to back of the list
										dictionary.push_back( newWord );

										// sort after inserting
										dictionary.sort();

										Console::Out( "Word added to dictionary.\n\n" );
									}

									delete textFin;
								}
							}
                            delete textEng;
                            if ( curWord == nullptr ) curWord = dictionary.begin();
                        }
                        break;
                    // Quit
                    case 'e':
                    case 'E':
                    case 'q':
                    case 'Q':
                    case kESC_KEY:
                        Console::Out( "Bye!\n" );
                        bRunning = false;
                        break;
                    default:
                        Console::Out( "Unknown command! (%d)\n", (int)ch );
                        break;
                }
            }
        }

        // save list to file
        dictionary.save( (char*)"dictionary.txt" );
	}

	#ifdef _CRTDBG_MAP_ALLOC
	_CrtDumpMemoryLeaks();
	#endif

    return 0;
}

void displayWord( Dictionary& dict, Dictionary::iterator& it )
{
    // Display current word
    if ( it == nullptr )
        it = dict.begin();
    if ( it != nullptr )
    {
        WordPair* wordpair = *it;
        Console::Out( "Current word: %s (eng) = %s (fin)\n\n", wordpair->getFirstType(), wordpair->getSecondType() );
    }
    else
        Console::Out( "No words.\n\n" );
}

void displayHeader(void)
{
        // TODO, change to use Console class
        Console::Out(
            "\n"
            "************************************************\n"
            "****               Dictionary               ****\n"
            "**** By Mika Luoma-aho, Student id: 1004547 ****\n"
            "************************************************\n"
            "\n" );
}

void displayMenu(void)
{
        // TODO, change to use Console class
        Console::Out(
            "************************************************\n"
            "****                  MENU                  ****\n"
            "************************************************\n"
            "S - Search for a word\n"
            "I - Insert a word\n"
            "D - Delete a word\n"
            "L - List words\n"
            "E - Exit\n"
            "< > - Show words\n"
            "\n" );
}
