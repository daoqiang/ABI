// DotNetCalled.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream>
struct Base
{
	virtual void __stdcall hello(char* hello)=0;
};
struct MyStruct	:Base
{
	void __stdcall hello(char* hello)
	{
		std::cout << hello << std::endl;
	};
};
extern "C" __declspec(dllexport)  void __cdecl Create(Base** my)
{
	std::cout << "hello world" << std::endl;
	*my = new MyStruct();
}
