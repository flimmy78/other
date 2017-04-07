#include <string.h>
 
 
#include    "../inc/os_type_def.h"
 
#include    "../inc/dms_std.h"
#include    "../inc/dms_data_def.h"
#include    "../inc/dms_util_def.h"
#include    "../inc/dms_com.h"
#include    "../inc/dms_functions.h"




extern DBS_GBL_COMMON  *db_ptr;

int	GetCommonPtrById( POINTER *point, DMS_COMMON_PTR *common_ptr);
int	GetCommonPtrByNameStr( char *ptNameStr, DMS_COMMON_PTR *common_ptr);

/*Get database general info*/
int GetDBName( char *dbName )
{
	strcpy(dbName, db_ptr->Head_Union.head.dbName);
    return 0;
}


int GetDBLongname( char *dbLongname )
{
	strcpy(dbLongname, db_ptr->Head_Union.head.dbLongname);
    return 0;
}


int GetDBVersion( char *dbVersion )
{
	strcpy(dbVersion, db_ptr->Head_Union.head.version);
    return 0;
}


int GetStationNum( GULONG *stn_num )
{
    *stn_num= db_ptr->Head_Union.head.stn_num;
    Swap4Byte(stn_num);
    return 0;
}


int GetStnIdByIndex( UCHAR stnIndex, UCHAR *stnId ) //index from 1
{
    int  stn_num;

	stn_num= db_ptr->Head_Union.head.stn_num;
	Swap4Byte(&stn_num);

	if(stnIndex==0 || stnIndex > stn_num)
	{
		SendErrMsg(0, "No such station index in db: %d", stnIndex);
		return -1;
	}

	*stnId= db_ptr->Station_Union.StationEntry[stnIndex-1].stnId;
    return 0;
}
int GetStnIndexById( UCHAR stnId, UCHAR *stnIndex ) //index from 1
{
    int  stn_num, i;
    char err_str[128];
	
	//CHECK_DB_VALID_WAIT();
	stn_num= db_ptr->Head_Union.head.stn_num;
	Swap4Byte(&stn_num);
	
	for(i=0; i<stn_num; i++)
	{
		if(db_ptr->Station_Union.StationEntry[i].stnId == stnId)
		{
			*stnIndex= i+1;
			return 0;
		}
	}
	sprintf(err_str, "No such a station id: %d", stnId);
	Err_log(err_str);
    return -1;
}
static STATION_ENTRY* GetStnEntryPtrById(UCHAR stnId)
{
    int  i, stn_num;
    char err_str[128];

	stn_num= db_ptr->Head_Union.head.stn_num;
	Swap4Byte(&stn_num);

	for(i=0; i<stn_num; i++)
	{
		if(stnId == db_ptr->Station_Union.StationEntry[i].stnId)
			return db_ptr->Station_Union.StationEntry+i;
	}
	
  	sprintf(err_str, "No such a station id: %d", stnId);
  	Err_log(err_str);
	return (STATION_ENTRY*)-1;
}

int GetStnNameById( UCHAR stnId, char *stnName )
{
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

	strcpy(stnName, stn_ptr->stnName);
	return 0;
}


int GetStnLongnameById( UCHAR stnId, char *stnLongname )
{
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

#ifdef EXTEND_LANGUAGE_SYSTEM
	if(GetExLangState())
		strcpy(stnLongname, stn_ptr->stnExLongname);
	else
#endif
		strcpy(stnLongname, stn_ptr->stnLongname);
    return 0;
}

int GetStnCommentById( UCHAR stnId, char *stnComment )
{
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

#ifdef EXTEND_LANGUAGE_SYSTEM
	if(GetExLangState())
		strcpy(stnComment, stn_ptr->stnExComment);
	else
#endif
		strcpy(stnComment, stn_ptr->stnComment);
    return 0;
}


int GetStnIdByName( char *stnName, UCHAR *stnId )
{
    int i, stn_num;
    char err_str[256];

	if(!stnName[0])
	{
  		Err_log("Station name empty");
		return -1;
	}

	stn_num= db_ptr->Head_Union.head.stn_num;
	Swap4Byte(&stn_num);
  	for(i=0;i<stn_num;i++)
  	{
		if(stnName[0]!=db_ptr->Station_Union.StationEntry[i].stnName[0])
			continue;
        if(!strcmp(stnName, db_ptr->Station_Union.StationEntry[i].stnName))
		{
			*stnId= db_ptr->Station_Union.StationEntry[i].stnId;
			return 0;
		}
  	}

  	sprintf(err_str, "No such a station: %s", stnName);
  	Err_log(err_str);
  	return -1;
}


int GetStnTypeById( UCHAR stnId, UCHAR *stnType )
{
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    *stnType= stn_ptr->stnType;
	return 0;
}


int GetStnSysLcuIdById( UCHAR stnId, UCHAR *sysLcuId )
{
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

	*sysLcuId= stn_ptr->sysLcuId;
	return 0;
}


int GetGroupNumById( UCHAR stnId, GULONG *grp_num )
{
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    *grp_num= stn_ptr->grp_num;
    Swap4Byte(grp_num);
    return 0;
}



int GetGroupNameById( UCHAR stnId, UCHAR groupId, char *groupName )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;
	strcpy(groupName, db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName);
    return 0;
}



