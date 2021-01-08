//#include"pch.h" //precompiled header
#include<stdlib.h> //standard library 
#include<stdio.h> //standard input output
#include<windows.h> //for SLEEP function
#include<conio.h> //for getch() function
#include<string.h> //manipulate string variable
#pragma warning (disable:4996) //to avoid error when using scanf

void adminmenu(); //menu for admin
void staffmenu(); //menu for staff
void newstaff(); //create new staff profile
void newmember(); //create new member
void modify(); //edit profile
void deletefile(); //delete profile
void view(); //view member profile
void memberview(); //for member view their profile
void search(); //search profile

int main()
{
	char useroption;
	do {
		system("cls"); //clear window/new screen
		printf("*****Welcome to Toy Depot Billing System******\n");
		printf("Please select user type:");
		printf("\n\n1.Administrator\n2.Staff\n3.Member\n4.Exit\n");
		scanf("%c", &useroption);
		switch (useroption)
		{
		case '1': {
			char adminame[10], adminpass[10];
			while (TRUE)
			{
				printf("\nLogin admin username and password>>>>>\n\n");
				printf("Username:");
				scanf("%s", &adminame);
				printf("Password:");
				scanf("%s", &adminpass);
				if (strcmp(adminame, "admin") == 0 && strcmp(adminpass, "123") == 0) //compare admin user name and password
				{
					printf("Correct username and password.\n");
					Sleep(1000); //delay for 1 second
					adminmenu(); //calling function to adminmenu
				}
				else
				{
					printf("\nInvalid username or password!\n"); //validation when incorrect name or password
					Sleep(500);
					system("cls");
					printf("Please try again\n");
					continue; //continue until getting correct name or password
				}
			}
			break;
		}

		case '2':
		{
			char staffname[10], staffpass[10]; //string contain 10 characters
			while (TRUE)
			{
				printf("\nLogin staff username and password>>>>>\n\n");
				printf("Username:");
				scanf("%s", &staffname);
				printf("Password:");
				scanf("%s", &staffpass);
				if (strcmp(staffname, "staff") == 0 && strcmp(staffpass, "234") == 0)
				{
					printf("Correct username and password.\n");
					Sleep(1000);
					system("cls");
					staffmenu(); //direct to function staffmenu
				}
				else
				{
					printf("\nInvalid username or password!\n");
					Sleep(500);
					system("cls");
					printf("Please try again\n");
					continue;
				}
			}
			break;
		}
		case '3':
			system("cls");
			memberview(); //direct to function memberview
			break;
		case '4':
			exit(1); //exit system
			break;
		}
	} while (useroption != '1' && useroption != '2' && useroption != '3' && useroption != '4');
	printf("Invalid input\n");
	Sleep(1000);
}

void adminmenu()
{
	system("cls");
	char adminchoice1;
	int adminchoice2;
	printf("Welcome, admin!\n\nWhat would like to do?\n\n");
	printf("1.Create new user\n");
	printf("2.Modify profile\n");
	printf("3.Delete profile\n");
	printf("4.View member profile\n");
	printf("5.Search member profile\n");
	printf("6.Main menu\n");
	scanf(" %c", &adminchoice1); //getting character from input and store in adminchoice1 variable
	if (adminchoice1 == '1')
	{
	selection1:
		printf("New staff or member?\n 1.Staff\n 2.Member\n");
		scanf("%d", &adminchoice2);
		if (adminchoice2 == 1)
		{
			newstaff();
		}
		else if (adminchoice2 == 2)
		{
			newmember();
		}
		else
		{
			printf("Invalid input"); //validation
			goto selection1; //go to line 119
		}
	}
	else if (adminchoice1 == '2')
		modify();
	else if (adminchoice1 == '3')
		deletefile();
	else if (adminchoice1 == '4')
		view();
	else if (adminchoice1 == '5')
		search();
	else if (adminchoice1 == '6')
		main();
	else
	{
		printf("Invalid input\n");
		adminmenu();
	}
}

