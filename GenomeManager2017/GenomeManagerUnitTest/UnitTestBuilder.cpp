#include "stdafx.h"
#include "../GenomeServer2017/stdafx.h"
#include "CppUnitTest.h"
#include "BuildRequestClient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeServerUnitTest
{
	TEST_CLASS(UnitTestBuilder)
	{
	public:

		string path_test_file = "GenomeTest.txt";
		BuildRequestClient builder_test;
		string string_test;

		TEST_METHOD(TestMethodBuilderDiseases)
		{
			builder_test.createRequest(path_test_file);

			string_test = "MA v1.0\r\nGET DISEASES\r\n\r\n";
			builder_test.requestDiseases();
			Assert::AreEqual(string_test, builder_test.getRequest());
		}

		TEST_METHOD(TestMethodBuilderFullAnalysis)
		{
			builder_test.createRequest(path_test_file);

			string_test = "MA v1.0\r\nCHECK ALL\r\nAAAA;GGGG;TTTT;CCCC;\r\n\r\n";
			builder_test.requestFullAnalysis();
			Assert::AreEqual(string_test, builder_test.getRequest());
		}

		TEST_METHOD(TestMethodBuilderSpecificAnalysis)
		{
			builder_test.createRequest(path_test_file);

			string_test = "MA v1.0\r\nCHECK DISEASE\r\nMaladieTest\r\nAAAA;GGGG;TTTT;CCCC;\r\n\r\n";
			builder_test.requestSpecificAnalysis("MaladieTest");
			Assert::AreEqual(string_test, builder_test.getRequest());
		}



	};
}
