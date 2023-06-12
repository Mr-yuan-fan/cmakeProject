#include "stlTest.h"

#include <array>
#include <vector>
#include <deque>
#include <string>

using namespace ns_stl_test;



void StlTest::testExecute()
{
	cout << "-----------------------------------------\t STL ���Կ�ʼ \t\t---------------------------------" << endl;

	//array
	stlArrayTest();

	//vector
	stlVectorTest();

	//deque
	stlDequeTest();

	//forward_list


	cout << "-----------------------------------------\t STL ���Խ��� \t\t---------------------------------" << endl;
	cout << endl;
}

void StlTest::stlArrayTest()
{
	cout << endl;

	array<int, 8> m_arr1 = {1,2,3};
	array<int, 8> m_arr2 = {4,5,6,7};

	//m_arr1 [index]
	cout << "m_arr1 Ԫ������[]: " ;
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1[i] << " ";
	}
	cout<< endl;

	//m_arr2 [index]
	cout << "m_arr2 Ԫ������[]: ";
	for (int i = 0; i < m_arr2.size(); ++i)
	{
		cout << m_arr2[i] << " ";
	}
	cout << endl;

	//m_arr1 at(index)
	cout << "m_arr1 Ԫ������at(): " ;
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1.at(i) << " " ;
	}
	cout << endl;

	//m_arr2 at(index)
	cout << "m_arr2 Ԫ������at(): ";
	for (int i = 0; i < m_arr2.size(); ++i)
	{
		cout << m_arr2.at(i) << " ";
	}
	cout << endl;

	//swap Ҫ�����������ߴ�һ��
	m_arr1.swap(m_arr2);
	cout << "m_arr1 swap�� Ԫ������at(): " ;
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1.at(i) << " ";
	}
	cout << endl;

	cout << "m_arr2 swap�� Ԫ������at(): ";
	for (int i = 0; i < m_arr2.size(); ++i)
	{
		cout << m_arr2.at(i) << " ";
	}
	cout << endl;

	//front ->��һ��Ԫ��
	cout << "m_arr1.front() : " << m_arr1.front() << endl;

	//back ->���һ��Ԫ��
	cout << "m_arr1.back() : " << m_arr1.back() << endl;

	//data ->��Ԫ��ָ��
	cout << "m_arr1.data() : " << m_arr1.data() << endl;

	//*data ->�����õ�һ��Ԫ��
	cout << "*m_arr1.data() : " << *m_arr1.data() << endl;

	//fill ->�������Ԫ��
	m_arr1.fill(100);
	cout << "m_arr1 fill�� Ԫ������at(): ";
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1.at(i) << " ";
	}
	cout << endl;

	//���������
	cout << "m_arr2 ��������� Ԫ������at(): ";
	for (auto iter = m_arr2.begin(); iter != m_arr2.end(); ++iter)
	{
		cout <<*iter << " ";
	}
	cout << endl;

	//���򳣵�����
	cout << "m_arr2 ���򳣵����� Ԫ������at(): ";
	for (auto iter = m_arr2.cbegin(); iter != m_arr2.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//���������
	cout << "m_arr2 ��������� Ԫ������at(): ";
	for (auto iter = m_arr2.rbegin(); iter != m_arr2.rend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//���򳣵�����
	cout << "m_arr2 ���򳣵����� Ԫ������at(): ";
	for (auto iter = m_arr2.crbegin(); iter != m_arr2.crend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "m_arr2.size() : " << m_arr2.size() << endl;
	cout << "m_arr2.max_size() : " << m_arr2.max_size() << endl;

	//get<index>(std::array) ->����ָ����������Ԫ������
	cout << "get<1>(m_arr2) : " << get<1>(m_arr2) << endl;

}

void StlTest::stlVectorTest()
{
	cout << endl;

	vector<int> m_vec1; // ������
	vector<int> m_vec2(10,2); // ��СΪ10 ; ��ֵ2
	vector<int> m_vec3(m_vec2.begin(),--m_vec2.end()); // ʹ�õ���������Ԫ��
	vector<int> m_vec4(m_vec2); // ʹ����������

	cout << "m_vec3.size() : " << m_vec3.size() << endl;
	cout << "m_vec3.capacity() : " << m_vec3.capacity() << endl;

	//m_vec2 [index]
	cout << "m_vec2 Ԫ������[]: ";
	for (int i = 0; i < m_vec2.size(); ++i)
	{
		cout << m_vec2[i] << " ";
	}
	cout << endl;

	//m_vec2.at(index)
	cout << "m_vec2 Ԫ������ at(): ";
	for (int i = 0; i < m_vec2.size(); ++i)
	{
		cout << m_vec2.at(i) << " ";
	}
	cout << endl;

	//���������
	m_vec2[3] = 666;
	cout << "m_vec2 ��������� Ԫ������at(): ";
	for (auto iter = m_vec2.begin(); iter != m_vec2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//origin size
	cout << endl;
	cout << "m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.max_size() : " << m_vec2.max_size() << endl;//�̶�ֵ
	cout << "m_vec2.capacity() : " << m_vec2.capacity() << endl;

	//resize(num) -> ��������������ԭʼ���ݲ��䣬�������ݳ�ֵΪ0
	cout << endl;
	m_vec2.resize(20);
	cout << "m_vec2.resize(20)��, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.resize(20)��, m_vec2.max_size() : " << m_vec2.max_size() << endl; //�̶�ֵ
	cout << "m_vec2.resize(20)��, m_vec2.capacity() : " << m_vec2.capacity() << endl;

	//reserve(num) ->Ԥ����ռ䣬��ǰ����size������ı�
	cout << endl;
	m_vec2.reserve(30);
	cout << "m_vec2.reserve(30)��, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.reserve(30)��, m_vec2.max_size() : " << m_vec2.max_size() << endl; ////�̶�ֵ
	cout << "m_vec2.reserve(30)��, m_vec2.capacity() : " << m_vec2.capacity() << endl;

	//shrink_to_fit ->�޸�capacity��ʹ������size
	cout << endl;
	m_vec2.shrink_to_fit();
	cout << "m_vec2.shrink_to_fit()��, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.shrink_to_fit()��, m_vec2.max_size() : " << m_vec2.max_size() << endl; ////�̶�ֵ
	cout << "m_vec2.shrink_to_fit()��, m_vec2.capacity() : " << m_vec2.capacity() << endl;

	cout << endl;
	m_vec2.front() = 777;
	m_vec2.back() = 888;
	//front ->��һ��Ԫ��
	cout << "m_vec2.front() : " << m_vec2.front() << endl;

	//back ->���һ��Ԫ��
	cout << "m_vec2.back() : " << m_vec2.back() << endl;

	//data ->��Ԫ��ָ��
	cout << "m_vec2.data() : " << m_vec2.data() << endl;

	//*data ->�����õ�һ��Ԫ��
	cout << "*m_vec2.data() : " << *m_vec2.data() << endl;

	//assign ->�������ݷ�����������滻��ǰ���ݣ����޸�size; ��capacity��δ�Ķ�
	cout << endl;
	m_vec2.assign(m_vec3.begin(),m_vec3.end());
	cout << "m_vec2.assign(m_vec3.begin(),m_vec3.end())��, Ԫ������ at(): ";
	for (int i = 0; i < m_vec2.size(); ++i)
	{
		cout << m_vec2.at(i) << " ";
	}
	cout << endl;
	cout << "m_vec2.assign��, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.assign��, m_vec2.max_size() : " << m_vec2.max_size() << endl; ////�̶�ֵ
	cout << "m_vec2.assign��, m_vec2.capacity() : " << m_vec2.capacity() << endl;
	cout << endl;

	//push_back ->β�������Ԫ��
	m_vec2.push_back(11);

	//pop_back ->ɾ�����һ��Ԫ�أ�size����
	m_vec2.pop_back();
	
	//insert -> ָ��λ�ò���
	{
		vector<int>::const_iterator iterVec2 = ++m_vec2.cbegin();
		m_vec2.insert(iterVec2, 12);
	}

	//erase ->ɾ��ָ��λ�õ�����Ԫ��
	{
		vector<int>::iterator iterVec2 = ++m_vec2.begin();
		m_vec2.erase(iterVec2);
	}

	//swap
	m_vec2.push_back(11);
	m_vec2.swap(m_vec3);
	cout << "m_vec2.swap(m_vec3)��, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.swap(m_vec3)��, m_vec2.capacity() : " << m_vec2.capacity() << endl;
	cout << "m_vec2.swap(m_vec3)��, m_vec3.size() : " << m_vec3.size() << endl;
	cout << "m_vec2.swap(m_vec3)��, m_vec3.capacity() : " << m_vec3.capacity() << endl;

	//emplace ->ָ��λ�ò���Ԫ��
	//emplace_back ->��β�����Ԫ��
	m_vec2.emplace_back(13);
	m_vec2.emplace(++m_vec2.begin(),14);
	

}

void StlTest::stlDequeTest()
{
	cout << endl;

	deque<string> m_deq;
	m_deq.push_back("str1_1");
	m_deq.push_back("str1_2");
	m_deq.push_back("str1_3");

	//[]
	cout << "m_deq Ԫ������[]: ";
	for (int i = 0; i < m_deq.size(); ++i)
	{
		cout << "\"" << m_deq[i] << "\"" << " ";
	}
	cout << endl;

	//at()
	m_deq.push_front("str2_1");
	m_deq.push_front("str2_2");
	m_deq.push_front("str2_3");

	cout << "m_deq Ԫ������at(): ";
	for (int i = 0; i < m_deq.size(); ++i)
	{
		cout << "\"" << m_deq.at(i) << "\"" << " ";
	}
	cout << endl;

	m_deq.pop_back();
	m_deq.pop_front();

	cout << "pop_back() �� pop_front()��, m_deq Ԫ������at(): ";
	for (int i = 0; i < m_deq.size(); ++i)
	{
		cout << "\"" << m_deq.at(i) << "\"" << " ";
	}
	cout << endl;
}

void StlTest::stlForwardList()
{
    //forward_listֻ�ṩǮ�����������˲�֧�ַ��������������rbegin()�ȳ�Ա������
	//forward_list���ṩsize������Ա������
	//forward_listû��ָ����ĩԪ�ص�ê�㣬��˲��ṩback������push_back������pop_back������
	//forward_list���ṩ������ʣ���һ���list��ͬ��
	//�����ɾ��Ԫ�ز�����ɡ�ָ��������Ԫ�ء���ָ�룬���ú͵�����ʧЧ��
}

void StlTest::stlList()
{
	//list˫�����������������������������е��κεط����г���ʱ�����Ͳ����������������������Ͻ��е���, ���Ը�Ч�ؽ��в���ɾ��Ԫ�ء�
	//list ������Ԫ�ز����������洢�ģ����Ը������������У��������һ������ָ�� list ������ָ�룬
}

void StlTest::stlStack()
{
	//stackû�е���������һ��������������������LIFO������ȳ����Ĳ���������Ԫ�ؽ���������һ�˲������ȡ��
	//stack�ײ�һ����list��dequeʵ�֣����ͷ�����ɣ�����vector��ԭ��Ӧ����������С�����ƣ����ݺ�ʱ
}

void StlTest::stlQueue()
{
	//queue ��һ��������������������FIFO�������ȳ����Ĳ���������Ԫ�ز��뵽������һ�˲�����һ����ȡ��
	//���в��ṩ����������ʵ�ֱ���������
}

void StlTest::stlPriorityQueue()
{
	//���ȶ��У���ײ����ö���ʵ�ֵġ������ȶ����У�����Ԫ��һ���ǵ�ǰ���������ȼ���ߵ���һ����
}
void StlTest::stlSet()
{
	//set �ǰ����ض�˳��洢ΨһԪ�ص�������
}





