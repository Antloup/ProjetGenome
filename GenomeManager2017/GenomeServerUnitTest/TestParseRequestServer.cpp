#include "stdafx.h"
#include "../GenomeServer2017/stdafx.h"
#include "CppUnitTest.h"
#include <list>
#include <string>
#include "../GenomeServer2017/Maladie.h"
#include "../GenomeServer2017/ParseRequestServer.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeServerUnitTest
{
	TEST_CLASS(TestParseRequestServer)
	{
	public:

		TEST_METHOD(TestConstructeur)
		{
			// Test1

			string maladie = "cancer";

			list<string> * genome = new list<string>();
			genome->push_back("ATC");
			genome->push_back("CGT");
			genome->push_back("GGTC");

			string test1 = "MA v1.0\r\nCHECK DISEASE\r\ncancer\r\nATC;CGT;GGTC;\r\n\r\n";
			ParseRequestServer prs(test1);
			Assert::AreEqual(maladie, prs.getMaladie());

			list<string>::iterator it = prs.getGenome()->begin();
			for (string mot : *genome)
			{
				Assert::AreEqual(mot, *it);
				++it;
			}

			Assert::AreEqual(0, prs.getType());

			// Test2

			string test2 = "MA v1.0\r\nGET DISEASES\r\n\r\n";
			ParseRequestServer prs2(test2);
			string null = "";
			Assert::AreEqual(null, prs2.getMaladie());
			int size = prs2.getGenome()->size();
			Assert::AreEqual(0, size);
			Assert::AreEqual(1, prs2.getType());

			// Test3

			string test3 = "MA v1.0\r\nCHECK ALL\r\nATC;CGT;GGTC;\r\n\r\n";
			ParseRequestServer prs3(test3);
			Assert::AreEqual(null, prs3.getMaladie());

			it = prs3.getGenome()->begin();
			for (string mot : *genome)
			{
				Assert::AreEqual(mot, *it);
				++it;
			}

			Assert::AreEqual(2, prs3.getType());
		}
	};
}