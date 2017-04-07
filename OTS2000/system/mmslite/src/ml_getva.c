/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER	*****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*		       1997 All Rights Reserved				*/
/*									*/
/* MODULE NAME : ml_getva.c						*/
/* PRODUCT(S)  : MMS-EASE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION	LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/11/04  GLB     05    Remove "thisFileName"                    	*/
/* 09/13/99  MDE     04    Added SD_CONST modifiers			*/
/* 08/13/98  MDE     03    Added m_log_tdl				*/
/* 06/22/98  MDE     02    Now allow TDL up to 10000 bytes long		*/
/* 06/09/97  MDE     01    Created from existing MLOG source		*/
/************************************************************************/


#include "glbtypes.h"
#include "sysincs.h"

#ifndef MMS_LITE
#include "mms_usr.h"		/* to access MMS fucntions, variables   */
#else
#include "mmsdefs.h"
#endif
#include "mloguser.h"
#include "mem_chk.h"

/************************************************************************/
/************************************************************************/
/* m_log_getvar_req                                                     */
/************************************************************************/


ST_VOID m_log_getvar_req (GETVAR_REQ_INFO *info)
  {

  if ( info->req_tag == 0 )
    {
    m_log_objname (&info->name);
    }
  else
    {
    m_log_address (&info->address);
    }

  }


/************************************************************************/
/* m_log_getvar_resp                                                 */
/************************************************************************/


ST_VOID m_log_getvar_resp (GETVAR_RESP_INFO *info)
  {
  if ( info->mms_deletable )
    {
    MLOG_CALWAYS0 ("MMS Deletable : YES");
    }
  else
    {
    MLOG_CALWAYS0 ("MMS Deletable : NO");
    }

  if ( info->address_pres )
    {
    m_log_address (&info->address);
    }
  else
    {
    MLOG_CALWAYS0 ("Address : Not Present ");
    }
  m_log_tdl (info->type_spec.data, info->type_spec.len); 
  }