int GetGroupLongnameById( UCHAR stnId, UCHAR groupId, char *groupLongname )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;

#ifdef EXTEND_LANGUAGE_SYSTEM
	if(GetExLangState())
		strcpy(groupLongname, db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpExLongname);
	else
#endif
		strcpy(groupLongname, db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpLongname);
    return 0;
}


int GetGroupCommentById( UCHAR stnId, UCHAR groupId, char *groupComment )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;
	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpComment[0])
		return -1;
    
#ifdef EXTEND_LANGUAGE_SYSTEM
	if(GetExLangState())
		strcpy(groupComment, db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpExComment);
	else
#endif
		strcpy(groupComment, db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpComment);
    return 0;
}


int GetGroupIdByName( UCHAR stnId, char *groupName, UCHAR *grpId )
{
    int		grp_offset, grp_num, grp_pos;
    char	err_str[128];
	GULONG	key;
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;
	
	if(!strcmp(groupName, ""))
	{
  		Err_log("group name empty");
		return -1;
	}

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	GetNameStrHash(groupName, &key);
	Swap4Byte(&key);
    for(grp_pos=grp_offset;grp_pos<(grp_num+grp_offset);grp_pos++)
    {
		if(key!=db_ptr->Group_Union.GroupEntry[grp_pos].hash_key)
			continue;
		if(!strcmp(groupName, db_ptr->Group_Union.GroupEntry[grp_pos].grpName))
		{
			*grpId= grp_pos-grp_offset+1;
			return 0;
		}
	}
   	sprintf(err_str, "No such a group: %d-%s", stnId, groupName);
   	Err_log(err_str);
   	return -1;
}


int GetGroupTypeNameById( UCHAR stnId, UCHAR groupId, char *groupTypeName )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	/*spare group also has typename*/
	/*if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;*/
        
	strcpy(groupTypeName, db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpTypeName);
    return 0;
}


int GetGroupSysLcuFlagById( UCHAR stnId, UCHAR groupId, UCHAR *sysLcuFlag )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;
        
    *sysLcuFlag= db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].sysLcuFlag;
    return 0;
}


int GetLcuIoGroupCommentById( UCHAR stnId, UCHAR devId, UCHAR ioGroup, char *ioGroupComment )
{
    int  grp_offset, grp_num;
    char err_str[128];
	UCHAR	i;
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(devId<1 || (devId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", devId);
   		Err_log(err_str);
   		return -1;
   	}

	/*spare group also has typename*/
	/*if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;*/
       
	for(i=0; i<db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.num; i++)
	{
		if(db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i].ioGroup == ioGroup)
		{
#ifdef EXTEND_LANGUAGE_SYSTEM
			if(GetExLangState())
				strcpy(ioGroupComment, db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i].exComment);
			else
#endif
				strcpy(ioGroupComment, db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i].comment);
			return 0;
		}
	}
	SendWarnMsg(1, "Fail to find LCU%d.%d ioGroup %d", stnId, devId, ioGroup);
    return -1;
}

int GetLcuIoGroupNumById( UCHAR stnId, UCHAR devId, int *ioGroup_num )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(devId<1 || (devId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", devId);
   		Err_log(err_str);
   		return -1;
   	}

	/*spare group also has typename*/
	/*if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;*/
       
	*ioGroup_num= db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.num;
	return 0;
}

int GetLcuIoGroupInfoByIndex( UCHAR stnId, UCHAR devId, int index, IOGROUP_INFO *ioGroupInfo)
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(devId<1 || (devId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", devId);
   		Err_log(err_str);
   		return -1;
   	}

	if(index<0 || index>=db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.num)
	{
		SendErrMsg(1, "ioGroup index %d is overrange: LCU%d.%d ioGroup num %d", stnId, devId, index, 
			db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.num);
		return -1;
	}
	*ioGroupInfo= db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[index];
	Swap4Byte(&ioGroupInfo->ioGroupStatus);
	return 0;
}

int GetLcuIoGroupInfoById( UCHAR stnId, UCHAR devId, UCHAR ioGroup, IOGROUP_INFO *ioGroupInfo )
{
    int  grp_offset, grp_num;
    char err_str[128];
    int  ioGroup_num, i;
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(devId<1 || (devId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", devId);
   		Err_log(err_str);
   		return -1;
   	}

	ioGroup_num= db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.num;
	for(i=0; i<ioGroup_num; i++)
	{
		if(db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i].ioGroup==ioGroup)
		{
			*ioGroupInfo= db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i];
			Swap4Byte(&ioGroupInfo->ioGroupStatus);
			return 0;
		}
	}
	SendErrMsg(1, "Fail to find ioGroup %d: LCU%d.%d", ioGroup, stnId, devId);
	return -1;
}

