/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2019 The Open Watcom Contributors. All Rights Reserved.
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
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#define FECALL_CALLER_POPS              ( 0x00000001LL << _TARG_AUX_SHIFT )
#define FECALL_DLL_EXPORT               ( 0x00000002LL << _TARG_AUX_SHIFT )
#define FECALL_SPECIAL_RETURN           ( 0x00000004LL << _TARG_AUX_SHIFT )
#define FECALL_SPECIAL_STRUCT_RETURN    ( 0x00000008LL << _TARG_AUX_SHIFT )
#define FECALL_FAR_CALL                 ( 0x00000010LL << _TARG_AUX_SHIFT )
#define FECALL_INTERRUPT                ( 0x00000020LL << _TARG_AUX_SHIFT )
#define FECALL_LOAD_DS_ON_CALL          ( 0x00000040LL << _TARG_AUX_SHIFT )
#define FECALL_LOAD_DS_ON_ENTRY         ( 0x00000080LL << _TARG_AUX_SHIFT )
#define FECALL_MODIFY_EXACT             ( 0x00000100LL << _TARG_AUX_SHIFT )
#define FECALL_NO_8087_RETURNS          ( 0x00000200LL << _TARG_AUX_SHIFT )
#define FECALL_NO_FLOAT_REG_RETURNS     ( 0x00000400LL << _TARG_AUX_SHIFT )
#define FECALL_NO_MEMORY_CHANGED        ( 0x00000800LL << _TARG_AUX_SHIFT )
#define FECALL_NO_MEMORY_READ           ( 0x00001000LL << _TARG_AUX_SHIFT )
#define FECALL_NO_STRUCT_REG_RETURNS    ( 0x00002000LL << _TARG_AUX_SHIFT )
#define FECALL_ROUTINE_RETURN           ( 0x00004000LL << _TARG_AUX_SHIFT )
#define FECALL_FAT_WINDOWS_PROLOG       ( 0x00008000LL << _TARG_AUX_SHIFT )
#define FECALL_GENERATE_STACK_FRAME     ( 0x00010000LL << _TARG_AUX_SHIFT )
#define FECALL_EMIT_FUNCTION_NAME       ( 0x00020000LL << _TARG_AUX_SHIFT )
#define FECALL_GROW_STACK               ( 0x00040000LL << _TARG_AUX_SHIFT )
#define FECALL_PROLOG_HOOKS             ( 0x00080000LL << _TARG_AUX_SHIFT )
#define FECALL_THUNK_PROLOG             ( 0x00100000LL << _TARG_AUX_SHIFT )
#define FECALL_EPILOG_HOOKS             ( 0x00200000LL << _TARG_AUX_SHIFT )
#define FECALL_FAR16_CALL               ( 0x00400000LL << _TARG_AUX_SHIFT )
#define FECALL_TOUCH_STACK              ( 0x00800000LL << _TARG_AUX_SHIFT )
#define FECALL_LOAD_RDOSDEV_ON_ENTRY    ( 0x01000000LL << _TARG_AUX_SHIFT )
#define FECALL_FARSS                    ( 0x02000000LL << _TARG_AUX_SHIFT )
#define LAST_TARG_AUX_ATTRIBUTE         ( 0x02000000LL << _TARG_AUX_SHIFT )

#if LAST_TARG_AUX_ATTRIBUTE == 0
    #error Overflowed a long long constant in x86auxa.h
#endif

typedef unsigned long long      call_class;

#define FLOATING_FIXUP_BYTE     0xFF

#define BYTE_SEQ_SYM    void *
#define BYTE_SEQ_OFF    unsigned

typedef enum {
    #define pick_fp(enum,name,alt_name,win,alt_win,others,alt_others) FIX_ ## enum,
    #include "fppatche.h"
    #undef pick_fp
    FIX_SYM_OFFSET,     /* followed by a long */
    FIX_SYM_SEGMENT,    /* .. */
    FIX_SYM_RELOFF      /* .. */
} cg_fixups;

typedef unsigned    byte_seq_len;

#define STRUCT_BYTE_SEQ( x ) \
{ \
    byte_seq_len    length; \
    bool            relocs; \
    byte            data[x]; \
}

typedef struct byte_seq STRUCT_BYTE_SEQ( 1 ) byte_seq;
