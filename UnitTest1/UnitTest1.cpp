#include "pch.h"
#include "CppUnitTest.h"
#include "../lb10.3/lb10.3.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Zodiac zodiacs[3] = {
                {"Doe", "John", "Aries", {15, 3, 1990}},
                {"Smith", "Alice", "Cancer", {25, 6, 1988}},
                {"Brown", "Charlie", "Virgo", {5, 9, 1992}}
            };

            // ��������� ������� ����������
            sortZodiacsByLastName(zodiacs, 3);

            // ����������, �� ����������� ����� �� ��������� � ���������� �������
            Assert::AreEqual("Brown", zodiacs[0].lastName);
            Assert::AreEqual("Doe", zodiacs[1].lastName);
            Assert::AreEqual("Smith", zodiacs[2].lastName);
        }

        // ���������� ������� ������ �� ������ ������
        TEST_METHOD(TestSearchByZodiacSign)
        {
            Zodiac zodiacs[3] = {
                {"Doe", "John", "Aries", {15, 3, 1990}},
                {"Smith", "Alice", "Cancer", {25, 6, 1988}},
                {"Brown", "Charlie", "Virgo", {5, 9, 1992}}
            };

            // ������������ ����, ��� �������� ��������� ������� � �����
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // ��������� ������� ������ �� ������ ������ "Cancer"
            searchByZodiacSign(zodiacs, 3, "Cancer");

            // ��������� ���������� �����
            std::cout.rdbuf(oldCout);

            // �������, �� ��������� ������ ���������� ��� "Alice Smith" � ������ "Cancer"
            std::string result = buffer.str();
            Assert::IsTrue(result.find("Smith") != std::string::npos);
            Assert::IsTrue(result.find("Alice") != std::string::npos);
            Assert::IsTrue(result.find("Cancer") != std::string::npos);

			
			
		}

		
	};
}
