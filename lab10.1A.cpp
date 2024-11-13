#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Speciality { ComputerScience, AppliedMath, Physics, Engineering };
string specialityStr[] = { "����'����� �����", "��������� ����������", "Գ����", "��������" };

struct Student
{
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
int CountGoodGrades(const Student* s, const int N, int subjectIndex);
double CalculateExcellentPercent(const Student* s, const int N);

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    int N;
    cout << "������ ������� �������� N: ";
    cin >> N;

    Student* s = new Student[N];
    int menuItem;

    do {
        cout << "\n\n������� ��:\n";
        cout << " [1] - �������� ����� ��������\n";
        cout << " [2] - ���� ����� �� �����\n";
        cout << " [3] - ��������� ������� ������ '�����' � ������� ��������\n";
        cout << " [4] - ���������� �������� ��������, �� �������� '5' � ������ � ����������\n";
        cout << " [0] - �����\n";
        cout << "������ ��������: ";
        cin >> menuItem;

        switch (menuItem) 
        {
        case 1:
            Create(s, N);
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            cout << "ʳ������ ������ '�����' (4) � ������: " << CountGoodGrades(s, N, 0) << endl;
            cout << "ʳ������ ������ '�����' (4) � ����������: " << CountGoodGrades(s, N, 1) << endl;
            cout << "ʳ������ ������ '�����' (4) � �����������: " << CountGoodGrades(s, N, 2) << endl;
            break;
        case 4:
            cout << "������� ��������, �� �������� '5' � � ������ � ����������: "
                << CalculateExcellentPercent(s, N) << "%" << endl;
            break;
        case 0:
            break;
        default:
            cout << "������������ ����!" << endl;
        }
    } while (menuItem != 0);

    delete[] s;
    return 0;
}

void Create(Student* s, const int N) 
{
    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "������� �" << i + 1 << ":\n";
        cout << " �������: ";
        cin >> s[i].surname;
        cout << " ����: ";
        cin >> s[i].course;
        cout << " ������������ (0 - ����'����� �����, 1 - ��������� ����������, 2 - Գ����, 3 - ��������): ";
        cin >> speciality;

        s[i].speciality = static_cast<Speciality>(speciality); //������������
        cout << " ������ � ������: ";
        cin >> s[i].physicsGrade;
        cout << " ������ � ����������: ";
        cin >> s[i].mathGrade;
        cout << " ������ � �����������: ";
        cin >> s[i].informaticsGrade;
    }
}

void Print(const Student* s, const int N) 
{
    cout << "==========================================================================================\n";
    cout << "| �  | �������       | ���� | ������������       | Գ����  | ���������� | �����������  |\n"; 
    cout << "------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
            << setw(15) << left << s[i].surname << "| "
            << setw(4) << s[i].course << " | "
            << setw(20) << left << specialityStr[s[i].speciality] << "| "
            << setw(7) << s[i].physicsGrade << " | "
            << setw(10) << s[i].mathGrade << " | "
            << setw(12) << s[i].informaticsGrade << " |\n";
    }
    cout << "==========================================================================================\n";
}

int CountGoodGrades(const Student* s, const int N, int subjectIndex)
{
    int count = 0;
    for (int i = 0; i < N; i++) 
    {
        int grade = 0;
        switch (subjectIndex)
        {
        case 0: grade = s[i].physicsGrade; 
            break;
        case 1: grade = s[i].mathGrade; 
            break;
        case 2: grade = s[i].informaticsGrade; 
            break;
        }
        if (grade == 4) 
            count++;
    }
    return count;
}

double CalculateExcellentPercent(const Student* s, const int N) 
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].physicsGrade == 5 && s[i].mathGrade == 5) count++;
    }
    return (N > 0) ? (static_cast<double>(count) / N) * 100 : 0;
}
 