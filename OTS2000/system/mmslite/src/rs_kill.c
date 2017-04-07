/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	  1986 - 2001, All Rights Reserved.		        */
/*									*/
/*		    PROPRIETARY AND CONFIDENTIAL			*/
/*									*/
/* MODULE NAME : rs_kill.c						*/
/* PRODUCT(S)  : MMSEASE, MMSEASE-LITE					*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*	This module contains the responder portion of the kill		*/
/*	operation.  It decodes the kill request (indication) and	*/
/*	encodes the kill response.					*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/11/04  GLB     05    Remove "thisFileName"                    	*/
/* 12/20/01  JRB     04    Converted to use ASN1R (re-entrant ASN1)	*/
/* 09/13/99  MDE     03    Added SD_CONST modifiers			*/
/* 03/23/99  MDE     02    Changes to decode buffer allocation scheme	*/
/* 07/03/97  MDE     01    Op-specific info buffer handling changes	*/
/* 06/09/97  MDE     01    Changed op specific buffer allocation	*/
/* 04/02/97  DTL   7.00    MMSEASE 7.0 release. See MODL70.DOC for	*/
/*			   history.					*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"

#include "mmsdefs.h"
#include "mms_pprg.h"
#include "asn1defs.h"

/************************************************************************/
/* variables global to the DECODE portion :				*/

static  KILL_REQ_INFO	*req_info;

/************************************************************************/
/* variables global to the ENCODE portion : NONE			*/

static ST_VOID kill_get_piname (ASN1_DEC_CTXT *aCtx);


/************************************************************************/
/************************************************************************/
/*			mms_kill_req					*/
/* This function is called from MMSDEC when the opcode for this 	*/
/* operation is decoded. Setup state machine function pointers, etc.	*/
/************************************************************************/

ST_VOID mms_kill_req (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("Kill Request");


/* get storage for request information		*/
  req_info = (KILL_REQ_INFO *) _m_get_dec_buf (aCtx, sizeof (KILL_REQ_INFO));
  ASN1R_TAG_ADD (aCtx, CTX, 0, kill_get_piname);
  }

/************************************************************************/
/*			kill_get_piname 				*/
/* kill request is being decoded: get the program invocation name.	*/
/************************************************************************/

static ST_VOID kill_get_piname (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("kill_get_piname");

			/* read program invocation name from message	*/
  if (asn1r_get_identifier (aCtx, req_info->piname))
    asn1r_set_dec_err (aCtx, REQ_BAD_VALUE);

  _ms_set_cs_check (aCtx);		/* check for Companion Standard info	*/
  }


#ifndef MMS_LITE
/************************************************************************/
/************************************************************************/
/*			mp_kill_resp					*/
/* This function is called from either the application or the virtual	*/
/* machine to ENCODE and send the kill response.			*/
/************************************************************************/

ST_RET mp_kill_resp (MMSREQ_IND *indptr)
  {
  return (_mms_send_null_resp (indptr,MMSOP_KILL));
  }

#else
/************************************************************************/
/************************************************************************/
/*			mpl_kill_resp					*/
/* This function is called from either the application or the virtual	*/
/* machine to ENCODE the kill response.					*/
/************************************************************************/

ST_RET mpl_kill_resp (ST_UINT32 invoke_id)
  {
  return (_mms_fin_null_resp (invoke_id,MMSOP_KILL));
  }
#endif
