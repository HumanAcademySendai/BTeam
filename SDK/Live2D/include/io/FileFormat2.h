/**
 *  FileFormat2.h
 *
 *  Copyright(c) Live2D Inc. All rights reserved.
 *  [[ CONFIDENTIAL ]]
 */
#include "../io/BReader.h"

#ifndef __LIVE2D_FILE_FORMAT2_H__
#define __LIVE2D_FILE_FORMAT2_H__


#ifndef __SKIP_DOC__

#include "../memory/LDObject.h"

//--------- LIVE2D NAMESPACE ------------
namespace live2d
{ 
	class ClassDef ;
	
	
	class FileFormat2 : public live2d::LDObject 
	{
	public:
		//  æ°ãããã?ã¸ã§ã³ãå ããå ´åã?ãå¿?æ?°çã«ãè¨­å®ãã?
		static const int LIVE2D_FORMAT_VERSION_V2_6_INTIAL 		= 6;	// æ??ã®ãã?ã¸ã§ã³
		static const int LIVE2D_FORMAT_VERSION_V2_7_OPACITY 	= 7;	// åé?æã«å¯¾å¿?
		static const int LIVE2D_FORMAT_VERSION_V2_8_TEX_OPTION 	= 8;	// ã?¯ã¹ãã£ã«ãªãã·ã§ã³ãä»ãã?
		static const int LIVE2D_FORMAT_VERSION_V2_9_AVATAR_PARTS= 9;	// ã¢ãã¿ã¼ã®ãã?ã?å¦ç?ã?
		static const int LIVE2D_FORMAT_VERSION_V2_10_SDK2       = 10 ;//SDK2.0

		// ---- å¯¾å¿å¯è½ãªæ?°çã?ãã¡ã¤ã« ---- Live2D#BUILD_NO 1000
		static const int LIVE2D_FORMAT_VERSION_AVAILABLE	 	= LIVE2D_FORMAT_VERSION_V2_10_SDK2 ;
	
		// --- EOF ã®ãã©ã°
		static const int LIVE2D_FORMAT_EOF_VALUE = 0x88888888;			// æ??ã®ãã?ã¸ã§ã³
	
		// ãã?ãã?ã¸ã§ã³ã§ãã¯ã©ã¹ã®ã­ã¼ãæ¹æ³ãä½¿ã??ãã(Live2DFormat.LIVE2D_FORMAT_VERSIONããã?
	//	static const int FILE_FORMAT_VERSION = 0 ;
		static const int NULL_NO	= 0;		// 
		static const int ARRAY_NO	= 23;		// 
		static const int OBJECT_REF = 33;		// èª­ã¿è¾¼ã¿æ¸ã¿ãªãã¸ã§ã¯ãã?åç?
	
	public:
		FileFormat2();
		virtual ~FileFormat2();
		
	public:
		//  æ?®ããã¯ã©ã¹åå¾?
		static ClassDef * getClass( int classNo ) ;
		
		static void * newInstance(MemoryParam* memParam , int classNo) ;

		static bool isSerializable(int classNo) ;

		//  æ?®ã?ã¯ã©ã¹çªå·ãã?ãªããã£ãåãªãtrue
		static bool isPrimitive(int classNo){ return ( 2 <= classNo && classNo <= 9 ) ; }
	
		
		static bool isPrimitiveDouble(int classNo){ return classNo == 30 ; } // æ±ºãæã¡(å¤æ´ä¸å¯)

		
		static bool isPrimitiveFloat(int classNo){ return classNo == 31 ; }// æ±ºãæã¡(å¤æ´ä¸å¯)

		
		static bool isPrimitiveInt(int classNo){ return classNo == 29 ; }// æ±ºãæã¡(å¤æ´ä¸å¯)
	
	};
} 
//------------------------- LIVE2D NAMESPACE ------------

#endif // __SKIP_DOC__

#endif		// __LIVE2D_FILE_FORMAT2_H__
