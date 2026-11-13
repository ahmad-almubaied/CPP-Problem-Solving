#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

// دالة تقسيم النص
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

// دالة تحويل السطر إلى سجل عميل
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

// دالة تحميل العملاء من الملف إلى Vector
vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    
    MyFile.open(FileName, ios::in);
    
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

// دالة طباعة تفاصيل العميل الواحد
void PrintClientCard(sClient Client)
{
    cout << "\n\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance << endl;
}

// دالة البحث عن العميل برقم الحساب
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C; // تخزين بيانات العميل المطابق لإرجاعها
            return true; // تم العثور عليه
        }
    }
    
    return false; // لم يتم العثور عليه بعد انتهاء الفحص
}

int main()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber;

    cout << "Please enter AccountNumber? ";
    cin >> AccountNumber;

    sClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
    }

    system("pause>0");
    return 0;
}
