#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GenomeManager2017/stdafx.h"
#include <iostream>
#include <list>
#include "../GenomeManager2017/ResponseHandler.h"
#include "../GenomeManager2017/SocketClient.h"
#include "../GenomeManager2017/GenomeManager2017Dlg.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenomeManagerUnitTest
{
	TEST_CLASS(TestResponseHandler)
	{
	public:

		TEST_METHOD(TestSendDisease)
		{
			ResponseHandler* rh = new ResponseHandler("Syndrome de Treacher-Collins","MonFichier.txt");
			string request = rh->getBrc()->getRequest();
			string request_expected = "MA v1.0\r\nGET DISEASES\r\n\r\n";

			Assert::AreEqual(request_expected, request);

			delete rh;

		}
		TEST_METHOD(TestSendAll)
		{
			
			ResponseHandler* rh = new ResponseHandler("", "MonFichier.txt");
			string genome = "ATC;CGT;CGA;";
			rh->getBrc()->setGenome(genome);
			rh->getBrc()->requestFullAnalysis();
			string request = rh->getBrc()->getRequest();
			
			
			string request_expected = "MA v1.0\r\nCHECK ALL\r\n"+genome+"\r\n\r\n";

			Assert::AreEqual(request_expected, request);

			delete rh;
		}

		TEST_METHOD(TestReceiveError)
		{

			ResponseHandler* rh = new ResponseHandler("", "MonFichier.txt");
			string response = "Wrong answer";
			string output = rh->processResponse(response);
			string output_expected = "Erreur interne au serveur.\r\n";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

		TEST_METHOD(TestReceiveDiseasesKnow)
		{

			ResponseHandler* rh = new ResponseHandler("Maladie2", "MonFichier.txt");

			string response = "MA v1.0\r\nDISEASES\r\nMaladie1\r\nMaladie2\r\n\r\n";
			string output = rh->processResponse(response);
			string output_expected = "Le serveur va analyser votre maladie.";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

		TEST_METHOD(TestReceiveDiseasesUnknow)
		{

			ResponseHandler* rh = new ResponseHandler("Maladie1", "MonFichier.txt");

			string response = "MA v1.0\r\nDISEASES\r\nMaladie3\r\nMaladie4\r\n\r\n";
			string output = rh->processResponse(response);
			string output_expected = "Le serveur ne connait pas cette maladie.\r\n";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

		TEST_METHOD(TestReceiveDisease0)
		{
			ResponseHandler* rh = new ResponseHandler("Maladie1", "MonFichier.txt");

			string response = "MA v1.0\r\nDISEASE Maladie1\r\n<0>\r\n\r\n";
			string output = rh->processResponse(response);
			string output_expected = "Vous n'avez pas la maladie.\r\n";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

		TEST_METHOD(TestReceiveDisease1)
		{
			ResponseHandler* rh = new ResponseHandler("Maladie1", "MonFichier.txt");

			string response = "MA v1.0\r\nDISEASE Maladie1\r\n<1>\r\n\r\n";
			string output = rh->processResponse(response);
			string output_expected = "Vous avez la maladie suivante : Maladie1.\r\n";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

		TEST_METHOD(TestReceiveMultipleDiseasesNone)
		{
			ResponseHandler* rh = new ResponseHandler("", "MonFichier.txt");

			string response = "MA v1.0\r\nDISEASE \r\n";
			string output = rh->processResponse(response);
			string output_expected = "Vous n'avez pas de maladie.\r\n";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

		TEST_METHOD(TestReceiveMultipleDiseases)
		{
			ResponseHandler* rh = new ResponseHandler("", "MonFichier.txt");

			string response = "MA v1.0\r\nDISEASE Maladie1\r\nDISEASE Maladie2\r\n";
			string output = rh->processResponse(response);
			string output_expected = "Vous avez les maladies suivantes :\r\nMaladie1\r\nMaladie2\r\n\r\n";

			Assert::AreEqual(output_expected, output);

			delete rh;
		}

	};
}