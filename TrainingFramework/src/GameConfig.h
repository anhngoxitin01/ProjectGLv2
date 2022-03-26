#pragma once

#include <string>
#include "targetver.h"
#include "CMath.h"
#include "ft2build.h"
#include FT_FREETYPE_H

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef ANDROID	
#include <stdio.h>
#include <tchar.h>
#endif

// define game debug  -------------------	1: yes	0: no
#define GAME_DEBUG 1

//Player
#define PLAYER_STATUS_LIVE				0
#define PLAYER_STATUS_BUBBLE			1
#define PLAYER_STATUS_DEAD				2
#define PLAYER_MOVE_DOWN				0
#define PLAYER_MOVE_LEFT				1
#define PLAYER_MOVE_UP					2
#define PLAYER_MOVE_RIGHT				3
#define PLAYER_TEXTURE_EACH_DIRECTION	1
#define PLAYER_BASE_SPEED				5
#define PLAYER_SIZE_X					Globals::item_size
#define PLAYER_SIZE_Y					(Globals::item_size + 24)


//define map
#define PATHFILE_MAP_1			"..\\Data\\Map\\map1.txt"
#define MAP_SIZE_X				14
#define MAP_SIZE_Y				14
#define MAP_TOP_LEFT_CORNER		48					//so 0
#define MAP_TOP_RIGHT_CORNER	49					//so 1
#define MAP_BOTTOM_LEFT_CORNER	50					//so 2
#define MAP_BOTTOM_RIGHT_CORNER	51					//so 3
#define MAP_TOP_BORDER			52					//so 4
#define MAP_LEFT_BORDER			53					//so 5
#define MAP_BOTTOM_BORDER		54					//so 6
#define MAP_RIGHT_BORDER		55					//so 7
#define MAP_ITEM_TREE			56					//so 8
#define MAP_ITEM_BUSH			57					//so 9
#define MAP_PLAYER_SPON			63					//ki tu ?
#define MAP_NOTHING				111					//ki tu o

#define MAP_ITEM_CAN_DESTROY		0				//item which can be destroy
#define MAP_ITEM_CAN_NOT_DESTROY	1				//item which can not be destroy
#define MAP_ITEM_ROAD				2				//item which is road

#define MAP_LEVEL_1					0
#define MAP_LEVEL_2					1
#define MAP_LEVEL_3					2


//define collisionManager
#define COLL_NOT_OK					0				// khong va cham
#define	COLL_OK						1				// va cham

//define rectangle
#define	REC_IS_LINE					-1				// hcn la mot duong thang
#define REC_ABOVE					0				// hai hcn giao nhau
#define	REC_NOT_ABOVE				1				// hai hcn ko giao nhau
#define	REC_OVER_LAP				2				// hai hcn trung nhau

class Globals
{
public:
	static int Globals::screenWidth;
	static int Globals::screenHeight;
	static int Globals::item_size;
	static int Globals::menuGPWidth;
	static int Globals::colMap;
	static int Globals::rowMap;
};

// define value
#define PI 3.14f
#define MAX_DEGREE 360
// define vetex 
#define VETEX_POSITION		(char*)0
#define VETEX_NORM			(char*)0+(sizeof(Vector3))
#define VETEX_BITTANGEN		(char*)0+2*(sizeof(Vector3))
#define VETEX_TANGEN		(char*)0+3*(sizeof(Vector3))
#define VETEX_UV			(char*)0+4*(sizeof(Vector3))

// define type of Models
#define NONE	111 
#define RAW		222 
#define NFG		333

#ifdef WIN32

#define FSCANF fscanf

#elif ANDROID

#define FSCANF fscanf

#endif

// for debug game

#ifdef WIN32 

#define LOGI(...) printf(__VA_ARGS__);
#define LOGE(...) printf(__VA_ARGS__);
#define LOGV(...) printf(__VA_ARGS__);
#define LOGD(...) printf(__VA_ARGS__);
#define LOGW(...) printf(__VA_ARGS__);
#define LOGF(...) printf(__VA_ARGS__);

#elif ANDROID

#include <android/log.h>
#define  LOG_TAG    "GAME"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, __VA_ARGS__)

#endif

#ifndef GAME_DEBUG
#define LOGI(...)
#define LOGE(...)
#define LOGV(...)
#define LOGD(...)
#define LOGW(...)
#define LOGF(...)
#endif

// KEY define 
#ifdef WIN32

#define KEY_BACK			VK_ESCAPE
#define KEY_LEFT			VK_LEFT
#define KEY_RIGHT			VK_RIGHT
#define KEY_UP				VK_UP
#define KEY_DOWN			VK_DOWN
#define KEY_MOVE_LEFT		'A'
#define KEY_MOVE_RIGHT		'D'
#define KEY_MOVE_FORWORD	'W'
#define KEY_MOVE_BACKWORD	'S'

#endif
