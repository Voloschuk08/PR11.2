#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11.2/PR11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest112
{
	TEST_CLASS(UnitTest112)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual((size_t)3, MaxConsecutiveSpaces("Hello   world!"));
			Assert::AreEqual((size_t)0, MaxConsecutiveSpaces("NoSpacesHere"));
			Assert::AreEqual((size_t)5, MaxConsecutiveSpaces("     "));
			Assert::AreEqual((size_t)2, MaxConsecutiveSpaces("Test  case"));
			Assert::AreEqual((size_t)4, MaxConsecutiveSpaces("Line with    spaces"));
		}

		// Тест для функції ReadFileContent
		TEST_METHOD(TestReadFileContent)
		{
			// Створення тимчасового файлу для тесту
			const string tempFilePath = "test_file.txt";
			ofstream tempFile(tempFilePath);
			tempFile << "Line 1\nLine  2\nLine   3";
			tempFile.close();

			// Очікуваний результат
			string expectedContent = "Line 1\nLine  2\nLine   3\n";

			// Виклик функції та перевірка
			Assert::AreEqual(expectedContent, ReadFileContent(tempFilePath));

			// Видалення тимчасового файлу
			remove(tempFilePath.c_str());
		}
	};
}
