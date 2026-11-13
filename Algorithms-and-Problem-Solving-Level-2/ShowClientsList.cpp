#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// دالة تحويل السطر المستخرج من الملف إلى هيكل عميل
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); 

    return Client;
}

// دالة قراءة بيانات العملاء من الملف وتخزينها في Vector
vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    
    MyFile.open(FileName, ios::in); // فتح الملف وضعية قراءة (Read Mode)
    
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            sClient Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    
    return vClients;
}

// دالة لطباعة صف واحد خاص بالعميل داخل الجدول
void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(10) << left << Client.AccountBalance;
    cout << "\n";
}

// دالة طباعة جدول قائمة العملاء بالكامل
void ShowClientsList()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "_________________________________________________________________________________________________\n\n";
    
    // طباعة ترويسة الجدول (Headers)
    cout << "| " << setw(15) << left << "Accout Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(40) << left << "Client Name";
    cout << "| " << setw(12) << left << "Phone";
    cout << "| " << setw(10) << left << "Balance";
    cout << "\n_________________________________________________________________________________________________\n\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Clients Available In the System!\n";
    }
    else
    {
        // المرور على كل عميل في الفيكتور وطباعة السطر الخاص به
        for (sClient Client : vClients)
        {
            PrintClientRecordLine(Client);
        }
    }

    cout << "\n_________________________________________________________________________________________________\n";
}

int main()
{
    ShowClientsList();

    system("pause>0");
    return 0;
}
