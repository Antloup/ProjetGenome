#include "stdafx.h"
#include "../GenomeServer2017/stdafx.h"
#include "CppUnitTest.h"
#include <list>
#include <string>
#include "../GenomeServer2017/Maladie.h"
#include "../GenomeServer2017/RequestHandler.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeServerUnitTest
{		
	TEST_CLASS(TestRequestHandler)
	{
	public:
		
		TEST_METHOD(TestSearchAllDeseases)
		{
			list<string> * genome = new list<string>;
			genome->push_back("ATC");
			genome->push_back("CC");
			genome->push_back("GTAAG");
			genome->push_back("ACGT");

			list<Maladie> * maladies = new list<Maladie>;
			list<string> mots1;
			mots1.push_back("ATC");
			mots1.push_back("CC");
			string nom1 = "cancer";
			Maladie maladie1(nom1, mots1);

			list<string> mots2 ;
			mots2.push_back("ATCG");
			mots2.push_back("CC");
			string nom2 = "grippe";
			Maladie maladie2(nom2, mots2);

			maladies->push_back(maladie1);
			maladies->push_back(maladie2);

			RequestHandler* rh = new RequestHandler();
			string res1 = rh->searchAllDeseases(genome, maladies);
			string test1 = "MA v1.0\r\nDESEASE cancer\r\n\r\n";
			Assert::AreEqual(test1, res1);
		}

	};
}