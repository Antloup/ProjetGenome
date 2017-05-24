#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GenomeManager2017/stdafx.h"
#include <iostream>
#include <list>
#include "Maladie.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeManagerUnitTest
{
	TEST_CLASS(TestMaladie)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			list<string>  listeMot;
			for (int i = 0; i < 5; i++) {
				listeMot.push_back("Mot" + i);
			}
			string nomMaladie = "Maladie";
			Maladie maladie = Maladie(nomMaladie, listeMot);

			Assert::AreEqual(nomMaladie, maladie.getNom());

			list<string> mots = maladie.getMots();
			string test;
			int i = 0;
			for (std::list<string>::iterator it = mots.begin(); it != mots.end(); it++){
				i++;
				test = "Mot" + i;
				Assert::AreEqual(*it , test);
			}
				

			}


	};
}