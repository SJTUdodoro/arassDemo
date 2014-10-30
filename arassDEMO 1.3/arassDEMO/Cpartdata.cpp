/**************************************************************************************/
/**�����Ϣ��ȡ��ֻ��������������󣬴洢���������Ϣ��������GetPartMes���ô洢����Ϣ**/
/***��������|�����=װ�䲽��|��������|������|����յ�|���ģ��·��|����|��Ƶ|����****/
/**************************************************************************************/
#pragma once

#include <osgDB//ReadFile>
#include <osg/Matrix>
#include <sstream>
#include <iostream>
#include <osg/Array>
#include "CPartData.h"

using namespace std;


#define SPIRAL           0
#define TRANSLATIONAL    1  //Ĭ��ƽ�ƶ���
#define TOOLS            0
#define HANDY            1  //Ĭ��ͽ��װ��
#define BASE             0
#define CURRENT          1  //Ĭ��ģ��Ϊ��ǰ��

//���캯��,��ʼ������
CPartData::CPartData()
{
	Ass_Num    = 0;
	Ass_Name   = "";
	part_CID    = -1;
	part_TYPE  = CURRENT;
	anim_TYPE  = TRANSLATIONAL;
	tool_TYPE  = HANDY;
	CurrentPartPath = "";
	BasePartPath    = "";
	ToolPath		= "";
	AudioPath		= "";
	TextString		= ""; 
}

CPartData::~CPartData()
{
	Ass_Num    = 0;
	Ass_Name   = "";
	part_CID    = -1;
	part_TYPE  = CURRENT;
	anim_TYPE = TRANSLATIONAL;
	tool_TYPE  = HANDY;
	CurrentPartPath = "";
	BasePartPath    = "";
	ToolPath		= "";
	AudioPath		= "";
	TextString		= ""; 
}

void CPartData::ReadPartData(ifstream& infile)
{
	int r_Num,r_CID,r_BID;
	double CPSmArray [4][4];
	double CPEmArray [4][4];
	string str,r_aName,r_CPath,r_BPath,r_aTYPE,r_pTYPE;

	//���������ʼ��־
	infile>>str;
	if(str!="PartBegin")
	{
		cout<<"Bad luck"<<endl;
		exit(0);
	}

	//���뵱ǰ��������
	infile>>str;
	SetStepName(r_aName);

	//�����׼��ID
	infile>>r_BID;
	SetPartBID(r_BID);

	//���뵱ǰ��ID
	infile>>r_CID;
	SetPartCID(r_CID);

/*
	//���ò�������
	stringstream ss;
	string sID;
	ss<<r_CID;
	ss>>sID;
	Ass_Name = "Ass_Name" + sID;

*/
	//����װ�䶯������
	infile>>r_aTYPE;
	SetAnimType(r_aTYPE);

	//�����������
	infile>>r_pTYPE;
	SetPartType(r_pTYPE);

	//���뵱ǰ���������
	infile>>str;
	if(str!="SMatrixBegin")
	{
		cout<<"Bad luck"<<endl;
		exit(0);
	}

	infile>>CPSmArray[0][0];
	infile>>CPSmArray[0][1];
	infile>>CPSmArray[0][2];
	infile>>CPSmArray[0][3];
	infile>>CPSmArray[1][0];
	infile>>CPSmArray[1][1];
	infile>>CPSmArray[1][2];
	infile>>CPSmArray[1][3];
	infile>>CPSmArray[2][0];
	infile>>CPSmArray[2][1];
	infile>>CPSmArray[2][2];
	infile>>CPSmArray[2][3];
	infile>>CPSmArray[3][0];
	infile>>CPSmArray[3][1];
	infile>>CPSmArray[3][2];
	infile>>CPSmArray[3][3];

	CPSm.set(CPSmArray[0][0],CPSmArray[0][1],CPSmArray[0][2],CPSmArray[0][3],
		CPSmArray[1][0],CPSmArray[1][1],CPSmArray[1][2],CPSmArray[1][3],
		CPSmArray[2][0],CPSmArray[2][1],CPSmArray[2][2],CPSmArray[2][3],
		CPSmArray[3][0],CPSmArray[3][1],CPSmArray[3][2],CPSmArray[3][3]);

	//���뵱ǰ����յ����
	infile>>str;
	if(str!="EMatrixBegin")
	{
		cout<<"Bad luck"<<endl;
		exit(0);
	}

	infile>>CPEmArray[0][0];
	infile>>CPEmArray[0][1];
	infile>>CPEmArray[0][2];
	infile>>CPEmArray[0][3];
	infile>>CPEmArray[1][0];
	infile>>CPEmArray[1][1];
	infile>>CPEmArray[1][2];
	infile>>CPEmArray[1][3];
	infile>>CPEmArray[2][0];
	infile>>CPEmArray[2][1];
	infile>>CPEmArray[2][2];
	infile>>CPEmArray[2][3];
	infile>>CPEmArray[3][0];
	infile>>CPEmArray[3][1];
	infile>>CPEmArray[3][2];
	infile>>CPEmArray[3][3];

	CPEm.set(CPEmArray[0][0],CPEmArray[0][1],CPEmArray[0][2],CPEmArray[0][3],
		CPEmArray[1][0],CPEmArray[1][1],CPEmArray[1][2],CPEmArray[1][3],
		CPEmArray[2][0],CPEmArray[2][1],CPEmArray[2][2],CPEmArray[2][3],
		CPEmArray[3][0],CPEmArray[3][1],CPEmArray[3][2],CPEmArray[3][3]);

	//���뵱ǰ���ģ��·��
	infile>>r_CPath;
	SetCurrentPartPath(r_CPath);
	
/*
	//�����׼���ģ��·������׼���δ������һ�����
	infile>>r_BPath;
	SetBasePartPath(r_BPath); */

	infile>>str;
	if (str!="PartEnd")
	{
		cout<<"Bad luck"<<endl;
		exit(0);
	}
	else
		cout<<"All done, good luck"<<endl;
	
}

