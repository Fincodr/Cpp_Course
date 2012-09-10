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
#ifndef FILE_HPP
#define FILE_HPP

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

#include "String.hpp"

namespace nonstd
{
    class File
    {
        public:
            File( char* filename, const char* mode );
            virtual ~File();
            virtual void Flush();
            virtual void Close();
            virtual bool Valid();
            virtual String* ReadLine( size_t maxlen = 256 );
            virtual String* ReadString( char sep = '\t', size_t maxlen = 256 ); 
            virtual void Write(const char *format, ...);

        protected:
        private:
            FILE* m_pFile;
    };

    File::File( char* filename, const char* mode ) : m_pFile(nullptr)
    {
        // Note: Not safe, use fopen_s instead.
        m_pFile = fopen( filename, mode );
    }

    void File::Flush()
    {
        fflush(m_pFile);
    }

    void File::Close()
    {
		if ( m_pFile != 0 )
		{
			fflush(m_pFile);
			fclose(m_pFile);
		}
        m_pFile = 0;
    }

    bool File::Valid()
    {
        if ( m_pFile != 0 )
            return ( true );
        else
            return ( false );
    }

    String* File::ReadString( char sep, size_t maxlen )
    {
        if ( m_pFile && !feof(m_pFile) )
        {
            char* buffer = new char[maxlen];
            size_t i = 0;
            buffer[i] = '\0';

            while ( true )
            {
                int c = fgetc(m_pFile);
                // do we have separation character?
                if ( c == sep )
                    break;
                // do we have any more characters?
                if ( c == EOF )
                    break;
                // was the char enter/return char?
                if ( c == '\n' )
                    break;
                buffer[i] = (char)c;
                ++i;
                buffer[i] = '\0';
                if ( i >= maxlen )
                break;
            }

            // create new String from buffer
            String* text = new String();
            text->Set(buffer);

            delete[] buffer;

            if ( feof(m_pFile) ) Close();

            // return String
            return( text ); 
        }
        else
            return nullptr;
    }

    String* File::ReadLine( size_t maxlen )
    {
        if ( m_pFile && !feof(m_pFile) )
        {
            char* buffer = new char[128];
            size_t i = 0;
            buffer[i] = '\0';

            while ( true )
            {
                int c = fgetc(m_pFile);
                // do we have any more characters?
                if ( c == EOF )
                    break;
                // was the char enter/return char?
                if ( c == '\n' )
                    break;
                buffer[i] = (char)c;
                ++i;
                buffer[i] = '\0';
                if ( i >= maxlen )
                    break;
            }

            // create new String from buffer
            String* text = new String();
            text->Set(buffer);

            delete[] buffer;

            if ( feof(m_pFile) ) Close();

            // return String
            return( text );            
        }
        else
            return nullptr;
    }

    void File::Write(const char *format, ...)
    {
        if ( m_pFile )
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
            fprintf( m_pFile, "%s", buffer );
        }
    }

    File::~File()
    {
        if ( m_pFile )
		{
			Close();
		}
        m_pFile = 0;
    }
}

#endif // FILE_HPP
