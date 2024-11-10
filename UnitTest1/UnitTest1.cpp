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

            // Викликаємо функцію сортування
            sortZodiacsByLastName(zodiacs, 3);

            // Перевіряємо, чи відсортовано масив за прізвищами в алфавітному порядку
            Assert::AreEqual("Brown", zodiacs[0].lastName);
            Assert::AreEqual("Doe", zodiacs[1].lastName);
            Assert::AreEqual("Smith", zodiacs[2].lastName);
        }

        // Тестування функції пошуку за знаком зодіаку
        TEST_METHOD(TestSearchByZodiacSign)
        {
            Zodiac zodiacs[3] = {
                {"Doe", "John", "Aries", {15, 3, 1990}},
                {"Smith", "Alice", "Cancer", {25, 6, 1988}},
                {"Brown", "Charlie", "Virgo", {5, 9, 1992}}
            };

            // Перехоплюємо потік, щоб зберегти результат функції в рядок
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // Викликаємо функцію пошуку за знаком зодіаку "Cancer"
            searchByZodiacSign(zodiacs, 3, "Cancer");

            // Повертаємо початковий буфер
            std::cout.rdbuf(oldCout);

            // Очікуємо, що результат містить інформацію про "Alice Smith" зі знаком "Cancer"
            std::string result = buffer.str();
            Assert::IsTrue(result.find("Smith") != std::string::npos);
            Assert::IsTrue(result.find("Alice") != std::string::npos);
            Assert::IsTrue(result.find("Cancer") != std::string::npos);

			
			
		}

		
	};
}
