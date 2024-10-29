#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1(char).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCount)
        {
            char str1[] = "nno";
            char str2[] = "n?o";
            char str3[] = "aaa n?o bbb n?o ccc";

            Assert::AreEqual(1, Count(str1)); // �� ������ ����� ����� 'n?o'
            Assert::AreEqual(1, Count(str2)); // ̳����� 1 ����� 'n?o'
            Assert::AreEqual(2, Count(str3)); // ̳����� 2 ����� 'n?o'
        }

        TEST_METHOD(TestChange)
        {
            char str1[] = "n?o";
            char str2[] = "Hello n?o world n?o!";
            char str3[] = "No pattern here";

            char* result1 = Change(str1);
            char* result2 = Change(str2);
            char* result3 = Change(str3);

            Assert::AreEqual("**", result1); // ����� 'n?o' �� '**'
            Assert::AreEqual("Hello ** world **!", result2); // ����� 'n?o' �� '**'
            Assert::AreEqual("No pattern here", result3); // ���� ����

            delete[] result1; // ��������� ���'��
            delete[] result2; // ��������� ���'��
            delete[] result3; // ��������� ���'��
        }
    };
}