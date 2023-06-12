#include "stlTest.h"

#include <array>
#include <vector>
#include <deque>
#include <string>

using namespace ns_stl_test;



void StlTest::testExecute()
{
	cout << "-----------------------------------------\t STL 测试开始 \t\t---------------------------------" << endl;

	//array
	stlArrayTest();

	//vector
	stlVectorTest();

	//deque
	stlDequeTest();

	//forward_list


	cout << "-----------------------------------------\t STL 测试结束 \t\t---------------------------------" << endl;
	cout << endl;
}

void StlTest::stlArrayTest()
{
	cout << endl;

	array<int, 8> m_arr1 = {1,2,3};
	array<int, 8> m_arr2 = {4,5,6,7};

	//m_arr1 [index]
	cout << "m_arr1 元素序列[]: " ;
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1[i] << " ";
	}
	cout<< endl;

	//m_arr2 [index]
	cout << "m_arr2 元素序列[]: ";
	for (int i = 0; i < m_arr2.size(); ++i)
	{
		cout << m_arr2[i] << " ";
	}
	cout << endl;

	//m_arr1 at(index)
	cout << "m_arr1 元素序列at(): " ;
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1.at(i) << " " ;
	}
	cout << endl;

	//m_arr2 at(index)
	cout << "m_arr2 元素序列at(): ";
	for (int i = 0; i < m_arr2.size(); ++i)
	{
		cout << m_arr2.at(i) << " ";
	}
	cout << endl;

	//swap 要求两个容器尺寸一样
	m_arr1.swap(m_arr2);
	cout << "m_arr1 swap后 元素序列at(): " ;
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1.at(i) << " ";
	}
	cout << endl;

	cout << "m_arr2 swap后 元素序列at(): ";
	for (int i = 0; i < m_arr2.size(); ++i)
	{
		cout << m_arr2.at(i) << " ";
	}
	cout << endl;

	//front ->第一个元素
	cout << "m_arr1.front() : " << m_arr1.front() << endl;

	//back ->最后一个元素
	cout << "m_arr1.back() : " << m_arr1.back() << endl;

	//data ->首元素指针
	cout << "m_arr1.data() : " << m_arr1.data() << endl;

	//*data ->解引用第一个元素
	cout << "*m_arr1.data() : " << *m_arr1.data() << endl;

	//fill ->填充所有元素
	m_arr1.fill(100);
	cout << "m_arr1 fill后 元素序列at(): ";
	for (int i = 0; i < m_arr1.size(); ++i)
	{
		cout << m_arr1.at(i) << " ";
	}
	cout << endl;

	//正向迭代器
	cout << "m_arr2 正向迭代器 元素序列at(): ";
	for (auto iter = m_arr2.begin(); iter != m_arr2.end(); ++iter)
	{
		cout <<*iter << " ";
	}
	cout << endl;

	//正向常迭代器
	cout << "m_arr2 正向常迭代器 元素序列at(): ";
	for (auto iter = m_arr2.cbegin(); iter != m_arr2.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//反向迭代器
	cout << "m_arr2 反向迭代器 元素序列at(): ";
	for (auto iter = m_arr2.rbegin(); iter != m_arr2.rend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//反向常迭代器
	cout << "m_arr2 反向常迭代器 元素序列at(): ";
	for (auto iter = m_arr2.crbegin(); iter != m_arr2.crend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "m_arr2.size() : " << m_arr2.size() << endl;
	cout << "m_arr2.max_size() : " << m_arr2.max_size() << endl;

	//get<index>(std::array) ->返回指定索引处的元素引用
	cout << "get<1>(m_arr2) : " << get<1>(m_arr2) << endl;

}

void StlTest::stlVectorTest()
{
	cout << endl;

	vector<int> m_vec1; // 空容器
	vector<int> m_vec2(10,2); // 大小为10 ; 初值2
	vector<int> m_vec3(m_vec2.begin(),--m_vec2.end()); // 使用迭代器构造元素
	vector<int> m_vec4(m_vec2); // 使用容器构造

	cout << "m_vec3.size() : " << m_vec3.size() << endl;
	cout << "m_vec3.capacity() : " << m_vec3.capacity() << endl;

	//m_vec2 [index]
	cout << "m_vec2 元素序列[]: ";
	for (int i = 0; i < m_vec2.size(); ++i)
	{
		cout << m_vec2[i] << " ";
	}
	cout << endl;

	//m_vec2.at(index)
	cout << "m_vec2 元素序列 at(): ";
	for (int i = 0; i < m_vec2.size(); ++i)
	{
		cout << m_vec2.at(i) << " ";
	}
	cout << endl;

	//正向迭代器
	m_vec2[3] = 666;
	cout << "m_vec2 正向迭代器 元素序列at(): ";
	for (auto iter = m_vec2.begin(); iter != m_vec2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	//origin size
	cout << endl;
	cout << "m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.max_size() : " << m_vec2.max_size() << endl;//固定值
	cout << "m_vec2.capacity() : " << m_vec2.capacity() << endl;

	//resize(num) -> 扩大容器容量，原始内容不变，新增内容初值为0
	cout << endl;
	m_vec2.resize(20);
	cout << "m_vec2.resize(20)后, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.resize(20)后, m_vec2.max_size() : " << m_vec2.max_size() << endl; //固定值
	cout << "m_vec2.resize(20)后, m_vec2.capacity() : " << m_vec2.capacity() << endl;

	//reserve(num) ->预分配空间，当前容器size并不会改变
	cout << endl;
	m_vec2.reserve(30);
	cout << "m_vec2.reserve(30)后, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.reserve(30)后, m_vec2.max_size() : " << m_vec2.max_size() << endl; ////固定值
	cout << "m_vec2.reserve(30)后, m_vec2.capacity() : " << m_vec2.capacity() << endl;

	//shrink_to_fit ->修改capacity，使其适配size
	cout << endl;
	m_vec2.shrink_to_fit();
	cout << "m_vec2.shrink_to_fit()后, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.shrink_to_fit()后, m_vec2.max_size() : " << m_vec2.max_size() << endl; ////固定值
	cout << "m_vec2.shrink_to_fit()后, m_vec2.capacity() : " << m_vec2.capacity() << endl;

	cout << endl;
	m_vec2.front() = 777;
	m_vec2.back() = 888;
	//front ->第一个元素
	cout << "m_vec2.front() : " << m_vec2.front() << endl;

	//back ->最后一个元素
	cout << "m_vec2.back() : " << m_vec2.back() << endl;

	//data ->首元素指针
	cout << "m_vec2.data() : " << m_vec2.data() << endl;

	//*data ->解引用第一个元素
	cout << "*m_vec2.data() : " << *m_vec2.data() << endl;

	//assign ->将新内容分配给容器，替换当前内容，并修改size; 但capacity并未改动
	cout << endl;
	m_vec2.assign(m_vec3.begin(),m_vec3.end());
	cout << "m_vec2.assign(m_vec3.begin(),m_vec3.end())后, 元素序列 at(): ";
	for (int i = 0; i < m_vec2.size(); ++i)
	{
		cout << m_vec2.at(i) << " ";
	}
	cout << endl;
	cout << "m_vec2.assign后, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.assign后, m_vec2.max_size() : " << m_vec2.max_size() << endl; ////固定值
	cout << "m_vec2.assign后, m_vec2.capacity() : " << m_vec2.capacity() << endl;
	cout << endl;

	//push_back ->尾后添加新元素
	m_vec2.push_back(11);

	//pop_back ->删除最后一个元素，size减少
	m_vec2.pop_back();
	
	//insert -> 指定位置插入
	{
		vector<int>::const_iterator iterVec2 = ++m_vec2.cbegin();
		m_vec2.insert(iterVec2, 12);
	}

	//erase ->删除指定位置的容器元素
	{
		vector<int>::iterator iterVec2 = ++m_vec2.begin();
		m_vec2.erase(iterVec2);
	}

	//swap
	m_vec2.push_back(11);
	m_vec2.swap(m_vec3);
	cout << "m_vec2.swap(m_vec3)后, m_vec2.size() : " << m_vec2.size() << endl;
	cout << "m_vec2.swap(m_vec3)后, m_vec2.capacity() : " << m_vec2.capacity() << endl;
	cout << "m_vec2.swap(m_vec3)后, m_vec3.size() : " << m_vec3.size() << endl;
	cout << "m_vec2.swap(m_vec3)后, m_vec3.capacity() : " << m_vec3.capacity() << endl;

	//emplace ->指定位置插入元素
	//emplace_back ->在尾后插入元素
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
	cout << "m_deq 元素序列[]: ";
	for (int i = 0; i < m_deq.size(); ++i)
	{
		cout << "\"" << m_deq[i] << "\"" << " ";
	}
	cout << endl;

	//at()
	m_deq.push_front("str2_1");
	m_deq.push_front("str2_2");
	m_deq.push_front("str2_3");

	cout << "m_deq 元素序列at(): ";
	for (int i = 0; i < m_deq.size(); ++i)
	{
		cout << "\"" << m_deq.at(i) << "\"" << " ";
	}
	cout << endl;

	m_deq.pop_back();
	m_deq.pop_front();

	cout << "pop_back() 与 pop_front()后, m_deq 元素序列at(): ";
	for (int i = 0; i < m_deq.size(); ++i)
	{
		cout << "\"" << m_deq.at(i) << "\"" << " ";
	}
	cout << endl;
}

void StlTest::stlForwardList()
{
    //forward_list只提供钱箱迭代器，因此不支持反向迭代器，比如rbegin()等成员函数。
	//forward_list不提供size（）成员函数。
	//forward_list没有指向最末元素的锚点，因此不提供back（）、push_back（）和pop_back（）。
	//forward_list不提供随机访问，这一点跟list相同。
	//插入和删除元素不会造成“指向至其他元素”的指针，引用和迭代器失效。
}

void StlTest::stlList()
{
	//list双向链表，是序列容器，允许在序列中的任何地方进行常数时间插入和擦除操作，并在两个方向上进行迭代, 可以高效地进行插入删除元素。
	//list 容器的元素并不是连续存储的，所以该容器迭代器中，必须包含一个可以指向 list 容器的指针，
}

void StlTest::stlStack()
{
	//stack没有迭代器，是一种容器适配器，用于在LIFO（后进先出）的操作，其中元素仅从容器的一端插入和提取。
	//stack底层一般用list或deque实现，封闭头部即可，不用vector的原因应该是容量大小有限制，扩容耗时
}

void StlTest::stlQueue()
{
	//queue 是一种容器适配器，用于在FIFO（先入先出）的操作，其中元素插入到容器的一端并从另一端提取。
	//队列不提供迭代器，不实现遍历操作。
}

void StlTest::stlPriorityQueue()
{
	//优先队列，其底层是用堆来实现的。在优先队列中，队首元素一定是当前队列中优先级最高的那一个。
}
void StlTest::stlSet()
{
	//set 是按照特定顺序存储唯一元素的容器。
}





