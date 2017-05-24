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

		string path_test_file = "../GenomeTest";
		string string_test;

		TEST_METHOD(TestMethodBuilderDiseases)
		{
			BuildRequestClient builder_test;
			builder_test.createRequest(path_test_file);

			string_test = "MA v1.0\r\nGET DISEASES\r\n\r\n";
			builder_test.requestDiseases();
			Assert::AreEqual(string_test, builder_test.getRequest());
		}

		TEST_METHOD(TestMethodBuilderFullAnalysis)
		{
			BuildRequestClient builder_test;
			builder_test.createRequest(path_test_file);

			string_test = "MA v1.0\r\CHECK ALL\r\AAAA;GGGG;TTTT;CCCC;\r\n\r\n";
			builder_test.requestFullAnalysis();
			Assert::AreEqual(string_test, builder_test.getRequest());
		}

		TEST_METHOD(TestMethodBuilderSpecificAnalysis)
		{
			BuildRequestClient builder_test;
			builder_test.createRequest(path_test_file);

			string_test = "MA v1.0\r\CHECK DISEASE\r\nMaladieTest\r\nAAAA;GGGG;TTTT;CCCC;\r\n\r\n";
			builder_test.requestSpecificAnalysis("MaladieTest");
			Assert::AreEqual(string_test, builder_test.getRequest());
		}

	};
}