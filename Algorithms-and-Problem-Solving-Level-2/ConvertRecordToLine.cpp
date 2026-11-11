#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// هيكل بيانات العميل (Client Structure)
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// دالة لقراءة بيانات العميل الجديدة من المستخدم
sClient ReadNewClient()
{
    sClient Client;
    
    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);
    
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    
    return Client;
}

// دالة لتحويل بيانات هيكل العميل إلى سطر واحد مفصول بفاصل معين (#//#)
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    
    return stClientRecord;
}

int main()
{
    cout << "\nPlease Enter Client Data: \n\n";
    
    sClient Client = ReadNewClient();
    
    cout << "\n\nClient Record for Saving is: \n";
    cout << ConvertRecordToLine(Client) << endl;

    system("pause>0");
    return 0;
}