int SetLcuIoGroupStatusById( UCHAR stnId, UCHAR devId, UCHAR ioGroup, UINT ioGroupStatus )
{
    int  grp_offset, grp_num;
    char err_str[128];
    int  ioGroup_num, i;
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);
	
	if(devId<1 || (devId-1)>grp_num)
   	{
		sprintf(err_str, "No such a group: %d", devId);
		Err_log(err_str);
		return -1;
   	}
	
	ioGroup_num= db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.num;
	for(i=0; i<ioGroup_num; i++)
	{
		if(db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i].ioGroup==ioGroup)
		{
			Swap4Byte(&ioGroupStatus);
			db_ptr->Group_Union.GroupEntry[grp_offset+devId-1].iogroup_def.iogroup[i].ioGroupStatus= ioGroupStatus;
			return 0;
		}
	}
	SendErrMsg(1, "Fail to find ioGroup %d: LCU%d.%d", ioGroup, stnId, devId);
	return -1;
}


int GetRecordNumById( UCHAR stnId, UCHAR groupId, GULONG *rec_num )
{
    int  grp_offset, grp_num;
    char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;
        
    *rec_num= db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].rec_num;
    Swap4Byte(rec_num);
    return 0;
}



/*Get database record info*/
static int	GetRecPositionByOffset(UCHAR stnId, UCHAR groupId, UCHAR offset)
{
   	int  rec_offset, rec_num;
    int  grp_offset, grp_num;
	char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;
		
    rec_num= db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].rec_num;
    rec_offset= db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].rec_offset;
    Swap4Byte(&rec_num);
    Swap4Byte(&rec_offset);
	if(offset>=rec_num)
   		return -1;
   	return rec_offset+offset;
}

static int GetRecPosition( UCHAR stnId, UCHAR groupId, UCHAR recType )
{
   	int  rec_pos, rec_offset, rec_num;
    int  grp_offset, grp_num;
	char err_str[128];
	STATION_ENTRY *stn_ptr= GetStnEntryPtrById(stnId);
	
	if((STATION_ENTRY*)-1 == stn_ptr)
		return -1;

    grp_num= stn_ptr->grp_num;
    grp_offset= stn_ptr->grp_offset;
    Swap4Byte(&grp_num);
    Swap4Byte(&grp_offset);

	if(groupId<1 || (groupId-1)>grp_num)
   	{
   		sprintf(err_str, "No such a group: %d", groupId);
   		Err_log(err_str);
   		return -1;
   	}

	if(!db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].grpName[0])
		return -1;
		
    rec_num= db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].rec_num;
    rec_offset= db_ptr->Group_Union.GroupEntry[grp_offset+groupId-1].rec_offset;
    Swap4Byte(&rec_num);
    Swap4Byte(&rec_offset);
    for(rec_pos=rec_offset;rec_pos<(rec_num+rec_offset);rec_pos++)
    {
    	if(db_ptr->Record_Union.RecordEntry[rec_pos].recType==recType)
			return rec_pos;
	}
   	return -1;
}



int GetRecNameByType( UCHAR recType, char *recName )
{
	if( (recType==ANA_TYPE) 
		|| ((recType>=IMP_TYPE) && (recType<=CURVE_TYPE)) 
		|| ((recType>=PARAM_TYPE) && (recType<=TIME_TYPE)) )
	{
		strcpy(recName, recordname[recType]);
		return 0;
	}
	return -1;
}


int GetRecLongnameByType( UCHAR recType, char *recLongname )
{
	if( (recType==ANA_TYPE) 
		|| ((recType>=IMP_TYPE) && (recType<=CURVE_TYPE)) 
		|| ((recType>=PARAM_TYPE) && (recType<=TIME_TYPE)) )
	{
#ifdef EXTEND_LANGUAGE_SYSTEM
		if(GetExLangState())
			strcpy(recLongname, recordExlongname[recType]);
		else
#endif
			strcpy(recLongname, recordlongname[recType]);
		return 0;
	}
	return -1;
}


int GetRecTypeByName( char *recName, UCHAR *recType )
{
	int	i;
	
	if( recName[0]==0 )
		return -1;
	for(i=1;i<MAX_DATATYPE_NUM;i++)
	{
		if(recName[0]!=recordname[i][0])
			continue;
		if( strcmp(recName, recordname[i])==0 )
		{
			*recType= i;
			return 0;
		}
	}
	return -1;
}



int GetEntryNumById( UCHAR stnId, UCHAR groupId, UCHAR recType, GULONG *entry_num )
{
   	int  rec_pos;

	rec_pos= GetRecPosition( stnId, groupId, recType );
	if( rec_pos<0 )
		return -1;
        
    *entry_num= db_ptr->Record_Union.RecordEntry[rec_pos].entry_num;
    Swap4Byte(entry_num);
    return 0;
}


int GetRecTypeByOffset( UCHAR stnId, UCHAR groupId, UCHAR offset, UCHAR *recType )
{
   	int  rec_pos;

	rec_pos= GetRecPositionByOffset( stnId, groupId, offset );
	if( rec_pos<0 )
		return -1;
        
    *recType= db_ptr->Record_Union.RecordEntry[rec_pos].recType;
    return 0;
}


int GetEntryNumByRecOffset( UCHAR stnId, UCHAR groupId, UCHAR offset, GULONG *entry_num )
{
   	int  rec_pos;

	rec_pos= GetRecPositionByOffset( stnId, groupId, offset );
	if( rec_pos<0 )
		return -1;
        
    *entry_num= db_ptr->Record_Union.RecordEntry[rec_pos].entry_num;
    Swap4Byte(entry_num);
    return 0;
}


