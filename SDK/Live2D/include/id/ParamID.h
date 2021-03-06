/**
 *  ParamID.h
 * 
 *  Copyright(c) Live2D Inc. All rights reserved.
 *  [[ CONFIDENTIAL ]]
 */
#ifndef __LIVE2D_PARAM_ID_H__
#define __LIVE2D_PARAM_ID_H__


#include "../Live2D.h"
#include "ID.h"

//------------ LIVE2D NAMESPACE ------------
namespace live2d
{ 
	
	class ParamID  : public ID
	{
	public:
		const static int L2D_PARAM_ID_INITIAL_CAPACITY = 64 ;
	
	
	public:
		
		const char * toChar() const { return id.c_str() ; }
	
	
		// IDãçæãã?
		//  ã»åä¸??å¤ãæã¤å¨ã¦ã®IDãã?åããã¤ã³ã¿ãæããã¨ãä¿è¨¼ãã ?åä¸??ç¢ºèªãã?= æ¯è¼?ã§è¯ã?¼?\n
		//  ã»Live2D::dispose()æã«è§£æ¾ããã?
		static ParamID * getID( const live2d::LDString & tmp_idstr ) ;
		static ParamID * getID( const char*  tmp_idstr ) ;
		static ParamID * getID(  const RefString& refStr ) ;
	
		/*
		 * ãªãªã¼ã¹ç¨ã¡ã½ã???ive2D::diposeããå¼ã°ãã)
		 */
		static void releaseStored_notForClientCall() ;
	
	
	
	
	#if L2D_SAMPLE
		static ParamID* SAMPLE_ID_X(){ return getID("ANGLE_X") ; }
		static ParamID* SAMPLE_ID_Y(){ return getID("ANGLE_Y") ; }
		static ParamID* SAMPLE_ID_ANGLE_Z(){ return getID("ANGLE_Z") ; }
		static ParamID* SAMPLE_ID_SMILE(){ return getID("SMILE") ; }
	#endif
		

		
	private:
		ParamID() ;
		ParamID( const char* str ) ;					
		ParamID( const live2d::LDString& _tmp_str);
		ParamID( const RefString& refStr ) ;
		//Prevention of copy Constructor	
		ParamID( const ParamID & ) ;
		ParamID& operator=( const ParamID & ) ;		

		virtual ~ParamID();
		
	private:
		static LDVector<ParamID*>* 		idlist ;		
	
	private:
		live2d::LDString 				id ;			// IDæ?­å?
	};
}
//------------ LIVE2D NAMESPACE ------------

#endif		// __LIVE2D_PARAM_ID_H__