void staffmenu()
{
	int staffchoice;
	system("cls");
	printf("Welcome, staff!\n");
	printf("What would you like to do?\n1.Create new member profile\n2.View member profile\n3.Search member profile\n");
	scanf("%d", &staffchoice);
	if (staffchoice == 1)
		newmember();
	else if (staffchoice == 2)
		view();
	else if (staffchoice == 3)
		search();
	else
	{
		printf("Invalid input.\n"); //validation
		staffmenu();
	}
}

void newstaff()
{
	FILE* stafflist; //file pointer named stafflist
	stafflist = fopen("Stafflist.txt", "a+"); //open text file named Stafflist for append data
	char staffname[15];
	char staffid[10];
	char staffphonenum[15];
	char staffemail[15];
	printf("Name:");
	scanf("%s", staffname);
	printf("Staff ID:");
	scanf("%s", staffid);
	printf("Phone number:");
	scanf("%s", staffphonenum);
	printf("Email address:");
	scanf("%s", staffemail);
	fprintf(stafflist, "Name:%s\tStaff ID:%s\tPhone number:%s\tEmail adress:%s\n", staffname, staffid, staffphonenum, staffemail); //print data into file
	fclose(stafflist); //close file
	printf("The profile has been created successfully.\nPress any key to continue>>>\n");
	getch(); //get a character before jump to next line
	main();
}

void newmember()
{
	system("cls");
	FILE* memberlist;
	memberlist = fopen("Memberlist.txt", "a+");
	char name[15];
	int memberid;
	char phonenum[15];
	char address[30];
	char email[15];
	char toyid[15];
	char amount[15];
	char paydate[15];

	printf("Membership ID:");
	scanf("%d", &memberid);
	printf("Name:");
	scanf("%s", name);
	printf("Phone number:");
	scanf("%s", phonenum);
	printf("Billing address:");
	scanf("%s", address);
	printf("Email address:");
	scanf("%s", email);
	printf("Toy ID:");
	scanf("%s", toyid);
	printf("Amount paid:RM ");
	scanf("%s", amount);
	printf("Payment date:");
	scanf("%s", paydate);
	fprintf(memberlist, "Member ID: %d \tName:%s\tPhone number:%s\tBilling address:%s\tEmail adress:%s\tToy ID:%s\tAmount paid:RM %s\tPayment date:%s\n", memberid, name, phonenum, address, email, toyid, amount, paydate);
	fclose(memberlist);
	printf("The profile has been created successfully.\nPress any key to continue>>>\n");
	getch();
	main();
}

