//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <fstream>
//---------------------------------------------------------------------------

#pragma argsused
struct Student
{
    char name[200];
    int year;
    char group_number[7];
    double phizika;
    double inform;
    double matem;
    double himia;
    double average_number;
};


// ??????? ??????-------------------------------
void GetInformation()
{   cout << "       ??????? ?????????? ?????????: " << endl;
    int n;
    cin >> n;
    Student *std = new Student[n];

    ofstream record("zapici.txt");
    if (record)
    {
      record << n << endl;

    for (int i = 0; i < n; i++)
  {
    cout << "???: " << endl;
    cin.ignore(100, '\n');   //????????? 100 ????????, ???? ????? ?? ????? ?????? ?????? \n
    gets(std[i].name);
    record << std[i].name << endl;

    cout << "??? ????????: " << endl;
    cin >> std[i].year;
    record << std[i].year << endl;

    cout << "????? ??????: " << endl;
    cin >> std[i].group_number;
    record << std[i].group_number << endl;

    cout << "??????: " << endl;
    cin >> std[i].phizika;
    record << std[i].phizika << endl;

    cout << "???????????: " << endl;
    cin >> std[i].inform;
    record << std[i].inform << endl;

    cout << "??????????: " << endl;
    cin >> std[i].matem;
    record << std[i].matem << endl;

    cout << "?????: " << endl;
    cin >> std[i].himia;
    record << std[i].himia << endl;

    std[i].average_number = (std[i].inform + std[i].matem + std[i].himia + std[i].phizika) / 4.;
    cout << "??????? ????: " << std[i].average_number << endl;
    record << std[i].average_number << endl;
    record << "--------------------" << endl;
  }
    }
 record.close();
// delete[] std;
}
//------------------------------------------------------------------

// ?????????? ?????????? ?????????------------------
int NumberOfStudents()
{
        ifstream number("zapici.txt");
        int n;
        if(number)
        {
              number >> n;
        }
          number.close();
    return n;
}
//--------------------------------------------------

