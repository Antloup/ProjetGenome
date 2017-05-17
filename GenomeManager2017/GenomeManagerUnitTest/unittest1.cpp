#include "stdafx.h"
#include "CppUnitTest.h"
#include "GenomeManager2017Dlg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeManagerUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			CGenomeManager2017Dlg cgm;
			int res = cgm.add(3, 2);
			Assert::AreEqual(5, res);
		}

	};
}