void modify()
{
	FILE* stafflist, * memberlist, * tempstafflist, * tempmemberlist; //file pointer declaration
	char staffname[15], staffid[10], staffphonenum[15], staffemail[15], ch, name[15], phonenum[15], address[30], email[15], toyid[15], amount[15], paydate[15];
	int choice3, modifyline, i = 1, memberid;
	printf("Which file do you wish to modify?\n1.Staff\n2.Member\n");
	scanf("%d", &choice3);
	system("cls");
	if (choice3 == 1)
	{
		stafflist = fopen("Stafflist.txt", "r+"); //open Stafflist file for reading
		if (stafflist == 0)
		{
			printf("File not found!"); //print when file doesn't exist
			exit(1); //end program
		}

		ch = getc(stafflist); //get a single char from Stafflist
		while (ch != EOF) //while loop for printing the whole file
		{
			printf("%c", ch);
			ch = getc(stafflist);
		}

		rewind(stafflist); //set the pointer to the initial of the file
		printf("\nEnter line number that you wish to modify:");
		scanf("%d", &modifyline);
		tempstafflist = fopen("Tempstafflist.txt", "w"); //open a temporary for stafflist for writing
		while ((ch = getc(stafflist)) != EOF)
		{
			if (i != modifyline)
			{
				putc(ch, tempstafflist); //get every char from stafflist to tempstafflist when it is not the modifyline
			}
			if (ch == '\n') //when get to end of line, i will iterate and jump to the next line
			{
				i++;
			}
		}

		printf("Name:");
		scanf("%s", staffname);
		printf("Staff ID:");
		scanf("%s", staffid);
		printf("Phone number:");
		scanf("%s", staffphonenum);
		printf("Email address:");
		scanf("%s", staffemail);
		fprintf(tempstafflist, "Name:%s\tStaff ID:%s\tPhone number:%s\tEmail address:%s\n", staffname, staffid, staffphonenum, staffemail);
		fclose(stafflist);
		fclose(tempstafflist);
		remove("Stafflist.txt");
		rename("Tempstafflist.txt", "Stafflist.txt");
		printf("\nThe profile has been successfully modified and below is the new update...\n\n");
		stafflist = fopen("Stafflist.txt", "r");
		ch = getc(stafflist);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(stafflist);
		}
		fclose(stafflist);
		Sleep(5000);
	}

	else if (choice3 == 2)
	{
		memberlist = fopen("Memberlist.txt", "r+");
		if (memberlist == 0)
		{
			printf("File not found!");
			exit(1);
		}

		ch = getc(memberlist);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(memberlist);
		}

		rewind(memberlist);
		printf("\nEnter line number that you wish to modify:");
		scanf("%d", &modifyline);
		tempmemberlist = fopen("Tempmemberlist.txt", "w");
		while ((ch = getc(memberlist)) != EOF)
		{
			if (i != modifyline)
			{
				putc(ch, tempmemberlist);
			}
			if (ch == '\n')
			{
				i++;
			}
		}

		printf("Membership ID:");
		scanf("%d", &memberid);
		printf("Name:");
		scanf("%s", name);
		printf("Phone number:");
		scanf("%s", phonenum);
		printf("Billing address:");
		scanf("%s", address);
		printf("Email address:");
		scanf("%s", email);
		printf("Toy ID:");
		scanf("%s", toyid);
		printf("Amount paid:RM ");
		scanf("%s", amount);
		printf("Payment date:");
		scanf("%s", paydate);
		fprintf(tempmemberlist, "Member ID: %d \tName:%s\tPhone number:%s\tBilling address:%s\tEmail adress:%s\tToy ID:%s\tAmount paid:RM %s\tPayment date:%s\n", memberid, name, phonenum, address, email, toyid, amount, paydate);
		fclose(memberlist);
		fclose(tempmemberlist);
		remove("Memberlist.txt");
		rename("Tempmemberlist.txt", "Memberlist.txt");
		printf("\nThe profile has been successfully modified and below is the new update...\n\n");
		memberlist = fopen("Memberlist.txt", "r");
		ch = getc(memberlist);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(memberlist);
		}
		fclose(memberlist);
		Sleep(5000);
	}

	else
	{
		printf("Invalid input!\n");
		modify();
	}
	printf("\n\n\nPress any key to return menu...");
	getch();
	adminmenu();
	getch();
}

