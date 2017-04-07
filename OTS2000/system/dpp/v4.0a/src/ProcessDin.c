/************************************************************************************************************************************************
FILENAME:	ProcessDin.c
FUNCTION:	
		functions of  processing pol data of dpp_data to form all send packet and alarm packet :Process_POL()

VERSION:	v4.0a
OPERATE SYSTEM:	window 2000, Unix

HISTORY:	2006.04.20		ycx
************************************************************************************************************************************************/

#include "../../../dms/v4.0a/inc/dms_com.h"

#include "../../../dps/v4.0a/inc/dps_rec_def.h"
#include "../../../dps/v4.0a/inc/dps_type_def.h"
#include "../../../dps/v4.0a/inc/ipc_common.h"

#include "../../../lan/v4.0a/inc/lan_common.h"
#include "../../../plc/v4.0a/inc/lcu_data.h"

#include "../../../dpp/v4.0a/inc/dppdef.h"
#include "../../../dpp/v4.0a/inc/dpp_functions.h"



void Process_POL(LCUID lcuno,USHORT offset,USHORT length,DPP_DATA *dpp,DATE_TIME tm)

{

       /* printf("\n Now is POL_TYPE !!!!!!!\n");*/

	Process_IND_ALL(lcuno,POL_TYPE, offset,length,dpp);
	 
	Process_IND(lcuno,POL_TYPE,offset,length,dpp,tm);

}
