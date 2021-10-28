#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm>

#include <process.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>

#include <C:\Loay\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\x86_64-w64-mingw32\include\color.hpp>

using namespace std;

//  GRAPHS //

class Color
{
public:
	Color(int desiredColor)
	{
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		color = desiredColor;
	}

	friend ostream &operator<<(ostream &ss, Color obj)
	{
		SetConsoleTextAttribute(obj.consoleHandle, obj.color);
		return ss;
	}

private:
	int color;
	HANDLE consoleHandle;
};

BOOL gotoxy(const WORD x, const WORD y)
{
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void ShowCursor(bool show)
{
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
	structCursorInfo.dwSize = 50;
	structCursorInfo.bVisible = show;

	SetConsoleCursorInfo(hConsoleOutput,
						 &structCursorInfo);
}
// END of GRAPHS //

typedef char option[45];
const int row = 10, col = 10;
int scan //To hold the special character for moving the prompt in menu
	,
	ascii;

// Array Of Options For Every Menu //
option menu_opt[] = {
	"Entry",
	"Display",
	"Enquiry",
	"Modification",
	"Performance",
	"Exit",
};
//To display the ENTRY menu option.
option entry_opt[] = {
	"College",
	"Student",
	"Exam Form",
	"Exam Schedule",
	"Result",
	"Back To Previous Menu",
};
//To display the DISPLAY menu option
option display_opt[] = {
	"College",
	"Student",
	"Exam Form",
	"Exam Schedule",
	"Result",
	"Back To Previous Menu",
};
//To display the ENQUIRY menu option
option enquiry_opt[] = {
	"College",
	"Student",
	"back To Previous Menu",
};
//To display the MODIFICATION menu option
option modification_opt[] = {
	"College",
	"Student",
	"Back To Previous Menu",
};
//To display the PERFORMANCE menu option
option performance_opt[] = {
	"Foundation",
	"Back To Previous Menu",
};
// End Of Menu Options //

// CLASSES DEFINITION //
class Main_menu
{
private:
	int i, done;

public:
	void normal(int x, int y, char *str);
	void reverse(int x, int y, char *str);
	void box(int x1, int y1, int x2, int y2);
	char menu();
	void control_menu();
	void entry_menu();
	char e_menu();
	void display_menu();
	char d_menu();
	void enquiry_menu();
	char enqu_menu();
	void modification_menu();
	char mod_menu();
	void performance_menu();
	char perform_menu();
	void welcome_screen();
};

class Shape
{
public:
	void line_hor(int, int, int, char);
	void line_ver(int, int, int, char);
	void box(int, int, int, int, char);
};

class College
{
private:
	void add_to_file(int, char[], char[], char[], char[], char[]);
	void box_for_dis(int);
	void box_for_enquiryCollege(int);
	int coll_id;
	char coll_name[30], coll_location[30], coll_stream[30], coll_degI[30], coll_degII[30];

public:
	void new_college();
	void dis_all_college();
	void college_enquiry();
	void college_modification();
	void clear(int, int);
	int found_college(int);
	char *valid_name(int);
	char *valid_location(int);
	char *valid_stream(int);
	char *valid_degI(int);
	char *valid_degII(int);
	void dis_by_id(int);
	void save_college_modification(int, char[], char[], char[], char[], char[]);
	int last_coll_id();
	int record_no(int);
};

class Student
{
private:
	void add_to_file(int, char[], char[], char[], char[], char[], char[], char[], char[], char[], char[]);
	void box_for_dis(int);
	void box_for_enquiryStudent(int);
	int stu_id;
	char first_name[30], last_name[30], stu_address[30], stu_city[30], stu_state[30], stu_zip[30], stu_contact[30], stu_code[30], stu_stream[30], stu_degree[30];

public:
	void new_student();
	void dis_all_student();
	void student_enquiry();
	void student_modification();
	void clear(int, int);
	int found_student(int);
	void exam_display(int, int);
	void result_display(int);
	char *valid_first_name(int);
	char *valid_last_name(int);
	char *valid_address(int);
	char *valid_city(int);
	char *valid_state(int);
	char *valid_zip(int);
	char *valid_contact(int);
	char *valid_code(int);
	char *valid_stream(int);
	char *valid_degree(int);
	void dis_by_id(int);
	void save_student_modification(int, char[], char[], char[], char[], char[], char[], char[]);
	int last_stu_id();
	int record_no(int);
};

class ExamInfo
{
	char stu_degree[30], first_name[30], last_name[30], stu_address[30], stu_stream[30], sd1[30], ed1[30], sm1[30], em1[30], sy1[30], ey1[30], deg[30];
	int stu_id, examform_id, hp1, hp2, hp3, hp4, hp5, hp6, hp7, hp8, s1, s2, com, gk;
	int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16;
	//function to add record
	void add_to_file_schedule(char[], char[], char[], char[], char[], char[], char[]);

public:
	void exam_form();			//function for the form fill up
	void exam_schedule();		//function for the entry of the schedule
	void display_forms();		//function to display
	void display_schedule();	//function to display
	void result_entry();		//function for the entry of the result
	void result_display_list(); //function for the result display
	char *return_degname(int);	//function for the valid entry of degree
	int last_examform_id();		//function to find the last id
	void clear(int, int);		//function for clearing screen
	void display(int);			//function to display
	//function to add record
	void add_to_file_form(int, int, char[], char[], char[], char[], char[]);
	//function to add record
	void add_to_filebaI(int, char[], char[], int, int, int, int, int);
	//function to add record
	void add_to_filebaII(int, char[], char[], int, int, int, int, int);
	//function to add record
	void add_to_filebaIII(int, char[], char[], int, int, int, int, int);
	//function to add record
	void add_to_filemaI(int, char[], char[], int, int, int, int, int, int, int, int);
	//function to add record
	void add_to_filemaII(int, char[], char[], int, int, int, int, int, int, int, int);
};

class Performance
{
public:
	void foundation();
};

// End Of Classes //

// Funtions For Graphics 
void Main_menu::normal(int x, int y, char *str)
{
	gotoxy(x, y);
	cout << str;
}
//Function to move the cursor in the menu prompt with reverse video color
void Main_menu::reverse(int x, int y, char *str)
{
	Color(5 + 143);
	system("Color 70");
	gotoxy(x, y);
	cout << str;
	system("Color 02");
	system("Color 00");
}
void Main_menu::box(int x1, int y1, int x2, int y2)
{
	for (int col = x1; col < x2; col++)
	{
		gotoxy(col, y1);
		cout << (char)196;
		gotoxy(col, y2);
		cout << (char)196;
	}
	for (int row = y1; row < y2; row++)
	{
		gotoxy(x1, row);
		cout << (char)179;
		gotoxy(x2, row);
		cout << (char)179;
	}
	gotoxy(x1, y1);
	cout << (char)218;
	gotoxy(x1, y2);
	cout << (char)192;
	gotoxy(x2, y1);
	cout << (char)191;
	gotoxy(x2, y2);
	cout << (char)217;
}

/* function to draw horizontal line.This public function draws one horizontal line at a time*/
void Shape::line_hor(int coloumn1, int coloumn2, int row, char c)
{
	for (coloumn1; coloumn1 <= coloumn2; coloumn1++)
	{
		gotoxy(coloumn1, row);
		cout << c;
	}
}

/*function to draw vertical line.this public function draws one vertical line at a time.*/
void Shape::line_ver(int row1, int row2, int coloumn, char c)
{
	for (row1; row1 <= row2; row1++)
	{
		gotoxy(coloumn, row1);
		cout << c;
	}
}

/*Function for drawing box.This function draws a box for menus*/
void Shape::box(int coloumn1, int row1, int coloumn2, int row2, char c)
{
	char ch = 218;
	char c1, c2, c3, c4;
	char l1 = 196, l2 = 179;
	if (c == ch)
	{
		c1 = 218;
		c2 = 191;
		c3 = 217;
		c4 = 217;
		l1 = 196;
		l2 = 179;
	}
	else
	{
		c1 = c;
		c2 = c;
		c3 = c;
		c4 = c;
		l1 = c;
		c2 = c;
	}
	gotoxy(coloumn1, row1);
	cout << c1;
	gotoxy(coloumn2, row1);
	cout << c2;
	gotoxy(coloumn1, row2);
	cout << c3;
	gotoxy(coloumn2, row2);
	cout << c4;
	coloumn1++;
	coloumn2--;
	line_hor(coloumn1, coloumn2, row1, l1); //Horizontal lines
	line_hor(coloumn1, coloumn2, row1, l1);
	coloumn1--;
	coloumn2++;
	row1++;
	row2--;
	line_ver(row1, row2, coloumn1, l2); //vertical line
	line_ver(row1, row2, coloumn2, l2);
}
/*Function to display college details.This function displays the heading and
the college id, name, location and stream on the screen*/
void College::box_for_dis(int t_collid)
{
	char t_name[30], t_location[30], t_stream[30];
	// Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(63, 2);
	cout << "Date: " << std::ctime(&_time);
	gotoxy(4, 2);
	cout << "College ID" << t_collid;

	strcpy(t_name, valid_name(t_collid));

	strcpy(t_location, valid_location(t_collid));

	strcpy(t_stream, valid_stream(t_collid));

	gotoxy(25, 2);
	cout << t_name;
	gotoxy(25, 3);
	cout << t_location;
	gotoxy(4, 5);
	cout << "ENQUIRY MENU FOR COLLEGE";
	gotoxy(1, 6);
	for (int i = 1; i <= 76; i++)
		cout << "=";
	gotoxy(4, 7);
	cout << "STREEM            DEGREE-I          DEGREE-II";
	gotoxy(1, 8);
	for (int i = 1; i <= 76; i++)
		cout << "=";
	
}
void College::box_for_enquiryCollege(int t_coll_id)
{
	char t_name[30], t_loc[30];
	gotoxy(4, 2);
	cout << "COLLEGE ID:" << t_coll_id;

	strcpy(t_name, valid_name(t_coll_id));
	strcpy(t_loc, valid_location(t_coll_id));

	gotoxy(25, 2);
	cout << t_name;
	gotoxy(25, 3);
	cout << t_loc;

	gotoxy(4, 5);
	cout << "ENQUIRY REPORT OF COLLEGE";
	
	gotoxy(1, 6);
	for (int i = 1; i <= 76; i++)
		cout << "=";
	gotoxy(4, 7);
	cout << "STREAM                         DEGREE-I         DEGREE-II";
	gotoxy(1, 8);
	for (int i = 1; i <= 79; i++)
		cout << "=";
	
}
/*Function to display student detail. This function displays the student name,
student id, father name, address, contact no., zip,  city,  state.*/
void Student::box_for_dis(int t_stuid)
{
	char t_first_name[30], t_last_name[30], t_address[30];
	// Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(63, 2);
	cout << "Date: " << std::ctime(&_time);
	gotoxy(4, 2);
	cout << "College ID" << t_stuid;
	char t_name[30];
	strcpy(t_first_name, valid_first_name(t_stuid));
	char t_fname[30];
	strcpy(t_last_name, valid_last_name(t_stuid));
	char t_add[30];
	strcpy(t_address, valid_address(t_stuid));
	gotoxy(25, 2);
	cout << t_name;
	gotoxy(25, 3);
	cout << t_add;
	gotoxy(25, 4);
	cout << t_fname;
	gotoxy(4, 5);
	cout << "ENQUIRY FOR STUDENT";
	gotoxy(1, 6);
	for (int i; i <= 79; i++)
		cout << "=";
	gotoxy(4, 7);
	cout << "ADDRESS     CITY     STATE     ZIP      CONTACT     CODE    STREAM     DEG";
	gotoxy(1, 8);
	for (int i = 1; i <= 79; i++)
		cout << "=";
	
}

void Student::box_for_enquiryStudent(int t_stuid)
{
	char t_name[30];char t_add[30];char t_fname[30];
	// Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);	
	gotoxy(63, 2);
	std::cout << "Date: " << std::ctime(&_time);

	gotoxy(4, 2);
	cout << "STUDENT ID:" << t_stuid;
	
	strcpy(t_name, valid_first_name(t_stuid));
	strcpy(t_add, valid_address(t_stuid));
	strcpy(t_fname, valid_last_name(t_stuid));

	gotoxy(25, 2);
	cout << t_name;
	gotoxy(25, 3);
	cout << t_fname;
	gotoxy(25, 3);
	cout << t_add;
	gotoxy(4, 5);
	cout << "ENQUIRY REPORT OF STUDENT";

	gotoxy(1, 6);
	for (int i = 1; i <= 79; i++)
		cout << "=";
	gotoxy(4, 7);
	cout <<"STATE      ZIP       CODE        CONTACT           STREAM         DEGREE";
	gotoxy(1, 8);
	for (int i = 1; i <= 79; i++)
		cout << "=";
	
}
// END Functions For Graphics //

// Functions For Display MENUS and Their Options 
char Main_menu::menu()
{

	system("cls");
	Color(22);
	box(20, 6, 65, 20);
	box(18, 4, 67, 22);
	Color(5 + 143);
	gotoxy(28, 5);
	system("Color 70");
	cout << Color(148) << "University Management System";
	system("Color 00");
	Color(22);
	for (int i = 1; i < 6; i++)
		normal(32, i + 10, menu_opt[i]);
	reverse(32, 10, menu_opt[0]);
	i = done = 0;
	ShowCursor(true); //change the cursor type
	do
	{
		int key = getch();
		switch (key)
		{
		case 72:
			normal(32, i + 10, menu_opt[i]);
			i--;
			if (i == -1)
				i = 5;
			reverse(32, i + 10, menu_opt[i]);
			break;

		case 80:
			normal(32, i + 10, menu_opt[i]);
			i++;
			if (i == 6)
				i = 0;
			reverse(32, i + 10, menu_opt[i]);
			break;

		case 13:
			done = 1;
		}
	} while (!done);
	ShowCursor(false);
	return (i + 49);
}

/*The function main_menu() is used to display the main menu of university managment system.
This function uses 6 main options and each has its specific purposes for maintaining
the university.In this menu,the user can avail the facilities by pressing any number
from 1 to 5 and in case he presses any other key the prompt will come back from menu to the
source promgram or it is better to press '0' to exit from the menu.other than 0 and 1...5
if you press any other key the university managment system do not response till you press a valid number
*/
void Main_menu::control_menu()
{
	char choice;
	do
	{
		choice = menu();
		system("cls");

		switch (choice)
		{
		case '1':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			gotoxy(7, 4);
			entry_menu(); //sub menu of main menu
			break;

		case '2':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			gotoxy(7, 5);
			display_menu(); //sub menu of main menu
			break;

		case '3':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			gotoxy(7, 6);
			enquiry_menu(); //sub menu of main menu
			Sleep(500);
			break;

		case '4':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			gotoxy(7, 8);
			modification_menu(); //sub menu of main menu
			break;

		case '5':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			gotoxy(7, 9);
			performance_menu(); //sub menu of main menu
			break;

		case '6':
			exit(0);
		}
	} while (choice != 5);
}
char Main_menu::e_menu()
{
	system("cls");
	Color(22);
	box(25, 6, 65, 20);
	box(23, 4, 67, 22);
	Color(5 + 143);
	gotoxy(34, 5);
	system("Color 70");
	cout << Color(148) << "Entery Menu";
	system("Color 00");
	Color(22);
	for (int i = 1; i < 6; i++)
		normal(32, i + 10, entry_opt[i]);
	reverse(32, 10, entry_opt[0]);
	i = done = 0;
	ShowCursor(true); //change the cursor type
	do
	{
		int key = getch();
		switch (key)
		{
		case 72:
			normal(32, i + 10, entry_opt[i]);
			i--;
			if (i == -1)
				i = 5;
			reverse(32, i + 10, entry_opt[i]);
			break;

		case 80:
			normal(32, i + 10, entry_opt[i]);
			i++;
			if (i == 6)
				i = 0;
			reverse(32, i + 10, entry_opt[i]);
			break;

		case 13:
			done = 1;
		}
	} while (!done);
	ShowCursor(false);
	return (i + 49);
}

/*Function for entry menu with open college, student, examform, schedule and result sub-menu.This is one of the submenu which manages
five basic operations such as:
	-New College
	-New Student
	-Exam Form
	-Exam Schedule
	-Result
while entering new college information college name, address, stream, degree are asked to enter
student menu provides information to add that are nessary.*/
void Main_menu::entry_menu()
{
	char choice;
	College college;
	Student student;
	ExamInfo exam;
	do
	{
		choice = e_menu();
		system("cls");

		switch (choice)
		{
		case '1':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			gotoxy(7, 4);
			college.new_college();; //sub menu of main menu
			break;

		case '2':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			gotoxy(7, 5);
			student.new_student(); //sub menu of main menu
			break;

		case '3':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			gotoxy(7, 6);
			exam.exam_form();; //sub menu of main menu
			break;

		case '4':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			gotoxy(7, 8);
			exam.exam_schedule(); //sub menu of main menu
			break;

		case '5':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			gotoxy(7, 9);
			exam.result_entry(); //sub menu of main menu
			break;
		case '6':
			//control_menu();
			return;
		}
	} while (choice != 5);
}

char Main_menu::d_menu()
{
	system("cls");
	Color(22);
	box(25, 6, 65, 20);
	box(23, 4, 67, 22);
	Color(5 + 143);
	gotoxy(34, 5);
	system("Color 70");
	cout << Color(148) << "Display Menu";
	system("Color 00");
	Color(22);
	for (int i = 1; i < 6; i++)
		normal(32, i + 10, display_opt[i]);
	reverse(32, 10, display_opt[0]);
	i = done = 0;
	ShowCursor(true); //change the cursor type
	do
	{
		int key = getch();
		switch (key)
		{
		case 72:
			normal(32, i + 10, display_opt[i]);
			i--;
			if (i == -1)
				i = 5;
			reverse(32, i + 10, display_opt[i]);
			break;

		case 80:
			normal(32, i + 10, display_opt[i]);
			i++;
			if (i == 6)
				i = 0;
			reverse(32, i + 10, display_opt[i]);
			break;

		case 13:
			done = 1;
		}
	} while (!done);
	ShowCursor(false);
	return (i + 49);
}

/*Function for display menu with college,  student,  exam form,  exam schedule,  and result.This is one of the sub menu which manages
five operations such as:
	-College
	-Student
	-Exam Form
	-Exam Schedule
	-Result
while displaying records it displays all the records that were enterd in the entry section and
extract this information from their particulat database files*/
void Main_menu::display_menu()
{
	char choice;
	College college;
	Student student;
	ExamInfo exam;
	do
	{
		choice = d_menu();
		system("cls");

		switch (choice)
		{
		case '1':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			college.dis_all_college();; //sub menu of main menu
			std::cin.get();
			break;

		case '2':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			student.dis_all_student();; //sub menu of main menu
			std::cin.get();
			break;

		case '3':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			exam.display_forms();; //sub menu of main menu
			std::cin.get();
			break;

		case '4':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			exam.display_schedule(); //sub menu of main menu
			std::cin.get();
			break;

		case '5':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			exam.result_display_list(); //sub menu of main menu
			std::cin.get();
			break;
		case '6':
			//control_menu();
			return;
		}
	} while (choice != 5);
}

char Main_menu::enqu_menu()
{
	system("cls");
	Color(22);
	box(25, 6, 65, 20);
	box(23, 4, 67, 22);
	Color(5 + 143);
	gotoxy(34, 5);
	system("Color 70");
	cout << Color(148) << "Enquiry Menu";
	system("Color 00");
	Color(22);
	for (int i = 1; i < 6; i++)
		normal(32, i + 10, enquiry_opt[i]);
	reverse(32, 10, enquiry_opt[0]);
	i = done = 0;
	ShowCursor(true); //change the cursor type
	do
	{
		int key = getch();
		switch (key)
		{
		case 72:
			normal(32, i + 10, enquiry_opt[i]);
			i--;
			if (i == -1)
				i = 2;
			reverse(32, i + 10, enquiry_opt[i]);
			break;

		case 80:
			normal(32, i + 10, enquiry_opt[i]);
			i++;
			if (i == 3)
				i = 0;
			reverse(32, i + 10, enquiry_opt[i]);
			break;

		case 13:
			done = 1;
		}
	} while (!done);
	ShowCursor(false);
	return (i + 49);
}

/*This function is used for the enquiry of aparticular college or student
This function asks the user to enter id of the college or student for which
they want to enquiry about*/
void Main_menu::enquiry_menu()
{
	char choice;
	College college;
	Student student;
	ExamInfo exam;
	do
	{
		choice = enqu_menu();
		system("cls");

		switch (choice)
		{
		case '1':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			college.college_enquiry();; //sub menu of main menu
			std::cin.get();
			break;

		case '2':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			student.student_enquiry();; //sub menu of main menu
			std::cin.get();
			break;
		case '3':
			//control_menu();
			return;
		}
	} while (choice != 3);
}

char Main_menu::mod_menu()
{
	system("cls");
	Color(22);
	box(25, 6, 65, 20);
	box(23, 4, 67, 22);
	Color(5 + 143);
	gotoxy(34, 5);
	system("Color 70");
	cout << Color(148) << "Display Menu";
	system("Color 00");
	Color(22);
	for (int i = 1; i < 6; i++)
		normal(32, i + 10, modification_opt[i]);
	reverse(32, 10, modification_opt[0]);
	i = done = 0;
	ShowCursor(true); //change the cursor type
	do
	{
		int key = getch();
		switch (key)
		{
		case 72:
			normal(32, i + 10, modification_opt[i]);
			i--;
			if (i == -1)
				i = 2;
			reverse(32, i + 10, modification_opt[i]);
			break;

		case 80:
			normal(32, i + 10, modification_opt[i]);
			i++;
			if (i == 3)
				i = 0;
			reverse(32, i + 10, modification_opt[i]);
			break;

		case 13:
			done = 1;
		}
	} while (!done);
	ShowCursor(false);
	return (i + 49);
}

/*This function is used to modify the information of the college or student.
This function asks for the college or student id for modification.First it
shows the old record and then asks the user "Do You Want To Modify(Y/N).If
the user press yes it ask the user to enter the new information and then
saves it in their particular data files*/
void Main_menu::modification_menu()
{
	char choice;
	College college;
	Student student;
	ExamInfo exam;
	do
	{
		choice = mod_menu();
		system("cls");

		switch (choice)
		{
		case '1':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			college.college_modification();; //sub menu of main menu
			std::cin.get();
			break;

		case '2':
			box(3, 1, 75, 24);
			box(5, 2, 73, 23);
			ShowCursor(true);
			student.student_modification();; //sub menu of main menu
			std::cin.get();
			break;
		case '3':
			//control_menu();
			return;
		}
	} while (choice != 3);
}

char Main_menu::perform_menu()
{
	system("cls");
	Color(22);
	box(25, 6, 65, 20);
	box(23, 4, 67, 22);
	Color(5 + 143);
	gotoxy(34, 5);
	system("Color 70");
	cout << Color(148) << "Performance Menu";
	system("Color 00");
	Color(22);
	for (int i = 1; i < 6; i++)
		normal(32, i + 10, performance_opt[i]);
	reverse(32, 10, performance_opt[0]);
	i = done = 0;
	ShowCursor(true); //change the cursor type
	do
	{
		int key = getch();
		switch (key)
		{
		case 72:
			normal(32, i + 10, performance_opt[i]);
			i--;
			if (i == -1)
				i = 1;
			reverse(32, i + 10, performance_opt[i]);
			break;

		case 80:
			normal(32, i + 10, performance_opt[i]);
			i++;
			if (i == 2)
				i = 0;
			reverse(32, i + 10, performance_opt[i]);
			break;

		case 13:
			done = 1;
		}
	} while (!done);
	ShowCursor(false);
	return (i + 49);
}
/*This function dispalys the performance of the university such as
	- Foundation
	-Annual Report
*/
void Main_menu::performance_menu()
{
	char choice;
	Performance performance;
	do
	{
		choice = perform_menu();
		system("cls");
		switch (choice)
		{
		case '1':
			box(2, 1, 77, 24);
			box(3, 2, 75, 23);
			ShowCursor(true);
			performance.foundation();
			std::cin.get();
			break;

		case '2':
			return;
		}
	} while (choice != 2);
}

// END Functions For Display MENUS and Their Options 


// Function for Find The ID And Return the Record Number //

//  College // 
/* Function to find a college for display college function. This is used to find any account in the
"college.dat"data files, where the file is searched from the first record position and it searches
whether the entred id exit or not. If it exit then the variable found will return a value 1 or
0 as the parameter*/
int College::found_college(int t_coll_id)
{
	int found = 0;
	ifstream iFile;
	iFile.open("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while(iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			found = 1;
			break;
		}
	}
	iFile.close();
	return found;
}

