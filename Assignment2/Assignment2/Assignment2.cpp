#include <iostream>

using namespace std;

int reviewForm(double idea, double novelty, double contribution, double paperOrganization, double evaluation);
double errorCheck(double num);
int counter = 0;

int main()
{
	double idea, novelty, contribution, paperOrganization, evaluation;

	for (int i = 1; i <= 4; i++) {
		counter++;

		cout << "Reviewer " << i << ": Please fill out the review form:" << endl;
		cout << "For the following form, please enter a grade of 0 to 10 for each criteria" << endl;
		cout << "Enter your evaluation for Idea: ";
		cin >> idea;
		errorCheck(idea);
		cout << "Enter your evaluation for Novelty: ";
		cin >> novelty;
		errorCheck(novelty);
		cout << "Enter your evaluation for Contribution: ";
		cin >> contribution;
		errorCheck(contribution);
		cout << "Enter your evaluation for Paper Organization: ";
		cin >> paperOrganization;
		errorCheck(paperOrganization);
		cout << "Enter your evaluation for Performance Evaluation: ";
		cin >> evaluation;
		errorCheck(evaluation);
		
		reviewForm(idea, novelty, contribution, paperOrganization, evaluation);
		
	}

}

int reviewForm(double idea, double novelty, double contribution, double paperOrganization, double evaluation) {
	bool isRejected{ false }, isAccepted{ false }, isBorderline{ false };
	static double calcAvgOne= (idea + novelty + contribution + paperOrganization + evaluation) / 5;
	static double totalAvg{ 0 }, totalSum{0};

	totalSum = totalSum + calcAvgOne;
	totalAvg = (totalSum) / counter;

	if (counter == 4) {
		if (calcAvgOne >= 5 && totalAvg >= 7) {
			isAccepted = true;
			cout << "The paper is accepted" << endl;
		}
		else if (calcAvgOne < 5 && totalAvg < 6) {
			isRejected = true;
			cout << "The paper is rejected" << endl;
		}
		else if (totalAvg >= 6 && totalAvg < 7) {
			isBorderline = true;
			cout << "The paper is borderline" << endl;
		}
	}
	else {
		return 0;
	}

}

double errorCheck(double num) {

	while (num < 0 || num >10) {
		cout << "Please enter an evaluation between 1 and 10" << endl;
		cin >> num;
	}
	return num;
}