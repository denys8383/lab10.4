#include "pch.h"
#include "CppUnitTest.h"
#include "../Project10.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest104
{
	TEST_CLASS(UnitTest104)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            std::string testString = "abc12345xyz";
            int result = findMaxDigitSequence(testString);
            Assert::AreEqual(5, result); 
           
		}
	};
}