void deletefile() //same with modify function but the difference is it doesn't need to input new data
{
	FILE* stafflist, * memberlist, * tempstafflist, * tempmemberlist;
	char ch;
	int choice4, deleteline, i = 1;
	printf("Which profile do you wish to delete?\n1.Staff\n2.Member\n");
	scanf("%d", &choice4);
	if (choice4 == 1)
	{
		stafflist = fopen("Stafflist.txt", "r");
		if (stafflist == 0)
		{
			printf("File not found!");
			exit(1);
		}
		ch = getc(stafflist);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(stafflist);
		}

		rewind(stafflist);
		printf("\nEnter line number that you wish to delete:");
		scanf("%d", &deleteline);
		tempstafflist = fopen("Tempstafflist.txt", "w");
		while ((ch = getc(stafflist)) != EOF)
		{
			if (i != deleteline)
			{
				putc(ch, tempstafflist);
			}
			if (ch == '\n')
			{
				i++;
			}
		}
		fclose(stafflist);
		fclose(tempstafflist);
		remove("Stafflist.txt");
		rename("Tempstafflist.txt", "Stafflist.txt");
		printf("\nThe profile has been successfully deleted and below is the new update...\n\n");
		stafflist = fopen("Stafflist.txt", "r");
		while ((ch = getc(stafflist)) != EOF)
		{
			printf("%c", ch);
		}
		fclose(stafflist);
		Sleep(5000);
	}

	else if (choice4 == 2)
	{
		memberlist = fopen("Memberlist.txt", "r");
		if (memberlist == 0)
		{
			printf("File not found!");
			exit(1);
		}
		ch = getc(memberlist);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = getc(memberlist);
		}

		rewind(memberlist);
		printf("\nEnter line number that you wish to delete:");
		scanf("%d", &deleteline);
		tempmemberlist = fopen("Tempmemberlist.txt", "w");
		while ((ch = getc(memberlist)) != EOF)
		{
			if (i != deleteline)
			{
				putc(ch, tempmemberlist);
			}
			if (ch == '\n')
			{
				i++;
			}
		}
		fclose(memberlist);
		fclose(tempmemberlist);
		remove("Memberlist.txt");
		rename("Tempmemberlist.txt", "Memberlist.txt");
		printf("\nThe profile has been successfully deleted and below is the new update...\n\n");
		memberlist = fopen("Memberlist.txt", "r");
		while ((ch = getc(memberlist)) != EOF)
		{
			printf("%c", ch);
		}
		fclose(memberlist);
		Sleep(5000);
	}

	else
	{
		printf("Invalid input!\n");
		deletefile();
	}
	printf("\n\n\nPress any key to return menu...");
	getch();
	adminmenu();
}

void view()
{
	system("cls");
	int choice5;
	char ch;
	FILE* memberlist;
	memberlist = fopen("Memberlist.txt", "r");
	if (memberlist == 0)
	{
		printf("File not found!");
		exit(1);
	}

	ch = getc(memberlist);
	while (ch != EOF)
	{
		printf("%c", ch);
		ch = getc(memberlist);
	}
	fclose(memberlist);
	printf("\n\n\nPress any key to return menu...\n");
	getch();
	main();
}

void memberview()
{
	FILE* memberlist;
	char line[200], cha;
	int i = 1, memberid, ID;
	memberlist = fopen("Memberlist.txt", "r+");
	if (memberlist == NULL)
	{
		printf("File not found!");
		exit(1);
	}
	printf("Enter Member ID:");
	scanf("%d", &ID);
	while (i != EOF)
	{
		fscanf(memberlist, "%s", line);
		memberid = atoi(line);
		if (memberid != ID)
		{
			continue;
		}
		if (memberid == ID)
		{
			printf("\nWelcome and Hello!");
			fgets(line, 200, (FILE*)memberlist);
			printf("\n\n**********************Search result**********************\n");
			printf("\nMember ID= %d %s", memberid, line);
			break;
		}
		i++;
	}
	printf("\nPress any key to return menu...\n");
	getch();
	printf("\nThank you for using Toy Depot Billing System!");
	main();
}

void search()
{
	FILE* memberlist;
	char line[200], cha;
	int i = 1, memberid, ID;
	memberlist = fopen("Memberlist.txt", "r+");
	if (memberlist == NULL)
	{
		printf("File not found!");
		exit(1);
	}
	cha = getc(memberlist);
	while (cha != EOF)
	{
		printf("%c", cha);
		cha = getc(memberlist);
	}
	rewind(memberlist);
memberview:
	printf("\n\nEnter Member ID:");
	scanf("%d", &ID);
	while (i != EOF)
	{
		fscanf(memberlist, "%s", line);
		memberid = atoi(line); //convert string line into integer and store in memberid
		if (memberid != ID)
		{
			continue;
		}
		else
		{
			fgets(line, 200, (FILE*)memberlist);
			printf("\n\n**********************Search result**********************\n");
			printf("\nMember ID= %d %s", memberid, line); //print the memberid and the whole line
			break;
		}
		i++;
	}
	printf("\nPress any key to return menu...\n");
	getch();
	main();
}