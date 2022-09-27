#include <iostream>
#include <string>
using namespace std;
#include "Windows.h"
#include <math.h>
class task {
protected:
    string k,str;
public:
    task() // конструктор класса
    {
        set_data(k);
    }
    void get_data() {
        cout << k<<"\n";
    }
    void set_data(string &we) {
        bool flag1 = true;
        do{
            cout << "число:";
            cin >> we;
            flag1 = check(we);
        } while (!flag1);
    }
    bool check(string strok) {
       bool flag = true;
       int z=0;
       if (strok[0] == '(' && strok[2] == ')' && (strok[1] == '1' || strok[0] == '0'))
           z = 3;
        for (int i = z; i < strok.length(); i++) {
            if ((strok[i] != '1') && (strok[i] != '0')) {
                cout << strok[i] << "-не является допустимом символом\n";//000101 обрабатывать?
                flag = false;
            }
        }
        return flag;
    }
    int to_int(string g) {
        int s1=0;
        int l = g.length() - 1;
        int z = -1;
        int m = 1;
        if (g[0] == '(' && g[2] == ')')
        {
            z = 2;
            if (g[1] == '1')
                m = -1;
        }
        for (int i = l; i > z; i--) {
            if (g[i] == '1')//10001 
                s1 =s1+ pow(2, l - i );
        }
        s1 =s1* m;
        return s1;
    }
    string to_2int(int s) {
        string d="";
        int ss = s;
        s = abs(s);
        if (s != 0) {
            while (s != 1) {
                d = d + to_string(s % 2);
                s /= 2;
            }
            d = d + "1";
        }
        else
            d = "0";
        reverse(d,ss);
        return d;
    }
    void division() {
        set_data(str);
        cout << k << "/" << str << "=";
        int s3;
        int ss = to_int(str);
        int sss = to_int(k);
        s3 = sss / ss;
        string h = to_2int(s3);
        cout << h << "\n";
        return;
    }
    void sum_s() {
        set_data(str);
        cout << k << "+" << str << "=";  
        int s3;
        int ss = to_int(str);
        int sss = to_int(k);
        s3 = sss + ss;
        string h= to_2int(s3);
        cout << h<<"\n";
        return;
    }
    void mult() {
        set_data(str);
        cout << k << "*" << str << "=";
        int ss = to_int(str)*to_int(k);
        string se = to_2int(ss);
        cout << se << "\n";
        return;
    }
    void diff() {
        set_data(str);
        cout << k << "-" << str << "=";
        int s4 = to_int(str);
        int s5 = to_int(k);
        int ss = s5-s4;
        string se = to_2int(ss);
        cout << se << "\n";
    }
    void reverse(string& f, int u) {
        string s="";
        if (u < 0)
            s += "(1)";
        for (int p= f.length()-1; p >-1; p--) {
            s = s + f[p];
        }
        f = s;
        return;
    }
    void replace() {
        set_data(k);
        return;
    }
};
class dop_oper :public task {
public:
    void AND() {
        set_data(str);
        cout << k << " AND " << str << "=";
        int l = str.length();
        int j = k.length();
        int z;
        int t;
        string s = "",s1=k,s2=str;
        reverse(s1,1);
        reverse(s2,1);
        if (j <= l) 
            z = j;
        else//11001 101
            z = l;
            for ( t = 0; t < z; t++) {
                if (s1[t] == '1' && s2[t] == '1')
                    s += "1";
                else
                    s += "0";
            }
            for (int j = t; j < (max(l,j)); j++)
                s += "0";
            reverse(s,1);
            cout << s << "\n";
    }
    void OR() {
        set_data(str);
        cout << k << " OR " << str << "=";
        int l = str.length();
        int j = k.length();
        int z;
        string s = "", s1 = k, s2 = str;
        reverse(s1, 1);
        reverse(s2, 1);
        string main_s;
        int t;
        if (j <= l) {
            z = j;
            main_s = s2;

        }
        else {
            z = l;
            main_s = s1;
        }
        for ( t =0 ; t<z; t++) {
            if (s1[t] == '0' && s2[t] == '0')
                s += "0";
            else
                s += "1";
        }
        for (int j = t; j < (max(l, j)); j++)
        {
            if (main_s[j] == '1')
                s += "1";
            else
                s += "0";
        }
        reverse(s,1);
        cout << s << "\n";
    }
    void NOT() {
        string s = k;
        cout <<"!(" << k << ")=";
        for (int i = 0; i < k.length(); i++) {
            if (k[i] == '1')
                k[i] = '0';
            else
                k[i] = '1';
        }
        get_data();
        k = s;
    }
    void XOR() {
        set_data(str);
        cout << k << " XOR " << str << "=";
        int l = str.length();
        int j = k.length();
        int z;
        int t;
        string s = "", s1 = k, s2 = str;
        reverse(s1, 1);
        reverse(s2, 1);
        string  main_s;
        if (j <= l) {
            z = j;
            main_s = s2;

        }
        else {
            z = l;
            main_s = s1;
        }
        for ( t = 0; t < z; t++) {
            if ((s1[t] == '0' && s2[t] == '0') ||( s1[t] == '1' && s2[t] == '1'))
                s += "0";
            else
                s += "1";
        }
        for (int j = t; j < (max(l, j)); j++)
        {
            if (main_s[j] == '1')
                s += "1";
            else
                s += "0";
        }
        reverse(s,1);
        cout << s<<"\n";
    }
    
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int d;
    dop_oper w;
    int y;
    do {
        cout << "1-суммирование\n2-деление(нацело)\n3-умножение\n4-разность\n5-изменить число\n6-показать число\n";
        cout << "7-XOR\n8-AND\n9-OR\n10-NOT\n11-конец\n";
        cin >> y;
        if (cin.fail()) {
            cout << "Неверные входные данные\n";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        switch (y) {
        case 1:w.sum_s(); break;
        case 2:w.division(); break;
        case 3:w.mult(); break;
        case 4:w.diff(); break;
        case 5:w.replace(); break;
        case 6:w.get_data(); break;
        case 7:w.XOR(); break;
        case 8:w.AND(); break;
        case 9:w.OR(); break;
        case 10:w.NOT(); break;
        case 11:break;
        default:cout << "Нет такой команды\n"; break;
        }
    } while (y != 11);
    return 1;
}
