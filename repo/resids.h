/* 
 * File:   resids.h
 * Author: user
 *
 * Created on 2013. december 6., 19:44
 */

#ifndef RESIDS_H
#define	RESIDS_H

#ifdef	__cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////
//                              OBJECT'S IDs
/////////////////////////////////////////////////////////////////////////////
#define ID_WINDOW1          10

#define ID_BUTTON1          11
#define ID_BUTTON2          12
#define ID_BUTTON3          13
#define ID_BUTTON4          14
#define ID_BUTTON5          15
#define ID_BUTTON6          16
#define ID_BUTTON7          17

#define ID_BUTTON_BACK      18
#define ID_BUTTON_NEXT      19

#define ID_CHECKBOX1        20
#define ID_CHECKBOX2        21
#define ID_CHECKBOX3        22
#define ID_CHECKBOX4        23
#define ID_CHECKBOX5        24

#define ID_RADIOBUTTON1     30
#define ID_RADIOBUTTON2     31
#define ID_RADIOBUTTON3     32
#define ID_RADIOBUTTON4     33
#define ID_RADIOBUTTON5     34
#define ID_RADIOBUTTON6     35
#define ID_RADIOBUTTON7     36
#define ID_RADIOBUTTON8     37

#define ID_SLIDER1          40
#define ID_SLIDER2          41
#define ID_SLIDER3          42

#define ID_GROUPBOX1        50
#define ID_GROUPBOX2        51
#define ID_STATICTEXT1      52
#define ID_STATICTEXT2      53
#define ID_STATICTEXT3      54

#define ID_PICTURE1         55
//#define ID_STATICTEXT4      56

#define ID_PROGRESSBAR1     60
#define ID_CUSTOM1          70

#define ID_LISTBOX1         80
#define ID_LISTBOX2         81
#define ID_LISTBOX3         82
#define ID_EDITBOX1         83

#define ID_CALL             91
#define ID_STOPCALL         92
#define ID_HOLD             93
#define ID_BACKSPACE        94
#define ID_POUND            95
#define ID_ASTERISK         96
#define ID_KEYPAD           100                         /* uses 100 to 110 for phone key pad demo */

#define ID_ROUNDDIAL        120
#define ID_METER1           130
#define ID_METER2           131
#define ID_DIGITALMETER1    132
#define ID_DIGITALMETER2    133

#define ID_BUTTONHR_P       150
#define ID_BUTTONHR_M       151
#define ID_BUTTONMN_P       152
#define ID_BUTTONMN_M       153
#define ID_BUTTONSC_P       154
#define ID_BUTTONSC_M       155

#define ID_BUTTON_DATE_UP   180
#define ID_BUTTON_DATE_DN   181

#define ID_BUTTON_MO        186
#define ID_BUTTON_DY        187
#define ID_BUTTON_YR        188
#define ID_BUTTON_RET       189

#define ID_EB_MONTH         200
#define ID_EB_DAY           201
#define ID_EB_YEAR          202

#define ID_EB_HOUR          205
#define ID_EB_MINUTE        206
#define ID_EB_SECOND        207

#define NAV_BTN_WIDTH		25

#define WAIT_UNTIL_FINISH(x)    while(!x)

// Language offset definitions
#define LANG_ENGLISH    0
#define LANG_CHINESE    1


#ifdef	__cplusplus
}
#endif

#endif	/* RESIDS_H */

