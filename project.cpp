#include <iostream>
#include <fstream>
#include <iomanip> //use for setw,endl function
#include <conio.h>
#include <windows.h>
using namespace std;
int count = 1;
//---- Bank Class ----
class Bank
{
public:
    int Acc_No;

    char cus_Name[50];
    float Acc_balance;
    void create_Acc();
    void show_Account();
    void Acc_modify();
    void Cus_Report();
};
// saving account class......................................................................
class Saving : public Bank
{
public:
    void Deposit_s(int x);
    void Withdraw_s(int x);
};

class current_account : public Bank
{
public:
    void Deposit_c(int x);
};

// loan class .................................................
class loan_account : public Bank
{
private:
    double interest_rate = 8;
    double total_amount, monthly_amount, total_interest;

public:
    double loan_amount, number_of_years;
    void total_loan()
    {
        cout << "\nEnter loan amount " << endl;
        cin >> loan_amount;
        cout << "Enter number of years" << endl;
        cin >> number_of_years;
        total_amount = (number_of_years * loan_amount) + (number_of_years * loan_amount * (interest_rate / 100.00));
        cout << "Final LOAN amount is " << total_amount << endl;
    }
    void monthly_amt()
    {
        monthly_amount = total_amount / (number_of_years * 12);
        cout << " EMI is " << monthly_amount << endl;
    }
    void total_intrest()
    {
        total_interest = total_amount - (number_of_years * loan_amount);
        cout << "Total interest is " << total_interest << endl;
    }
    void l_display()
    {
        cout << "\nYour principle ammount: " << loan_amount << endl;
        cout << "Banks Rate of interset per anum: " << interest_rate << endl;
        cout << "Number of years : " << number_of_years << endl;
    }
};

// admin class......................................................................................................
class admin
{
public:
    char adm_ID[10] = "admin";
    int pass_ID = 1234;
};

