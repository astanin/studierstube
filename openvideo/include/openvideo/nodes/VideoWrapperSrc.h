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
 * For further information please contact Denis Kalkofen under
 * <kalkofen@icg.tu-graz.ac.at> or write to Denis Kalkofen,
 * Graz University of Technology, Inffeldgasse 16a, A8010 Graz,
 * Austria.
 * ========================================================================
 * PROJECT: OpenVideo
 * ======================================================================== */
/** The header file for the VideoWrappersrc class.
  *
  * @author Denis Kalkofen
  *
  * $Id: VideoWrapperSrc.h 148 2006-05-26 14:53:05Z daniel $
  * @file                                                                   */
 /* ======================================================================= */
#ifndef _VIDEOWRAPPERSRC_H
#define _VIDEOWRAPPERSRC_H
#include <openvideo/openVideo.h>
#ifdef ENABLE_VIDEOWRAPPERSRC

#include <string>

#include <openvideo/Node.h>




namespace openvideo {


class VideoWrapperSrcBuffer;


    /**
    *@ingroup nodes
    *	VideoWrapperSrc implements an OpenVideo node to access the videowrapper library. 
    *	The xml entry looks like this:\n
    *@verbatim
    <VideoWrapperSrc 
    name="VWSrc_1"
    libId="vc"
    formatId="UYVY"
    cameraNum="1"
    width="320"
    height="240"
    frameRate="15"
    scale="0"> 
    </VideoWrapperSrc>
    @endverbatim
    *	The parameters are : \n
    *	(libID,camNum,width,height,frameRate,scale refer all to VideoWrapper's init. string) \n
    *	@li name = node name 
    *	@li libId = VideoWrapper's library identifier (vc=vidcature)
    *	@li	cameraNum = the camera number this nodes refers to 
    *	@li	width = video widht
    *	@li	height = video height
    *	@li	frameRate = VideoWrapper's update rate
    *	@li	scale = VideoWrapper's scale value
    *	\n
    *   Supported Pixel Formats: \n
    *	@li: R8G8B8
    */
class OPENVIDEO_API VideoWrapperSrc : 
public openvideo::Node

{
public:
	enum {
		MAX_BUFFERS = 10
	};

	/**
	*
	*/
	VideoWrapperSrc();	

	/**
	*
	*/
	~VideoWrapperSrc();

	/**
	*	Sets all relevat parameters. 
	*/
	virtual bool setParameter(std::string key, std::string value);

	/**
	*	This function calls intializes the videowrapper lib. it then opens and starts the video stream.
	*	Finally it creates a new context where it puts the video specific data on.
	*/
	virtual void init();

	/**
	*	Updates the video frame at its context object.
	*/
	virtual void process();

	/**
	*	releases the videoframe (which was previously locked by the process fucntion.
	*/
	virtual void postProcess();
	virtual void preProcess();
	virtual void initPixelFormats();

protected:
	/**
	*	the handle to the video stream
	*/
	unsigned short g_hVideo;

	/**
	*	videowrapper's library id.
	*/
	char libId[20];

	/**
	*	the video format string.
	*/
	char formatId[20];

	/**
	*	self explaining variables.
	*/
	int cameraNum,width,height,frameRate,format;

	/**
	*	videowrapper's scale value.
	*/
	float scale;


	/// Number of frame buffers
	int numBuffers;
};
}//namespace openvideo {

#endif // ENABLE_VIDEOWRAPPERSRC

#endif // _VIDEOWRAPPERSRC_H
