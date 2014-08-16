/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Semantic actions interface for WIN grammar (used by yydriver).
*
****************************************************************************/


#ifndef SEMANTCW_H_INCLUDED
#define SEMANTCW_H_INCLUDED

#include "yydrivrw.h"

#include "semmenuw.h"
#include "semdiagw.h"
#include "semtbarw.h"
#include "semverw.h"
#include "semsnglw.h"
#include "semresfl.h"

extern FullMemFlags     SemWINAddFirstMemOption( YYTOKENTYPE token );
extern FullMemFlags     SemWINAddMemOption( FullMemFlags, YYTOKENTYPE token );
extern char             *SemWINTokenToString( YYTOKENTYPE token );
extern void             SemWINSetGlobalLanguage( const WResLangType *newlang );
extern void             SemWINSetResourceLanguage( const WResLangType *newlang, bool from_parser );
extern void             SemWINUnsupported( YYTOKENTYPE token );
extern void             SemWINCheckMemFlags( FullMemFlags * currflags,
                                ResMemFlags loadopts, ResMemFlags memopts,
                                ResMemFlags pureopts );

#endif
