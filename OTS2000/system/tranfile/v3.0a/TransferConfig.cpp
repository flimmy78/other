// TransferConfig.cpp: implementation of the CTransferConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "transferfile.h"
#include "TransferConfig.h"
#include "transferfileDlg.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CTransferConfig::CTransferConfig()
{
	CString CurExeFilePath="";				//可执行文件的完整路径及文件名
	int i,j,curPos;
	CString strtmp="";
	TCHAR exeFullPath[MAX_PATH];			// MAX_PATH在API中定义了吧，好象是128 
	GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	strtmp=exeFullPath;						//获取当前运行路径及文件名。
	CurExeFilePath="";
	j=1;
	m_ftpTransMode=0;
	while(j>=0)
	{
		j=strtmp.Find("\\");
		CurExeFilePath=CurExeFilePath+strtmp.Left(j+1);
		strtmp=strtmp.Right(strtmp.GetLength()-j-1);
		curPos=j;
	};

	strConfigFileName=CurExeFilePath+"config.ini";
	for(i=0;i<MaxFileType;i++)
	{
		m_srcFileSel[i]=0;
	}
}

CTransferConfig::~CTransferConfig()
{

}

////从配置文件读取所有配置信息
bool CTransferConfig::GetConfigFromFile()
{

	int i,j;
	char chReturn[200];
	char buffer[2];
	CString strline,strtmp;
	CString DstIP,DstType,Passwd,Status,Username,DstDriver;	
	CString srcFileSel,srcDriver,srcVersion;
	//读取共用信息
	GetPrivateProfileString("COMMMON","srcDriver","Err",chReturn,200,strConfigFileName);
	m_srcDriver=chReturn;
	GetPrivateProfileString("COMMMON","srcVersion","Err",chReturn,200,strConfigFileName);
	m_srcVersion=chReturn;
	GetPrivateProfileString("COMMMON","PrjName","Err",chReturn,200,strConfigFileName);
	m_prjName=chReturn;
	GetPrivateProfileString("COMMMON","srcFileSel","Err",chReturn,200,strConfigFileName);
	for(i=0;i<MaxFileType;i++)
	{
		strtmp=chReturn[i];
		m_srcFileSel[i]=atoi(strtmp);
	}
	//m_ftpTransMode = GetPrivateProfileInt("GLOBAL","ftpMode",0,strConfigFileName); 
	//m_ShowMode= GetPrivateProfileInt("GLOBAL","ShowMode",0,strConfigFileName); 
	m_ftpTransMode =1;
	m_ShowMode=1;
	//读取目标计算机的个数
	m_dstCount = GetPrivateProfileInt("DSTCOMPUTERS","dstCount",0,strConfigFileName); 

	
	//读取每个目标计算机的信息
	for(i=0;i<m_dstCount;i++)
	{
		if(i<10)
		{
			sprintf(buffer,"%d",i);
			strtmp="Dst0" ;
			strtmp=strtmp+buffer;
		}
		//读取一行
		GetPrivateProfileString("DSTCOMPUTERS",strtmp,"Err",chReturn,200,strConfigFileName);
		strline=chReturn;
		//将一行数据写入m_config的dstcomputer

		strline.TrimLeft();
		strline.TrimRight();
		strline.Replace("	"," ");
		//获取IP或机器名
		j=strline.Find(" ");
		DstIP=strline.Left(j);
		if(DstIP=="null")
		{
			DstIP="";
		}
		strline=strline.Right(strline.GetLength()-j-1);
		strline.TrimLeft();
		//获取用户名
		j=strline.Find(" ");
		Username=strline.Left(j);
		if(Username=="null")
		{
			Username="";
		}
		strline=strline.Right(strline.GetLength()-j-1);
		strline.TrimLeft();
		//获取密码
		j=strline.Find(" ");
		Passwd=strline.Left(j);
		if(Passwd=="null")
		{
			Passwd="";
		}
		strline=strline.Right(strline.GetLength()-j-1);
		strline.TrimLeft();
		//获取盘符
		j=strline.Find(" ");
		DstDriver=strline.Left(j);
		strline=strline.Right(strline.GetLength()-j-1);
		strline.TrimLeft();
		//获取类型
		j=strline.Find(" ");
		DstType=strline.Left(j);
		strline=strline.Right(strline.GetLength()-j-1);
		strline.TrimLeft();
		//获取状态
		Status=strline;
		//赋予m_config
		m_dstComputer[i].DstIP=DstIP;
		m_dstComputer[i].Username=Username;
		m_dstComputer[i].Passwd=Passwd;
		m_dstComputer[i].DstDriver=DstDriver;
		m_dstComputer[i].DstType=atoi(DstType);
		m_dstComputer[i].Status=atoi(Status);
	}
	//初始化源文件过滤参数
	m_srcFileList[0][0]="*.*";				//数据库文本文件
	m_srcFileList[1][0]="DATABASE.OUT";		//数据库生成文件
	m_srcFileList[2][0]="*.txt";			//闭锁条件及综合计算文本
	m_srcFileList[3][0]="*.dat";			//闭锁条件及综合计算生成文件
	m_srcFileList[4][0]="*.DBIN";			//画面文件1
	m_srcFileList[4][1]="*.dbin";			//画面文件2
	m_srcFileList[4][2]="*.drbin";			//画面文件3
	m_srcFileList[4][3]="*.mrbin";			//画面文件4	
	m_srcFileList[5][0]="*.wav";			//语音文件
	m_srcFileList[6][0]="*.FAIL";			//事故追忆文件
	m_srcFileList[7][0]="ems_config.txt";	//项目配置文件

	//初始化文件类型，0为文本，1为二进制
	m_fileType[0]=0;						//数据库文本文件
	m_fileType[1]=1;						//数据库生成文件
	m_fileType[2]=0;						//闭锁条件及综合计算文本
	m_fileType[3]=1;						//闭锁条件及综合计算生成文件
	m_fileType[4]=1;						//画面文件1\2\3\4
	m_fileType[5]=1;						//语音文件
	m_fileType[6]=1;						//事故追忆文件
	m_fileType[7]=0;						//项目配置文件
	
	//初始化文件列表个数
	m_srcFileNum[0]=1;
	m_srcFileNum[1]=1;
	m_srcFileNum[2]=1;
	m_srcFileNum[3]=1;
	m_srcFileNum[4]=4;
	m_srcFileNum[5]=1;
	m_srcFileNum[6]=1;
	m_srcFileNum[7]=1;
	return true;
}


