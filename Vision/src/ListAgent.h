/* 
 * The contents of this file are subject to the Mozilla Public 
 * License Version 1.1 (the "License"); you may not use this file 
 * except in compliance with the License. You may obtain a copy of 
 * the License at http://www.mozilla.org/MPL/ 
 * 
 * Software distributed under the License is distributed on an "AS 
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or 
 * implied. See the License for the specific language governing 
 * rights and limitations under the License. 
 * 
 * The Original Code is Vision. 
 * 
 * The Initial Developer of the Original Code is The Vision Team.
 * Portions created by The Vision Team are
 * Copyright (C) 1999, 2000, 2001 The Vision Team.  All Rights
 * Reserved.
 * 
 * Contributor(s): Wade Majors <wade@ezri.org>
 *                 Rene Gollent
 *                 Todd Lair
 *                 Andrew Bazan
 *                 Jamie Wilkinson
 */

#ifndef _LISTAGENT_H_
#define _LISTAGENT_H_

#include <View.h>
#include <String.h>
#include <Messenger.h>
#include <MessageRunner.h>
#include <regex.h>

class BColumnListView;
class BScrollView;
class BMenuItem;
class StatusView;
class WindowListItem;

class ListAgent : public BView
{
  public:

                            ListAgent (BRect, const char *, BMessenger *);
    virtual                 ~ListAgent (void);
    virtual void            MessageReceived (BMessage *);
    virtual void            AttachedToWindow (void);
	virtual void			AllAttached (void);
    virtual void			Show(void);

    WindowListItem          *agentWinItem;
    BMessenger              msgr;
    
  private:
    BMessenger              *sMsgr;
    BMessageRunner          *listUpdateTrigger;
	BMenuBar				*mBar;
    BColumnListView               *listView;
    StatusView              *status;

    BString                 filter,
                              find,
                              statusStr;
    regex_t                 re,
                              fre;
                              
    bool                    processing;

    BMenuItem               *mFilter,
                              *mFind,
                              *mFindAgain;

    friend class WindowList;
};

const uint32 M_LIST_FIND               = 'lalf';
const uint32 M_LIST_FAGAIN             = 'lafa';
const uint32 M_LIST_FILTER             = 'lafr';
const uint32 M_LIST_INVOKE             = 'lali';
const uint32 M_LIST_UPDATE             = 'lalu';
#endif