/*Get/Set database entry info*/
static int GetEntryId(char *entryName, RECORD_ENTRY *rec_entry, ENTRY_FIXED start_entry[], USHORT *entryId)
{
	int			entry_num;
	GULONG		key;
	USHORT		index, hash_pn, hash_val;

	entry_num= rec_entry->entry_num;
    Swap4Byte(&entry_num);
	hash_pn= rec_entry->hash_pn;
    Swap2Byte(&hash_pn);
	if(hash_pn==0) /*a little entrys <3*/
	{
		for(index=0; index<entry_num; index++)
		{
			if(!strcmp(entryName, start_entry[index].entryName))
			{
				*entryId= index;
				return 0;
			}
		}
		return -1;
	}
	GetNameStrHash(entryName, &key);
	hash_val= key%hash_pn;

	index= start_entry[hash_val].hash_index;
	Swap2Byte(&index);
	if(index>=entry_num)
	{
		Err_log("Entry hash table error");
		return -1;
	}
	Swap4Byte(&key);
	while(key!=start_entry[index].hash_key 
		|| strcmp(entryName, start_entry[index].entryName))
	{
		if(start_entry[hash_val].hash_next==0xFFFF)
			return -1;
		hash_val= start_entry[hash_val].hash_next;
		Swap2Byte(&hash_val);
		index= start_entry[hash_val].hash_index;
		Swap2Byte(&index);
		if(index>=entry_num)
		{
			Err_log("Entry hash table error");
			return -1;
		}
	}
	if(index>=entry_num)
	{
		Err_log("Entry hash table error");
		return -1;
	}
	*entryId= index;
	return 0;
}


static int	GetPtPosition( POINTER *point )
{
	int  rec_pos;
	int  entry_num, entry_offset;
    char err_str[128];

	rec_pos= GetRecPosition( point->stn_id, point->dev_id, point->data_type );
	if( rec_pos<0 )
		return -1;

	entry_num= db_ptr->Record_Union.RecordEntry[rec_pos].entry_num;
	Swap4Byte(&entry_num);
	if( point->pt_id>=entry_num )
	{
   		sprintf(err_str, "No such a point: %d-%d-%d-%d", point->stn_id, point->dev_id, point->data_type, point->pt_id);
   		Err_log(err_str);
   		return -1;
   	}

	entry_offset= db_ptr->Record_Union.RecordEntry[rec_pos].entry_offset;
    Swap4Byte(&entry_offset);

    return (entry_offset+point->pt_id);
}
 

BOOL IsPointExist( POINTER *point )
{
	if(-1==GetPtPosition(point))
		return FALSE;
	else
		return TRUE;
}


int	GetPtIdByNameStr( char *ptNameStr, POINTER *point )
{
	int		ret;
	POINT_NAME  point_name;
	int		rec_pos;
	int		entry_offset;
    char	err_str[128];
	UCHAR	stn_id, grp_id, rec_type;
	ENTRY_FIXED	*fixed;
		
	ret= StrtoPointName(ptNameStr, &point_name);
	if( ret==-1 )
		return -1;
	
	ret= GetStnIdByName( point_name.stnName, &stn_id );
	if( ret==-1 )
		return -1;
	point->stn_id= stn_id;
		
	ret= GetGroupIdByName( point->stn_id, point_name.grpName, &grp_id );
	if( ret==-1 )
		return -1;
	point->dev_id= grp_id;
		
	ret= GetRecTypeByName( point_name.recName, &rec_type );
	if( ret==-1 )
		return -1;
	point->data_type= rec_type;
	
	rec_pos= GetRecPosition( point->stn_id, point->dev_id, point->data_type );
	if( rec_pos<0 )
		return -1;
	entry_offset= db_ptr->Record_Union.RecordEntry[rec_pos].entry_offset;
    Swap4Byte(&entry_offset);

	switch	( point->data_type )
	{
	case	SOE_TYPE:
	case	POL_TYPE:
	case	OUTS_TYPE:
	case	SYSMSG_TYPE:
		fixed= db_ptr->EntryFixed_Status_Union.EntryFixed;
		break;

	case	ANA_TYPE:
	case	OUTA_TYPE:
	case	PARAM_TYPE:
		fixed= db_ptr->EntryFixed_Anlg_Union.EntryFixed;
		break;

	case	IMP_TYPE:
		fixed= db_ptr->EntryFixed_Imp_Union.EntryFixed;
		break;

	case	CALC_TYPE:
		fixed= db_ptr->EntryFixed_Calc_Union.EntryFixed;
		break;

	case	CHARA_TYPE:
		fixed= db_ptr->EntryFixed_Chara_Union.EntryFixed;
		break;

	case	CURVE_TYPE:
		fixed= db_ptr->EntryFixed_Curve_Union.EntryFixed;
		break;

	case	DEVOBJ_TYPE:
		fixed= db_ptr->EntryFixed_DevObj_Union.EntryFixed;
		break;

	case	TIME_TYPE:
		fixed= db_ptr->EntryFixed_Time_Union.EntryFixed;
		break;
		
	default:
		return -1;
	}
	if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos],
		&fixed[entry_offset], &point->pt_id))
		return 0;
	
	sprintf(err_str, "No such a point: %s", ptNameStr);
	Err_log(err_str);
	return -1;
}


