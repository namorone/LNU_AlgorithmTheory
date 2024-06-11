#include "pch.h"
#include "CppUnitTest.h"
#include"../АВЛ/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTest
{
	TEST_CLASS(AVLTest)
	{
	public:

		TEST_METHOD(TestMethod_height)
		{
			Node* root5 = NULL;
			root5 = insert(root5, 9);
			root5 = insert(root5, 5);
			root5 = insert(root5, 10);
			root5 = insert(root5, 0);
			root5 = insert(root5, 11);
			root5 = insert(root5, 1);
			Assert::AreEqual(root5->height, 3);
		}

		TEST_METHOD(TestMethod_balance)
		{
			Node* root7 = NULL;
			root7 = insert(root7, 10);
			root7 = insert(root7, 20);
			root7 = insert(root7, 30);
			root7 = insert(root7, 40);
			root7 = insert(root7, 50);
			root7 = insert(root7, 25);
			Assert::AreEqual(getBalance(root7), 0);
		}

		TEST_METHOD(TestMethod_max)
		{
			int x = 4;
			int y = 8;
			Assert::IsTrue(max(x, y) == y);
			int m = 129;
			int n = 38;
			Assert::IsTrue(max(m, n) == m);
		}

		TEST_METHOD(TestMethod_delete_height)
		{
			Node* root3 = NULL;
			root3 = insert(root3, 10);
			root3 = insert(root3, 20);
			root3 = insert(root3, 30);
			root3 = insert(root3, 40);
			root3 = insert(root3, 50);
			root3 = insert(root3, 25);
			Assert::AreEqual(root3->height, 3);
			root3 = deleteNode(root3, 10);
			root3 = deleteNode(root3, 25);
			root3 = deleteNode(root3, 50);
			Assert::AreEqual(root3->height, 2);
		}
	};
}