int College::last_coll_id()
{
	ifstream iFile;
	iFile.open("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int t_coll_id = 0;
	while(iFile.read((char *)this, sizeof(College)))	
		t_coll_id = coll_id;
	
	iFile.close();
	return t_coll_id;
}

int College::record_no(int t_coll_id)
{
	ifstream iFile;
	iFile.open("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int count = 0;
	while(iFile.read((char *)this, sizeof(College)))	
	{
		count++;
		if (t_coll_id == coll_id)
			break;
	}	
	
	iFile.close();
	return count;
}

// Student //
/* Function to find a student for display college function. This is used to find any account in the
"student.dat"data files, where the file is searched from the first record position and it searches
whether the entred id exit or not. If it exit then the variable found will return a value 1 or
0 as the  parameter*/
int Student::found_student(int t_stu_id)
{
	int found = 0;
	ifstream iFile;
	iFile.open("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while(iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			found = 1;
			break;
		}
	}
	iFile.close();
	return found;

}
int Student::last_stu_id()
{
	ifstream iFile;
	iFile.open("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int t_stu_id = 0;
	while(iFile.read((char *)this, sizeof(Student)))	
		t_stu_id = stu_id;
	
	iFile.close();
	return t_stu_id;
}
int Student::record_no(int t_stu_id)
{
	ifstream iFile;
	iFile.open("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int count = 0;
	while(iFile.read((char *)this, sizeof(Student)))	
	{
		count++;
		if (t_stu_id == stu_id)
			break;
	}	
	
	iFile.close();
	return count;
}

// Exam Info //
int ExamInfo::last_examform_id()
{
	ifstream iFile;
	iFile.open("FORM.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int t_examform_id = 0;
	while(iFile.read((char *)this, sizeof(ExamInfo)))	
		t_examform_id = examform_id;
	
	iFile.close();
	return t_examform_id;
}
// END Function for Find The ID And Return the Record Number //

// Function for Validation the Data.

//  College //

char *College::valid_name(int t_coll_id)
{
	char t_name[30];
	ifstream iFile("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			strcpy(t_name, coll_name);
			break;
		}
	}
	iFile.close();
	return t_name; 
}
char *College::valid_location(int t_coll_id)
{
	char t_location[30];
	ifstream iFile("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			strcpy(t_location, coll_location);
			break;
		}
	}
	iFile.close();
	return t_location; 
}
char *College::valid_stream(int t_coll_id)
{
	char t_stream[30];
	ifstream iFile("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			strcpy(t_stream, coll_stream);
			break;
		}
	}
	iFile.close();
	return t_stream; 
}
char *College::valid_degI(int t_coll_id)
{
	char t_degI[30];
	ifstream iFile("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			strcpy(t_degI, coll_degI);
			break;
		}
	}
	iFile.close();
	return t_degI; 
}
char *College::valid_degII(int t_coll_id)
{
	char t_degII[30];
	ifstream iFile("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			strcpy(t_degII, coll_degII);
			break;
		}
	}
	iFile.close();
	return t_degII; 
}

