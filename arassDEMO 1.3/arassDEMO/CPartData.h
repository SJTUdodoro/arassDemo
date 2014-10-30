/**************************************************************************************/
/**�����Ϣ��ȡ��ֻ��������������󣬴洢���������Ϣ��������GetPartMes���ô洢����Ϣ**/
/***��������|�����=װ�䲽��|��������|������|����յ�|���ģ��·��|����|��Ƶ|����****/
/**************************************************************************************/

#pragma once
#include <osgDB/ReadFile>
#include <osg/Matrix>
#include <sstream>
#include <iostream>
#include <list>

#define SPIRAL           0
#define TRANSLATIONAL    1  //Ĭ��ƽ�ƶ���
#define TOOLS            0
#define HANDY            1  //Ĭ��ͽ��װ��
#define BASE             0
#define CURRENT          1  //Ĭ��ģ��Ϊ��ǰ��

using namespace std;


	class CPartData
	{
	private:
		int Ass_Num;	//�������Ŀ=װ�䲽������Ŀ
		string Ass_Name;//��Ӧװ�䲽������;
		int part_BID;   //��׼��ID
		int part_CID;   //���ID
		int anim_TYPE;//�������ͣ�TRANSLANTIONAL=1, SPIRAL=0
		int part_TYPE; //������ͣ�CURRENT=1��BASE=0
		int tool_TYPE; //�������ͣ�TOOLS=0��HANDY=1
		osg::Matrix CPSm;//��ʼλ�þ���
		osg::Matrix CPEm;//��ֹλ�þ���
		string CurrentPartPath;//ģ�ʹ��·��
		string BasePartPath;//��׼��ģ��·��
		string ToolPath;//����ģ��·��
		string AudioPath;//��Ƶ��Ϣ·��
		string TextString;//��������
	public: 
		
		CPartData();
		~CPartData();

		void SetAssStepNum(int r_Num)
		{
			Ass_Num=r_Num;
		}
		int GetAssStepNum()
		{
			return Ass_Num;
		}
		void SetStepName(string r_Name)
		{
			Ass_Name = r_Name;
		}
		string	GetStepName()
		{
			return Ass_Name ;
		}
		void SetPartBID(int r_BID)
		{
			part_BID=r_BID;
		}
		int GetPartBID()
		{
			return part_BID;
		}
		void SetPartCID(int r_CID)
		{
			part_CID=r_CID;
		}
		int GetPartID()
		{
			cout<<part_CID<<endl;
			return part_CID;
		}
		void SetAnimType(string r_aTYPE)
		{
			if(r_aTYPE=="TRANSLATIONAL")
				anim_TYPE = TRANSLATIONAL;
			else if(r_aTYPE == "SPIRAL")
				anim_TYPE = SPIRAL;
			else exit(0);
			cout<<"anim_TYPE"<<" "<<anim_TYPE<<endl;
		}
		int GetAnimType()
		{
			return anim_TYPE;
		}
		void SetPartType(string r_pTYPE)
		{
			if (r_pTYPE=="BASE")
				part_TYPE = BASE;
			else if (r_pTYPE=="CURRENT")
				part_TYPE = CURRENT;
			else exit(0);
			cout<<"part_TYPE"<<" "<<part_TYPE<<endl;
		}
		int GetPartType()
		{
			return part_TYPE;
		}
		void SetStartMatrix();
		osg::Matrix GetStartMatrix()
		{
			return CPSm;
		}
		void SetEndMatrix();
		osg::Matrix GetEndMatrix()
		{
			return CPEm;
		}		
		void SetCurrentPartPath(string r_CPath)
		{
			CurrentPartPath=r_CPath;
		}
		string GetCurrentPartPath()
		{
			return CurrentPartPath;
		}
		void SetBasePartPath(string r_BPath)
		{
			BasePartPath=r_BPath;
		}
		string GetBasePartPath()
		{
			return BasePartPath;
		}
		void ReadPartData(ifstream& infile);

		/*��ʱ�����ǵ����ݣ����ߣ���Ƶ������*/
		/*
		void SetToolPath(string r_ToolPath)
		{
			ToolPath=r_ToolPath;
		}
		string GetToolPath()
		{
			return ToolPath;
		}
		void SetAudioPath(string r_AudioPath)
		{
			AudioPath = r_AudioPath;
		}
		string GetAudioPath()
		{
			return AudioPath;
		}
		void SetTextString(string r_Text)
		{
			TextString = r_Text;
		}
		string GetTextString()
		{
			return TextString;
		}
		*/
	};
