/********���ܣ�ͳһ CPartData �� CAnimData�� 
/********����CPartData������Ӧ��AnimData��������CAssInstruct��*/

#include "CAnimData.h"
#include "CPartData.h"

#include <list>

using namespace std;

class CAssInstruct
{
private:
	int Ass_Num;//װ���ܲ���=�ؼ�֡����
	int Part_Num;//�������
	
	//�����Ϣ�γɵ�����
	list <CPartData*> PartList;

	//���ɶ�������
	vector<CAnimData*> AnimVector;

public:

	CAssInstruct();
	~CAssInstruct();

	int GetPartID();
	int GetAnimID();

	void SetAssStepNum(int a)
	{
		Ass_Num = a;
	}

	//���ļ������������Ϣ����������
	void ReadFromFile(ifstream& infile);

	//���������������˳������
	void GenAnimVector();

	//���η��ظ��¶����ڵ㣬�õ���������
	void RunAssAnim(osg::ref_ptr<osg::MatrixTransform> mt);

};