// Student //
char *Student::valid_first_name(int t_stu_id)
{
	char t_first_name[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_first_name, first_name);
			break;
		}
	}
	iFile.close();
	return t_first_name; 
}
char *Student::valid_last_name(int t_stu_id)
{
	char t_last_name[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_last_name, last_name);
			break;
		}
	}
	iFile.close();
	return t_last_name; 
}
char *Student::valid_address(int t_stu_id)
{
	char t_address[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_address, stu_address);
			break;
		}
	}
	iFile.close();
	return t_address; 
}
char *Student::valid_city(int t_stu_id)
{
	char t_city[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_city, stu_city);
			break;
		}
	}
	iFile.close();
	return t_city; 
}
char *Student::valid_state(int t_stu_id)
{
	char t_state[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_state, stu_state);
			break;
		}
	}
	iFile.close();
	return t_state; 
}
char *Student::valid_zip(int t_stu_id)
{
	char t_zip[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_zip, stu_zip);
			break;
		}
	}
	iFile.close();
	return t_zip; 
}
char *Student::valid_contact(int t_stu_id)
{
	char t_contact[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_contact, stu_contact);
			break;
		}
	}
	iFile.close();
	return t_contact; 
}
char *Student::valid_code(int t_stu_id)
{
	char t_code[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_code, stu_code);
			break;
		}
	}
	iFile.close();
	return t_code; 
}
char *Student::valid_stream(int t_stu_id)
{
	char t_stream[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_stream, stu_stream);
			break;
		}
	}
	iFile.close();
	return t_stream; 
}
char *Student::valid_degree(int t_stu_id)
{
	char t_degree[30];
	ifstream iFile("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (t_stu_id == stu_id)
		{
			strcpy(t_degree, stu_degree);
			break;
		}
	}
	iFile.close();
	return t_degree; 
}

// Exam Info //
//char *ExamInfo::return_degname(int){}

// END Function for Validation the Data.

// Functions To ADD NEW College, Student,  Form Entry, Result Entry and Schedule Entry//

