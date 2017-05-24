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
			string res1 = rh->searchAllDiseases(genome, maladies);
			string test1 = "MA v1.0\r\nDISEASE cancer\r\n\r\n";
			Assert::AreEqual(test1, res1);

			genome->push_back("ATCG");
			string test2 = "MA v1.0\r\nDISEASE cancer\r\nDISEASE grippe\r\n\r\n";
			string res2 = rh->searchAllDiseases(genome, maladies);
			Assert::AreEqual(test2, res2);

			genome->remove("ATC");
			genome->remove("ATCG");
			string test3 = "MA v1.0\r\n\r\n";
			string res3 = rh->searchAllDiseases(genome, maladies);
			Assert::AreEqual(test3, res3);

		}

		TEST_METHOD(TestSearchDisease) 
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

			list<string> mots2;
			mots2.push_back("ATCG");
			mots2.push_back("CC");
			string nom2 = "grippe";
			Maladie maladie2(nom2, mots2);

			maladies->push_back(maladie1);
			maladies->push_back(maladie2);

			RequestHandler* rh = new RequestHandler();
			string res1 = rh->searchDisease(genome, "cancer", maladies);
			string test1 = "MA v1.0\r\nDISEASE cancer\r\n\<1>\r\n\r\n";
			Assert::AreEqual(test1, res1);

			string res2 = rh->searchDisease(genome, "test", maladies);
			string test2 = "MA v1.0\r\nERROR\r\n\r\n";
			Assert::AreEqual(test2, res2);

			genome->remove("CC");
			string res3 = rh->searchDisease(genome, "cancer", maladies);
			string test3 = "MA v1.0\r\nDISEASE cancer\r\n\<0>\r\n\r\n";
			Assert::AreEqual(test3, res3);
		}

		TEST_METHOD(TestRepDiagnostique)
		{
			list<Maladie> * maladies = new list<Maladie>;
			list<string> mots1;
			mots1.push_back("ATC");
			mots1.push_back("CC");
			string nom1 = "cancer";
			Maladie maladie1(nom1, mots1);

			list<string> mots2;
			mots2.push_back("ATCG");
			mots2.push_back("CC");
			string nom2 = "grippe";
			Maladie maladie2(nom2, mots2);

			maladies->push_back(maladie1);
			maladies->push_back(maladie2);

			RequestHandler* rh = new RequestHandler();
			string res1 = rh->repDiagnostique(maladies);
			string test1 = "MA v1.0\r\nDISEASES\r\ncancer\r\ngrippe\r\n\r\n";
			Assert::AreEqual(test1, res1);

			list<Maladie> * maladies2 = new list<Maladie>();
			string res2 = rh->repDiagnostique(maladies2);
			string test2 = "MA v1.0\r\nDISEASES\r\n\r\n";
			Assert::AreEqual(test2, res2);
		}
	};
}