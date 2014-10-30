
#include "CAnimData.h"
#include "CPartData.h"
#include "CAssInstruct.h"

#include <list>

using namespace std;

CAssInstruct::CAssInstruct()
{
	Ass_Num = 0;
	Part_Num= 0; 	//Ԥ���Ŀǰ�ò���
}
CAssInstruct::~CAssInstruct()
{
	Ass_Num = 0;
	Part_Num= 0;	////Ԥ���Ŀǰ�ò��� 
	
	for (list<CPartData*>::iterator it1 = PartList.begin();it1!=PartList.end();++it1)
	{
		delete *it1;
	}
	PartList.clear();
	AnimVector.clear();
}

void CAssInstruct::ReadFromFile(ifstream& infile)
{
	int a;		//��ָ���������
	string str;//��ָ������ַ���

	//main�д��ļ���ʼ������
	infile>>str;
	if(str!="AssMesBegin")
	{
		cout<<"Bad luck"<<endl;
		exit(0);
	}
	
	//�����ܲ���
	infile>>a;
	SetAssStepNum(a);

	//����б�ʼ
	infile>>str;
	if (str!="PartListBegin")
	{
		cout<<"bad luck"<<endl;
		exit(0);
	} 

	//��ʼ��ȡ����б�(���DMSP��KeyFrame��ȡ��)
	for (int i=0;i<Ass_Num;++i)
	{
		CPartData* tempPart = new CPartData;
		//tempPart->SetPartCID(i);
		tempPart->ReadPartData(infile);
		PartList.push_back(tempPart);	 
	}
	
	infile>>str;
	if (str!="PartListEnd")
	{
		cout<<"bad luck"<<endl;
		exit(0);
	}
}

void CAssInstruct::GenAnimVector()
{
	for (list<CPartData*>::iterator it2 = PartList.begin();it2!=PartList.end();++it2)
	{
		CAnimData* tempAnim = new CAnimData;
		tempAnim->SetAssAnim(**it2);
		AnimVector.push_back(tempAnim);
	}
}


void CAssInstruct::RunAssAnim(osg::ref_ptr<osg::MatrixTransform> mt)
{
	for (vector<CAnimData*>::iterator it3 = AnimVector.begin();it3!=AnimVector.end();++it3)
	{
		mt->addChild((*it3)->getmt());
	}
}