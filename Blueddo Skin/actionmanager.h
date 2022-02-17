#pragma once

#include <QObject>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QKeyEvent>

#include "config/config.h"
#include "lirc/lirc.h"
#include "keyinput/keyinput.h"
#include "scripts/lua/menu/myluamenuext.h"

#define IS_TOGGLE -1

#define CONNECT_ACTION_EXECUTOR(E) connect(CTheApp::Instance().getActionManager().data(),\
SIGNAL(signal_executAction(int,int)),E,SLOT(slot_executeAction(int,int)),Qt::QueuedConnection);

namespace Action{

//----------------------------------------------------------------------------
//CActionListener
//----------------------------------------------------------------------------
class CActionListener
{
 public:
   CActionListener(bool inStart=false);
   virtual ~CActionListener();
   
 public:
  virtual bool onAction(int,int=-1)=0;  
 
 protected:
  bool verifyActionOrder(void);
  bool m_inStart;
};
//----------------------------------------------------------------------------
//CActionManager
//----------------------------------------------------------------------------
class CActionManager : public QObject
{
 Q_OBJECT
 Q_DISABLE_COPY(CActionManager)
 
 friend CActionListener;

 public:
    CActionManager(QObject *parent=nullptr);

 public:    
    bool onKey(QKeyEvent *e) const;
    void onGlobalKey(int id) const;
    bool onMouseButton(Qt::MouseButton button) const;
    void onMouseWheel(QWheelEvent* e) const;
    
    Lua::CMyLuaMenuExt& getExtMenu(void){return m_LuaMenu;}

    KeyInput::CKeyInput& getKeyInput(void){return m_KeyInput;}

    Q_INVOKABLE void invoke_addExtMenu(TSharedLuaMenuExt_Info p){m_LuaMenu.add(p);}
    Q_INVOKABLE void invoke_removeExtMenu(void* p){m_LuaMenu.remove(p);}
 
 public slots:
    void slot_onConfigEndAction(TSharedConfigEndAction);
    void slot_onLirc(QStringList input) const;
    void slot_executAction(int,int=-1) const;
    void slot_onAppExit(void);

 protected slots:
    void slot_onPlaylistPlayMode(void);
    
    void slot_onTriggeredAudioTrack(void);
    void slot_onTriggeredAudioDevice(void);
    void slot_onTriggeredSpeakerConfig(void);
    void slot_onTriggeredVisualization(void);

    void slot_onTriggeredVideoTrack(void);
    void slot_onTriggeredCrop(void);
    void slot_onTriggeredRatio(void);
    void slot_onTriggeredDeint(void); 
    
    void slot_onTriggeredSubtitleTrack(void);
    void slot_onTriggeredSubtitleEncoding(void);

    void slot_onTriggeredTitleTrack(void);
    void slot_onTriggeredChapterTrack(void);

    void slot_onTriggeredMultiAddress(void);
    void slot_onTriggeredBookmark(void);
   
    void slot_onTriggeredProgram(void);

  public:
    bool eventFilter(QObject *watched, QEvent *e) override;

 signals:
    void  signal_executAction(int,int=-1) const;
    void  signal_globalUserInput(void) const;
 
 protected:
    void restartKeyInput(void);
    void restartLirc(void);
    
    void addListener(CActionListener* listener,bool inStart=false);
    void removeListener(CActionListener* listener);
    bool verifyListener(CActionListener* listener,bool inStart);
    
 private:
  QList<CActionListener*> m_Listeners;
  QScopedPointer<Lirc::CLirc> m_Lirc;
  KeyInput::CKeyInput m_KeyInput;
  Lua::CMyLuaMenuExt  m_LuaMenu;
  
//----------------------------------------------------------------------------
//Actions
//----------------------------------------------------------------------------
 public:
 enum ACTION_TYPE
 {
  NO_ACTION=-1,
  LEFT_CH_PREV= 0,      
  RIGHT_CH_NEXT=1,      
  CHANNEL_FROM_HISTORY=2,  //CBackChannels
  UP_SLIDER_UP= 3,        //CMainPlayerController +
  DOWN_SLIDER_DOWN=	   4,   //CMainPlayerController +
  ENTER_KEY=  5,
  CHANNELLISTOSD= 6, //COsd
  ONPIP=      7,     //CMainPlayerView
  PIPDOWN=    8,     //CPipSingleWindow
  PIPUP=      9,     //CPipSingleWindow
  PIPSWAP=    10,    //CPipSingleWindow
  KEYSTOP=    11, //CMainPlayerController
  KEY_EXIT=    12, //CMainFrame 
  KEY_TOGGLE_MUTE=    13, //CMainPlayerController
  KEY_TOGGLE_FULLSCREEN= 14, //CMainFrame 
  KEY_QREC=    15,         ///CMainPlayerController 
  KEY_TOGGLE_DEINT=   16,  //CMainPlayerController
  KEY_TOGGLE_RATIO=   17,  //CMainPlayerController
  KEY_TOGGLE_ATRACK=  18,  //CMainPlayerController
  
