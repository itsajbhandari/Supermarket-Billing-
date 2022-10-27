#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t   supermarket main Menu      \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t______________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t    1). Administrator         \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t    2). Buyer                 \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t    3). Exit                  \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t Please Select Above Options  \n";
    cout << "\t\t\t\t                              \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\t\t Please Login \n";
        cout << "\t\t\t\t Enter Your Email  \n";
        cin >> email;
        cout << "\t\t\t\t Enter Your Password  \n";
        cin >> password;
        if (email == "ajay@gmail.com" && "password == ajay@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email Password   \n";
        }

        break;
    }

    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from givem Option\n";
    }
    }
    goto m;
};
void shopping ::administrator()
{
m:
    int choice;
    cout << "                                     \n";
    cout << "\t\t\t\t\t\t Administrator Menu         \n";
    cout << "\t\t\t\t|____1). Add the Product_______|\n";
    cout << "\t\t\t\t|                              |\n";
    cout << "\t\t\t\t|____2). Modifiy the product___|\n";
    cout << "\t\t\t\t|                              |\n";
    cout << "\t\t\t\t|____3). Delete the Product____|\n";
    cout << "\t\t\t\t|                              |\n";
    cout << "\t\t\t\t|____4). Back to the Menu______|\n";

    cout << "Please Enter Your Choice  \n";
    cin >> choice;

    switch (choice)

    {

    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid Choice \n";
    }
    goto m;
};

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t  Buyers Menu            \n";
    cout << "\t\t\t\t_________________________\n";
    cout << "                                 \n";
    cout << "\t\t\t\t 1). Buy Product         \n";
    cout << "                                 \n";
    cout << "\t\t\t\t 2). Go back             \n";
    cout << "                                 \n";
    cout << "\t\t\t\t Kindly Entter Your choice:";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "Invalid Choice \n";
    }
    goto m;
};

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t Add new Product ";
    cout << "\n\n\t Code of the product ";
    cin >> pcode;
    cout << "\n\n\t Enter the name of the product ";
    cin >> pname;
    cout << "\n\n\t Enter the price of the product ";
    cin >> price;
    cout << "\n\n\t Enter discount on the product ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
        data.close();
    }
    else
    {

        data >> c >> n >> p >> d;

        while (!data.eof())
        {

            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record Inserted Successfuly";
};
void shopping::edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the Record ";
    cout << "\n\t\t\t Product Code ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {

        cout << "\n File Does'nt Exist ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios ::out);

        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {

                cout << "\n\t\t Product new code";
                cin >> c;
                cout << "\n\t\t Name of the product ";
                cin >> n;
                cout << "\n\t\t Price ";
                cin >> p;
                cout << "\n\t\t Discount ";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record Edit Successfully ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record Not Found Sorry";
        }
    }
};

void shopping ::rem()
{

    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\n\n\t Delete Product";

    cout << "\n\n\t Enter Product Code ";
    cin >> pkey;
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "File does'nt exist";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {

            if (pcode == pkey)

            {

                cout << "\n\n\t Product Delete Successfuly";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << ("\n\n Record not found");
        }
    }
};

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << ("\n\n|________________________________|\n");
    cout << ("ProNo\t\tName\t\tPrice\n");
    cout << ("\n     ");
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
};

void shopping ::receipt()
{

    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << " \n\n\t\t\t\t RECIEPT";
    data.open("database.txt", ios::in);
    if (!data)
    {

        cout << "\n\n Emplty Database";
    }

    else
    {

        data.close();

        list();
        cout << "\n ______________";
        cout << "\n Please place the order";
        cout << "\n ______________";

        do
        {
        m:
            cout << "\n\nEnter Product code :";
            cin >> arrc[c];
            cout << "\n\nEnter Quantity :";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {

                if (arrc[c] == arrc[i])
                {

                    cout << "\n\n  Duplicate Product code please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to add another product? if yes then press y else n \n";
            cin >> choice;

        } while (choice == 'y');
        cout << "\n\n\t\t\t_______________________Reciept__________________________________\n";
        cout << "\nP Code.\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount with Discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {

                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n __________________\n";
    cout << "Total Amount : " << total;
}
int main()
{

    shopping s;
    s.menu();
}