/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of HPL1 Engine.
 *
 * HPL1 Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HPL1 Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HPL1 Engine.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "impl/Platform.h"
#include "i_opndir.h"
#include <sys/types.h>
#include <sys/stat.h>
#ifndef _WIN32
#include <unistd.h>
#include <dirent.h>
#else
#include "i_opndir.h"
#endif
#include <wctype.h>
#include "system/LowLevelSystem.h"

namespace hpl {

	long Platform::FileLength(const tWString& asFileName)
	{
		struct stat statbuf;
		if (stat(cString::To8Char(asFileName).c_str(), &statbuf) == -1) {
			return 0;
		};
		return ((long)statbuf.st_size);
	}

	long Platform::FileLength(FILE *pFile)
	{
		struct stat statbuf;
		if (fstat(fileno(pFile), &statbuf) == -1) {
			return 0;
		};
		return ((long)statbuf.st_size);
	}

	static inline int patiMatch (const wchar_t *pattern, const wchar_t *string) {
	  switch (pattern[0])
	  {
	  case _W('\0'):
			return !string[0];

	  case _W('*') :
			return patiMatch(pattern+1, string) || (string[0] && patiMatch(pattern, string+1));

	  case _W('?') :
			return string[0] && patiMatch(pattern+1, string+1);

	  default  :
			return (towupper(pattern[0]) == towupper(string[0])) && patiMatch(pattern+1, string+1);
	  }
	}

#ifdef _WIN32
	void Platform::FindFileInDir(tWStringList& alstStrings, const char* asDir, int8_t asMask)
#else
	void Platform::FindFileInDir(tWStringList &alstStrings,tWString asDir, tWString asMask)
#endif
	{
		//Log("Find Files in '%ls' with mask '%ls'\n",asDir.c_str(), asMask.c_str());
		//Get the search string
		wchar_t sSpec[256];
		tWString asMaskHandle;
		asMaskHandle = asMask;
#ifdef _WIN32
		wchar_t end = sizeof(asDir - 1);
#else
		wchar_t end = asDir[asDir.size()-1];
#endif
		//The needed structs
		DIR *dirhandle;
		dirent *_entry;
		struct stat statbuff;
		tWString fileentry;

#ifdef _WIN32
		dirhandle = opendir(cString::ToInt8(asDir, &asMask));
		if (dirhandle) 
			return;
#else
		if ((dirhandle = opendir(cString::To8Char(asDir).c_str()))==NULL) return;
#endif
		while ((_entry = readdir(dirhandle)) != NULL) {
#ifdef _WIN32
			if (end == _W('/'))
				swprintf(sSpec, 256, _W("%ls%s"), asDir, _entry->d_name);
			else
				swprintf(sSpec, 256, _W("%ls/%s"), asDir, _entry->d_name);
#else
			if (end==_W('/'))
				swprintf(sSpec,256,_W("%ls%s"),asDir.c_str(),_entry->d_name);
			else
				swprintf(sSpec,256,_W("%ls/%s"),asDir.c_str(),_entry->d_name);
#endif
			// skip unreadable
			if (stat(cString::To8Char(sSpec).c_str(),&statbuff) ==-1) continue;
			// skip directories
			if (S_ISDIR(statbuff.st_mode)) continue;

#ifdef _WIN32
			fileentry.assign(cString::To16Char(asDir));
#else
			fileentry.assign(cString::To16Char(_entry->d_name));
#endif
#ifdef _WIN32
			if (!patiMatch(asMaskHandle.c_str(), fileentry.c_str())) continue;
#else
			if (!patiMatch(asMask.c_str(), fileentry.c_str())) continue;
#endif
			alstStrings.push_back(fileentry);
		}
		closedir(dirhandle);
	}
}