  KEYBRUP=      19,  //CMainPlayerController
  KEYBRDOWN=    20,  //CMainPlayerController
  KEYCONUP=     21,  //CMainPlayerController
  KEYCONDOWN=   22,  //CMainPlayerController
  KEYSATURUP=   23,  //CMainPlayerController
  KEYSATURDOWN= 24,  //CMainPlayerController
  KEYHUEUP=     25,  //CMainPlayerController
  KEYHUEDWON=   26,  //CMainPlayerController
  KEYGAMMAUP=   27,  //CMainPlayerController
  KEYGAMMADOWN= 28,  //CMainPlayerController
  KEY_ZOOM_UP=     29,  //CMainPlayerController
  KEY_ZOOM_DOWN=   30,  //CMainPlayerController
  
  KEY_SHOW_TIME=  31,    //COsd
  KEY_TOGGLE_TRAY=   32, //CMainFrame 

  KEY_TOGGLE_PIP_POSITION=     33, //CPipSingleWindow
  KEY_COMPACT_MODE=   34, //CMainFrame 
  TOGGLE_STANDALONE_PLAYLIST= 35, //CDialogManager

  KEYOSDCURPROG=  36,  //COsd
  KEY_ESC=      37,    
  SHOW_OSD_EPG=  38,   //COsd
  UPDATE_ALL_EPG=  39,         //CEpg
  UPDATE_EPG_FOR_CURRENT_DEPRECATE=  40, //CEpg
  KEY_TOGGLE_CROP= 41,   //CMainPlayerController
  KEY_QREC_PiP= 42,        //CMainPlayerView

  KEYNUMBER_0= 43,  //COsd
  KEYNUMBER_1= 44,  //COsd
  KEYNUMBER_2= 45,  //COsd
  KEYNUMBER_3= 46,  //COsd
  KEYNUMBER_4= 47,  //COsd
  KEYNUMBER_5= 48,  //COsd
  KEYNUMBER_6= 49,  //COsd
  KEYNUMBER_7= 50,  //COsd
  KEYNUMBER_8= 51,  //COsd
  KEYNUMBER_9= 52,  //COsd
  KEYNUMBER_POS=  53, //COsd

  KEYPAUSE=    54,	  //CMainPlayerController
  PLAY_RATE_UP=  55,	  //CMainPlayerController
  PLAY_RATE_DOWN=		56,	  //CMainPlayerController
  KEYJUMPFF=   57,	  //CMainPlayerController
  KEYJUMPBB=   58,    //CMainPlayerController
  KEYLJUMPFF=  59,	  //CMainPlayerController
  KEYLJUMPBB=  60,    //CMainPlayerController
  KEYVOLUMEUP= 61,    //CMainPlayerController
  KEYVOLUMEDOWN= 62,  //CMainPlayerController
  KEYRESTART=     63, //CMainPlayerController

  KEYMULTIPiP=  64,   //CMainPlayerView
  CHANNEL_INFO_OSD= 65,   //COsd

  KEYPiPZOOMUP=    66,  //CMainPlayerView 
  KEYPiPZOOMDOWN=  67,  //CMainPlayerView
  KEY_TURN_OFF=    68, //CMyPower 
  KEY_OPTIONS=     69, //CDialogManager


  KEY_SHARP_UP=   70, //CMainPlayerController
  KEY_SHARP_DOWN= 71, //CMainPlayerController

  KEY_CONTROL_PANEL= 72, //CDialogManager

  KEY_MINIMIZE= 73,    //CMainFrame
  KEY_OVER_ALL= 74,    //CMainFrame 
  KEY_NORMAL_SPEED= 75, //CMainPlayerController

  KEY_TOGGLE_SHORT_PROGRAMM= 76, //COsd
  KEY_OSD_PGUP=   77,
  KEY_OSD_PGDOWN= 78,
  KEY_TOGGLE_MEDIATYPE= 79, //CPlaylist
  KEY_OSD_HOME=   80,
  KEY_OSD_END=    81,

  KEY_HIHG_SPEED= 82, //CMainPlayerController  

  KEY_SNAPSHOT=    83, //CMainPlayerController

  KEY_SCHEDULER_OSD= 84, //COsd
  KEY_SHUTDOWN=    85, //CMyPower 

  KEY_STOP_LAST_RECORD = 86,   //CScheduler 
  KEYVIDEOTRACKTOGGLE= 87, //CMainPlayerController

  KEY_OSD_AUDIO_TRACK= 88, //COsd
  KEY_OSD_VIDEO_TRACK= 89, //COsd
  KEY_OSD_SUBTITLE_TRACK= 90, //COsd
  KEY_OSD_DEINT_TRACK= 91, //COsd
  KEY_OSD_CROP_TRACK= 92, //COsd
  KEY_OSD_RATIO_TRACK= 93, //COsd
  KEY_OSD_TOGGLE_QPROG= 94, //COsd 

  KEY_FAV_CHANNEL= 95, //CPlaylist

  KEY_OSD_OPTION= 96,  //COsd
  SPEAKER_CONFIG_TOGGLE= 97, //CMainPlayerController
  