// ????????? ??????-------------------------------------------
void AddInformation()
{   cout << "       ??????? ?????????? ?????????: " << endl;
    int n;
    cin >> n;
    Student *std;       
    std = new Student[n];

    string number = "";
    int num = NumberOfStudents() + n;

    ofstream record("zapici.txt", ios::app);
    ofstream record_("zapici.txt", ios::in); //??? ?????? ? ?????? ?????

       if (record_)
      {
        record_ << num << endl;
         if (record)
         {
    for (int i = 0; i < n; i++)
    {
    cout << "???: " << endl;
    cin.ignore(100, '\n');  //????????? 100 ????????, ???? ????? ?? ????? ?????? ?????? \n
    gets(std[i].name);
    record << std[i].name << endl;

    cout << "??? ????????: " << endl;
    cin >> std[i].year;
    record << std[i].year << endl;

    cout << "????? ??????: " << endl;
    cin >> std[i].group_number;
    record << std[i].group_number << endl;

    cout << "??????: " << endl;
    cin >> std[i].phizika;
    record << std[i].phizika << endl;

    cout << "???????????: " << endl;
    cin >> std[i].inform;
    record << std[i].inform << endl;

    cout << "??????????: " << endl;
    cin >> std[i].matem;
    record << std[i].matem << endl;

    cout << "?????: " << endl;
    cin >> std[i].himia;
    record << std[i].himia << endl;

    std[i].average_number = (std[i].inform + std[i].matem + std[i].himia + std[i].phizika) / 4.;
    cout << "??????? ????: " << std[i].average_number << endl;
    record << std[i].average_number << endl;
    record << "--------------------" << endl;
    }
  }
  }
 record_.close();
 record.close();
// delete[] std;
}
//--------------------------------------------------------------



 // ?????? ?? ????? ------------------------------------------------------------
 void ReadInformation()
 {
        ifstream reading("zapici.txt");

        if (reading) //???? ?????? ????
        {       string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka = "";
                string str;
                int n;
                reading >> n;
                getline(reading, str);  //?????? ??????, ?????? ?? ?????
         cout << "      ??????????: " << endl;
         cout << "????? ?????????? ?????????: " << n << endl;

                for (int i = 0; i < n; i++)
                {
                      getline(reading, name);
                      cout << "???: " << name << endl;

                        getline(reading, year);
                        cout << "??? ????????: " << year << endl;

                        getline(reading, group);
                        cout << "????? ??????: " << group << endl;

                        getline(reading, phizika);
                        cout << "??????: " << phizika << endl;

                        getline(reading, inform);
                        cout << "???????????: " << inform << endl;

                        getline(reading, matem);
                        cout << "??????????: " << matem << endl;

                        getline(reading, himia);
                        cout << "?????: " << himia << endl;

                        getline(reading, sr_ball);
                        cout << "??????? ????: " << sr_ball << endl;

                        getline(reading, stroka);
                        cout << stroka << endl;
                }
        }
        reading.close();
 }
 // --------------------------------------------------

 //???????? ??????-----------------------------------
 void Copy()
 {
        ifstream reading("zapici.txt"); //????? ??? ??????
        ofstream record("newzapici.txt"); //????? ??? ?????? ????? ??????

        if (reading)
        {       if(record)
                {
                string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka= "";
                string str;
                int n;
                reading >> n;

                      record << n << endl;
                      getline(reading, str); //?????? ?????? ??????
                for (int i = 0; i < n; i++)
                {
                        getline(reading, name);
                        record << name << endl;

                        getline(reading, year);
                        record << year << endl;

                        getline(reading, group);
                        record << group << endl;

                        getline(reading, phizika);
                        record << phizika << endl;

                        getline(reading, inform);
                        record << inform << endl;

                        getline(reading, matem);
                        record << matem << endl;

                        getline(reading, himia);
                        record << himia << endl;

                        getline(reading, sr_ball);
                        record << sr_ball << endl;

                        getline(reading, stroka);
                        record << stroka << endl;
                }
                }
        }
        reading.close();
        record.close();
 }
 //--------------------------------------------------

 //????????? ??????--------------------------------
 void Change()
 {
        Copy();

        ifstream reading("newzapici.txt");
        ofstream record("zapici.txt", ios::out);

        if (reading)
        {
            if (record)
              { string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka= "";
                        int n, k;
                        reading >> n;

                        cout << "       ??????? ????? ??????, ??????? ?????? ????????: " << endl;
                        cin >> k;
                        k--;

                        record << n << endl;
                        getline(reading, stroka);
                        if (k >= 0 && k < n)
                        {
                          for (int i = 0; i < n; i++)
                              {
                                if (i != k)
                                    {
                        getline(reading, name);
                        record << name << endl;

                        getline(reading, year);
                        record << year << endl;

                        getline(reading, group);
                        record << group << endl;

                        getline(reading, phizika);
                        record << phizika << endl;

                        getline(reading, inform);
                        record << inform << endl;

                        getline(reading, matem);
                        record << matem << endl;

                        getline(reading, himia);
                        record << himia << endl;

                        getline(reading, sr_ball);
                        record << sr_ball << endl;

                        getline(reading, stroka);
                        record << stroka << endl;
                                    }
                         else {
    Student* std = new Student[n];

    cout << "???: " << endl;
    cin.ignore(100, '\n');  //????????? 100 ????????, ???? ????? ?? ????? ?????? ?????? \n
    gets(std[i].name);
    record << std[i].name << endl;

    cout << "??? ????????: " << endl;
    cin >> std[i].year;
    record << std[i].year << endl;

    cout << "????? ??????: " << endl;
    cin >> std[i].group_number;
    record << std[i].group_number << endl;

    cout << "??????: " << endl;
    cin >> std[i].phizika;
    record << std[i].phizika << endl;

    cout << "???????????: " << endl;
    cin >> std[i].inform;
    record << std[i].inform << endl;

    cout << "??????????: " << endl;
    cin >> std[i].matem;
    record << std[i].matem << endl;

    cout << "?????: " << endl;
    cin >> std[i].himia;
    record << std[i].himia << endl;

    std[i].average_number = (std[i].inform + std[i].matem + std[i].himia + std[i].phizika) / 4.;
    cout << "??????? ????: " << std[i].average_number << endl;
    record << std[i].average_number << endl;
    record << "--------------------" << endl;




    //????????? ?? ??????, ??????? ????? ????????
    getline(reading, name);
    getline(reading, year);
    getline(reading, group);
    getline(reading, phizika);
    getline(reading, inform);
    getline(reading, matem);
    getline(reading, himia);
    getline(reading, sr_ball);
    getline(reading, stroka);
                              }
                              }
                        }
              }
        }

        reading.close();
        record.close();

        remove("newzapici.txt");
 }
 //-----------------------------------------------------------------------------

 //??????? ??????---------------------------------------------------------------