/*Function for creating a new college.This is a very important function which is used used to create new college with
all the details of the college.This function uses member functions like last_collid(), add_to_file(), delete_account etc.
The last_collid() function will create automatically a new college id number after checking from the "COLLEGE.dat" file.
Here the college id numbers start from 1 onwards if it is the first record.Also in this function the validation checking
occurs to the name, address, stream and degree.At the time of validation checking the name,
address, stream and degree should not blank and should not more than the specified length.*/
void College::new_college()
{
	char ch;
	int valid, i;
	system("cls");
	Shape shape;
	shape.box(2, 1, 79, 25, 318);
	shape.box(25, 2, 54, 4, 219);
	gotoxy(65, 2);
	cout << "Press \"0\" To Exit";
	gotoxy(3, 3);
	for (i = 1; i <= 76; i++)
		cout << " ";
	//textbackground(BLACK);
	//textcolor(BLACK + BLINK);
	//textbackground(WHITE);
	gotoxy(30, 3);
	ShowCursor(false); //changes cursor type
	cout << dye::grey_on_black("College Entery");
	std::cin.get();
	// Get Current Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);

	int coll_id;
	coll_id = last_coll_id();
	coll_id++;

	char coll_name[30], coll_location[30], coll_stream[30], coll_degI[30], coll_degII[30];
	ShowCursor(true);
	gotoxy(5, 6);
	std::cout << "Date: " << std::ctime(&_time);
	gotoxy(5, 8);
	cout << "College ID: " << coll_id;
	gotoxy(5, 10);
	cout << "Name: ";
	gotoxy(5, 12);
	cout << "Location: ";
	gotoxy(5, 14);
	cout << "Stream: ";
	gotoxy(5, 16);
	cout << "Degree I: ";
	gotoxy(5, 18);
	cout << "Degree II: ";

	// Checking for validation Location
	do
	{

		clear(28, 12);
		clear(5, 23);
		gotoxy(5, 23);
		cout << "Enter the Location of the college: ";
		valid = 1;
		gotoxy(28, 12);
		cin.getline(coll_location, 30);
		strupr(coll_location);
		if (coll_location[0] == '0')
			return;
		if (strlen(coll_location) > 20 || strlen(coll_location) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "The Location of the College MUST be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{

		clear(26, 14);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "Enter the Stream of the college(ARTS/SCIENCE/COMMERCE): ";
		valid = 1;
		gotoxy(24, 14);
		cin.getline(coll_stream, 30);
		strupr(coll_stream);
		if (coll_stream[0] == '0')
			return;
		if (strlen(coll_stream) > 20 || strlen(coll_stream) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "The Stream MUST be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{

		clear(26, 16);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER THE DEGREE COURSE FOR BACHELOR DEGREE(B.A/B.COM/B.SC): ";
		valid = 1;
		gotoxy(26, 16);
		cin.getline(coll_degI, 30);
		strupr(coll_degI);
		if (coll_degI[0] == '0')
			return;
		if (strlen(coll_degI) > 20 || strlen(coll_degI) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "DEGREE SHOULD NOT BE GREATER THAN 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{

		clear(29, 18);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER THE DEGREE COURSE FOR MASTER DEGREE(M.A/M.SC/M.COM)";
		valid = 1;
		gotoxy(29, 18);
		cin.getline(coll_degII, 30);
		strupr(coll_degII);
		if (coll_degII[0] == '0')
			return;
		if (strlen(coll_degII) > 20 || strlen(coll_degII) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 DEGREE SHOULD NOT BE GREATER THAN 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{

		valid = 1;
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "Do You Want to Save the Record? (N/Y): ";
		if (ch == 0)
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	//append the record to college, dat
	add_to_file(coll_id, coll_name, coll_location, coll_stream, coll_degI, coll_degII);
}

/*Function for creating a new student.This is a very important function which is used to create new student with
all the details of the student.This function uses member functions like last_stu_id(), add_to_file(),  etc.
The last_stu_id() function will create automatically a new student id number after checking from the "STUDENT.dat" file.
Here the Student id numbers start from 1 onwards if it is the first record.Also in this function the validation checking
occurs to the name, father's name, address, city, state, contact number, code zip, stream and degree.At the time of validation
checking the name, father's name, address, city, state, contact number, zip, stream and degree should not blank and sholud not
more than the specified length.*/
void Student::new_student()
{
	char ch;
	int i, valid;
	Student student;
	Shape shape;
	gotoxy(65, 2);
	cout << "Press \"0\" To Exit";
	gotoxy(3, 3);
	for (i = 1; i <= 76; i++)
		cout << " ";
	//textbackground(BLACK);
	//textcolor(BLACK + BLINK);
	//textbackground(WHITE);
	gotoxy(30, 3);
	ShowCursor(false); //changes cursor type
	cout << dye::grey_on_black("Student Entry");
	std::cin.get();
	// Get Current Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	int stu_id = last_stu_id();
	stu_id++;
	char first_name[30], last_name[30], stu_address[30], stu_city[30], stu_state[30], stu_zip[30], stu_contact[30], stu_code[30], stu_stream[30], stu_degree[30];
	ShowCursor(true);
	gotoxy(5, 6);
	cout << "Date: " << std::ctime(&_time);
	gotoxy(5, 7);
	cout << "Student ID: " << stu_id;
	gotoxy(5, 8);
	cout << "Student's Name: ";
	gotoxy(5, 9);
	cout << "Student's Last Name: ";
	gotoxy(5, 10);
	cout << "Address: ";
	gotoxy(5, 11);
	cout << "City: ";
	gotoxy(5, 12);
	cout << "State: ";
	gotoxy(5, 13);
	cout << "ZIP Code: ";
	gotoxy(5, 14);
	cout << "Contact Number: ";
	gotoxy(5, 15);
	cout << "Student's Code: ";
	gotoxy(5, 16);
	cout << "Student's Stream: ";
	gotoxy(5, 17);
	cout << "Student's Degree: ";
	do
	{
		clear(24, 8);
		clear(5, 23);
		gotoxy(5, 23);
		valid = 1;
		cout << "Enter First Student's Name: ";
		gotoxy(24, 8);
		cin.getline(first_name, 30);
		strupr(first_name);
		if (first_name[0] == '0')
			return;
		if (strlen(first_name) > 20 || strlen(first_name) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Name Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(24, 9);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Last Student's Name: ";
		gotoxy(24, 9);
		cin.getline(last_name, 30);
		strupr(last_name);
		if (last_name[0] == '0')
			return;
		if (strlen(last_name) > 20 || strlen(last_name) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Name Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(19, 10);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's Address: ";
		gotoxy(19, 10);
		cin.getline(stu_address, 30);
		strupr(stu_address);
		if (stu_address[0] == '0')
			return;
		if (strlen(stu_address) > 20 || strlen(stu_address) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Address Length Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(16, 11);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's City: ";
		gotoxy(16, 11);
		cin.getline(stu_city, 30);
		strupr(stu_city);
		if (stu_city[0] == '0')
			return;
		if (strlen(stu_city) > 20 || strlen(stu_city) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Name of City Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(17, 12);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's State: ";
		gotoxy(17, 12);
		cin.getline(stu_state, 30);
		strupr(stu_state);
		if (stu_state[0] == '0')
			return;
		if (strlen(stu_state) > 20 || strlen(stu_state) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Name of State Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(20, 13);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's ZIP Code: ";
		gotoxy(20, 13);
		cin.getline(stu_zip, 30);
		strupr(stu_zip);
		if (stu_zip[0] == '0')
			return;
		if (strlen(stu_zip) > 10 || strlen(stu_zip) < 5)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The ZIP Code Must be Between 5 and 10";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(22, 14);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's Contact Number: ";
		gotoxy(22, 14);
		cin.getline(stu_contact, 30);
		strupr(stu_contact);
		if (stu_contact[0] == '0')
			return;
		if (strlen(stu_contact) != 11)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Contact Number Must be Equal 11";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(20, 15);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's Code: ";
		gotoxy(20, 15);
		cin.getline(stu_code, 30);
		strupr(stu_code);
		if (stu_code[0] == '0')
			return;
		if (strlen(stu_code) > 10 || strlen(stu_code) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Student's Code Must be LESS than 10";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(26, 16);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "Enter Student's Stream: ";
		gotoxy(26, 16);
		cin.getline(stu_stream, 30);
		strupr(stu_stream);
		if (stu_stream[0] == '0')
			return;
		if (strlen(stu_stream) > 20 || strlen(stu_stream) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Student's Stream Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		clear(26, 17);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "ENTER THE DEGREE CODE(B.A/B.SC/B.COM-I/II/III Or MA/M.SC/M.COM-I/II): ";
		gotoxy(26, 17);
		cin.getline(stu_degree, 30);
		strupr(stu_degree);
		if (stu_degree[0] == '0')
			return;
		if (strlen(stu_degree) > 20 || strlen(stu_degree) == 0)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Please, The Student's Degree Must be LESS than 20";
			std::cin.get();
		}
	} while (!valid);
	do
	{
		valid = 1;
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "DO YOU WANT TO SAVE THE RECORD (Y/N):-";
		ch = getche();
		if (ch == 0)
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;

	add_to_file(stu_id, first_name, last_name, stu_address, stu_city, stu_state, stu_zip, stu_contact, stu_code, stu_stream, stu_degree);
}

/*This is a important function.This function asks for the student id for the
form entry and after entering the student id it matches the id in "STUDENT.dat"
if id is found it extract information related to that id and displays in the
screen and the writes it in to "FORM.dat" data file*/
void ExamInfo::exam_form()
{
	system("cls");
	//ifstream iFile.open("STUDENT.dat", ios::binary);
	int t_stu_id, valid, i;
	Student student;
	Shape shape;
	shape.box(2, 1, 79, 25, 218);
	shape.box(25, 2, 54, 4, 219);
	gotoxy(5, 5);
	cout << "Enter Student's ID: ";
	cin >> t_stu_id;
	if (t_stu_id == 0) return;
	if (!student.found_student(t_stu_id))
	{
		gotoxy(5, 5);
		cout << "NOT Found";
		cin.get();
		return;
	}
	gotoxy(65, 2);
	cout << "Press \"0\" To EXIT";
	gotoxy(3, 3);
	for (i = 1; i <= 76; i++)
		cout << " ";
	cout << dye::grey_on_black("Exam Entry Form");
	std::cin.get();
	// Get Current Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	int t_examform_id = last_examform_id();
	t_examform_id++;
	gotoxy(5, 6);
	cout << "Date: " << std::ctime(&_time);
	gotoxy(5, 8);
	cout << "Exam Form ID: " << examform_id;
	gotoxy(5, 9);
	cout << "First Name: ";
	gotoxy(5, 10);
	cout << "Last Name: ";
	gotoxy(5, 11);
	cout << "Address:-";
	gotoxy(5, 12);
	cout << "Stream: ";
	gotoxy(5, 13);
	cout << "degree: ";
	student.exam_display(t_stu_id, examform_id);
}
/*This is a special function which is used to enter the examination schedule
which includes starting date,  starting month,  staring year as well as ending
date,  ending month,  ending year*/
void ExamInfo::exam_schedule()
{
	int valid, i;
	char ch, degree[30], sd1[30], ed1[30], sm1[30], em1[30], sy1[30], ey1[30];
	Shape shape;
	shape.box(2, 1, 79, 25, 318);
	shape.box(25, 2, 54, 4, 219);	
	gotoxy(65, 2);
	cout << "Press \"0\" To EXIT";
	gotoxy(3, 3);
	for (i = 1; i <= 76; i++)
		cout << " ";
	cout << dye::grey_on_black("Exam Entry SCHEDULE");
	// Get Current Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(5, 6);
	cout << "Date: " << std::ctime(&_time);
	gotoxy(5, 8);
	cout << "Degree: ";
	gotoxy(5, 10);
	cout << "Starting Date: ";
	gotoxy(5, 12);
	cout << "Ending Date: ";
	gotoxy(5, 14);
	cout << "Staring Month: ";
	gotoxy(5, 16);
	cout << "End Month: ";
	gotoxy(5, 18);
	cout << "Starting Year: ";
	gotoxy(5, 20);
	cout << "Ending Year: ";
	do
	{
		clear(18,8);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER DEGREE: ";
		valid = 1;
		gotoxy(18, 8);
		cin	>> degree;
		strupr(degree);
		if (deg[0] == '0') return;
		if (strlen(degree) > 30 || strlen(degree) == 0)
		{
			valid = 0;
			cout << "Degree Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		clear(25,10);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "Enter Starting Date: ";
		valid = 1;
		gotoxy(25, 10);
		cin	>> sd1;
		strupr(sd1);
		if (sd1[0] == '0') return;
		if (strlen(sd1) > 30 || strlen(sd1) == 0)
		{
			valid = 0;
			cout << "Starting Date Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		clear(23,12);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "Enter Ending Date: ";
		valid = 1;
		gotoxy(23, 12);
		cin	>> ed1;
		strupr(ed1);
		if (ed1[0] == '0') return;
		if (strlen(ed1) > 30 || strlen(ed1) == 0)
		{
			valid = 0;
			cout << "Ending Date Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		clear(24,14);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "Enter Starting Month: ";
		valid = 1;
		gotoxy(24, 14);
		cin	>> sm1;
		strupr(sm1);
		if (sm1[0] == '0') return;
		if (strlen(sm1) > 30 || strlen(sm1) == 0)
		{
			valid = 0;
			cout << "Starting Month Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		clear(24,16);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "Enter Ending Month: ";
		valid = 1;
		gotoxy(24, 16);
		cin	>> em1;
		strupr(em1);
		if (em1[0] == '0') return;
		if (strlen(em1) > 30 || strlen(em1) == 0)
		{
			valid = 0;
			cout << "Ending Month Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		clear(25,18);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER Starting Year: ";
		valid = 1;
		gotoxy(25,18);
		cin	>> sy1;
		strupr(sy1);
		if (sy1[0] == '0') return;
		if (strlen(sy1) > 30 || strlen(sy1) == 0)
		{
			valid = 0;
			cout << "Staring Year Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		clear(23,20);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER Ending Year: ";
		valid = 1;
		gotoxy(23, 20);
		cin	>> ey1;
		strupr(ey1);
		if (ey1[0] == '0') return;
		if (strlen(ey1) > 30 || strlen(ey1) == 0)
		{
			valid = 0;
			cout << "Ending Year Must be LESS Than 30 characters";
			cin.get();
		}
	} while(!valid);
	do
	{
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			printf(" ");
		}
		valid = 1;
		gotoxy(5, 23);
		cout << "DO YOU WANT TO SAVE THE RECORD(Y/N)";
		ch = getche();
		if (ch == 0)
			return;

		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	add_to_file_schedule(degree, sd1, ed1, sm1, em1, sy1, ey1);
}

/*This is a special function.This funcion is used to enter the marks of the
student.This function first asks for the student id and then it flashes the
student name,  address,  stream,  degree the it asks to enter the marks after comparing
the degree*/
void ExamInfo::result_entry()
{
	system("cls");
	char ch;
	int i, valid, t_stuid, thp1, thp2, thp3, thp4, thp5, thp6, ts1, ts2, tcom, tgk, tp1, tp2, tp3, tp4, tp5, tp6;
	char tstu_name[30], tstu_fname[30], tstu_add[30], tstu_strm[30], tstu_deg[30];
	
	Shape shape;
	Student stu;
	shape.box(2, 1, 79, 25, 218);
	shape.box(25, 2, 54, 4, 219);	
	gotoxy(65, 2);
	cout << "<0>=EXIT";
	gotoxy(5, 3);
	cout << "ENTER THE STUDENT ID:-";
	cin >> t_stuid;
	if (!stu.found_student(t_stuid))
	{
		gotoxy(5, 4);
		cout << "\7 STUDENT NOT FOUND";
		getch();
		return;
	}
	gotoxy(65, 2);
	cout << "<0>=EXIT";
	gotoxy(3, 3);
	for (i = 1; i <= 79; i++)
		cout << "";
	gotoxy(30, 3);
	cout << dye::light_purple_on_black("RESULT ENTRY");
	
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(5, 6);
	cout << "Date: " << std::ctime(&_time);
	gotoxy(5, 8);
	cout << "NAME:-";
	gotoxy(5, 10);
	cout << "DEGREE:-";
	gotoxy(5, 12);
	cout << "STREAM:-";
	stu.result_display(t_stuid);
}

// END Functions To ADD NEW College, Student,  Form Entry, Result Entry and Schedule Entry//


// Functions for Modifications //

// College //
/* This function is used to modify the college detail.This function asks for the
college id for which the information is to be modified.Then it asks "Do you want to
Modify (Y/N)".If 'Y' is entred it asks for the user to enter new information.
*/
void College::college_modification()
{
	system("cls");
	int j, mod, modified = 0, valid, t, t_collid;;
	char ch, t_name[30], t_loc[30], t_str[30], t_degI[30], t_degII[30];
	cout << "Enter College's ID: ";
	cin >> t_collid;
	if(t_collid == 0) return;
	if (!found_college(t_collid))
	{
		gotoxy(5, 5);
		cout << "Not Found";
		cin.get();
		return;
	}
	gotoxy(71, 1);
	cout << "Press \"0\" To EXIT";
	for (j = 1; j <= 76; j++)
		cout << "";
	cout << dye::grey_on_black("Modify College Detail");
	// Get Current Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(4, 2);
	cout << "Date: " << std::ctime(&_time);
	dis_by_id(t_collid);
	do
	{
		clear(5, 13);
		gotoxy(5, 13);
		cout << "MODIFY COLLEGE DETAILS:(Y/N)";
		ch = getche();
		if (ch == '0')
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	gotoxy(5, 15);
	cout << "NAME:";
	gotoxy(5, 16);
	cout << "LOCATION:";
	gotoxy(5, 17);
	cout << "STREAM:";
	gotoxy(5, 18);
	cout << "DEGREE I:";
	gotoxy(5, 19);
	cout << "DEGREE II:";
	do
	{
		clear(15, 15);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			printf(" ");
		}
		gotoxy(5, 23);
		cout << "ENTER NAME OR PRESS ENTER FOR NO CHANGE:";
		valid = 1;
		gotoxy(15, 15);
		cin.getline(t_name, 30);
		strupr(t_name);
		if (t_name[0] == '0')
			return;
		if (strlen(t_name) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "Name Must be Less than 20";
			getch();
		}
	} while (!valid);
	do
	{
		clear(20, 16);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER LOCATION OR PRESS ENTER FOR NO CHANGE:";
		valid = 1;
		gotoxy(20, 16);
		cin.getline(t_loc, 30);
		strupr(t_loc);
		if (t_loc[0] == '0')
			return;
		if (strlen(t_loc) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "LOCTION SHOULD NOT BE GREATER THAN 20";
			cin.get();
		}
	} while (!valid);
	do
	{
		clear(18, 17);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER STREAM OR PRESS ENTER FOR NO CHANGE:";
		valid = 1;
		gotoxy(18, 17);
		cin.getline(t_str, 30);
		strupr(t_str);
		if (t_str[0] == '0')
			return;
		if (strlen(t_str) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "STREAM SHOULD NOT BE GREATER THAN 20";
			cin.get();
		}
	} while (!valid);
	do
	{
		clear(18, 18);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER DEGREE OR PRESS ENTER FOR NO CHANGE:";
		valid = 1;
		gotoxy(18, 18);
		cin.getline(t_degI, 30);
		strupr(t_degI);
		if (t_degI[0] == '0')
			return;
		if (strlen(t_degI) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "DEGREE SHOULD NOT BE GREATER THAN 20";
			cin.get();
		}
	} while (!valid);
	do
	{
		clear(25, 19);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER DEGREE OR PRESS ENTER FOR NO CHANGE:";
		valid = 1;
		gotoxy(25, 19);
		cin.getline(t_degII, 30);
		strupr(t_degII);
		if (t_degII[0] == '0')
			return;
		if (strlen(t_degII) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "DEGREE SHOULD NOT BE GREATER THAN 20";
			cin.get();
		}
	} while (!valid);
	if (strlen(t_degII) > 0)
		modified = 1;
	if (!modified)
		return;
	clear(5, 23);
	do
	{
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		valid = 1;
		gotoxy(5, 21);
		cout << "DO YOU WANT TO SAVE CHANGES(Y/N)";
		ch = getche();
		if (ch == '0')
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	save_college_modification(t_collid, t_name, t_loc, t_str, t_degI, t_degII);
	gotoxy(5, 22);
	cout << "\7 RECORD MODIFIED";
	gotoxy(5, 23);
	cout << "PRESS ANY KEY TO CONTINUE";
	cin.get();
}
void College::save_college_modification(int t_collid, char t_name[30], char t_loc[30], char t_str[30], char t_degI[30], char t_degII[30])
{
	ofstream oFile;
	oFile.open("COLLEGE.dat", ios::binary | ios::ate);
	strcpy(coll_name, t_name);
	strcpy(coll_location, t_loc);
	strcpy(coll_stream, t_str);
	strcpy(coll_degI, t_degI);
	strcpy(coll_degII, t_degII);
	int recordNo = record_no(t_collid), position;
	//finds the position in the data file ;
	position = (recordNo - 1) * sizeof(College);
	oFile.seekp(position);
	//overwrite the modified record in to the COLLEGE.dat data file.
	oFile.write((char *)this, sizeof(College));
	oFile.close();
	return;
}

// Student //
void Student::student_modification()
{
	system("cls");
	char ch, t_name[30], t_fname[30], t_add[30], t_stream[30], t_city[30], t_state[30], t_zip[30], t_code[10], t_contact[30], t_deg[30];
	int j, t, t_stuid, modified = 0, valid;
	gotoxy(17, 1);
	cout << "Press \"0\" To EXIT";
	gotoxy(5, 5);
	cout << "ENTER THE STUDENT ID:-";
	cin >> t_stuid;
	if (t_stuid == 0)
		return;
	system("cls");
	if (!found_student(t_stuid))
	{
		gotoxy(5, 5);
		cout << "\7 STUDENT NOT FOUND";
		cin.get();
		return;
	}
	gotoxy(71, 1);
	cout << "Press \"0\" To EXIT";
	gotoxy(3, 3);
	for (j = 1; j <= 76; j++)
		cout << "";
	cout << dye::grey_on_black("Modify Student Detail");
	// Get Current Time
	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(4, 2);
	cout << "Date: " << std::ctime(&_time);
	
	dis_by_id(t_stuid);
	do
	{
		clear(5, 13);
		gotoxy(5, 13);
		cout << "MODIFY THESE Student DETAILS<Y/N>";
		ch = getche();
		if (ch == '0')
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	
	gotoxy(5, 15);
	cout << "NAME:-";
	gotoxy(5, 16);
	cout << "FATHER NAME:-";
	gotoxy(5, 17);
	cout << "ADDRESS:-";
	gotoxy(5, 18);
	cout << "STATE:-";
	gotoxy(5, 19);
	cout << "CONTACT-NO.:-";
	gotoxy(5, 20);
	cout << "STREEM:-";
	gotoxy(5, 21);
	cout << "DEGREE:-";
	do
	{
		clear(17, 15);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER NAME OR PRESS ENTER FOR NO CHANGE";
		valid = 1;
		gotoxy(17, 15);
		cin.getline(t_name, 30);
		strupr(t_name);
		if (t_name[0] == '0')
			return;
		if (strlen(t_name) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 NAME SHOULD NOT BE GREATER THAN 20";
			getch();
		}
	} while (!valid);
	do
	{
		clear(23, 16);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER FATHER NAME OR PRESS ENTER FOR NO CHANGE";
		valid = 1;
		gotoxy(23, 16);
		cin.getline(t_fname, 30);
		strupr(t_fname);
		if (t_fname[0] == '0')
			return;
		if (strlen(t_fname) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 FATHER NAME SHOULD NOT BE GREATER THAN 20";
			getch();
		}
	} while (!valid);
	do
	{
		clear(19, 17);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER ADDRESS OR PRESS ENTER FOR NO CHANGE";
		valid = 1;
		gotoxy(19, 17);
		cin.getline(t_add, 30);
		strupr(t_add);
		if (t_add[0] == -'0')
			return;
		if (strlen(t_add) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout <<"\7 ADDRESS SHOULD NOT BE GREATER THAN 20";
			getch();
		}
	} while (!valid);
	do
	{
		clear(17, 18);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(5, 23);
		cout << "ENTER STATE OR PRESS ENTER FOR NO CHANGE";
		valid = 1;
		gotoxy(17, 18);
		cin.getline(t_state, 30);
		strupr(t_state);
		if (t_state[0] == '0')
			return;
		if (strlen(t_state) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 STATE SHOULD NOT BE GREATER THAN 20";
			getch();
		}
	} while (!valid);
	do
	{
		clear(23, 19);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			printf(" ");
		}
		gotoxy(5, 23);
		cout << "ENTER CONTACT OR PRESS ENTER FOR NO CHANGE";
		valid = 1;
		gotoxy(23, 19);
		cin.getline(t_contact, 30);
		strupr(t_contact);
		if (t_contact[0] == '0')
			return;
		if (strlen(t_contact) > 10)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 CONTACT SHOULD NOT BE GREATER THAN 10";
			getch();
		}
	} while (!valid);
	do
	{
		clear(18, 20);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " "; 
		}
		gotoxy(5, 23);
		cout << "ENTER STREEM OR PRESS ENTER FOR NO CHANGE(ARTS/SCIENCE/COMMERCE)";
		valid = 1;
		gotoxy(18, 20);
		cin.getline(t_stream, 30);
		strupr(t_stream);
		if (t_stream[0] == '0')
			return;
		if (strlen(t_stream) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 STREAM SHOULD NOT BE GREATER THAN 20";
			getch();
		}
	} while (!valid);
	do
	{
		clear(18, 21);
		for (int i = 5; i < 79; i++)
		{
			gotoxy(i, 23);
			cout << " ";
		}
		gotoxy(1, 23);
		cout << "ENTER DEGREE OR PRESS ENTER FOR NO CHANGE(B.A/B.SC/B.COM-I/II/III OR M.A/M.SC-I/II)";
		valid = 1;
		gotoxy(18, 21);
		cin.getline(t_deg, 30);

		strupr(t_deg);
		if (t_deg[0] == '0')
			return;
		if (strlen(t_deg) > 20)
		{
			valid = 0;
			gotoxy(5, 23);
			cout << "\7 DEGREE SHOULD NOT BE GREATER THAN 20";
			getch();
		}
	} while (!valid);
	if (strlen(t_deg) > 0)
		modified = 1;
	if (!modified)
		return;
	for (int i = 1; i < 81; i++)
	{
		gotoxy(i, 23);
		printf(" ");
	}

	for (int i = 1; i < 80; i++)
	{
		gotoxy(i, 24);
		cout << " ";
	}
	//clears the screen at 23rd row & from 5th coloum
	clear(5, 23);
	do
	{
		gotoxy(5, 23);
		cout << "DO YOU WANT TO SAVE CHANGES (Y/N):-";
		ch = getche();
		if (ch == '0')
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	//passes the parameter to add in data file
	save_student_modification(t_stuid, t_name, t_fname, t_add, t_state, t_contact, t_stream, t_deg);
	for (int i = 5; i < 79; i++)
	{
		gotoxy(i, 23);
		cout << " ";
	}
	gotoxy(5, 23);
	cout << "\7 RECORD MODIFIED";
	gotoxy(5, 24);
	cout << "PRESS ANY KEY TO CONTINUE";
	getch();
}
void Student::save_student_modification(int t_stuid, char t_name[30], char t_fname[30], char t_add[30], char t_state[30], char t_cont[30], char t_str[30], char t_deg[30])
{
	ofstream oFile;
	oFile.open("STUDENT.dat", ios::binary | ios::ate);
	strcpy(first_name, t_name);
	strcpy(last_name, t_fname);
	strcpy(stu_address, t_add);
	strcpy(stu_state, t_state);
	strcpy(stu_contact, t_cont);
	strcpy(stu_stream, t_str);
	strcpy(stu_degree, t_deg);
	int recordNo = record_no(t_stuid), position;
	//finds the position in the data file ;
	position = (recordNo - 1) * sizeof(Student);
	oFile.seekp(position);
	//overwrite the modified record in to the Student.dat data file.
	oFile.write((char *)this, sizeof(Student));
	oFile.close();
	return;
}
// END Functions for Modifications //


// FUNCTION for DISPLAY DATA FORM FILE //

/*This is a function which displays the details of all the colleges under the university
with all the detail such as colleg id,  college name,  college address,  college stream, college degree
that are under that college.Thus the user can look and know the detail of colleges*/
void College::dis_all_college()
{
	system("cls");
	int flag;
	ifstream iFile;
	gotoxy(25, 1);
	cout << "College List";
	gotoxy(25, 2);
	cout << "=====================";
	gotoxy(1, 3);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	gotoxy(1, 5);
	cout << "College's ID: ";
	gotoxy(4, 5);
	cout << "College's NAME: ";
	gotoxy(20, 5);
	cout << "College's LOCATION: ";
	gotoxy(34, 5);
	cout << "College's STREAM: ";
	gotoxy(48, 5);
	cout << "DEGREE I: ";
	gotoxy(60, 5);
	cout << "DEGREE II: ";
	gotoxy(1, 6);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	iFile.open("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int row = 7;
	while (iFile.read((char *)this, sizeof(College)))
	{
		flag = 0;
		Sleep(2);
		gotoxy(1, row);
		cout << coll_id << endl;
		gotoxy(4, row);
		cout << coll_name << endl;
		gotoxy(20, row);
		cout << coll_location << endl;
		gotoxy(34, row);
		cout << coll_stream << endl;
		gotoxy(48, row);
		cout << coll_degI << endl;
		gotoxy(60, row);
		cout << coll_degII << endl;
		row++;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(4, 24);
			cout << "Press ANy Key To Continue";
			std::cin.get();
			system("cls");
		}
	}
	gotoxy(1, row);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	row++;
	iFile.close();
	if (!flag)
	{
		gotoxy(4, 24);
		cout << "PRESS ANY KEY TO CONTINUE:";
		std::cin.get();
	}
}

void College::college_enquiry()
{
	system("cls");
	ifstream iFile;
	int t_collid;
	gotoxy(71, 1);
	cout << "Press \"0\" To Exit";
	gotoxy(5, 5);
	cout << "Enter College's ID: ";
	cin >> t_collid;
	if (t_collid == 0) return;
	if (!found_college(t_collid))
	{
		gotoxy(5, 5);
		cout << "INVALID ID";
		cin.get();
		return;
	}
	box_for_enquiryCollege(t_collid);
	int row = 9, flag;
	iFile.open("COLLEGE.dat", ios::binary);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (coll_id == t_collid)
		{
			Sleep(2);
			gotoxy(4, row);
			puts(coll_stream);
			gotoxy(38, row);
			puts(coll_degI);
			gotoxy(55, row);
			puts(coll_degII);
			row++;
			if (row > 23)
			{
				flag = 1;
				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE:";
				cin.get();
				box_for_enquiryCollege(t_collid);
			}
		}
	}
	iFile.close();
	if (!flag)
	{
		gotoxy(4, 24);
		cout << "PRESS ANY KEY TO CONTINUE:";
		cin.get();
	}
}

void College::dis_by_id(int t_coll_id)
{
	ifstream iFile;
	iFile.open("COLLEGE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_coll_id == coll_id)
		{
			gotoxy(8, 5);
			cout << "College's ID: " << coll_id << endl;
			gotoxy(8, 6);
			cout << "Name: " << coll_name << endl;
			gotoxy(8, 7);
			cout << "Location: " << coll_location << endl;
			gotoxy(8, 8);
			cout << "Stream: " << coll_stream << endl;
			gotoxy(8, 9);
			cout << "Degree I: " << coll_degI << endl;
			gotoxy(8, 10);
			cout << "Degree II: " << coll_degII << endl;
			break;
		}
	}
	iFile.close();
}

/*This is a function which displays the details of all the Students under the university
with all the detail such as student id,  student name,  student address,  student stream, student degree
etc.Thus the user can look and know the detail of student*/
void Student::dis_all_student()
{
	system("cls");
	int flag;
	ifstream iFile;
	gotoxy(25, 1);
	cout << "The Students List";
	gotoxy(25, 2);
	cout << "=====================";
	gotoxy(1, 3);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	gotoxy(1, 5);
	cout << "Student's ID: ";
	gotoxy(10, 5);
	cout << "Student's First NAME: ";
	gotoxy(26, 5);
	cout << "Student's Last NAME: ";
	gotoxy(43, 5);
	cout << "Address: ";
	gotoxy(62, 5);
	cout << "Stream: ";
	gotoxy(72, 5);
	cout << "DEGREE: ";
	gotoxy(1, 6);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	iFile.open("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int row = 7;
	while (iFile.read((char *)this, sizeof(College)))
	{
		flag = 0;
		Sleep(2);
		gotoxy(1, row);
		cout << stu_id << endl;
		gotoxy(10, row);
		cout << first_name << endl;
		gotoxy(26, row);
		cout << last_name << endl;
		gotoxy(43, row);
		cout << stu_address << endl;
		gotoxy(63, row);
		cout << stu_stream << endl;
		gotoxy(73, row);
		cout << stu_degree << endl;
		row++;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(4, 24);
			cout << "Press Any Key To Continue";
			std::cin.get();
			system("cls");
		}
	}
	gotoxy(1, row);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	row++;
	iFile.close();
	if (!flag)
	{
		gotoxy(4, 24);
		cout << "PRESS ANY KEY TO CONTINUE:";
		std::cin.get();
	}
}

/*This function is used to enquire about the Student.This function ask for the student id
to enquire about and after matching the id it displays the record of the enquired student */
void Student::student_enquiry()
{
	system("cls");
	ifstream iFile;
	int t_stuid;
	gotoxy(71, 1);
	cout << "Press \"0\" To Exit";
	gotoxy(5, 5);
	cout << "Enter Student's ID: ";
	cin >> t_stuid;
	if (t_stuid == 0) return;
	if (!found_student(t_stuid))
	{
		gotoxy(5, 5);
		cout << "INVALID ID";
		cin.get();
		return;
	}
	box_for_enquiryStudent(t_stuid);
	int row = 9, flag;
	iFile.open("STUDENT.dat", ios::binary);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (stu_id == t_stuid)
		{
			Sleep(2);
			gotoxy(4, row);
			puts(stu_state);
			gotoxy(14, row);
			puts(stu_zip);
			gotoxy(25, row);
			puts(stu_code);
			gotoxy(38, row);
			puts(stu_contact);
			gotoxy(57, row);
			puts(stu_stream);
			gotoxy(70, row);
			puts(stu_degree);
			row++;
			if (row > 23)
			{
				flag = 1;
				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE:";
				cin.get();
				box_for_enquiryStudent(t_stuid);
			}
		}
	}
	iFile.close();
	if (!flag)
	{
		gotoxy(4, 24);
		cout << "PRESS ANY KEY TO CONTINUE:";
		cin.get();
	}
	
}

void Student::dis_by_id(int t_stu_id)
{
	ifstream iFile;
	iFile.open("STUDENT.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(College)))
	{
		if (t_stu_id == stu_id)
		{
			gotoxy(8, 5);
			cout << "College's ID: " << stu_id << endl;
			gotoxy(8, 6);
			cout << "Student's First Name: " << first_name << endl;
			gotoxy(8, 7);
			cout << "Student's Last Name: " << last_name << endl;
			gotoxy(8, 8);
			cout << "Student's Address: " << stu_address << endl;
			gotoxy(8, 9);
			cout << "Stream: " << stu_stream << endl;
			gotoxy(8, 10);
			cout << "Degree: " << stu_degree << endl;
			break;
		}
	}
	iFile.close();
}

/*This is a special function related to form it reads the student information
from "STUDENT.dat" and put it on the screen of Exam form entry screen after
matching the id of the student*/
void Student::exam_display(int t_stu_id, int t_exam_form_id)
{
	char t_first_name[30], t_last_name[30], t_stu_address[30], t_stu_stream[30], t_stu_degree[30];
	char ch;
	ifstream iFile;
	iFile.open("STUDENT.dat", ios::binary);
	ExamInfo exam;
	iFile.seekg(0, ios::beg);
	while (iFile.read((char *)this, sizeof(Student)))
	{
		if (stu_id == t_stu_id)
		{
			gotoxy(16, 9);
			cout << first_name;
			strcpy(t_first_name, first_name);

			gotoxy(24, 10);
			cout << last_name;
			strcpy(t_last_name, last_name);

			gotoxy(19, 11);
			cout << stu_address;
			strcpy(t_stu_address, stu_address);

			gotoxy(18, 12);
			cout << stu_stream;
			strcpy(t_stu_stream, stu_stream);

			gotoxy(18, 13);
			cout << stu_degree;
			strcpy(t_stu_degree, stu_degree);
		}
	}
	iFile.close();
	do
	{
		exam.clear(5, 23);
		gotoxy(5, 23);
		cout << "DO YOU WANT TO SAVE THE RECORD (Y/N):-";
		ch = getche();
		if (ch == 0)
			return;
		ch = toupper(ch);
	} while (ch != 'N' && ch != 'Y');
	if (ch == 'N')
		return;
	else
	{
		exam.add_to_file_form(t_stu_id, t_exam_form_id, t_first_name, t_last_name, t_stu_address, t_stu_stream, t_stu_degree);
	}
}

void Student::result_display(int t_stuid)
{
	{

		fstream file;
		ExamInfo einfo;
		char tstu_name[30], tstu_fname[30], tstu_add[30], tstu_strm[30], tstu_deg[30];
		int thp1, thp2, thp3, thp4, thp5, thp6, thp7, thp8, ts1, ts2, tcom, tgk;
		int tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8, tp9, tp10, tp11, tp12, tp13, tp14, tp15, tp16;
		file.open("STUDENT.dat", ios::binary | ios::in);
		file.seekg(0, ios::beg);
		//displays the record content  matching with t_stuid from STUDENT.dat data files.
		while (file.read((char *)this, sizeof(Student)))
		{
			if (t_stuid == stu_id)
			{
				gotoxy(16, 8);
				puts(first_name);
				strcpy(tstu_name, first_name);
				gotoxy(18, 10);
				puts(stu_stream);
				strcpy(tstu_strm, stu_stream);
				gotoxy(18, 12);
				puts(stu_degree);
				strcpy(tstu_deg, stu_degree);
			}
		}
		file.close();
		file.open("STUDENT.dat", ios::binary | ios::in);
		file.seekg(0, ios::beg);
		while (file.read((char *)this, sizeof(Student)))
		{
			strcpy(tstu_deg, stu_degree);
			if (stu_id == t_stuid)
			{
				if ((strcmp(stu_degree, "B.A-I") == 0) || (strcmp(stu_degree, "B.SC-I") == 0) || (strcmp(stu_degree, "B.COM-I") == 0))
				{
					gotoxy(5, 14);
					cout << "HONOURS PAPER :";
					cin >> thp1;
					gotoxy(5, 16);
					cout << "HONOURS :";
					cin >> thp2;
					gotoxy(5, 18);
					cout << "SUBSIDIARY I:";
					cin >> ts1;
					gotoxy(5, 19);
					cout << "SUBSSIDIARY II:";
					cin >> ts2;
					gotoxy(5, 20);
					cout << "COMPULSORY";
					cin >> tcom;
				}
				else if ((strcmp(stu_degree, "B.A-II") == 0) || (strcmp(stu_degree, "B.SC-II") == 0) || (strcmp(stu_degree, "B.COM-II") == 0))
				{
					gotoxy(5, 14);
					cout << "HONOURS PAPER :";
					cin >> thp3;
					gotoxy(5, 16);
					cout << "HONOURS :";
					cin >> thp4;
					gotoxy(5, 18);
					cout << "SUBSIDIARY I:";
					cin >> ts1;
					gotoxy(5, 19);
					cout << "SUBSSIDIARY II:";
					cin >> ts2;
					gotoxy(5, 20);
					cout << "COMPULSORY";
					cin >> tcom;
				}
				else if ((strcmp(stu_degree, "B.A-III") == 0) || (strcmp(stu_degree, "B.SC-III") == 0) || (strcmp(stu_degree, "B.COM-III") == 0))
				{
					gotoxy(5, 14);
					cout << "HONOURS PAPER :";
					cin >> thp5;
					gotoxy(5, 16);
					cout << "HONOURS PAPER:";
					cin >> thp6;
					gotoxy(5, 18);
					cout << "HONUURS PAPER";
					cin >> thp7;
					gotoxy(5, 19);
					cout << "HONOURS PAPER IV:";
					cin >> thp8;
					gotoxy(5, 20);
					cout << "GENERAL KNOWLEDGE";
					cin >> tgk;
				}
				else if ((strcmp(stu_degree, "M.A-I") == 0) || (strcmp(stu_degree, "M.SC-I") == 0) || (strcmp(stu_degree, "M.COM-I") == 0))
				{
					gotoxy(5, 14);
					cout << "PAPER I:-";
					cin >> tp1;
					gotoxy(5, 15);
					cout << "PAPER II:-";
					cin >> tp2;
					gotoxy(5, 16);
					cout << "PAPER III:-";
					cin >> tp3;
					gotoxy(5, 17);
					cout << "PAPER IV:-";
					cin >> tp4;
					gotoxy(5, 18);
					cout << "PAPER V:-";
					cin >> tp5;
					gotoxy(5, 19);
					cout << "PAPER VI:-";
					cin >> tp6;
					gotoxy(5, 20);
					cout << "PAPER VII:-";
					cin >> tp7;
					gotoxy(5, 21);
					cout << "PAPER VIII:-";
					cin >> tp8;
				}
				else if ((strcmp(stu_degree, "M.A-II") == 0) || (strcmp(stu_degree, "M.SC-II") == 0) || (strcmp(stu_degree, "M.COM-II") == 0))
				{
					gotoxy(5, 14);
					cout << "PAPER IX:-";
					cin >> tp9;
					gotoxy(5, 15);
					cout << "PAPER X:-";
					cin >> tp10;
					gotoxy(5, 16);
					cout << "PAPER XI:-";
					cin >> tp11;
					gotoxy(5, 17);
					cout << "PAPER XII:-";
					cin >> tp12;
					gotoxy(5, 18);
					cout << "PAPER XIII:-";
					cin >> tp13;
					gotoxy(5, 19);
					cout << "PAPER XIV:-";
					cin >> tp14;
					gotoxy(5, 20);
					cout << "PAPER XV:-";
					cin >> tp15;
					gotoxy(5, 21);
					cout << "PAPER XVI:-";
					cin >> tp16;
				}
			}
		}
		char ch;
		do
		{
			clear(5, 23);
			gotoxy(5, 23);
			cout << "DO YOU WANT TO SAVE THE RECORD (Y/N):-";
			ch = getche();
			if (ch == 0)
				return;
			ch = toupper(ch);
		} while (ch != 'N' && ch != 'Y');
		if (ch == 'N')
			return;
		if (ch == 'Y')
		{
			if ((strcmp(tstu_deg, "B.A-I") == 0) || (strcmp(tstu_deg, "B.SC-I") == 0) || (strcmp(tstu_deg, "B.COM-I") == 0))
			{
				einfo.add_to_filebaI(t_stuid, tstu_name, tstu_deg, thp1, thp2, ts1, ts2, tcom);
			}
			else if ((strcmp(tstu_deg, "B.A-II") == 0) || (strcmp(tstu_deg, "B.SC-II") == 0) || (strcmp(tstu_deg, "B.COM-II") == 0))
			{
				einfo.add_to_filebaII(t_stuid, tstu_name, tstu_deg, thp3, thp4, ts1, ts2, tcom);
			}
			else if ((strcmp(tstu_deg, "B.A-III") == 0) || (strcmp(tstu_deg, "B.SC-III") == 0) || (strcmp(tstu_deg, "B.COM-III") == 0))
			{
				einfo.add_to_filebaIII(t_stuid, tstu_name, tstu_deg, thp5, thp6, thp7, thp8, tgk);
			}
			else if ((strcmp(tstu_deg, "M.A-I") == 0) || (strcmp(tstu_deg, "M.SC-I") == 0) || (strcmp(tstu_deg, "M.COM-I") == 0))
			{
				einfo.add_to_filemaI(t_stuid, tstu_name, tstu_deg, tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8);
			}
			else if ((strcmp(tstu_deg, "M.A-II") == 0) || (strcmp(tstu_deg, "M.SC-II") == 0) || (strcmp(tstu_deg, "M.COM-II") == 0))
			{
				einfo.add_to_filemaII(t_stuid, tstu_name, tstu_deg, tp9, tp10, tp11, tp12, tp13, tp14, tp15, tp16);
			}
		}
	}
}

/*This is a special function because this function displays all the forms that
are being entred and finally displays on the screen*/
void ExamInfo::display_forms()
{
	system("cls");
	ifstream iFile;
	Student student;
	int flag, t_stu_id;
	gotoxy(25, 1);
	cout << "EXAM FORM LIST";
	gotoxy(25, 2);
	cout << "========================";
	gotoxy(1, 3);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	gotoxy(2, 5);
	cout << "Enter Student ID:";
	cin >> t_stu_id;
	if (!student.found_student(t_stu_id))
	{
		gotoxy(5, 5);
		cout << "\7 STUDENT NOT FOUND";
		std::cin.get();
		return;
	}
	for (int i = 2; i < 79; i++)
	{
		gotoxy(i, 5);
		cout << " ";
	}

	gotoxy(1, 5);
	cout << "Form ID: ";
	gotoxy(10, 5);
	cout << "Student ID: ";
	gotoxy(18, 5);
	cout << "Student's First Name: ";
	gotoxy(32, 5);
	cout << "Student's Last Name: ";
	gotoxy(50, 5);
	cout << "Student's Address: ";
	gotoxy(68, 5);
	cout << "Student's Stream: ";
	gotoxy(75, 5);
	cout << "Student's Degree: ";

	gotoxy(1, 6);
	for (int j = 1; j <= 79; j++)
		cout << "=";

	iFile.open("FORM.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int row = 7;

	while (iFile.read((char *)this, sizeof(ExamInfo)))
	{

		if (t_stu_id == stu_id)
		{
			flag = 0;
			Sleep(2);
			gotoxy(1, row);
			cout << examform_id;
			gotoxy(10, row);
			cout << stu_id;
			gotoxy(18, row);
			puts(first_name);
			gotoxy(32, row);
			puts(last_name);
			gotoxy(50, row);
			puts(stu_address);
			gotoxy(68, row);
			puts(stu_stream);
			gotoxy(75, row);
			puts(stu_degree);
		}
		row++;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(4, 23);
			cout << "PRESS ANY KEY TO CONTINUE";
			std::cin.get();
			system("cls");
		}
	}
	iFile.close();
	gotoxy(1, row);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	row++;
	if (!flag)
	{
		gotoxy(5, 23);
		cout << "PRESS ANY KEY TO CONTINUE";
		std::cin.get();
	}
}

/*This is a important function the use to display the schedule of the exam
that are going to be conducted in the colleges*/
void ExamInfo::display_schedule()
{
	system("cls");
	int flag;
	ifstream iFile;
	gotoxy(25, 1);
	cout << "EXAM SCHEDULE DISPLAY LIST";
	gotoxy(25, 2);
	cout << "===========================";
	gotoxy(1, 3);
	for (int j = 1; j <= 76; j++)
		cout << "=";
	gotoxy(1, 5);
	cout << "Degree: ";
	gotoxy(10, 5);
	cout << "Start Date: ";
	gotoxy(20, 5);
	cout << "End Date: ";
	gotoxy(30, 5);
	cout << "Start Month: ";
	gotoxy(40, 5);
	cout << "End Month: ";
	gotoxy(50, 5);
	cout << "Start Year: ";
	gotoxy(60, 5);
	cout << "End Year: ";
	gotoxy(1, 6);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	iFile.open("SCHEDULE.dat", ios::binary);
	iFile.seekg(0, ios::beg);
	int row = 7;
	while (iFile.read((char *)this, sizeof(ExamInfo)))
	{

		flag = 0;
		Sleep(2);
		gotoxy(1, row);
		puts(deg);
		gotoxy(10, row);
		puts(sd1);
		gotoxy(20, row);
		puts(ed1);
		gotoxy(30, row);
		puts(sm1);
		gotoxy(40, row);
		puts(em1);
		gotoxy(50, row);
		puts(sy1);
		gotoxy(60, row);
		puts(ey1);
		row++;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(4, 23);
			cout << "PRESS ANY KEY TO CONTINUE";
			std::cin.get();
			system("cls");
		}
	}
	gotoxy(1, row);
	for (int j = 1; j <= 79; j++)
		cout << "=";
	row++;
	iFile.close();
	if (!flag)
	{
		gotoxy(5, 23);
		cout << "PRESS ANY KEY TO CONTINUE";
		std::cin.get();
	}
}

/*This is a important function it displays the result of the student according
to their degree for different different  result data files*/
void ExamInfo::result_display_list()
{
	system("cls");
	fstream file;
	Student stu;
	gotoxy(25, 1);
	cout << "EXAM RESULT DISPLAY LIST";
	gotoxy(25, 2);
	cout << "=============================";
	int t_stuid;
	gotoxy(5, 3);
	cout << "Enter Student ID";
	cin >> t_stuid;
	if (!stu.found_student(t_stuid))
	{
		gotoxy(5, 4);
		cout << "\7 invalid";
		std::cin.get();
		return;
	}

	auto time = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(time);
	gotoxy(62, 3);
	cout << "Date: " << std::ctime(&_time);
	char t_studeg[30];
	strcpy(t_studeg, stu.valid_degree(t_stuid));
	if ((strcmp(t_studeg, "B.A-I") == 0) || (strcmp(t_studeg, "B.SC-I") == 0) || (strcmp(t_studeg, "B.COM-I") == 0))
	{
		gotoxy(1, 4);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		gotoxy(1, 5);
		cout << "ID";
		gotoxy(3, 5);
		cout << "NAME";
		gotoxy(34, 5);
		cout << "DEGREE";
		gotoxy(48, 5);
		cout << "HONOURS";
		gotoxy(40, 6);
		cout << "PAPER I";
		gotoxy(50, 6);
		cout << "PAPER II";
		gotoxy(65, 5);
		cout << "SUBCIDIARY";
		gotoxy(60, 6);
		cout << "PAPER I";
		gotoxy(68, 6);
		cout << "PAPER II";
		gotoxy(76, 5);
		cout << "COMPULSORY";
		gotoxy(1, 7);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		file.open("RESULTF.dat", ios::in);
		file.seekg(0, ios::beg);
		int row = 8;
		while (file.read((char *)this, sizeof(ExamInfo)))
		{

			gotoxy(1, row);
			cout << stu_id;
			gotoxy(3, row);
			puts(first_name);
			gotoxy(34, row);
			puts(stu_degree);
			gotoxy(40, row);
			cout << hp1;
			gotoxy(50, row);
			cout << hp2;
			gotoxy(60, row);
			cout << s1;
			gotoxy(70, row);
			cout << s2;
			gotoxy(72, row);
			cout << com;
			row++;
			if (row > 23)
			{
				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE...";
				std::cin.get();
				system("cls");
			}
			gotoxy(1, row);
			for (int j = 1; j <= 79; j++)
				cout << "=";
		}
		file.close();
	}
	if ((strcmp(t_studeg, "B.A-II") == 0) || (strcmp(t_studeg, "B.SC-II") == 0) || (strcmp(t_studeg, "B.COM-II") == 0))
	{
		gotoxy(1, 4);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		gotoxy(1, 5);
		cout << "ID";
		gotoxy(3, 5);
		cout << "NAME";
		gotoxy(34, 5);
		cout << "DEGREE";
		gotoxy(48, 5);
		cout << "HONOURS";
		gotoxy(40, 6);
		cout << "PAPER III";
		gotoxy(50, 6);
		cout << "PAPER IV";
		gotoxy(65, 5);
		cout << "SUBCIDIARY";
		gotoxy(60, 6);
		cout << "PAPER I";
		gotoxy(68, 6);
		cout << "PAPER II";
		gotoxy(76, 5);
		cout << "COMPULSORY";
		gotoxy(1, 7);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		file.open("RESULTS.dat", ios::in);
		file.seekg(0, ios::beg);
		int row = 8;
		while (file.read((char *)this, sizeof(ExamInfo)))
		{
			gotoxy(1, row);
			cout << t_stuid;
			gotoxy(3, row);
			puts(first_name);
			gotoxy(34, row);
			puts(stu_degree);
			gotoxy(40, row);
			cout << hp3;
			gotoxy(50, row);
			cout << hp4;
			gotoxy(60, row);
			cout << s1;
			gotoxy(70, row);
			cout << s2;
			gotoxy(72, row);
			cout << com;
			row++;
			if (row > 23)
			{
				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE...";
				std::cin.get();
				system("cls");
			}
			gotoxy(1, row);
			for (int j = 1; j <= 79; j++)
				cout << "=";
		}
		file.close();
	}
	if ((strcmp(t_studeg, "B.A-III") == 0) || (strcmp(t_studeg, "B.SC-III") == 0) || (strcmp(t_studeg, "B.COM-III") == 0))
	{
		gotoxy(1, 4);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		gotoxy(1, 5);
		cout << "ID";
		gotoxy(3, 5);
		cout << "NAME";
		gotoxy(34, 5);
		cout << "DEGREE";
		gotoxy(53, 5);
		cout << "HONOURS";
		gotoxy(40, 6);
		cout << "PAPER V";
		gotoxy(50, 6);
		cout << "PAPER VI";
		gotoxy(60, 6);
		cout << "PAPER VII";
		gotoxy(70, 6);
		cout << "PAPER VIII";
		gotoxy(78, 5);
		cout << "G.K";
		gotoxy(1, 7);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		file.open("RESULTT.dat", ios::in);
		file.seekg(0, ios::beg);
		int row = 8;
		while (file.read((char *)this, sizeof(ExamInfo)))
		{
			gotoxy(1, row);
			cout << t_stuid;
			gotoxy(3, row);
			puts(first_name);
			gotoxy(34, row);
			puts(stu_degree);
			gotoxy(40, row);
			cout << hp5;
			gotoxy(50, row);
			cout << hp6;
			gotoxy(60, row);
			cout << hp7;
			gotoxy(70, row);
			cout << hp8;
			gotoxy(72, row);
			cout << gk;
			row++;
			if (row > 23)
			{
				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE...";
				std::cin.get();
				system("cls");
			}
			gotoxy(1, row);
			for (int j = 1; j <= 79; j++)
				cout << "=";
		}
		file.close();
	}
	if ((strcmp(t_studeg, "M.A-I") == 0) || (strcmp(t_studeg, "M.SC-I") == 0) || (strcmp(t_studeg, "M.COM-I") == 0))
	{
		gotoxy(1, 4);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		gotoxy(1, 5);
		cout << "ID";
		gotoxy(3, 5);
		cout << "NAME";
		gotoxy(34, 5);
		cout << "DEGREE";
		gotoxy(53, 5);
		cout << "MASTER DEGREE";
		gotoxy(40, 6);
		cout << "I";
		gotoxy(44, 6);
		cout << "II";
		gotoxy(48, 6);
		cout << "III";
		gotoxy(52, 6);
		cout << "IV";
		gotoxy(56, 6);
		cout << "V";
		gotoxy(60, 6);
		cout << "VI";
		gotoxy(64, 6);
		cout << "VII";
		gotoxy(68, 6);
		cout << "VIII";
		gotoxy(1, 7);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		file.open("RESULTMF.dat", ios::in);
		file.seekg(0, ios::beg);
		int row = 8;
		while (file.read((char *)this, sizeof(ExamInfo)))
		{
			gotoxy(1, row);
			cout << t_stuid;
			gotoxy(3, row);
			puts(first_name);
			gotoxy(34, row);
			puts(stu_degree);
			gotoxy(40, row);
			cout << p1;
			gotoxy(44, row);
			cout << p2;
			gotoxy(48, row);
			cout << p3;
			gotoxy(52, row);
			cout << p4;
			gotoxy(56, row);
			cout << p5;
			gotoxy(60, row);
			cout << p6;
			gotoxy(64, row);
			cout << p7;
			gotoxy(68, row);
			cout << p8;
			row++;
			if (row > 23)
			{

				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE...";
				std::cin.get();
				system("cls");
			}
			gotoxy(1, row);
			for (int j = 1; j <= 79; j++)
				cout << "=";
		}
		file.close();
	}
	if ((strcmp(t_studeg, "M.A-II") == 0) || (strcmp(t_studeg, "M.SC-II") == 0) || (strcmp(t_studeg, "M.COM-II") == 0))
	{
		gotoxy(1, 4);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		gotoxy(1, 5);
		cout << "ID";
		gotoxy(3, 5);
		cout << "NAME";
		gotoxy(34, 5);
		cout << "DEGREE";
		gotoxy(53, 5);
		cout << "MASTER DEGREE";
		gotoxy(40, 6);
		cout << "IX";
		gotoxy(44, 6);
		cout << "X";
		gotoxy(48, 6);
		cout << "XI";
		gotoxy(52, 6);
		cout << "XII";
		gotoxy(56, 6);
		cout << "XIII";
		gotoxy(60, 6);
		cout << "XIV";
		gotoxy(64, 6);
		cout << "XV";
		gotoxy(68, 6);
		cout << "XVI";
		gotoxy(1, 7);
		for (int j = 1; j <= 79; j++)
			cout << "=";
		file.open("RESULTMS.dat", ios::in);
		file.seekg(0, ios::beg);
		int row = 8;
		while (file.read((char *)this, sizeof(ExamInfo)))
		{
			gotoxy(1, row);
			cout << t_stuid;
			gotoxy(3, row);
			puts(first_name);
			gotoxy(34, row);
			puts(stu_degree);
			gotoxy(40, row);
			cout << p9;
			gotoxy(44, row);
			cout << p10;
			gotoxy(48, row);
			cout << p11;
			gotoxy(52, row);
			cout << p12;
			gotoxy(56, row);
			cout << p13;
			gotoxy(60, row);
			cout << p14;
			gotoxy(64, row);
			cout << p15;
			gotoxy(68, row);
			cout << p16;
			row++;
			if (row > 23)
			{
				row = 7;
				gotoxy(4, 24);
				cout << "PRESS ANY KEY TO CONTINUE...";
				std::cin.get();
				system("cls");
			}
			gotoxy(1, row);
			for (int j = 1; j <= 79; j++)
				cout << "=";
		}
		file.close();
	}
	std::cin.get();
}


// END OF FUNCTION for DISPLAY DATA FORM FILE //

// Functions For Clear //

/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void College::clear(int col, int row)
{
	for (int j = col; j <= 76; j++)
	{
		gotoxy(j, row);
		cout << "";
	}
}

void Student::clear(int col, int row)
{
	for (int j = col; j <= 79; j++)
	{
		gotoxy(j, row);
		cout << "";
	}
}

void ExamInfo::clear(int col, int row)
{
	for (int j = col; j <= 79; j++)
	{
		gotoxy(j, row);
		cout << "";
	}
}
// END OF Functions For Clear //

// Functions for Add the DATA to files //
// Add DATA TO College File //
void College::add_to_file(int t_collid, char t_name[30], char t_loc[30], char t_str[30], char t_degI[30], char t_degII[30])
{
	coll_id = t_collid;
	strcpy(coll_name, t_name);
	strcpy(coll_location, t_loc);
	strcpy(coll_stream, t_str);
	strcpy(coll_degI, t_degI);
	strcpy(coll_degII, t_degII);
	//cout << coll_stream;
	//Append new record into COLLEGE.dat data files.
	ofstream oFile;
	oFile.open("COLLEGE.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(College));
	oFile.close();
}

// Add DATA TO Student File //
void Student::add_to_file(int t_stu_id, char t__first_name[30], char t_last_name[30], char t_address[30], char t_city[30], char t_state[30], char t_zip[30], char t_contact[30], char t_code[30], char t_stream[30], char t_deg[30])
{
	stu_id = t_stu_id;
	strcpy(first_name, t__first_name);
	strcpy(last_name, t_last_name);
	strcpy(stu_address, t_address);
	strcpy(stu_city, t_city);
	strcpy(stu_state, t_state);
	strcpy(stu_zip, t_zip);
	strcpy(stu_contact, t_contact);
	strcpy(stu_code, t_code);
	strcpy(stu_stream, t_stream);
	strcpy(stu_degree, t_deg);
	ofstream oFile;
	oFile.open("STUDENT.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(Student));
	oFile.close();
}

// Add DATA TO Student File Form //
void ExamInfo::add_to_file_form(int t_stu_id, int t_examform_id, char t_first_name[30], char t_last_name[30], char t_address[30], char t_stream[30], char t_degree[30])
{
	stu_id = t_stu_id;
	examform_id = t_examform_id;
	strcpy(t_first_name, first_name);
	strcpy(t_last_name, last_name);
	strcpy(t_address, stu_address);
	strcpy(t_stream, stu_stream);
	strcpy(t_degree, stu_degree);
	ofstream oFile("Form.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}

// Add DATA TO Student File Schedule //
void ExamInfo::add_to_file_schedule(char t_degree[30], char t_sd1[30], char t_ed1[30], char t_sm1[30], char t_em1[30], char t_sy1[30], char t_ey1[30])
{
	strcpy(sd1, t_sd1);
	strcpy(ed1, t_ed1);
	strcpy(sm1, t_sm1);
	strcpy(em1, t_em1);
	strcpy(sy1, t_sy1);
	strcpy(ey1, t_ey1);
	strcpy(deg, t_degree);

	ofstream oFile;
	oFile.open("SCHEDULE.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}

void ExamInfo::add_to_filebaI(int t_stuid, char t_name[30], char t_deg[30], int t_hp1, int t_hp2, int t_s1, int t_s2, int t_com)
{
	ofstream oFile;
	stu_id = t_stuid;
	hp1 = t_hp1;
	hp2 = t_hp2;
	s1 = t_s1;
	s2 = t_s2;
	com = t_com;
	strcpy(first_name, t_name);
	strcpy(stu_degree, t_deg);

	oFile.open("RESULT_F.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}
//suporting function of result
void ExamInfo::add_to_filebaII(int t_stuid, char t_name[30], char t_deg[30], int t_hp3, int t_hp4, int t_s1, int t_s2, int t_com)
{
	ofstream oFile;
	stu_id = t_stuid;
	hp3 = t_hp3;
	hp4 = t_hp4;
	s1 = t_s1;
	s2 = t_s2;
	com = t_com;
	strcpy(first_name, t_name);
	strcpy(stu_degree, t_deg);

	oFile.open("RESULT_S.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}
//suporting function function of result
void ExamInfo::add_to_filebaIII(int t_stuid, char t_name[30], char t_deg[30], int t_hp5, int t_hp6, int t_hp7, int t_hp8, int t_gk)
{
	ofstream oFile;
	stu_id = t_stuid;
	hp5 = t_hp5;
	hp6 = t_hp6;
	hp7 = t_hp7;
	hp8 = t_hp8;
	gk = t_gk;
	strcpy(first_name, t_name);
	strcpy(stu_degree, t_deg);

	oFile.open("RESULT_T.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}
//suporting fuinction of result
void ExamInfo::add_to_filemaI(int t_stuid, char t_name[30], char t_deg[30], int t_p1, int t_p2, int t_p3, int t_p4, int t_p5, int t_p6, int t_p7, int t_p8)
{
	ofstream oFile;
	stu_id = t_stuid;
	p1 = t_p1;
	p2 = t_p2;
	p3 = t_p3;
	p4 = t_p4;
	p5 = t_p5;
	p6 = t_p6;
	p7 = t_p7;
	p8 = t_p8;
	strcpy(first_name, t_name);
	strcpy(stu_degree, t_deg);

	oFile.open("RESULT_MF.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}
//suporting function of result
void ExamInfo::add_to_filemaII(int t_stuid, char t_name[30], char t_deg[30], int t_p9, int t_p10, int t_p11, int t_p12, int t_p13, int t_p14, int t_p15, int t_p16)
{
	ofstream oFile;
	stu_id = t_stuid;
	p9 = t_p9;
	p10 = t_p10;
	p11 = t_p11;
	p12 = t_p12;
	p13 = t_p13;
	p14 = t_p14;
	p15 = t_p15;
	p16 = t_p16;
	strcpy(first_name, t_name);
	strcpy(stu_degree, t_deg);

	oFile.open("RESULT_MS.dat", ios::binary | ios::app);
	oFile.write((char *)this, sizeof(ExamInfo));
	oFile.close();
}
// END OF ADD FUNCTIONS DATA FILE //

void Performance::foundation()
{
	gotoxy(50, 2);
	cout << dye::aqua_on_bright_white("Loay Terek Mostafa");
}
int main()
{

	Main_menu m;
	m.control_menu();
	cin.get();
}