/* ======================================================================== 
* Copyright (C) 2005  Graz University of Technology  
*  
* This framework is free software; you can redistribute it and/or modify  
* it under the terms of the GNU General Public License as published by  
* the Free Software Foundation; either version 2 of the License, or  
* (at your option) any later version.  
* 
* This framework is distributed in the hope that it will be useful,  
* but WITHOUT ANY WARRANTY; without even the implied warranty of  
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
* GNU General Public License for more details.  
* 
* You should have received a copy of the GNU General Public License  
* along with this framework; if not, write to the Free Software  
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA  
*  
* For further information please contact Dieter Schmalstieg under  
* <schmalstieg@icg.tu-graz.ac.at> or write to Dieter Schmalstieg,  
* Graz University of Technology, Inffeldgasse 16a, A8010 Graz,  
* Austria.  
* ========================================================================  
* PROJECT: Studierstube  
* ======================================================================== */  
/** The header file for the SimpleApp class.  
*  
* @author Denis Kalkofen  
*  
* $Id: SimpleApp.h 25 2005-11-28 16:11:59Z denis $  
* @file                                                                   */  
/* ======================================================================= */  

#ifndef _SIMPLEAPP_H_
#define _SIMPLEAPP_H_

#include <stb/kernel/Application.h>

namespace stb{
/**
*	
*/
class SimpleApp : public stb::Application
{
public:
	/**
	*     The Constructor	
	*/
	SimpleApp();

	/**
	*     The destructor.
	*/
	virtual ~SimpleApp();

	/// Called before the application is destructed.
	virtual bool init();
	/// Called before the application is destructed.
	virtual void shutDown();

	virtual void update();

    virtual void registerScene();

    virtual void setParameter(stb::string key, stb::string value);

protected:	
    SoSeparator* root;
    stb::string sceneFile; 

private:
	
};// class 

} //namespace



#endif//_SIMPLEAPP_H_