int	GetCommonPtrById( POINTER *point, DMS_COMMON_PTR *common_ptr)
{
	int  entry_pos;
	
	entry_pos= GetPtPosition( point );
	if( entry_pos<0 )
		return -1;

	switch	( point->data_type )
	{
	case	SOE_TYPE:
	case	POL_TYPE:
	case	OUTS_TYPE:
	case	SYSMSG_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Status_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Status_Union.EntryVariable[entry_pos];
		break;

	case	ANA_TYPE:
	case	OUTA_TYPE:
	case	PARAM_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Anlg_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Anlg_Union.EntryVariable[entry_pos];
		break;

	case	IMP_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Imp_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Imp_Union.EntryVariable[entry_pos];
		break;

	case	CALC_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Calc_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Calc_Union.EntryVariable[entry_pos];
		break;

	case	CHARA_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Chara_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Chara_Union.EntryVariable[entry_pos];
		break;

	case	CURVE_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Curve_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Curve_Union.EntryVariable[entry_pos];
		break;

	case	DEVOBJ_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_DevObj_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_DevObj_Union.EntryVariable[entry_pos];
		break;

	case	TIME_TYPE:
		common_ptr->fixed_ptr= &db_ptr->EntryFixed_Time_Union.EntryFixed[entry_pos];
		common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Time_Union.EntryVariable[entry_pos];
		break;
		
	default:
		return -1;
	}

	common_ptr->point= *point;
	return 0;
}



int	GetCommonPtrByNameStr( char *ptNameStr, DMS_COMMON_PTR *common_ptr)
{
	int			ret;
	POINT_NAME  point_name;
	int			rec_pos;
	int			entry_offset, entry_pos;
    char		err_str[128];
	POINTER		point;
		
	ret= StrtoPointName(ptNameStr, &point_name);
	if( ret==-1 )
		return -1;
	
	ret= GetStnIdByName( point_name.stnName, &point.stn_id );
	if( ret==-1 )
		return -1;
		
	ret= GetGroupIdByName( point.stn_id, point_name.grpName, &point.dev_id );
	if( ret==-1 )
		return -1;
		
	ret= GetRecTypeByName( point_name.recName, &point.data_type );
	if( ret==-1 )
		return -1;
	
	rec_pos= GetRecPosition( point.stn_id, point.dev_id, point.data_type );
	if( rec_pos<0 )
		return -1;
	entry_offset= db_ptr->Record_Union.RecordEntry[rec_pos].entry_offset;
    Swap4Byte(&entry_offset);

	switch	( point.data_type )
	{
	case	SOE_TYPE:
	case	POL_TYPE:
	case	OUTS_TYPE:
	case	SYSMSG_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos],
			&db_ptr->EntryFixed_Status_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Status_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Status_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	ANA_TYPE:
	case	OUTA_TYPE:
	case	PARAM_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos],
			&db_ptr->EntryFixed_Anlg_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Anlg_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Anlg_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	IMP_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos],
			&db_ptr->EntryFixed_Imp_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Imp_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Imp_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	CALC_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos],
			&db_ptr->EntryFixed_Calc_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Calc_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Calc_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	CHARA_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Chara_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Chara_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Chara_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	CURVE_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Curve_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Curve_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Curve_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	DEVOBJ_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_DevObj_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_DevObj_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_DevObj_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;

	case	TIME_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Time_Union.EntryFixed[entry_offset], &point.pt_id))
		{
			entry_pos= entry_offset+point.pt_id;
			common_ptr->fixed_ptr= &db_ptr->EntryFixed_Time_Union.EntryFixed[entry_pos];
			common_ptr->var_ptr= (RD_VAR_UNION	*)&db_ptr->EntryVar_Time_Union.EntryVariable[entry_pos];
			common_ptr->point= point;
			return 0;
		}
		break;
		
	default:
		return -1;
	}
	
	sprintf(err_str, "No such a point: %s", ptNameStr);
	Err_log(err_str);
	return -1;
}



int GetEntryIdByName( char *entryName, POINTER *point )
{
	int		rec_pos;
	int		entry_offset;
    char	err_str[128];
	ENTRY_FIXED	*fixed;
	
	rec_pos= GetRecPosition( point->stn_id, point->dev_id, point->data_type );
	if( rec_pos<0 )
		return -1;
	entry_offset= db_ptr->Record_Union.RecordEntry[rec_pos].entry_offset;
    Swap4Byte(&entry_offset);

	switch	( point->data_type )
	{
	case	SOE_TYPE:
	case	POL_TYPE:
	case	OUTS_TYPE:
	case	SYSMSG_TYPE:
		fixed= db_ptr->EntryFixed_Status_Union.EntryFixed;
		break;

	case	ANA_TYPE:
	case	OUTA_TYPE:
	case	PARAM_TYPE:
		fixed= db_ptr->EntryFixed_Anlg_Union.EntryFixed;
		break;

	case	IMP_TYPE:
		fixed= db_ptr->EntryFixed_Imp_Union.EntryFixed;
		break;

	case	CALC_TYPE:
		fixed= db_ptr->EntryFixed_Calc_Union.EntryFixed;
		break;

	case	CHARA_TYPE:
		fixed= db_ptr->EntryFixed_Chara_Union.EntryFixed;
		break;

	case	CURVE_TYPE:
		fixed= db_ptr->EntryFixed_Curve_Union.EntryFixed;
		break;

	case	DEVOBJ_TYPE:
		fixed= db_ptr->EntryFixed_DevObj_Union.EntryFixed;
		break;

	case	TIME_TYPE:
		fixed= db_ptr->EntryFixed_Time_Union.EntryFixed;
		break;
		
	default:
		return -1;
	}
	if(!GetEntryId(entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], &fixed[entry_offset], &point->pt_id))
		return 0;
	
	sprintf(err_str, "No such a point: %d.%d.%d-%s", point->stn_id, point->dev_id, 
		point->data_type, entryName);
	Err_log(err_str);
	return -1;
}




