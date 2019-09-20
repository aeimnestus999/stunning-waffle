#include <iostream>
#include <fstream>
#define N 64
using namespace std;

struct DataResult
{
	char surname[N];
	char result_first[N];
	char result_second[N];
	char result_third[N];
	char result_fourth[N];
	char result_fifth[N];
};
void StructCreateData(DataResult *Student, int n)
{
	for (int i = 0; i < n; i++)
	{
		DataResult *d = &Student[i];
		cout << "Enter surname student:";
		cin >> d->surname;
		cout << "Enter result of first exam: ";
		cin >> d->result_first;
		cout << "Enter result of second exam: ";
		cin >> d->result_second;
		cout << "Enter result of third exam: ";
		cin >> d->result_third;
		cout << "Enter result of forty exam: ";
		cin >> d->result_fourth;
		cout << "Enter result of fifty exam: ";
		cin >> d->result_fifth;
		cout << endl;
	}
	cout << endl;
}
void StructWriteFile(DataResult *Student, int n)
{
	ofstream input_file("StudentsResult.dat");
	if (input_file.fail())
	{
		cerr << "Error with opening file!" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		DataResult *d = &Student[i];
		input_file <<  d->surname << endl;
		input_file << "Result of first exam: " << d->result_first << endl;
		input_file << "Result of second exam " << d->result_second << endl;
		input_file << "Result of third exam: " << d->result_third << endl;
		input_file << "Result of fourth exam: " << d->result_fourth << endl;
		input_file << "Result of fifth exam: " << d->result_fifth << endl;
		input_file << "      " << endl;
	}
	input_file.close();
}
void StructReadFile(DataResult *Student, int n)
{
	ifstream output_file("StudentsResult.dat");
	for (int i = 0; i < n; i++)
	{
		char empty_line[N];
		DataResult *d = &Student[i];
		output_file.getline(d->surname, N);
		output_file.getline(d->result_first, N);
		output_file.getline(d->result_second, N);
		output_file.getline(d->result_third, N);
		output_file.getline(d->result_fourth, N);
		output_file.getline(d->result_fifth, N);
		output_file.getline(empty_line, N);
	}
	output_file.close();
}
void StructWriteStudent(DataResult *Student, int n)
{
	char mark_exam[] = "5";
	for (int i = 0; i < n; i++)
	{
		DataResult *d = &Student[i];
		if ((strstr(d->result_first, mark_exam) != 0) && (strstr(d->result_second, mark_exam) != 0) && (strstr(d->result_third, mark_exam) != 0) && (strstr(d->result_fourth, mark_exam) != 0) && (strstr(d->result_fifth, mark_exam) != 0)) 
		{
			cout << "Surname student, who has passed all exams with '5': " << d->surname << endl;
			cout << endl;
		}
	}
}
int main()
{
	int n;
	cout << "Enter amount of students: ";
	cin >> n;
	cout << endl;
	DataResult *Student = new DataResult[n];
	StructCreateData(Student, n);
	StructWriteFile(Student, n);
	StructReadFile(Student, n);
	StructWriteStudent(Student, n);
	return 0;
}