  KEY_TIMER_SLEEP=  98,  //CMyPower

  KEY_ADD_BOOKMARK= 99,        //CPlaylist
  KEY_SHOW_BOOKMARK_OSD= 100,  //COsd
  KEY_SHOW_EXTFILTER_OSD= 101, //COsd

  KEY_CHANNEL_NEXT_ALT_PGDOWN= 102,  //CPlaylist
  KEY_CHANNEL_PREV_ALT_PGUP= 103,  //CPlaylist

  KEY_OPEN_FILE=    104,  //CDialogManager
  KEY_OPEN_URL =    105,  //CDialogManager

  KEY_RECORD_DUMP=  106,  //CMainPlayerController

  KEY_TIMER_EXIT = 107, //CMyPower

  KEY_OSD_MULTIADDRESS_SHOW=  108,  //CMainPlayerController

  KEY_TOGGLE_PLAY_MODE=  109,  //CPlaylist
  KEY_TOGGLE_PLAY_MODE_STOP_ON_ERROR = 110,  //CPlaylist
  
  KEY_OPEN_FROM_CLIPBOARD=  112, //CDialogManager

  KEY_REBOOT_COMP=  113, //CMyPower 

  SHOW_MEDIA_INFO =  114, //CDialogManager
  REFRESH_PLAYLIST = 115, //CPlaylist 

  KEY_CHAPTER_SHOW_OSD = 116, //COsd
  KEY_CHAPTER_NEXT= 117,  //CMainPlayerController
  KEY_CHAPTER_PREV= 118,  //CMainPlayerController
  KEY_PREVIEW_PIP=  119,  //CMainPlayerView

  KEY_PLAY_ONLY =  120, //CMainPlayerController
  KEY_PAUSE_ONLY = 121, //CMainPlayerController

  KEY_ENTER_PROTECT_CODE=  122, //CParentalControl

  LEFT_SLIDER_DOWN= 123, //CMainPlayerController +
  RIGHT_SLIDER_UP= 124,  //CMainPlayerController +
  UP_CH_PREV =125,       //CPlaylist +
  DOWN_CH_NEXT= 126,     //CPlaylist +
  UP_CH_NEXT= 127,		 //CPlaylist +	  
  DOWN_CH_PREV= 128,     //CPlaylist +

  SHOW_SCHEDULER= 129,   //CDialogManager
  SHOW_SCAN_WINDOW= 130, //CDialogManager 
  SHOW_MESSAGES_WINDOW= 131, //CDialogManager
  
  PIP_SOUND_SWAP=  132,  //CMainPlayerView

  FAV_TOGGLE=     133,   //CTreeOsd, CPlaylist 

  LOAD_PLAYLIST=  134,    //CPlaylist
  UNLOAD_PLAYLIST=  135,  //CPlaylist
  
  MAINFRAME_TOUCH_VOUT =  136,      //CMainFrame
  MAINFRAME_SIZE_ORIG_VIDEO =  137, //CMainFrame
  MAINFRAME_SIZE_DIV2_VIDEO =  138, //CMainFrame
  MAINFRAME_SIZE_MUL2_VIDEO =  139, //CMainFrame
  
  SHOW_RECORDS_FOLDER = 140,   //CScheduler 
  SHOW_EPG=  141,              //CDialogManager

  SUBTITLE_DISABLE_AT_START=142,  //CMainPlayerController
  SUBTITLE_AUTO_DETECT=143,       //CMainPlayerController
  SUBTITLE_LOAD_FILE=144,         //CMainPlayerController

  ABOUT=145,                      //CDialogManager 
  CHECK_UPDATES=146, 
  GOTO_MAIN_SITE=147,             //CDialogManager 
  GOTO_BUGTRACKER=148,            //CDialogManager
  
  VISUALIZATION_TOGGLE=149,         //CMainPlayerController
  SINGLE_PIP_TOGGLE_SHOW_NAME=  150,   //CPipSingleWindow
  TOGGLE_RANDOM_MODE=  151,        //CPlaylist
  SINGLE_PIP_PLAYCHANNEL=  152,    //

  OSD_PICTURE_SETTINGS= 153, //COsd
  OSD_SYNCHRONIZATION_SETTINGS= 154, //COsd

  SHOW_CURRENT_CHANNEL= 155, //CPlaylist
  PIP_RESTART_CURRENT_CHANNEL=156,  //CPipSingleWindow CMultiPipContainer CPreViewPipWindow  

  KEY_OSD_AUDIO_DEVICE = 157,  //COsd

  KEY_CHANNEL_NEXT_ALT_PGUP= 158,  //CPlaylist
  KEY_CHANNEL_PREV_ALT_PGDOWN= 159,  //CPlaylist

  KEY_OSD_SHOW_ALL_CONTROL_WINDOW= 160,  //COsd
  KEY_OSD_SHOW_CURRENT_EPD_DESC = 161   //COsd
 };
 //----------------------------------------------------------------------------
};
}
typedef QSharedPointer<Action::CActionManager> TSharedAction;
Q_DECLARE_METATYPE(TSharedAction);