int	ReadEntryById( POINTER *point , DMS_COMMON *common_all)
{
	int		entry_pos;
	float	imp_cvt;
	
	entry_pos= GetPtPosition( point );
	if( entry_pos<0 )
		return -1;

	common_all->point= *point;
			
	switch	( point->data_type )
	{
	case	SOE_TYPE:
	case	POL_TYPE:
	case	OUTS_TYPE:
	case	SYSMSG_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Status_Union.EntryFixed[entry_pos];
		common_all->var.ind= db_ptr->EntryVar_Status_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.ind.update_time);
		SwapDateTimeByte(&common_all->var.ind.change_time);
		Swap2Byte(&common_all->var.ind.status);
		SwapStcDataByte(&common_all->var.ind.stc);
		break;

	case	ANA_TYPE:
	case	OUTA_TYPE:
	case	PARAM_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Anlg_Union.EntryFixed[entry_pos];
		common_all->var.anlg= db_ptr->EntryVar_Anlg_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.anlg.update_time);
		Swap4Byte(&common_all->var.anlg.value.data);
		Swap2Byte(&common_all->var.anlg.value.status);
		Swap4Byte(&common_all->var.anlg.fValue);
		SwapAnaEngParaByte(&common_all->var.anlg.eng_para);
		SwapLmtParaByte(&common_all->var.anlg.lmt_para);
		break;

	case	IMP_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Imp_Union.EntryFixed[entry_pos];
		common_all->var.imp.entry= db_ptr->EntryVar_Imp_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.imp.entry.update_time);
		Swap4Byte(&common_all->var.imp.entry.rt_value);
		Swap2Byte(&common_all->var.imp.entry.status);
		Swap4Byte(&common_all->var.imp.entry.base_value);
		Swap4Byte(&common_all->var.imp.entry.d_accum);
		SwapImpEngParaByte(&common_all->var.imp.entry.eng_para);
		SwapImpDataByte(&common_all->var.imp.entry.init);
		SwapImpDataByte(&common_all->var.imp.entry.last);
		SwapImpDataByte(&common_all->var.imp.entry.ppeak);
		SwapImpDataByte(&common_all->var.imp.entry.peak);
		SwapImpDataByte(&common_all->var.imp.entry.valley);
		SwapImpDataByte(&common_all->var.imp.entry.normal);
		SwapImpDataByte(&common_all->var.imp.entry.sum);
		imp_cvt= common_all->var.imp.entry.eng_para.CT*common_all->var.imp.entry.eng_para.PT
			*common_all->var.imp.entry.eng_para.ENG_CVT;

		common_all->var.imp.init.day= common_all->var.imp.entry.init.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.last.day= common_all->var.imp.entry.last.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.ppeak.day= common_all->var.imp.entry.ppeak.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.peak.day= common_all->var.imp.entry.peak.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.valley.day= common_all->var.imp.entry.valley.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.normal.day= common_all->var.imp.entry.normal.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.sum.day= common_all->var.imp.entry.sum.day*imp_cvt
			/common_all->var.imp.entry.eng_para.DAY_RATE;

		common_all->var.imp.init.month= common_all->var.imp.entry.init.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.last.month= common_all->var.imp.entry.last.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.ppeak.month= common_all->var.imp.entry.ppeak.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.peak.month= common_all->var.imp.entry.peak.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.valley.month= common_all->var.imp.entry.valley.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.normal.month= common_all->var.imp.entry.normal.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.sum.month= common_all->var.imp.entry.sum.month*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.init.year= common_all->var.imp.entry.init.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.last.year= common_all->var.imp.entry.last.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.ppeak.year= common_all->var.imp.entry.ppeak.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.peak.year= common_all->var.imp.entry.peak.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.valley.year= common_all->var.imp.entry.valley.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.normal.year= common_all->var.imp.entry.normal.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		common_all->var.imp.sum.year= common_all->var.imp.entry.sum.year*imp_cvt
			/common_all->var.imp.entry.eng_para.YEAR_RATE;

		break;

	case	CALC_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Calc_Union.EntryFixed[entry_pos];
		common_all->var.calc= db_ptr->EntryVar_Calc_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.calc.update_time);
		Swap4Byte(&common_all->var.calc.value.data);
		Swap2Byte(&common_all->var.calc.value.status);
		Swap4Byte(&common_all->var.calc.fValue);
		SwapAnaEngParaByte(&common_all->var.calc.eng_para);
		SwapLmtParaByte(&common_all->var.calc.lmt_para);
		break;

	case	CHARA_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Chara_Union.EntryFixed[entry_pos];
		common_all->var.chara= db_ptr->EntryVar_Chara_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.chara.update_time);
		SwapCharaDataByte(&common_all->var.chara.chara_data);
		break;

	case	CURVE_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Curve_Union.EntryFixed[entry_pos];
		common_all->var.curve= db_ptr->EntryVar_Curve_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.curve.update_time);
		Swap2Byte(&common_all->var.curve.seg_num);
		SwapAnaEngParaByte(&common_all->var.curve.eng_para);
		SwapCurveDataByte(&common_all->var.curve.data);
		break;

	case	DEVOBJ_TYPE:
		common_all->fixed = db_ptr->EntryFixed_DevObj_Union.EntryFixed[entry_pos];
		common_all->var.devobj= db_ptr->EntryVar_DevObj_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.devobj.update_time);
		SwapDateTimeByte(&common_all->var.devobj.cmd_time);
		Swap2Byte(&common_all->var.devobj.status);
		Swap4Byte(&common_all->var.devobj.data);
		Swap2Byte(&common_all->var.devobj.fb_status1);
		Swap2Byte(&common_all->var.devobj.fb_status2);
		Swap2Byte(&common_all->var.devobj.param);
		break;

	case	TIME_TYPE:
		common_all->fixed = db_ptr->EntryFixed_Time_Union.EntryFixed[entry_pos];
		common_all->var.time= db_ptr->EntryVar_Time_Union.EntryVariable[entry_pos];
		SwapDateTimeByte(&common_all->var.time.update_time);
		Swap4Byte(&common_all->var.time.value_sec);
		Swap4Byte(&common_all->var.time.coords.x);
		Swap4Byte(&common_all->var.time.coords.y);
		Swap4Byte(&common_all->var.time.coords.z);
		Swap2Byte(&common_all->var.time.value_ms);
		Swap2Byte(&common_all->var.time.status);
		break;
		
	default:
		return -1;
	}
	Swap2Byte(&common_all->fixed.io_group);	
	Swap2Byte(&common_all->fixed.iost);	
	Swap4Byte(&common_all->fixed.ioattr);	
	Swap2Byte(&common_all->fixed.ctrl_addr);
	Swap2Byte(&common_all->fixed.pair_pt.pt_id);
	return 0;	
}