void Delete()
{        Copy();

        ifstream reading("newzapici.txt");
        ofstream record("zapici.txt", ios::out);

        if (reading)
        { if (record)
              { string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka= "";
                        int n, k;
                        reading >> n;
                        int b = n - 1;

                cout << "       ??????? ????? ??????, ??????? ?????? ????????: " << endl;
                cin >> k;
                k--;

                        record << b << endl;
                        getline(reading, stroka);
                        if (k >= 0 && k < n)
                        {
                          for (int i = 0; i < n; i++)
                            {
                                if (i != k)
                                {
                        getline(reading, name);
                        record << name << endl;

                        getline(reading, year);
                        record << year << endl;

                        getline(reading, group);
                        record << group << endl;

                        getline(reading, phizika);
                        record << phizika << endl;

                        getline(reading, inform);
                        record << inform << endl;

                        getline(reading, matem);
                        record << matem << endl;

                        getline(reading, himia);
                        record << himia << endl;

                        getline(reading, sr_ball);
                        record << sr_ball << endl;

                        getline(reading, stroka);
                        record << stroka << endl;
                                    }
                         else {
    //? ??? ? ????? ???? ?????????, ??????? ?????????? ?? ??????????? ????? ? ??
    //???? ????????
    //????????? ???? ? ????????, ??? ?????? ???????
    getline(reading, name);
    getline(reading, year);
    getline(reading, group);
    getline(reading, phizika);
    getline(reading, inform);
    getline(reading, matem);
    getline(reading, himia);
    getline(reading, sr_ball);
    getline(reading, stroka);
                                }
                            }
                        }
              }
        }

        reading.close();
        record.close();

        remove("newzapici.txt");
}
 //-----------------------------------------------------------------------------

 //????? ??????? ????-----------------------------------------------------------
  void AverageBall()
  {
        double srball, Balls = 0, A_ball = 0;
        ifstream reading("zapici.txt");
        ofstream record("ball.txt");

        if (reading)
        {       if (record)
                {
                string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka= "";
                string str;
                int n, number;


                reading >> n;
                for(int i = 0; i < n; i++)
                {       getline(reading, str);
                        getline(reading, name);
                        getline(reading, year);
                        getline(reading, group);
                        getline(reading, phizika);
                        getline(reading, inform);
                        getline(reading, matem);
                        getline(reading, himia);
                        reading >> srball;
                        Balls += srball;
                        getline(reading, stroka);
                }
               A_ball = Balls / n;
               record << A_ball;
              }
        }
  }
 //-----------------------------------------------------------------------------

 //????? ????????? ?? ????? ??????----------------------------------------------
  void Search()
  {
        ifstream reading("zapici.txt");
        ofstream record("search.txt");
        ifstream reading_("ball.txt");
        ofstream number("group.txt");
        ofstream counting("count.txt");
        cout << "       ??????? ????? ???????????? ??? ??????: " << endl;
        string s;
        getline(cin, s);
        number << s << endl;

        if (reading)
        {       if (record)
                {
                if (reading_)
                {
                string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka= "";
                string str;
                int n, count = 0;
                double ball;
                reading >> n;
                reading_ >> ball;
                cout << "     ????? ??????? ???? ???? ?????????: " << ball << endl;
                cout << "???????? ?? ?????? " << s << ", ? ??????? ??????? ???? ???? ?????? ???????? ?????:" << endl;
                getline(reading, str);    //?????? ?????? ? ??????????? ?????????

                for(int i = 0; i < n; i++)
                {
                        getline(reading, name);
                        getline(reading, year);
                        getline(reading, group);
                        getline(reading, phizika);
                        getline(reading, inform);
                        getline(reading, matem);
                        getline(reading, himia);
                        getline(reading, sr_ball);
                        getline(reading, stroka);
                        if (s == group)
                        {
                                record << name << endl;
                                record << year << endl;
                                record << group << endl;
                                record << phizika << endl;
                                record << inform << endl;
                                record << matem << endl;
                                record << himia << endl;
                                record << sr_ball << endl;
                                record << stroka << endl;
                                count++;
                        }
                }  counting << count;
                }
                }
        }
        reading.close();
        record.close();
        reading_.close();
        number.close();
  }
 //-----------------------------------------------------------------------------

 //???? ??????? ???? ???? ?????? ????????---------------------------------------
 void Ball()
 {      ifstream read("zapici.txt");
        ifstream reading_("ball.txt");
        ifstream reading("search.txt");
        ofstream record("7.txt");
        ofstream record_("cash.txt");
        ifstream number("group.txt");
        ifstream counting("count.txt");

        if (reading)
        {       if(record)
                {
                if(reading_)
                {
                if (record_)
                {
                string name = "";
                string year = "";
                string group = "";
                string phizika = "";
                string inform = "";
                string matem = "";
                string himia = "";
                string sr_ball = "";
                string stroka= "";
                string str;
                string s;
                int n, count;
                double ball, srball;
                read >> n;
                reading_ >> ball;
                record << "     ????? ??????? ???? ???? ?????????: " << ball << endl;
                getline(number, s);
                counting >> count;
                for(int i = 0; i < count; i++)
                {
                        getline(reading, name);
                        getline(reading, year);
                        getline(reading, group);
                        getline(reading, phizika);
                        getline(reading, inform);
                        getline(reading, matem);
                        getline(reading, himia);
                        reading >> srball;
                        getline(reading, str);
                        getline(reading, stroka);
                        if(srball > ball)
                        {
                                record << "???: " << name << endl;
                                cout << "???: " << name << endl;
                                record << "??? ????????: " << year << endl;
                                cout << "??? ????????: " << year << endl;
                                record << "????? ??????: " << group << endl;
                                cout << "????? ??????: " << group << endl;
                                record << "??????: " << phizika << endl;
                                cout << "??????: " << phizika << endl;
                                record << "???????????: " << inform << endl;
                                cout << "???????????: " << inform << endl;
                                record << "??????????: " << matem << endl;
                                cout << "??????????: " << matem << endl;
                                record << "?????: " << himia << endl;
                                cout << "?????: " << himia << endl;
                                record << "??????? ????: " << srball << endl;
                                cout << "??????? ????: " << srball << endl;
                                record << stroka << endl;
                                cout << stroka << endl;
                        }     else
                        {
                                record_ << name;
                                record_  << year;
                                record_ << group;
                                record_ << phizika;
                                record_ << inform;
                                record_ << matem;
                                record_ << himia;
                                record_ << srball;
                                record_ << stroka;
                        }
                }
                }
                }
                }
        }
        read.close();
        reading.close();
        record.close();
        reading_.close();
        record_.close();
 }
 //-----------------------------------------------------------------------------

 //????????? ??????????? ? ????-------------------------------------------------
  void Save()
 {
        ifstream reading("7.txt");  //? ??????????? ?? ?????????? ??????????????? ???????
        ofstream record("spiski.txt");
        ifstream number("group.txt");
        string s;
        if(number)
        {
                getline(number, s);
        }

        if (reading)
        {       if(record)
                {
                int n;

                string str ="";
        record << "???????? ?? ?????? " << s << ", ? ??????? ??????? ???? ???? ?????? ???????? ?????:" << endl;
                while(!reading.eof())
                {
                        getline(reading, str);
                        record << str << endl;
                }
                }
        }
        reading.close();
        record.close();
        number.close();
    /*  remove("ball.txt");
        remove("7.txt");
        remove("cash.txt");
        remove("zapici.txt");
        remove("count.txt");
        remove("group.txt");
        remove("search.txt");     */
 }
 //-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
        // ???????????---------------------
        setlocale(LC_ALL, "Russian");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        // --------------------------------

    int n, s;
   // setlocale(0, "");
    while (true)
    {   cout << "      ???????? ????????:" << endl;
        cout << "       ??????? ?????? - 1" << endl << "       ???????? - 2" << endl
            << "       ???????? ?????? - 3" << endl << "       ???????? ?????? - 4" << endl
            << "       ??????? ?????? - 5" << endl << "       ?????????????? ??????? - 6" << endl
            << "       ????????? ??????????? ? ???? - 7" << endl
            << "       ????? - 0" << endl;

        cin >> s;
        switch (s)
        {

        case 1:        //??????? ??????
        system("cls"); //?????? ??????? ?? ???????
            GetInformation();
            break;


        case 2:        //??????? ?????? ?? ?????
         system("cls"); //?????? ??????? ?? ???????
               ReadInformation();
               break;


        case 3:    //????????? ??????
        system("cls");
            AddInformation();
            break;


        case 4:      //????????? ??????
        system("cls");
        Change();
            break;


        case 5:    //??????? ??????
        system("cls");
        Delete();
            break;

        case 6:  //?????????????? ???????
        system("cls");
        AverageBall();
        Search();
        Ball();
        break;

        case 7:  //????????? ? ????
        system("cls");
        Save();
        break;
        }
       if (s == 0)
            break;
    }


        getch();
        return 0;
}
//---------------------------------------------------------------------------


