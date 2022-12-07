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
#ifndef HPL_RESOURCEBASE_H
#define HPL_RESOURCEBASE_H

#include <stdint.h>
#include "system/SystemTypes.h"
//
namespace hpl {

	class iResourceBase
	{
	public:

		iResourceBase(tString asName,unsigned int alPrio);

		virtual ~iResourceBase();

		/**
		 * Free all memory.
		 */
		virtual void Destroy()=0;

		tString GetName(){return msName;}
		uint32_t GetHandle(){return mlHandle;}
		void SetHandle(uint32_t alHandle){mlHandle=alHandle;}
		tString GetFilePath(){return msFilePath;}
        uint32_t GetTime(){return mlTime;}
        uint32_t GetPrio(){return mlPrio;}
        uint32_t GetSize(){return mlSize;}

		void SetLogDestruction(bool abX){ mbLogDestruction = abX;}

		unsigned int GetUserCount(){return mlUserCount;}
		void IncUserCount();
		void DecUserCount(){if(mlUserCount>0)mlUserCount--;}
		bool HasUsers(){ return mlUserCount>0;}

		static bool GetLogCreateAndDelete(){ return mbLogCreateAndDelete;}
		static void SetLogCreateAndDelete(bool abX){ mbLogCreateAndDelete = abX;}

	protected:
		static bool mbLogCreateAndDelete;

		unsigned int mlPrio; //dunno if this will be of any use.
        uint32_t mlTime; //Time for creation.
        uint32_t mlSize; //for completion. Not used yet.

		unsigned int mlUserCount;
        uint32_t mlHandle;
		tString msName;
		tString msFilePath;
		bool mbLogDestruction;
	};

};
#endif // HPL_RESOURCEBASE_H
