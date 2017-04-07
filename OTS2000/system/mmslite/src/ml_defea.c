/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER	*****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*		       1997 All Rights Reserved				*/
/*									*/
/* MODULE NAME : ml_defea.c						*/
/* PRODUCT(S)  : MMS-EASE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION	LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/11/04  GLB     04    Remove "thisFileName"                    	*/
/* 10/14/03  JRB     03    Del unnecessary casts.			*/
/* 09/13/99  MDE     02    Added SD_CONST modifiers			*/
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

/************************************************************************/
/************************************************************************/
/* m_log_defea_req                                                      */
/************************************************************************/


ST_VOID m_log_defea_req (DEFEA_REQ_INFO *info)
  {
MODIFIER *mod_ptr;
ST_INT j;

  MLOG_CALWAYS0 ("Event Action Name Follows:");
  m_log_objname (&(info->evact_name));
  
  MLOG_CALWAYS0 ("Confirmed Serv Request : ");
  MLOG_ALWAYSH (info->conf_serv_req_len,info->conf_serv_req);

  if (info->cs_rdetail_pres)
    {
    MLOG_CALWAYS0 ("Comp Std Request Detail Follows:");
    MLOG_ALWAYSH (info->cs_rdetail_len,info->cs_rdetail);
    }
  else
    {
    MLOG_CALWAYS0 ("Comp Std Request Detail : Not present");
    }

  if (info->modlist_pres)
    {
    MLOG_CALWAYS1 ("Number of Modifiers : %d",info->num_of_modifiers);
    mod_ptr = (MODIFIER *) (info + 1);
    for (j = 0; j < info->num_of_modifiers; j++)
      {
      MLOG_CALWAYS1 ("Modifier : %d", j+1);
      m_log_modifier (mod_ptr);
      mod_ptr++;
      }
    }
  else
    {
    MLOG_CALWAYS0 ("List of Modifiers : Not present");
    }
  }



