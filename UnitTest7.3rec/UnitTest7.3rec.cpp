#include "pch.h"
#include "CppUnitTest.h"
#include "../laboratory7.3rec/laboratory7.3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 5;
			int colCount = 5;
			int low = -10;
			int high = 10;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			Create(a, rowCount, colCount, low, high, 0, 0);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(a[i][j] >= low && a[i][j] <= high);
				}
			}
			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
		TEST_METHOD(TestRowSeria)
		{

			int arr[3][4] = {
				{ 1, 1, 2, 3 },
				{ 4, 4, 3, 4 },
				{ 7, 8, 8, 8 }
			};
			int* a[3];
			for (int i = 0; i < 3; ++i) {
				a[i] = arr[i];
			}
			int longestRow = -1;
			int maxLength = 0;
			int rowCount = 3;
			int colCount = 4;


			rowSeria(a, rowCount, colCount, longestRow, maxLength);


			Assert::AreEqual(longestRow, 2);
		}
		TEST_METHOD(TestPart1_CountColsWithZero_NoZeroColumns)
		{

			int arr[3][3] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};
			int* a[3];
			for (int i = 0; i < 3; ++i) {
				a[i] = arr[i];
			}
			int count = 0;
			bool result = false;
			int rowCount = 3;
			int colCount = 3;

			bool res = Part1_CountColsWithZero(a, rowCount, colCount, count, result);

			Assert::IsFalse(res);
			Assert::AreEqual(count, 0);
			Assert::IsFalse(result);
		}
	};
}
