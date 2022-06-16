#pragma once
#define CTRL_PRESS  1
#define SHIFT_PRESS 2

#define RIGHT      0
#define LEFT	   1
#define PREVCHANNEL 2
#define UP		   3
#define DOWN	   4
#define TOGGLE_CONTROL_KEY  5
#define CHANNELLISTOSD 6
#define ONPIP      7
#define PIPDOWN    8
#define PIPUP      9
#define PIPSWAP    10
#define KEYSTOP    11 
#define KEYEXIT    12
#define KEYMUTE    13
#define KEYFULLSCREEN 14
#define KEYQREC    15
#define KEYDEINT   16
#define KEYFORMAT  17
#define KEYSTRACK  18

#define KEYBRUP      19
#define KEYBRDOWN    20
#define KEYCONUP     21
#define KEYCONDOWN   22
#define KEYSATURUP   23
#define KEYSATURDOWN 24
#define KEYHUEUP     25
#define KEYHUEDWON   26
#define KEYGAMMAUP   27
#define KEYGAMMADOWN 28
#define KEYMASUP     29
#define KEYMASDOWN   30

#define KEYSHOWTIME  31
#define KEYRESTORE   32

#define KEYPIPPOS     33
#define KEYCOMPMODE   34
#define KEYSHOWCANNEL 35

#define KEYOSDCURPROG  36
#define KEYOSDESC      37
#define KEYOSDALLPROG  38
#define KEYOSDUPDATE_ALL_PROG  39
#define KEYOSDUPDATE_ONE_PROG  40
#define KEYCROP 41
#define KEYQRECPiP 42

#define KEYNUMBER_0 43
#define KEYNUMBER_1 44
#define KEYNUMBER_2 45
#define KEYNUMBER_3 46
#define KEYNUMBER_4 47
#define KEYNUMBER_5 48
#define KEYNUMBER_6 49
#define KEYNUMBER_7 50
#define KEYNUMBER_8 51 
#define KEYNUMBER_9 52 
#define KEYNUMBER_POS  53 

#define KEYPAUSE    54	
#define KEYFORWARD  55	
#define KEYREW		56	
#define KEYJUMPFF   57	
#define KEYJUMPBB   58
#define KEYLJUMPFF  59	
#define KEYLJUMPBB  60
#define KEYVOLUMEUP 61
#define KEYVOLUMEDOWN 62
#define KEYPLAY     63

#define KEYMULTIPiP  64
#define KEYCHANNELINFO 65

#define KEYPiPZOOMUP    66
#define KEYPiPZOOMDOWN  67
#define KEY_SLEEP       68
#define KEY_OPTIONS     69


#define  KEY_SHARP_UP   70
#define  KEY_SHARP_DOWN 71

#define  KEY_CONTROL_PANEL 72

#define  KEY_MINIMIZE 73
#define  KEY_OVER_ALL 74
#define  KEY_NORMAL_SPEED 75

#define  KEY_TOGGLE_SHORT_PROGRAMM 76
#define  KEY_OSD_PGUP   77
#define  KEY_OSD_PGDOWN 78
#define  KEY_TOGGLE_MEDIATYPE 79
#define  KEY_OSD_HOME   80
#define  KEY_OSD_END    81

#define  KEY_HIHG_SPEED 82

#define  KEYSNAPSHOT    83
#define  KEYCURRENTRECOSD 84
#define  KEYSHUTDOWN    85
#define  KEYSTOPLASTREC 86
#define  KEYVIDEOTRACKTOGGLE 87
#define  KEY_OSD_AUDIO_TRACK 88
#define  KEY_OSD_VIDEO_TRACK 89
#define  KEY_OSD_SUB_TRACK 90
#define  KEY_OSD_DEINT_TRACK 91
#define  KEY_OSD_CROP_TRACK 92
#define  KEY_OSD_FORMAT_TRACK 93
#define  KEY_OSD_TOGGLE_QPROG 94

#define  KEY_FAV_CHANNEL 95

#define  KEY_OSD_OPTION 96
#define  KEY_TYPEAUDIO_TOGGLE 97
#define  KEY_TIMER_SLEEP  98

#define  KEY_ADD_BOOKMARK 99
#define  KEY_SHOW_BOOKMARK_OSD 100
#define  KEY_SHOW_EXTFILTER_OSD 101

#define  KEY_CHANNEL_NEXT 102
#define  KEY_CHANNEL_PREV 103

#define  KEY_OPEN_FILE    104
#define  KEY_OPEN_URL     105

#define  KEY_RECORD_DUMP  106

#define  KEY_TIMER_SLEEP_EXIT  107

#define  KEY_OSD_MULTIADRESS_SHOW  108

#define  KEY_TOGGLE_PLAY_MODE  109
#define  KEY_TOGGLE_PLAY_MODE_STOP_ON_ERROR  110
#define  KEY_OPEN_FROM_CLIPBOARD  112

#define MAX_ACTION 120
  
class CKeyControl
{
public:
	CKeyControl(void);
	~CKeyControl(void);

PINPUTINFO SearchActionForMenu(LONG MenuId,LONG MenuComm);
void  KeysGetKeyName(PINPUTINFO InpInfo,CString * Name);

BOOL ActionXKey(LONG XKey);
void ActionVirtualKey(LONG CtrlKey,LONG Key,LONG VKey);

int GetActionLircKey(CStringA * Key,CStringA * Remote);

BOOL ExecuteAction(LONG ActionID);
void UpdateInput(void);
inline void SetUseOnlyVKey(LONG Val){UseOnlyVKey=Val;}

INPUTINFO ActionMass[MAX_ACTION];


private:
	void UnregGlobalHotKeys(void);

protected:
LONG UseOnlyVKey;
BOOL b_RegHotKeys;
};

