/*******************************************************************************************************************************
FILENAME:	
FUNCTION:		

VERSION:	v4.0a
OPERATE SYSTEM:	window 2000, XP

HISTORY:
2008.4.10	start to modify the code for H9000 V4.0		zyf
********************************************************************************************************************************/
#define STADDR		149
#define ANAADDR		92
#define PIADDR		6

unsigned short din_new[20];
unsigned short ain_st[48];
unsigned short ain_data[48];
unsigned short pin_data[16];

unsigned char dioinf[MAX_STN_NUM103] = {48,48,48,48,16,32,16,32};//每个RTU开关量个数
unsigned char anainf[MAX_STN_NUM103] = {0,0,0,0,16,8,16,8};		//每个RTU模拟量个数
unsigned short diobase[MAX_STN_NUM103] = {0,3,6,9,12,13,15,16};
unsigned short anabase[MAX_STN_NUM103] = {0,0,0,0,0,16,24,40};
unsigned short pibase[MAX_STN_NUM103] = {0,0,0,0,0,8,8,16};

unsigned char dinf[MAX_STN_NUM103][MAX_YX_NUM] = {				//开关量信息号
	{ 5,6,20,131,132,133,134,135,136,137,
	139,140,141,53,61,62,63,64,65,66,
	67,68,102,194,195,222,200,241,250,251,
	206,7,233,217,3,8,9,34,35,0,
	149,150,151,152,153,154,0,0 },

	{ 5,6,20,131,132,133,134,135,136,137,
	139,140,141,53,61,62,63,64,65,66,
	67,68,102,194,195,222,200,241,250,251,
	206,7,233,217,3,8,9,34,35,0,
	149,150,151,152,153,154,0,0 },

	{ 5,6,20,131,132,133,134,135,136,137,
	139,140,141,53,61,62,63,64,65,66,
	67,68,102,194,195,222,200,241,250,251,
	206,7,233,217,3,8,9,34,35,0,
	149,150,151,152,153,154,0,0 },

	{ 5,6,20,131,132,133,134,135,136,137,
	139,140,141,53,61,62,63,64,65,66,
	67,68,102,194,195,222,200,241,250,251,
	206,7,233,217,3,8,9,34,35,0,
	149,150,151,152,153,154,0,0 },

	{ 149,150,151,152,153,154,155,156,157,158,
	159,160,161,162,163,164},

	{149,150,151,152,153,154,155,156,157,158,
	159,160,161,162,163,164,165,166,167,168,
	169,170,171,172,173,174,175,176,177,0,
	0,0},

	{ 149,150,151,152,153,154,155,156,157,158,
	159,160,161,162,163,164},

	{149,150,151,152,153,154,155,156,157,158,
	159,160,161,162,163,164,165,166,167,168,
	169,170,171,172,173,174,175,176,177,0,
	0,0}};

unsigned char dfun[MAX_STN_NUM103][MAX_YX_NUM] = {				//开关量信息号
	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},

	{ 178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178,178,178,
	178,178,178,178,178,178,178,178},
	};

unsigned char ainf[MAX_STN_NUM103][MAX_YC_NUM] = {	//模拟量
	{0,0},{0,0},{0,0},{0,0},

	{92,93,94,95,96,97,98,99,100,101,
	102,103,104,105,106,0},

	{92,93,94,95,96,97,98,99},

	{92,93,94,95,96,97,98,99,100,101,
	102,103,104,105,106,0},

	{92,93,94,95,96,97,98,99}};

unsigned short aistatus[MAX_STN_NUM103][16] = {
	{0,0},{0,0},{0,0},{0,0},

	{20,20,20,20,20,20,20,20,20,20},

	{20,20,20,20,20,20,20,20,20,20},

	{20,20,20,20,20,20,20,20,20,20},

	{20,20,20,20,20,20,20,20,20,20}};