int	ReadEntryByNameStr( char *ptNameStr, DMS_COMMON *common_all)
{
	int			ret;
	POINT_NAME  point_name;
	int			rec_pos;
	int			entry_offset, entry_pos;
    char		err_str[128];
	float		imp_cvt;
		
	ret= StrtoPointName(ptNameStr, &point_name);
	if( ret==-1 )
		return -1;
	
	ret= GetStnIdByName( point_name.stnName, &common_all->point.stn_id );
	if( ret==-1 )
		return -1;
		
	ret= GetGroupIdByName( common_all->point.stn_id, point_name.grpName, &common_all->point.dev_id );
	if( ret==-1 )
		return -1;
		
	ret= GetRecTypeByName( point_name.recName, &common_all->point.data_type );
	if( ret==-1 )
		return -1;
	
	rec_pos= GetRecPosition( common_all->point.stn_id, common_all->point.dev_id, common_all->point.data_type );
	if( rec_pos<0 )
		return -1;
	entry_offset= db_ptr->Record_Union.RecordEntry[rec_pos].entry_offset;
    Swap4Byte(&entry_offset);

	switch	( common_all->point.data_type )
	{
	case	SOE_TYPE:
	case	POL_TYPE:
	case	OUTS_TYPE:
	case	SYSMSG_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Status_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed= db_ptr->EntryFixed_Status_Union.EntryFixed[entry_pos];
			common_all->var.ind= db_ptr->EntryVar_Status_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.ind.update_time);
			SwapDateTimeByte(&common_all->var.ind.change_time);
			Swap2Byte(&common_all->var.ind.status);
			SwapStcDataByte(&common_all->var.ind.stc);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	ANA_TYPE:
	case	OUTA_TYPE:
	case	PARAM_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Anlg_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_Anlg_Union.EntryFixed[entry_pos];
			common_all->var.anlg= db_ptr->EntryVar_Anlg_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.anlg.update_time);
			Swap4Byte(&common_all->var.anlg.value.data);
			Swap2Byte(&common_all->var.anlg.value.status);
			Swap4Byte(&common_all->var.anlg.fValue);
			SwapAnaEngParaByte(&common_all->var.anlg.eng_para);
			SwapLmtParaByte(&common_all->var.anlg.lmt_para);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	IMP_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Imp_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_Imp_Union.EntryFixed[entry_pos];
			common_all->var.imp.entry= db_ptr->EntryVar_Imp_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.imp.entry.update_time);
			Swap4Byte(&common_all->var.imp.entry.rt_value);
			Swap2Byte(&common_all->var.imp.entry.status);
			Swap4Byte(&common_all->var.imp.entry.base_value);
			Swap4Byte(&common_all->var.imp.entry.d_accum);
			SwapImpEngParaByte(&common_all->var.imp.entry.eng_para);
			SwapImpDataByte(&common_all->var.imp.entry.init);
			SwapImpDataByte(&common_all->var.imp.entry.last);
			SwapImpDataByte(&common_all->var.imp.entry.ppeak);
			SwapImpDataByte(&common_all->var.imp.entry.peak);
			SwapImpDataByte(&common_all->var.imp.entry.valley);
			SwapImpDataByte(&common_all->var.imp.entry.normal);
			SwapImpDataByte(&common_all->var.imp.entry.sum);
			imp_cvt= common_all->var.imp.entry.eng_para.CT*common_all->var.imp.entry.eng_para.PT
				*common_all->var.imp.entry.eng_para.ENG_CVT;

			common_all->var.imp.init.day= common_all->var.imp.entry.init.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.last.day= common_all->var.imp.entry.last.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.ppeak.day= common_all->var.imp.entry.ppeak.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.peak.day= common_all->var.imp.entry.peak.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.valley.day= common_all->var.imp.entry.valley.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.normal.day= common_all->var.imp.entry.normal.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.sum.day= common_all->var.imp.entry.sum.day*imp_cvt
				/common_all->var.imp.entry.eng_para.DAY_RATE;

			common_all->var.imp.init.month= common_all->var.imp.entry.init.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.last.month= common_all->var.imp.entry.last.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.ppeak.month= common_all->var.imp.entry.ppeak.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.peak.month= common_all->var.imp.entry.peak.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.valley.month= common_all->var.imp.entry.valley.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.normal.month= common_all->var.imp.entry.normal.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.sum.month= common_all->var.imp.entry.sum.month*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.init.year= common_all->var.imp.entry.init.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.last.year= common_all->var.imp.entry.last.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.ppeak.year= common_all->var.imp.entry.ppeak.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.peak.year= common_all->var.imp.entry.peak.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.valley.year= common_all->var.imp.entry.valley.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.normal.year= common_all->var.imp.entry.normal.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			common_all->var.imp.sum.year= common_all->var.imp.entry.sum.year*imp_cvt
				/common_all->var.imp.entry.eng_para.YEAR_RATE;

			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	CALC_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Calc_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_Calc_Union.EntryFixed[entry_pos];
			common_all->var.calc= db_ptr->EntryVar_Calc_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.calc.update_time);
			Swap4Byte(&common_all->var.calc.value.data);
			Swap2Byte(&common_all->var.calc.value.status);
			Swap4Byte(&common_all->var.calc.fValue);
			SwapAnaEngParaByte(&common_all->var.calc.eng_para);
			SwapLmtParaByte(&common_all->var.calc.lmt_para);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	CHARA_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Chara_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_Chara_Union.EntryFixed[entry_pos];
			common_all->var.chara= db_ptr->EntryVar_Chara_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.chara.update_time);
			SwapCharaDataByte(&common_all->var.chara.chara_data);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	CURVE_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Curve_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_Curve_Union.EntryFixed[entry_pos];
			common_all->var.curve= db_ptr->EntryVar_Curve_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.curve.update_time);
			Swap2Byte(&common_all->var.curve.seg_num);
			SwapAnaEngParaByte(&common_all->var.curve.eng_para);
			SwapCurveDataByte(&common_all->var.curve.data);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	DEVOBJ_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_DevObj_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_DevObj_Union.EntryFixed[entry_pos];
			common_all->var.devobj= db_ptr->EntryVar_DevObj_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.devobj.update_time);
			SwapDateTimeByte(&common_all->var.devobj.cmd_time);
			Swap2Byte(&common_all->var.devobj.status);
			Swap4Byte(&common_all->var.devobj.data);
			Swap2Byte(&common_all->var.devobj.fb_status1);
			Swap2Byte(&common_all->var.devobj.fb_status2);
			Swap2Byte(&common_all->var.devobj.param);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;

	case	TIME_TYPE:
		if(!GetEntryId(point_name.entryName, &db_ptr->Record_Union.RecordEntry[rec_pos], 
			&db_ptr->EntryFixed_Time_Union.EntryFixed[entry_offset], &common_all->point.pt_id))
		{
			entry_pos= entry_offset+common_all->point.pt_id;
			common_all->fixed = db_ptr->EntryFixed_Time_Union.EntryFixed[entry_pos];
			common_all->var.time= db_ptr->EntryVar_Time_Union.EntryVariable[entry_pos];
			SwapDateTimeByte(&common_all->var.time.update_time);
			Swap4Byte(&common_all->var.time.value_sec);
			Swap4Byte(&common_all->var.time.coords.x);
			Swap4Byte(&common_all->var.time.coords.y);
			Swap4Byte(&common_all->var.time.coords.z);
			Swap2Byte(&common_all->var.time.value_ms);
			Swap2Byte(&common_all->var.time.status);
			Swap2Byte(&common_all->fixed.io_group);	
			Swap2Byte(&common_all->fixed.iost);	
			Swap4Byte(&common_all->fixed.ioattr);	
			Swap2Byte(&common_all->fixed.ctrl_addr);
			Swap2Byte(&common_all->fixed.pair_pt.pt_id);
			return 0;
		}
		break;
		
	default:
		return -1;
	}
	
	sprintf(err_str, "No such a point: %s", ptNameStr);
	Err_log(err_str);
	return -1;
}