void Bank::create_Acc()
{
    cout << "Enter Account Number : ";
    cin >> Acc_No;
    cout << "\nEnter Account Holder Name : ";
    cin.ignore();
    cin.getline(cus_Name, 50);

    cout << "\nEnter Account Opening Balance :";
    cin >> Acc_balance;
}
void Bank::show_Account()
{
    cout << "\nAccount number : " << Acc_No;
    cout << "\nAccount Holder's name : " << cus_Name;

    cout << "\nBalance amount : " << Acc_balance;
}
void Saving::Deposit_s(int x)
{
    float interest;
    Acc_balance += x;
    interest = (Acc_balance * 2) / 100;
    Acc_balance += interest;
}
void current_account::Deposit_c(int x)
{
    Acc_balance += x;
}
void Saving::Withdraw_s(int x)
{
    Acc_balance -= x;
}
void Bank::Acc_modify()
{
    cout << "\nAccount number : " << Acc_No;
    cout << "\nModify account Holder's name : ";
    cin.ignore();
    cin.getline(cus_Name, 50);

    cout << "\nModify balance amount : ";
    cin >> Acc_balance;
}
void Bank::
    Cus_Report()
{
    cout << Acc_No << setw(15) << cus_Name << setw(16) << setw(15) << Acc_balance << endl;
}
//-------------------------------------------
void addBank_record();
void search_acc(int n);
void modify_Acc(int n);
void file_DepositeWithdraw(int n, int option);
void show_AllBank();
void delete_Acc(int n);
//-------------------------------------------
void transactions()
{
    int menu3choice, num;
    cout << "\nChoose your transaction type : \n[1].Deposit Amount \n[2].Withdraw Amount\n[3].Exit\n";
    cin >> menu3choice;
    cout << "\n\n\tEnter the account no. : ";
    cin >> num;
    file_DepositeWithdraw(num, menu3choice);
}
void choice_Bank()
{
    loan_account l;
    int num;
    char menu2choice;
    if (count == 1)
    {
        char arrshow[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', ' ', 'T', 'O', ' ', 'S', 'B', 'I'};
        cout << "\n\n\n\n\n\n\t\t\t";
        for (int i = 0; i < 15; i++)
        {
            cout << arrshow[i];
            Sleep(200);
        }
        system("CLS");
        count++;
    }
    cout << "\n[1].Open Saving Account\n[2].open Current account\n[3].Open Loan Account\n[4].Services\n[5].Account Settings\n[6].Account Information\n[8].Exit\n";
    cin >> menu2choice;
    switch (menu2choice)
    {
    case '1':
        addBank_record();
        break;
    case '2':
        addBank_record();
        break;
    case '3':
    NOW:
        addBank_record();
        l.total_loan();
        l.monthly_amt();
        l.total_intrest();

        break;
    case '4':
        transactions();
        break;
    case '5':
        int n;
        cout << "\nChoose your setting :  \n\t[1].Modify An Account \n\t[2].Delete Account";
        cin >> n;
        cout << "\n\n\tEnter the account no. : ";
        cin >> num;
        if (n == 1)
        {
            modify_Acc(num);
        }
        else if (n == 2)
        {
            delete_Acc(num);
        }
        else
        {
            break;
        }
        break;
    case '6':
        cout << "\n\n\tPlease login!! : ";
        cout << "\n\n\tEnter the account no. : ";
        cin >> num;
        search_acc(num);
        break;

    case '7':
        break;
    default:
        cout << "\nInvalid Input.........";
        break;
    }
}
int main()
{
    system("color A2");
    admin a;
    char arr[20];
    int p;
START:
    char menu1choise, choiceYN = 'Y';
    int n;
    std::cout << "##########__WELCOME TO SBI __###############\n";
    do
    {
        cout << "\n\nChoose Category :";
        cout << "\n[1].Enter as Custometer [2].Enter as Admin  [3].Exit  ";
        cin >> menu1choise;
        switch (menu1choise)
        {
        case '1':
            choice_Bank();
            break;
        case '2':
            cout << "enter admin user id :\n";
            cin >> arr;
            cout << "enter admin password :\n";
            cin >> p;
            int num;
            if ((p == a.pass_ID) && !(strcmp(arr, a.adm_ID)))
            {
                cout << "Press 1 to display details: " << endl;
                cout << "Press 2 to delete any account: " << endl;
                cin >> n;
                switch (n)
                {
                case 1:
                    show_AllBank();
                    break;
                case 2:
                    cout << "Enter account number u want to delete: " << endl;
                    cin >> num;
                    delete_Acc(num);
                    break;
                }
            }
            break;
        case '3':
            cout << "\n\n^^^^^^^^^^^^=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=^^^^^^^^^^^^\n";
            cout << "\t                   >>>>>>>>>>>>>__THANK YOU__<<<<<<<<<<<<<\n";

            return 0;
        default:
            cout << "\n Invalid Input.......";
            cout << "\n\n^^^^^^^^^^^^=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=^^^^^^^^^^^^\n";
            cout << "\t                   >>>>>>>>>>>>>__THANK YOU__<<<<<<<<<<<<<\n";

            return 0;
        }

        cout << "\n Do you want to do anything else ? ";
        cin >> choiceYN;
        if (choiceYN == 'y' || choiceYN == 'Y')
        {
            goto START;
        }
    } while (choiceYN == 'Y');
    cout << "\n\n^^^^^^^^^^^^=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=^^^^^^^^^^^^\n";
    cout << "\t                   >>>>>>>>>>>>>__THANK YOU__<<<<<<<<<<<<<\n";

    cout << " __________________________________________________________________________________________\n ";
    return 0;
}

//___________________ Bank - File Handling _________________________________________________________________
void addBank_record()
{
    Bank Bank;
    ofstream(outfile);
    outfile.open("Bank.dat", ios::app | ios::binary);
    Bank.create_Acc();
    outfile.write((char *)&Bank, sizeof(Bank));
}
void search_acc(int n)
{
    Bank Bank;
    bool flag = false;
    ifstream inFile;
    inFile.open("Bank.dat", ios::in | ios::binary);
    if (!inFile)
    {
        cout << "File could not be open. press any key...";
        return;
    }
    while (inFile.read((char *)&Bank, sizeof(Bank)))
    {
        if (Bank.Acc_No == n)
        {
            Bank.show_Account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount number not exist";
}
void modify_Acc(int n)
{
    bool found = false;
    Bank Bank;
    fstream File;
    File.open("Bank.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open. press any key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&Bank), sizeof(Bank));
        if (Bank.Acc_No == n)
        {
            Bank.show_Account();
            cout << "\n\nEnter new account details" << endl;
            Bank.Acc_modify();
            int pos = (-1) * static_cast<int>(sizeof(Bank));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&Bank), sizeof(Bank));
            cout << "\n\n\t Record updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record not found";
}
void file_DepositeWithdraw(int n, int option)
{
    Saving Bank;
    current_account Bank2;
    int amt;
    bool found = false;
    fstream File;
    File.open("Bank.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open, press any key...";
        return;
    }
    while ((char *)&Bank, sizeof(Bank) && found == false)
    {
        File.read(reinterpret_cast<char *>(&Bank), sizeof(Bank));
        if (Bank.Acc_No == n)
        {
            found = true;
            Bank.show_Account();
            if (option == 1)
            {
                cout << "\n\n\tTo deposit amount ";
                cout << "\n\nEnter the amount to deposit";
                cin >> amt;
                Bank.Deposit_s(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tWithdraw amount ";
                cout << "\n\nEnter amount to withdraw";
                cin >> amt;
                float bal = Bank.Acc_balance - amt;
                if (bal < 1000)
                    cout << "Insufficient balance";
                else
                    Bank.Withdraw_s(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(Bank));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&Bank), sizeof(Bank));
            cout << "\n\n\tRecord updated";
        }
    }
    File.close();
    if (found == false)
        cout << "\n\nRecord not found";
}
void show_AllBank()
{
    Saving Bank;
    ifstream(infile);
    infile.open("Bank.dat", ios::in | ios::binary);
    if (!infile)
    {
        cout << "File could not Found";
        return;
    }
    cout << "\n\n\t\tACCOUNT LIST\n\n";
    cout << "==========================================================\n";
    cout << "Acc no.      NAME         Account Balance\n";
    cout << "==========================================================\n";
    while (infile.read((char *)&Bank, sizeof(Bank)))
    {
        Bank.Cus_Report();
    }
    infile.close();
}
void delete_Acc(int n)
{
    Saving Bank;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Bank.dat", ios::in | ios::binary);
    if (!inFile)
    {
        cout << "File could not be open. press any key...";
        return;
    }
    outFile.open("Temp.dat", ios::out | ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read((char *)&Bank, sizeof(Bank)))
        ;
    {
        if (Bank.Acc_No != n)
        {
            outFile.write((char *)&Bank, sizeof(Bank));
        }
    }
    inFile.close();
    outFile.close();
    remove("Bank.dat");
    rename("Temp.dat", "Bank.dat");
    cout << "\n\n\tRecord deleted..";
}