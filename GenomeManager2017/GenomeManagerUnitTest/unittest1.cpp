#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GenomeManager2017/GenomeManager2017Dlg.h"
#include "../GenomeManager2017/Analyse.h"
#include <iostream>
#include <list>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeManagerUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		/*TEST_METHOD(TestMethod1)
		{
			CGenomeManager2017Dlg cgm;
			int res = cgm.add(3, 2);
			Assert::AreEqual(5, res);
		}*/

		TEST_METHOD(TestMethod1)
		{
			Analyse analyse = Analyse("C:\\Users\\mbronnert\\Source\\Repos\\ProjetGenome\\GenomeManager2017\\GenomeManager2017\\x64\\Debug\\genome.txt");
			list <string> * liste = new list<string>();
			liste->push_back("ATC");
			liste->push_back("CG");
			Assert::AreEqual(liste->size(), analyse.getGenome()->size());
			list<string>::iterator itGenome = analyse.getGenome()->begin();
			for (list<string>::iterator it = liste->begin(); it != liste->end() ; ++it)
			{
				Assert::AreEqual(*it, *itGenome);
				++itGenome;
			}
			
		}

	};
}