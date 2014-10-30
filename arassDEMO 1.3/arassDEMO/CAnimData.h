/*����Լ�����ʹ���������������������int������1����ƽ�ƣ�0������ת�����ض����ڵ�
���������������룺��������㡢�յ�λ�˾���ģ��·������������
			�������������Ӧ�����ľ���任�ڵ㣬���ø���ڵ�����޵��ӹ���*/
#pragma once
#include <osg/Matrix>
#include <osg/Array>
#include <osg/AnimationPath>
#include <osgDB/FileUtils>
#include <osg/Group>
#include <osg/Node>
#include <osgART/Scene>

#include "CPartData.h"

using namespace std;


	class CAnimData
	{  
	private:
		CPartData  partd;
		int    anim_ID;
		int    anim_TYPE;	//��������
		osg::Matrix  sm;	//������
		osg::Matrix  em;	//�յ����
		osg::Vec3d	spos;	//���λ��
		osg::Vec3d  epos;	//�յ�λ��
		osg::Quat   sori;	//�����̬
		osg::Quat   eori;	//�յ���̬
		
		/*osg::Vec3d	sscale;	//���λ��
		osg::Vec3d  escale;	//�յ�λ��
		osg::Quat   soscale;	//�����̬
		osg::Quat   eoscale;	//�յ���̬*/

	public:		
		CAnimData();
		~CAnimData();

		//��ȡ����յ����
		
		void SetAnimID()
		{
			anim_ID = partd.GetPartID();
		}
		void SetStartMatrix()
		{
			sm = partd.GetStartMatrix();
		}
		void SetEndMatrix()
		{
			em = partd.GetEndMatrix();
		}
		//��������յ�λ��
		void SetStartPose(osg::Matrix sm)
		{
			osg::Vec3d a;
			osg::Quat  b;
			osg::Vec3d c;
			osg::Quat  d;
			sm.decompose(a,b,c,d);
			spos = a;
			sori = b;
			//sori = b;
		}
		void SetEndPose(osg::Matrix em)
		{
			osg::Vec3d a;
			osg::Quat  b;
			osg::Vec3d c;
			osg::Quat  d;
			em.decompose(a,b,c,d);
			epos = a;
			eori = b;

		}
		
		//���ö�������
		void SetAnimType()
		{
			this->anim_TYPE = partd.GetAnimType();
		}
		//����ƽ�ƶ�������
		osg::AnimationPath* SegTransPath(osg::Vec3d a,osg::Vec3d b,osg::Quat c,osg::Quat d)
		{
			osg::AnimationPath* path1 = new osg::AnimationPath();
			path1->setLoopMode(osg::AnimationPath::NO_LOOPING);
			path1->insert(5.0*(anim_ID),osg::AnimationPath::ControlPoint(a,c));
			path1->insert(5.0*(anim_ID)+5.0,osg::AnimationPath::ControlPoint(b,d));
			//path1->insert(6.0,osg::AnimationPath::ControlPoint(a,c));
			return path1;
		}
		osg::ref_ptr<osg::MatrixTransform> SetAssAnim(CPartData partd);
		osg::ref_ptr<osg::MatrixTransform> mt;
		osg::ref_ptr<osg::MatrixTransform> getmt() const { return mt; }
		void setmt(osg::ref_ptr<osg::MatrixTransform> val) { mt = val; }
	};