//设置路径信息
bool CTransferConfig::SetConfigDir()
{
	int i;
	//初始化源文件目录
	m_srcFileDir[0]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"dms\\"+m_srcVersion+"\\gen";				//数据库文本文件
	m_srcFileDir[1]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"dms\\"+m_srcVersion+"\\db";				//数据库生成文件
	m_srcFileDir[2]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"pas\\"+m_srcVersion+"\\DATA";				//闭锁条件及综合计算文本
	m_srcFileDir[3]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"pas\\"+m_srcVersion+"\\DATA";				//闭锁条件及综合计算生成文件
	m_srcFileDir[4]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"oix\\"+m_srcVersion+"\\DSP";				//画面文件1、2、3、4
	m_srcFileDir[5]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"dps\\"+m_srcVersion+"\\AUD";				//语音文件
	m_srcFileDir[6]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"pas\\"+m_srcVersion+"\\DATA";	
	m_srcFileDir[7]=m_srcDriver+":\\users\\ems\\project\\"+ m_prjName +"cmm\\"+m_srcVersion+"\\def";	
	//事故追忆文件
	for(i=0;i<m_dstCount;i++)
	{
		
		m_dstComputer[i].PortNum=21;
		//初始化PC机目标目录
		if(m_dstComputer[i].DstType==0)						
		{
		m_dstComputer[i].DstFileDir[0]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"dms\\"+m_srcVersion+"\\gen";				//数据库文本文件
		m_dstComputer[i].DstFileDir[1]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"dms\\"+m_srcVersion+"\\db";				//数据库生成文件
		m_dstComputer[i].DstFileDir[2]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"pas\\"+m_srcVersion+"\\DATA";				//闭锁条件及综合计算文本
		m_dstComputer[i].DstFileDir[3]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"pas\\"+m_srcVersion+"\\DATA";				//闭锁条件及综合计算生成文件
		m_dstComputer[i].DstFileDir[4]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"oix\\"+m_srcVersion+"\\DSP";				//画面文件1
		m_dstComputer[i].DstFileDir[5]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"dps\\"+m_srcVersion+"\\AUD";				//语音文件
		m_dstComputer[i].DstFileDir[6]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"pas\\"+m_srcVersion+"\\DATA";				//事故追忆文件
		m_dstComputer[i].DstFileDir[7]=m_dstComputer[i].DstDriver+
			"$\\users\\ems\\project\\"+ m_prjName +"cmm\\"+m_srcVersion+"\\def";				//项目配置文件
		}
		else												//初始化Unix机目标目录
		{
		//虚拟目录
		m_dstComputer[i].DstFileDir[0]="/DMSGEN";			//数据库文本文件
		m_dstComputer[i].DstFileDir[1]="/DMSDB";			//数据库生成文件
		m_dstComputer[i].DstFileDir[2]="/PASDATA";			//闭锁条件及综合计算文本
		m_dstComputer[i].DstFileDir[3]="/PASDATA";			//闭锁条件及综合计算生成文件
		m_dstComputer[i].DstFileDir[4]="/OIXDSP";			//画面文件1、2、3、4
		m_dstComputer[i].DstFileDir[5]="/AUD";				//语音文件
		m_dstComputer[i].DstFileDir[6]="/PASDATA";			//事故追忆文件
		m_dstComputer[i].DstFileDir[7]="/PRJDEF";			//项目配置文件
		}
	}
	return true;	
}

