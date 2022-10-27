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
    void remove();
    void list();
    void reciept();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t________________________\n";
    cout << "\t\t\t\t                        \n";
    cout << "|       supermarket main Menu  |\n";
    cout << "\t\t\t\t                        \n";
    cout << "\t\t\t\t________________________\n";
    cout << "\t\t\t\t                        \n";
    cout << "     1). Administrator          \n";
    cout << "\t\t\t\t                        \n";
    cout << "    2). Buyer                   \n";
    cout << "\t\t\t\t                        \n";
    cout << "    2). Exit                    \n";
    cout << "\t\t\t\t                        \n";
    cout << "   Please Select Above Options  \n";
    cout << "\t\t\t\t                        \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Please Login \n";
        cout << "Enter Your Email  \n";
        cin >> email;
        cout << "Enter Your Password  \n";
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
}
void shopping ::administrator()
{
m:
    int choice;
    cout << "\t\t\t\t                         \n";
    cout << "|       Administrator Menu      |\n";
    cout << "\t\t\t\t                         \n";
    cout << "\t\t\t\t                         \n";
    cout << "      1). Add the Product        \n";
    cout << "\t\t\t\t                         \n";
    cout << "      2). Modifiy the product    \n";
    cout << "\t\t\t\t                         \n";
    cout << "      3). Delete the Product     \n";
    cout << "\t\t\t\t                         \n";
    cout << "      4).  Back to the Menu      \n";
    cout << "\t\t\t\t                         \n";

    cout << "Please Enter Your Choice         \n";
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
        rename();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid Choice \n";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t                         \n";
    cout << "|       Buyers Menu              |\n";
    cout << "\t\t\t\t                         \n";
    cout << "\t\t\t\t                         \n";
    cout << "      1). Buy Product            \n";
    cout << "\t\t\t\t                         \n";
    cout << "      2). Go back                \n";
    cout << "\t\t\t\t                         \n";
    cout << "     Kindly Entter Your choice   \n";
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
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    count << "\n Add new Product ";
    count << "\n Code of the product ";
    cin >> pcode;
    count << "\n Enter the name of the product ";
    cin >> pname;
    count << "\n Enter the price of the product ";
    cin >> price;
    count << "\n Enter discount on the product ";
    cin >> dis;

    data.open("database.txt", ios::in)

        if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {

        data >> c << n << p << d;

        while (!data.eof())
        {

            if (c == pcode)
            {
                token++;
            }
            data >> c << n << p << d;
        }
        data.close();

        if (token == 1)
            goto m : else
            {
                data.open("database.txt", ios::app | ios::out);
                data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                data.close();
            }
    }
    cout << "\n\n\n Record Inserted Successfuly";
}
void shopping::edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    count << "\n Modify the Record ";
    count << "\n Product Code ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {

        count << "\n File Does'nt Exist ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios ::out);

        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {

                Cout << "\nProduct new code";
                Cin >> c;
                Cout << "\n Name of the product ";
                Cin >> n;
                Cout << "\n Price ";
                Cin >> p;
                Cout << "\n Discount ";
                Cin >> d;

                data1 << "" << c << "" << n << "" << p << "" << d << ""
                      << "\n";
                Cout << "\n Record Edit Successfully ";
                token++
            }
            else
            {
                data1 << "" << pcode << "" << pname << "" << price << "" << disc << ""
                      << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n record not found sorry";
        }
    }
}

void shopping ::remove()
{

    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "delete product";

    cout << "enter product code ";
    cin >> pkey();
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "file not exist";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {

            if (pcode == pkey)

            {

                cout << "product delete successfuly";
                token++
            }
            else
            {
                data1 << "" << pcode << "" << pname << "" << price << "" << disc << "<<\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        remove("database1.txt", "database.txt");

        if (token == 0)
            (
                count << ("record not found");

            )
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    count << ("\n     ");
    count << ("prono\t tname\t tprice     \n");
    count << ("\n     ");
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << " " << pname << "" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping ::reciept()
{

    ftream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount;
    float dis = 0;
    float total;

    cout << " RECIEPT";
    data.open(database.txt, ios::in);
    if (!data)
    {

        cout << "Empltu Database";
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
            m;
            cout << "Enter Product code";
            cin >> arrc(c);
            cout << "Enter Quantity";
            cin >> arrq(c);

            for (int i = 0, i < c; i++)
            {

                if (arrc[c] == arrc{i})
                {

                    cout << "\n  Duplicate Product code please try again";
                    goto m;
                }
            }
            c++;
            Cout << "do you want to add another product\n";
            cin >> choice;

        } while (choice == "y");
        cout << "\n           Reciept";
        cout << "nproduct no. \t product name\t product Quantity \t price\t amount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt" ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {

                    amaount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << " " << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.closee();
    }
    cout << "\n\n __________________";
    cout << "total amount : " << total;
}
int main()
{

    shopping s;
    s.menu();
}