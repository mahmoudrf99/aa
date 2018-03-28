#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <bitset>
#include<fstream>
#include<cstdlib>
#include<limits>
using namespace std;
int main()
{
    int cipher ;
    cout<<"Which Cipher from 0-9 you want ?!  ";
    cin>>cipher;
    if (cipher ==0)
    {

        while(true)
        {
            string text,mess;
            char x,y;
            int a,b,c;
            text="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            int Result,Version;
            cout<<"Which Version 1,2 ?! : ";
            cin>>Version;
            if(Version==1)
            {
                cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
                cin>>Result;
                if (Result==1)
                {
                    cout << "Please enter the message to cipher ::\n";
                    cin.get();
                    getline(cin,mess);
                    for(int i=0; i<mess.size(); i++)
                    {
                        mess[i]=toupper(mess[i]);
                        for(int j=0; j<27; j++)
                        {
                            if(mess[i]==' ')
                            {
                                cout<<' ';
                                break;
                            }
                            else if(text[j]==mess[i])
                            {
                                x=text[(j*5+8)%26];
                                cout<<x;
                            }
                        }
                    }
                }
                else if (Result==2)
                {
                    cout << "Please enter the message to decipher ::\n";
                    cin.get();
                    getline(cin,mess);
                    for(int i=0; i<mess.size(); i++)
                    {
                        mess[i]=toupper(mess[i]);
                        for(int j=0; j<27; j++)
                        {
                            if(mess[i]==' ')
                            {
                                cout<<' ';
                                break;
                            }
                            else if(text[j]==mess[i] && j>=8)
                            {
                                y=text[21*(j-8)%26];
                                cout<<y;
                            }
                            else if(text[j]==mess[i] && j<8)
                            {
                                y=text[21*(j-8)%26+26];
                                cout<<y;
                            }
                        }
                    }
                }
                else
                {
                    cout<<"\n\t\t\tGood Bye !\n";
                    return 0;
                }
            }
            else if(Version==2)
            {
                cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
                cin>>Result;
                if (Result==1)
                {
                    cout << "Enter a & b & c : ";
                    cin>>a>>b>>c;
                    if ( (a*c)%26 != 1 )
                    {
                        cout<<"Enter a correct variables !\n";
                        cout<<"Enter a & b & c : ";
                        cin>>a>>b>>c;
                    }
                    cout << "Please enter the message to cipher ::\n";
                    cin.get();
                    getline(cin,mess);
                    for(int i=0; i<mess.size(); i++)
                    {
                        mess[i]=toupper(mess[i]);
                        for(int j=0; j<27; j++)
                        {
                            if(mess[i]==' ')
                            {
                                cout<<' ';
                                break;
                            }
                            else if(text[j]==mess[i])
                            {
                                x=text[(a*j+b)%26];
                                cout<<x;
                            }
                        }
                    }
                }
                else if (Result==2)
                {
                    cout<<"Enter a & b & c : ";
                    cin>>a>>b>>c;
                    if ( (a*c)%26 != 1 )
                    {
                        cout<<"Enter a correct variables !\n";
                        cout<<"Enter a & b & c : ";
                        cin>>a>>b>>c;
                    }
                    cout << "Please enter the message to decipher ::\n";
                    cin.get();
                    getline(cin,mess);
                    for(int i=0; i<mess.size(); i++)
                    {
                        mess[i]=toupper(mess[i]);
                        for(int j=0; j<27; j++)
                        {
                            if(mess[i]==' ')
                            {
                                cout<<' ';
                                break;
                            }
                            else if(text[j]==mess[i])
                            {
                                y=text[c*(j-b)%26+26];
                                cout<<y;
                            }
                        }
                    }
                }
                else
                {
                    cout<<"\n\t\t\tGood Bye !\n";
                    return 0;
                }
            }
            else
            {
                cout<<"Please Enter 1 or 2 only !";
                continue;
            }
        }

    }
    else if (cipher ==1)
    {

        while(true)
        {
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            int Result;
            cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
            cin>>Result;
            if (Result==1)
            {
                string a,temp;
                int shift,j;
                cout << "Please enter the message to cipher ::\n";
                cin.get();
                getline(cin,a);
                cout << "Please enter number of shifts :  ";
                cin >> shift;
                temp=a;
                for(int i = 0; i<a.size(); i++)
                {
                    if(a[i] >= 97 && a[i] <= 122)
                    {
                        a[i] = a[i + shift];
                    }
                    else if(a[i] >= 65 && a[i] <= 90)
                    {
                        a[i] = a[i + shift];
                    }
                    else
                    {
                        cout<<"Enter only Characters please !"<<endl;
                        return 0;
                    }
                }
                for(int c=0; c<shift; c++)
                {
                    j=a.length()-shift+c;
                    a[j]=temp[c];
                }
                cout<<a<<endl;
            }
            else if (Result==2)
            {
                string a,temp;
                int shift,j;
                cout << "Please enter the message to decipher ::\n";
                cin.get();
                getline(cin,a);
                cout << "Please enter number of shifts :  ";
                cin >> shift;
                temp=a;
                for(int i = a.size()-1; i>=shift; i--)
                {
                    if(a[i] >= 97 && a[i] <= 122)
                    {
                        a[i] = a[i - shift];
                    }
                    else if(a[i] >= 65 && a[i] <= 90)
                    {
                        a[i] = a[i - shift];
                    }
                    else
                    {
                        cout<<"Enter only Characters please !"<<endl;
                        return 0;
                    }
                }
                for(int c=0; c<shift; c++)
                {
                    j=a.length()-shift+c;
                    a[c]=temp[j];
                }
                cout<<a<<endl;
            }
            else
            {
                cout<<"\n\t\t\tGood Bye !\n";
                return 0;
            }
        }
    }
    else if (cipher ==2)
    {

        string x,y="";
        int shift;
        cout << "enter any word: ";
        getline(cin,x);


        for(int i = 0; i<x.length(); i++)
        {

            if(x[i]>=97&& x[i] <=109)
            {

                int    v = 122-(x[i]-97);
                y+=(char)v;
            }
            else if(x[i]>=109 && x[i]<=122)
            {
                int  v = 97 +(122-x[i]);

                y+=(char)v;
            }

            else if(x[i]>=65 && x[i]<=77)
            {
                int v = 90-(x[i]-65);
                y+=(char)v;
            }
            else if(x[i]>=77 && x[i]<=90)
            {
                int v = 65 +(90-x[i]);

                y+=(char)v;
            }
        }
        cout<<"after encoding ....."<<y<<endl;
        return 0;
    }
    else if (cipher ==3)
    {

        while(true)
        {
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            int Result;
            cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
            cin>>Result;
            if (Result==1)
            {
                string text,ans;
                cout<<"Please Enter the message to Cipher ::"<<endl;
                cin.get();
                getline(cin,text);
                for(int i=0; i<text.size(); ++i)
                {
                    if( ( (int)text[i]>=65 && (int)text[i]<=77 ) || ( (int)text[i]>=97 && (int)text[i]<=109 ) )
                    {
                        ans+= ( ( char ) ( ( int ) text [ i ] + 13 ) );
                    }
                    else if( ( (int)text[i]>=78 && (int)text[i]<=90 ) || ( (int)text[i]>=110 && (int)text[i]<=122 ) )
                    {
                        ans+= ( ( char ) ( ( int ) text [ i ] - 13 ) );
                    }
                    else if( text[i]==' ' )
                    {
                        ans += ' ';
                        continue;
                    }
                    else
                    {
                        cout<<"Please enter only letters !!"<<endl;
                        break;
                    }
                }
                cout<<ans<<endl;
            }
            else if (Result==2)
            {
                string text,ans;
                cout<<"Please Enter the message to deCipher ::"<<endl;
                cin.get();
                getline(cin,text);
                for(int i=0; i<text.size(); ++i)
                {
                    if( ( (int)text[i]>=65 && (int)text[i]<=77 ) || ( (int)text[i]>=97 && (int)text[i]<=109 ) )
                    {
                        ans+= ( ( char ) ( ( int ) text [ i ] + 13 ) );
                    }
                    else if( ( (int)text[i]>=78 && (int)text[i]<=90 ) || ( (int)text[i]>=110 && (int)text[i]<=122 ) )
                    {
                        ans+= ( ( char ) ( ( int ) text [ i ] - 13 ) );
                    }
                    else if( text[i]==' ' )
                    {
                        ans += ' ';
                        continue;
                    }
                    else
                    {
                        cout<<"Please enter only letters !!"<<endl;
                        break;
                    }
                }
                cout<<ans<<endl;
            }
            else
            {
                cout<<"Good Bye !";
                return 0;
            }

        }
    }
    else if (cipher ==4)
    {

        while(true)
        {
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            int Result;
            cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
            cin>>Result;
            if (Result==1)
            {
                string text,Name,binary ;
                text = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
                cout<<"Please Enter the message to Cipher ::"<<endl;
                cin>>Name;
                for(int i=0; i<Name.length(); i++)
                {
                    for(int j=0; j<26; j++)
                    {
                        if(Name[i]==text[j])
                        {
                            binary = bitset<5>(j).to_string();
                            for(int k=0; k<5; k++)
                            {
                                if(binary[k]=='1')
                                {
                                    cout<<"b";
                                }
                                else if(binary[k]=='0')
                                {
                                    cout<<"a";
                                }
                            }
                        }
                    }
                    cout<<" ";
                }
            }
            else if (Result==2)
            {
                string text,Name,result,temp_str;
                cout<<"Please Enter the message to deCipher ::"<<endl;
                cin.get();
                getline(cin,Name);
                for(int i=0; i<Name.length(); i++)
                {
                    if(Name[i] != ' ')
                    {
                        temp_str+=Name[i];
                    }
                }
                text = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
                int j=0;
                bool isOk= false;
                int c=0;
                for(int i=1; i<=temp_str.length(); i++)
                {
                    if(i%5==0)
                    {
                        c+=5;
                    }
                    for(; j<c && i%5==0 ; j++)
                    {
                        if (temp_str[j]=='a')
                        {
                            result+='0';
                        }
                        else if (temp_str[j]=='b')
                        {
                            result+='1';
                        }
                        isOk=true;
                    }
                    if(isOk)
                    {
                        unsigned long decimal = bitset<5>(result).to_ulong();
                        for(int k=0; k<26 ; k++)
                        {
                            if(k==decimal)
                            {
                                cout<<text[k];
                            }
                        }
                        result.erase(0,5);
                    }
                    isOk=false;
                }
            }
            else
            {
                cout<<"\n\n\t\t\tGood Bye !"<<endl;
                return 0;
            }
        }
    }
    else if (cipher ==5)
    {

        string abc="abcdefghijklmnopqrstuvwxyz " ;
        string text, mode, key,  cmp=abc;
        int i, j, k=5  ;
        cout<<"ahlan ya user ya habibi"<<endl;
        cout<<"what do you want to do today ?"<<endl;
        cout<<"	1- cipher a message \n	2- decipher a message \n	3- End"<<endl;
        while ( 1 )
        {
            cin>>mode;
            if ( mode!="1" && mode!="2" && mode!="3" )
            {
                cout<<"only choose 1 , 2 or 3 "<<endl;
                continue;
            }
            break;
        }

        if ( mode== "3" )
        {
            cout<<"See you...";
            return 0;
        }

        cout<<"Enter the text :"<<endl;
        cin.get();
        getline(cin, text) ;
        cout<<"Enter the key : ";
        while(true)
        {
            j=5;
            cin>>key;
            for ( i=0 ; i<5 && j==5 ; i++)
            {
                for ( j=0 ; j<5 ; j++)
                {
                    if (i==j)
                    {
                        continue;
                    }
                    if (key[i] == key[j])
                    {
                        break;
                    }
                }
            }
            if ( i!=5 && j!=5 || key.length()!=5 )
            {
                cout<<"Invalid key, enter another key : ";
                continue;
            }
            else
            {
                break;
            }
        }
        for ( i=0 ; i<5 ; i++ )
        {
            cmp[i]=key[i];
        }
        for ( i=0 ; i<26 ; i++)
        {
            for ( j=0 ; j<5 ; j++ )
            {
                if (abc[i] == cmp[j])
                {
                    break;
                }
            }

            if (j==5)
            {
                cmp[k]=abc[i] ;
                k+=1;
            }
        }
        if (mode == "1" )
        {
            for (i=0 ; i<text.length() ; i++)
            {
                for (j=0 ; j<27 ; j++)
                {
                    if (text[i] == abc[j])
                    {
                        cout<<cmp[j] ;
                        break;
                    }
                }
            }
        }

        else if ( mode == "2" )
        {
            for (i=0 ; i<text.length() ; i++)
            {
                for (j=0 ; j<27 ; j++)
                {
                    if (text[i] == cmp[j])
                    {
                        cout<<abc[j] ;
                        break;
                    }
                }
            }
        }
    }
    else if (cipher ==6)
    {

        while(true)
        {
            int Result,Version;
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            cout<<"\nEnter a Version 1 or 2 : ";
            cin>>Version;
            if(Version == 1)
            {
                cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
                cin>>Result;
                int arr [5][5]=
                {
                    { 'A', 'B', 'C', 'D', 'E' },
                    { 'F', 'G', 'H', 'I', 'J' },
                    { 'K', 'L', 'M', 'N', 'O' },
                    { 'P', 'Q', 'R', 'S', 'T' },
                    { 'U', 'V', 'X', 'Y', 'Z' }
                };
                if (Result==1)
                {
                    bool isTest = true;
                    string  phrase;
                    cout<<"Please Enter the message to Cipher ::"<<endl;
                    cin.ignore();
                    getline(cin,phrase);
                    for (int k=0; k < phrase.length(); k++)
                    {
                        for(int i=0 ; i<5; i++)
                        {
                            for(int j=0 ; j<5; j++)
                            {
                                if ( phrase[k] == arr[i][j] || toupper(phrase[k]) == arr[i][j])
                                {
                                    cout<<i+1<<j+1;
                                }
                                else if(phrase[k] == ' ' && isTest )
                                {
                                    cout<< ' ';
                                    isTest = false;
                                }
                            }
                        }
                        isTest = true;
                    }
                }
                else if (Result==2)
                {
                    string num;
                    cout<<"Please Enter the message to deCipher ::"<<endl;
                    cin.ignore();
                    getline(cin,num);
                    for(int i=0; i<num.length(); i++)
                    {
                        int x,y,z;
                        if(num[i]==' ')
                        {
                            cout<<' ';
                            continue;
                        }
                        x=(num[i]-'0');
                        y=(num[i+1]-'0');
                        z=(arr[x-1][y-1]);
                        if( (i==0 || num[i-1]==' ') && (num[i+2]==' ' || i==num.length()-2)  )
                        {
                            cout<<(char)z;
                        }
                        else
                        {
                            cout<<(char)(z+32);
                        }
                        i++;
                    }
                }
                else
                {
                    cout<<"\n\n\t\t\tGood Bye !"<<endl;
                    return 0;
                }
            }
            else if(Version == 2)
            {
                int a,b,c,d,e;
                cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
                cin>>Result;
                int arr [5][5]=
                {
                    { 'A', 'B', 'C', 'D', 'E' },
                    { 'F', 'G', 'H', 'I', 'J' },
                    { 'K', 'L', 'M', 'N', 'O' },
                    { 'P', 'Q', 'R', 'S', 'T' },
                    { 'U', 'V', 'X', 'Y', 'Z' }
                };
                if (Result==1)
                {
                    bool isTest = true;
                    string  phrase;
                    cout<<"Please Enter the message to Cipher ::"<<endl;
                    cin.get();
                    getline(cin,phrase);
                    cout<<"\nPlease Enter your arrangement : ";
                    cin>>a>>b>>c>>d>>e;
                    for (int k=0; k < phrase.length(); k++)
                    {
                        for(int i=0 ; i<5; i++)
                        {
                            for(int j=0 ; j<5; j++)
                            {
                                if ( phrase[k] == arr[i][j] || toupper(phrase[k]) == arr[i][j])
                                {
                                    if(i+1==1)
                                    {
                                        cout<<a;
                                    }
                                    if(i+1==2)
                                    {
                                        cout<<b;
                                    }
                                    if(i+1==3)
                                    {
                                        cout<<c;
                                    }
                                    if(i+1==4)
                                    {
                                        cout<<d;
                                    }
                                    if(i+1==5)
                                    {
                                        cout<<e;
                                    }
                                    if(j+1==1)
                                    {
                                        cout<<a;
                                    }
                                    if(j+1==2)
                                    {
                                        cout<<b;
                                    }
                                    if(j+1==3)
                                    {
                                        cout<<c;
                                    }
                                    if(j+1==4)
                                    {
                                        cout<<d;
                                    }
                                    if(j+1==5)
                                    {
                                        cout<<e;
                                    }
                                }
                                else if(phrase[k] == ' ' && isTest )
                                {
                                    cout<< ' ';
                                    isTest = false;
                                }
                            }
                        }
                        isTest = true;
                    }
                }
                else if (Result==2)
                {
                    string num,temp;
                    cout<<"Please Enter the message to deCipher ::"<<endl;
                    cin.get();
                    getline(cin,num);
                    cout<<"\nPlease Enter your arrangement : ";
                    cin>>a>>b>>c>>d>>e;
                    for(int i=0; i<num.length(); i++)
                    {
                        if     ( num[i]-'0'==a )
                        {
                            temp+="1";
                        }
                        else if( num[i]-'0'==b )
                        {
                            temp+="2";
                        }
                        else if( num[i]-'0'==c )
                        {
                            temp+="3";
                        }
                        else if( num[i]-'0'==d )
                        {
                            temp+="4";
                        }
                        else if( num[i]-'0'==e )
                        {
                            temp+="5";
                        }
                        else if( num[i]==' ' )
                        {
                            temp+=" ";
                        }
                    }
                    for(int i=0; i<temp.length(); i++)
                    {
                        int x,y,z;
                        if(temp[i]==' ')
                        {
                            cout<<' ';
                            continue;
                        }
                        x=(temp[i]-'0');
                        y=(temp[i+1]-'0');
                        z=(arr[x-1][y-1]);
                        if( (i==0 || temp[i-1]==' ') && (temp[i+2]==' ' || i==temp.length()-2)  )
                        {
                            cout<<(char)z;
                        }
                        else
                        {
                            cout<<(char)(z+32);
                        }
                        i++;
                    }
                }
                else
                {
                    cout<<"\n\n\t\t\tGood Bye !"<<endl;
                    return 0;
                }
            }
            else
            {
                cout<<"\nEnter 1 or 2 only !";
            }
        }
    }
    else if (cipher ==7)
    {

        /*
        A B C D E
        F G H I J
        K L M N O
        p Q R S T
        U V W X Y
        Z

        .-       -...     -.-.     -..     .
        ..-.     --.      ....     ..     .---
        -.-      .-..      --      -.      ---
        .--.     --.-      .-.     ...     -
        ..-      ...-      .--     -..-    -.--
        --..

        */
        while(true)
        {
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            int Result;
            cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
            cin>>Result;
            if (Result==1)
            {
                string text;
                cout<<"Please Enter the message to Cipher ::"<<endl;
                cin.get();
                getline(cin,text);
                for(int i=0; i<text.length(); i++)
                    switch( text[i] )
                    {
                    case ' ':
                        cout<<"   ";
                        break;
                    case 'A':
                        cout<<".-"<<' ';
                        break;
                    case 'B':
                        cout<<"-..."<<' ';
                        break;
                    case 'C':
                        cout<<"-.-."<<' ';
                        break;
                    case 'D':
                        cout<<"-.."<<' ';
                        break;
                    case 'E':
                        cout<<"."<<' ';
                        break;
                    case 'F':
                        cout<<"..-."<<' ';
                        break;
                    case 'G':
                        cout<<"--."<<' ';
                        break;
                    case 'H':
                        cout<<"...."<<' ';
                        break;
                    case 'I':
                        cout<<".."<<' ';
                        break;
                    case 'J':
                        cout<<".---"<<' ';
                        break;
                    case 'K':
                        cout<<"-.-"<<' ';
                        break;
                    case 'L':
                        cout<<".-.."<<' ';
                        break;
                    case 'M':
                        cout<<"--"<<' ';
                        break;
                    case 'N':
                        cout<<"-."<<' ';
                        break;
                    case 'O':
                        cout<<"---"<<' ';
                        break;
                    case 'P':
                        cout<<".--."<<' ';
                        break;
                    case 'Q':
                        cout<<"--.-"<<' ';
                        break;
                    case 'R':
                        cout<<".-."<<' ';
                        break;
                    case 'S':
                        cout<<"..."<<' ';
                        break;
                    case 'T':
                        cout<<"-"<<' ';
                        break;
                    case 'U':
                        cout<<"..-"<<' ';
                        break;
                    case 'V':
                        cout<<"...-"<<' ';
                        break;
                    case 'W':
                        cout<<".--"<<' ';
                        break;
                    case 'X':
                        cout<<"-..-"<<' ';
                        break;
                    case 'Y':
                        cout<<"-.--"<<' ';
                        break;
                    case 'Z':
                        cout<<"--.."<<' ';
                        break;
                    default :
                        cout<<"\nYou should enter a letter from A-Z only!!\n";
                    }
            }
            else if ( Result==2 )
            {
                string Morse,temp;
                cout<<"Please Enter the message to deCipher ::"<<endl;
                cin.get();
                getline(cin,Morse);
                Morse+=' ';
                for(int i=0; i<=Morse.length(); i++)
                {
                    if(Morse[i]!=' ')
                    {
                        temp+=Morse[i];
                    }
                    else if(Morse[i]==' ' || i==Morse.length()-1)
                    {
                        if ( temp ==".-")
                        {
                            cout<<"A";
                        }
                        else if ( temp =="-...")
                        {
                            cout<<"B";
                        }
                        else if ( temp =="-.-.")
                        {
                            cout<<"C";
                        }
                        else if ( temp =="-..")
                        {
                            cout<<"D";
                        }
                        else if ( temp ==".")
                        {
                            cout<<"E";
                        }
                        else if ( temp =="..-.")
                        {
                            cout<<"F";
                        }
                        else if ( temp =="--.")
                        {
                            cout<<"G";
                        }
                        else if ( temp =="....")
                        {
                            cout<<"H";
                        }
                        else if ( temp =="..")
                        {
                            cout<<"I";
                        }
                        else if ( temp ==".---")
                        {
                            cout<<"J";
                        }
                        else if ( temp =="-.-")
                        {
                            cout<<"K";
                        }
                        else if ( temp ==".-..")
                        {
                            cout<<"L";
                        }
                        else if ( temp =="--")
                        {
                            cout<<"M";
                        }
                        else if ( temp =="-.")
                        {
                            cout<<"N";
                        }
                        else if ( temp =="---")
                        {
                            cout<<"O";
                        }
                        else if ( temp ==".--.")
                        {
                            cout<<"P";
                        }
                        else if ( temp =="--.-")
                        {
                            cout<<"Q";
                        }
                        else if ( temp ==".-.")
                        {
                            cout<<"R";
                        }
                        else if ( temp =="...")
                        {
                            cout<<"S";
                        }
                        else if ( temp =="-")
                        {
                            cout<<"T";
                        }
                        else if ( temp =="..-")
                        {
                            cout<<"U";
                        }
                        else if ( temp =="...-")
                        {
                            cout<<"V";
                        }
                        else if ( temp ==".--")
                        {
                            cout<<"W";
                        }
                        else if ( temp =="-..-")
                        {
                            cout<<"X";
                        }
                        else if ( temp =="-.--")
                        {
                            cout<<"Y";
                        }
                        else if ( temp =="--..")
                        {
                            cout<<"Z";
                        }
                        if(Morse[i]==' ' && Morse[i+1]==' ' && Morse[i+2]==' ')
                        {
                            cout<<' ';
                        }
                        temp.erase(0,5);
                    }
                }
            }
            else
            {
                cout<<"\n\n\t\t\tGood Bye !";
                return 0;
            }
        }
        return 0;
    }
    else if (cipher ==8)
    {

        /*
        01010000
        01111001
        --------
        00101001
        2 9
        */
        while(true)
        {
            cout<<"\nAhlan ya user ua habibi. "<<endl;
            int Result,Version;
            cout<<"Which Version you want 1 , 2 :";
            cin>>Version;
            if(Version==1)
            {
                cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
                cin>>Result;
                if (Result==1)
                {
                    string mess,text,key,HEX;
                    cout<<"Enter the key ::"<<endl;
                    cin.ignore();
                    cin.ignore();
                    cin>>key;
                    cout<<"Please Enter the message to Cipher ::"<<endl;
                    cin.get();
                    getline(cin,mess);
                    for(int i=0; i<mess.size(); i++)
                    {
                        text+=((char)( mess[i] ^ key[0]));
                    }
                    cout<<"Text = "<<text<<endl;
                    cout<<"HEX = ";
                    for(int i=0; i<text.size(); i++)
                    {
                        cout << hex << (int)text[i] << " ";
                    }
                }
                else if(Result==2)
                {
                    string text,msg,key,HEX;
                    cout<<"Enter the key ::"<<endl;
                    cin.ignore();
                    cin.ignore();
                    cin>>key;
                    cout<<"Please Enter the message to deCipher ::"<<endl;
                    cin.get();
                    getline(cin,text);
                    for(int i=0; i<text.size(); i++)
                    {
                        msg+=((char)( text[i] ^ key[0]));
                    }
                    cout<<"massage = "<<msg<<endl;
                    cout<<"HEX = ";
                    for(int i=0; i<msg.size(); i++)
                    {
                        cout << hex << (int)msg[i] << " ";
                    }
                }
                else
                {
                    cout<<"Good Bye !";
                    return 0;
                }
            }
            else if(Version ==2)
            {
                cout<<"\nWhat do you like to do today?\n\n1-Cipher a message\n2-deCipher a message\n3-End"<<endl;
                cin>>Result;
                if (Result==1)
                {
                    string mess,text,key,HEX;
                    cout<<"Enter the key ::"<<endl;
                    cin.ignore();
                    cin.ignore();
                    cin>>key;
                    cout<<"Please Enter the message to Cipher ::"<<endl;
                    cin.get();
                    getline(cin,mess);
                    for(int i=0; i<mess.size(); i++)
                    {
                        text+=((char)( mess[i] ^ key[0]));
                    }
                    cout<<"Text = "<<text<<endl;
                    cout<<"HEX = ";
                    for(int i=0; i<text.size(); i++)
                    {
                        cout << hex << (int)text[i] << " ";
                    }
                }
                else if(Result==2)
                {
                    int ans=0;
                    string text,msg,key,HEX;
                    cout<<"Enter the key ::"<<endl;
                    cin.ignore();
                    cin.ignore();
                    cin>>key;
                    cout<<"Do U like to Enter : 1-text or 2-Hexa ?!";
                    cin>>ans;
                    if(ans==1)
                    {
                        cout<<"Please Enter the message to deCipher ::"<<endl;
                        cin.get();
                        getline(cin,text);
                        for(int i=0; i<text.size(); i++)
                        {
                            msg+=((char)( text[i] ^ key[0]));
                        }
                        cout<<"massage = "<<msg<<endl;
                        cout<<"HEX = ";
                        for(int i=0; i<msg.size(); i++)
                        {
                            cout << hex << (int)msg[i] << " ";
                        }
                    }
                    else if(ans==2)
                    {
                        cout<<"Please Enter the message to deCipher ::"<<endl;
                        cin>>hex>>text;
                        for(int i=0; i<text.size(); i++)
                        {
                            msg+=((char)( text[i] ^ key[0]));
                        }
                        cout<<"massage = "<<msg<<endl;
                        cout<<"HEX = ";
                        for(int i=0; i<msg.size(); i++)
                        {
                            cout << hex << (int)msg[i] << " ";
                        }
                    }
                }
                else
                {
                    cout<<"Good Bye !";
                    return 0;
                }
            }
            else
            {
                cout<<"Please Enter 1 or 2 only !";
            }
        }
    }

    else if (cipher ==9)
    {

        cout<<"__________________________________________________"<<endl;
        cout<<endl<<"ahlan ya user ya habibi ...\n\n";

        string mode, text, tmp;
        int i, j, k, l, key, jump1, jump2 ;

        cout<<"What do you like to do today?\n  1- Cipher a message\n  2- Decipher a message\n  3- End\n";

        cin>>mode; //choosing mode
        while ( mode!="1" && mode!="2" && mode!="3" )
        {
            cout<<"only choose 1, 2 or 3\n";
            cin>>mode;
        }

        if (mode=="3")   //ending program
        {
            cout<<"see you...";
            return 0;
        }

        cout<<"Enter the text : \n   "; //getting the text
        cin.get() ;
        getline(cin,text) ;
        for ( i = 0 ; i<text.length() ; i++ )
        {
            if ( text[i]==' ' )
                text.erase(i,1);
        }

        for ( i=0 ; i<text.length() ; i++ )   //converting all letters to lower case
        {
            if (text[i]>='A' && text[i]<='Z' )
            {
                text[i]=text[i]+32;
            }
        }

        cout<<"Enter the key : ";
        while ( 1 )   //checking the key
        {
            cin>>key;
            if ( cin.fail() || key<=1 )
            {
                cout << "invalid key , enter another one : ";
                cin.clear() ;
                cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
                continue;
            }
            break;
        }

        tmp=text;
        jump1=2*key-2;
        jump2=0;
        l=0;

        if (mode=="1")   //Encryption method **
        {
            for ( i=0 ; i<key ; i++)
            {
                if (i==0 || i==(key-1) )
                {
                    j=i;
                    while ( j<text.length() )
                    {
                        tmp[l]=text[j] ;
                        j+=2*key-2;
                        l+=1;
                    }
                }
                else if ( i>0 & i<key-1 )
                {
                    jump1-=2;
                    jump2+=2;
                    k=0;
                    j=i;
                    while ( j<text.length() )
                    {
                        if ( k%2==0 )
                        {
                            tmp[l]=text[j] ;
                            j+=jump1;
                        }
                        if ( k%2==1 )
                        {
                            tmp[l]=text[j] ;
                            j+=jump2;
                        }
                        k+=1;
                        l+=1;
                    }
                }
            } //end while , elif , for
            cout<<endl<<"The encrypted text is : << "<<tmp<<" >>"<<endl;
        }

        else if (mode=="2")   //Decryption method **
        {
            for ( i=0 ; i<key ; i++)
            {
                if (i==0 || i==(key-1) )
                {
                    j=i;
                    while ( j<text.length() )
                    {
                        tmp[j]=text[l];
                        j+=2*key-2;
                        l+=1;
                    }
                }
                else if ( i>0 & i<key-1 )
                {
                    jump1-=2;
                    jump2+=2;
                    k=0;
                    j=i;
                    while ( j<text.length() )
                    {
                        if ( k%2==0 )
                        {
                            tmp[j]=text[l] ;
                            j+=jump1;
                        }
                        if ( k%2==1 )
                        {
                            tmp[j]=text[l] ;
                            j+=jump2;
                        }
                        k+=1;
                        l+=1;
                    }
                }
            } //end while , elif , for
            cout<<endl<<"The decrypted text is : << "<<tmp<<" >>"<<endl;
        }

    }
}
