#include "stdafx.h"
#include "CppUnitTest.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Jeu d'Echecs/util.h"
//#include "util.h"

#include "../Jeu d'Echecs/Case.h"
#include "../Jeu d'Echecs/Piece.h"
#include "../Jeu d'Echecs/Pion.h"
#include "../Jeu d'Echecs/Cavalier.h"

#include "init.h"

void processInput(GLFWwindow *window)
{
	//
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PionsCavaliersUnitTest
{
	Pion PionBlancTest;
	Pion PionNoirTest(NOIR, PION);

	TEST_CLASS(PionsEtCavalier)
	{
	public:

		TEST_CLASS_INITIALIZE(initCases)
		{
			Logger::WriteMessage("Début des Tests:");
			Logger::WriteMessage("Initialisations des Cases...");
			InitialiserLesCases();
		}

		TEST_CLASS_CLEANUP(fin)
		{
			Logger::WriteMessage("Fin des Tests!!!");
		}

		PionsEtCavalier()
		{
			//
		}

		~PionsEtCavalier()
		{
			//
		}

		/*****************		Pion Blanc 2A		*****************/
		//Pion PionBlancTest;

		TEST_METHOD(ConstructeurPionBlancInitCouleur)
		{
			//Assert::AreEqual((unsigned short)BLANC, PionBlancTest.getCouleur());
			Assert::IsTrue(PionBlancTest.getCouleur() == (unsigned short)BLANC);
			//Assert::IsTrue(PionBlancTest.getCouleur() == 0);
		}

		TEST_METHOD(ConstructeurPionBlancInitType)
		{
			//Assert::AreEqual((unsigned short)PION, PionBlancTest.getType());
			Assert::IsTrue(PionBlancTest.getType() == (unsigned short)PION);
			//Assert::IsTrue(PionBlancTest.getType() == 0);
		}

		TEST_METHOD(ConstructeurPionNoirInitCouleur)
		{
			Assert::IsTrue(PionNoirTest.getCouleur() == (unsigned short)NOIR);
		}

		TEST_METHOD(ConstructeurPionNoirInitType)
		{
			Assert::IsTrue(PionNoirTest.getType() == (unsigned short)PION);
		}

		// (2, A) ----> (2, A)
		TEST_METHOD(PionBlancSurPlace)
		{
			//bool valeurAttendue = PionBlancTest.validerDeplacement(1, 1, 1, 1);

			Assert::IsFalse(PionBlancTest.validerDeplacement(2, 'A', 2, 'A'));
		}
		
		// (2, A) ----> (0, A)
		TEST_METHOD(PionBlancDansVide)
		{
			Assert::IsFalse(PionBlancTest.validerDeplacement(2, 'A', 0, 'A'));
		}

		// (2, A) ----> (3, A)
		TEST_METHOD(PionBlancEnAvantLibreA)
		{
			Assert::IsTrue(PionBlancTest.validerDeplacement(2, 'A', 3, 'A'));

			// MODIFIER L'ÉCHEQUIER
			deplacerPiece(2, 'A', 3, 'A');
		}

		// (3, A) ----> (5, A)
		TEST_METHOD(PionBlancEnAvantTropGrand)
		{
			Assert::IsFalse(PionBlancTest.validerDeplacement(3, 'A', 5, 'B'));
		}

		/*****************		Pion Blanc 2B		*****************/
		// (2, B) ----> (1, B)
		TEST_METHOD(PionBlancEnArriereOccupe)
		{
			Assert::IsFalse(PionBlancTest.validerDeplacement(2, 'B', 1, 'B'));
		}

		// (2, B) ----> (1, C)
		TEST_METHOD(PionBlancEnArriereDiagOccupe)
		{
			Assert::IsFalse(PionBlancTest.validerDeplacement(2, 'B', 1, 'C'));
		}

		// (2, B) ----> (4, B)
		TEST_METHOD(PionBlancEnAvant2Rangees)
		{
			Assert::IsTrue(PionBlancTest.validerDeplacement(3, 'A', 5, 'B'));

			deplacerPiece(3, 'A', 5, 'B');
		}

		/*****************		Pion Noir 7B		*****************/
		/*****************		Pion Noir 7C		*****************/
		//Pion PionNoirTest(NOIR, PION);
		//unsigned short couleur = 0,
		//	type = 1;
		//Pion PionX(couleur, type);

		// (7, B) ----> (5, B)
		TEST_METHOD(PionNoirEnAvantLibreB)
		{
			Pion PionNoirTest(NOIR, PION);

			Assert::IsTrue(PionNoirTest.validerDeplacement(7, 'B', 5, 'B'));

			deplacerPiece(7, 'B', 5, 'B');
		}
	};

	//TEST_CLASS(Tour)
	//{
	//public:

	//	//// (2, A) ----> (0, A)
	//	//TEST_METHOD(PionSurPlace)
	//	//{
	//	//	//bool valeurAttendue = PionTest.validerDeplacement(1, 1, 1, 1);

	//	//	Assert::IsFalse(PionTest.validerDeplacement(2, 'A', 0, 'A'));
	//	//}

	//	//// (2, A) ----> (3, A)
	//	//TEST_METHOD(PionEnAvantOccupe)
	//	//{
	//	//	Assert::IsTrue(PionTest.validerDeplacement(2, 'A', 3, 'A'));

	//	//	deplacerPiece(2, 'A', 3, 'A');
	//	//}

	//	//// (3, A) ----> (5, A)
	//	//TEST_METHOD(PionADroiteOccupe)
	//	//{
	//	//	Assert::IsFalse(PionTest.validerDeplacement(3, 'A', 5, 'B'));
	//	//}

	//	//TEST_METHOD(PionEnDiagOccupe)
	//	//{
	//	//	Assert::IsFalse(PionTest.validerDeplacement(1, 'A', 2, 'B'));
	//	//}
	//};

	//TEST_CLASS(Fou)
	//{
	//public:

	//};

	//TEST_CLASS(Reine)
	//{
	//public:

	//};

	//TEST_CLASS(Roi)
	//{
	//public:

	//};
}