//将用户在界面中所选择的所有配置信息写入文件
bool CTransferConfig::WriteConfigToFile()
{
	int i;
	char buffer[2];
	CString strline,strtmp;
	CString DstIP,DstType,Passwd,Status,Username,DstDriver;	
	CString srcFileSel,srcDriver,srcVersion;
	
	//写入共用信息
	WritePrivateProfileString("COMMMON","srcDriver",m_srcDriver,strConfigFileName);
	WritePrivateProfileString("COMMMON","srcVersion",m_srcVersion,strConfigFileName);
	strtmp="";
	for(i=0;i<MaxFileType;i++)
	{
		sprintf(buffer,"%d",m_srcFileSel[i]);
		strtmp=strtmp+buffer;
	}
	WritePrivateProfileString("COMMMON","srcFileSel",strtmp,strConfigFileName);

	
	//写入目标计算机的个数
	sprintf(buffer,"%d",m_dstCount);
	WritePrivateProfileString("DSTCOMPUTERS","dstCount",buffer,strConfigFileName); 
	
	//写入每个目标计算机的信息
	for(i=0;i<m_dstCount;i++)
	{
		if(i<10)
		{
			sprintf(buffer,"%d",i);
			strtmp="Dst0" ;
			strtmp=strtmp+buffer;
		}
		else
		{
			sprintf(buffer,"%d",i);
			strtmp="Dst";
			strtmp=strtmp+buffer;
		}
		strline="";
		//计算机名或IP地址
		strline=strline+m_dstComputer[i].DstIP;
		//用户名
		m_dstComputer[i].Username.TrimLeft();
		m_dstComputer[i].Username.TrimRight();
		if(m_dstComputer[i].Username.GetLength()>=1)
		{
			strline=strline+"\t\t"+m_dstComputer[i].Username;
		}
		else
		{
			strline=strline+"\t\t"+"null";
		}
		//密码
		m_dstComputer[i].Passwd.TrimLeft();
		m_dstComputer[i].Passwd.TrimRight();
		if(m_dstComputer[i].Passwd.GetLength()>=1)
		{
			strline=strline+"\t\t"+m_dstComputer[i].Passwd;
		}
		else
		{
			strline=strline+"\t\t"+"null";
		}
		//盘符
		m_dstComputer[i].DstDriver.TrimLeft();
		m_dstComputer[i].DstDriver.TrimRight();
		if(m_dstComputer[i].DstDriver.GetLength()>=1)
		{
			strline=strline+"\t\t"+m_dstComputer[i].DstDriver;
		}
		else
		{
			strline=strline+"\t\t"+"null";
		}
		//类型
		sprintf(buffer,"%d",m_dstComputer[i].DstType);
		strline=strline+"\t\t"+buffer;
		//状态
		sprintf(buffer,"%d",m_dstComputer[i].Status);
		strline=strline+"\t\t"+buffer;
		WritePrivateProfileString("DSTCOMPUTERS",strtmp,strline,strConfigFileName); 
	}
	for(i=m_dstCount;i<11;i++)
	{
		if(i<10)
		{
			sprintf(buffer,"%d",i);
			strtmp="Dst0" ;
			strtmp=strtmp+buffer;
		}
		else
		{
			sprintf(buffer,"%d",i);
			strtmp="Dst";
			strtmp=strtmp+buffer;
		}
		strline="";
		WritePrivateProfileString("DSTCOMPUTERS",strtmp,strline,strConfigFileName); 
	}
	return true;
}

//删除指定计算机
bool CTransferConfig::DelDst(int nDst)					
{
	int i;
	if(nDst>m_dstCount-1) 
		return false;
	if(nDst==m_dstCount-1)
	{
		m_dstCount=m_dstCount-1;
		return true;
	}
	for(i=nDst;i<m_dstCount-1;i++)
	{
		m_dstComputer[i]=m_dstComputer[i+1];
	}
	m_dstCount=m_dstCount-1;
	return true;
}

//将用户在界面中所选择的目标计算机配置信息写入文件
bool CTransferConfig::WriteDstConfigToFile()
{
	return true;
}