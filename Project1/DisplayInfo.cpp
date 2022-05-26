#include "DisplayInfo.h"
#include<string>
#include <map>
#define Open_read_write_NEWS open("NEWS.txt", ios::in | ios::out)
#define Open_write_app_NEWS open("NEWS.txt", ios::in | ios::app)    // write in file and file not empty( has any word )
#define Open_read_NEWS  open("NEWS.txt", ios::in)
#define Open_write_NEWS open("NEWS.txt", ios::out)                  // write in file and file is empty , if file has any word ,the word is deleted
#define Open_read_write_user open("User.txt", ios::in | ios::out)
#define Open_write_app_user open("User.txt", ios::in | ios::app)    // write in file and file not empty( has any word )
#define Open_read_user  open("User.txt", ios::in)
#define Open_write_user open("User.txt", ios::out)                  // write in file and file is empty , if file has any word ,the word is deleted
#define open_write_new open("replace.txt",ios::out)
#define open_read_new open("replace.txt",ios::in)
#define Open_read_write_new open("replace.txt", ios::in | ios::out)


//#define read 
#define write  news.getTitle() << "\t\t" << news.getDescription() << "\t\t      " <<Dt();
#define wh(fp) while (fp >> news.title >> news.description >> Dt() )
#define table  cout << "\t\t\t--------------------------------------------------------------------------------------------\n\t\t\tTitle\t\tDescription\t\t\t\tDate&Time\t\tRate\n\t\t\t----------------------------------------------------------------------------------------\n"

void DisplayInfo::HomePage()
{
    char ch;
    do
    {
        system("cls");  // clear the screan
        cout << "\n\n\t\t\t-------------------------( Main Menu )--------------------------";
        cout << "\n\n\t\t\t(1) Admin Page";
        cout << "\n\n\t\t\t(2) User Page";
        cout << "\n\n\t\t\t(3) EXIT";
        cout << "\n\n\t\t\tPlease enter your choice (1-3) :  ";
        //ch = _getche();
        cin >> ch;
        string  username = "1"
            , password = "1";
        string user, pass;


        switch (ch)
        {
        case '1':
            system("cls");
            cout << "\n\n\t\t\t-------------------------( Check Privacy )--------------------------";
            cout << "\n\n\n\t\t\tEnter the username : ";                   cin >> user;
            cout << "\n\n\t\t\tEnter the password : ";                     cin >> pass;
            if (user == username && pass == password) {
                cout << "\n\t\t\t<<<< USERNAME OR PASSWORD IS CORRECRT !!!!!!!! >>>> ";
                _getch();
                AdminPage();
            }
            else {
                cout << "\n\t\t\t<<<< USERNAME OR PASSWORD IS NOT CORRECRT !!!!!!!! >>>> ";
                _getch();
                HomePage();
            }
            break;
        case '2':
            SignIn_Up();
            break;
        case '3':
            exit(0);
            break;
        default:
            cout << "\t<<< Error >>>";
            _getch();
        }
    } while (ch != 8);
}



void DisplayInfo::AdminPage()
{
    char ch;
    do
    {
        system("cls");
        cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
        cout << "\n\n\t\t\t-------------------------( Main Menu )--------------------------";
        cout << "\n\n\t\t\t(1) Create News";
        cout << "\n\n\t\t\t(2) Display News";
        cout << "\n\n\t\t\t(3) Searchs";
        cout << "\n\n\t\t\t(4) Update";
        cout << "\n\n\t\t\t(5) Delete";
        cout << "\n\n\t\t\t(6) Max Rating";
        cout << "\n\n\t\t\t(7) Return to Home Page";
        cout << "\n\n\t\t\t(8) EXIT";
        cout << "\n\n\t\t\tPlease enter your choice (1-8) :  ";
        //ch = _getche();
        cin >> ch;

        switch (ch)
        {
        case '1':
            system("cls");
            cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
            create_news();
            break;
        case '2':
            system("cls");
            cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
            cout << "\n\n\t\t\t<  All News >";
            display_All();
            break;
        case '3':
            system("cls");
            cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
            cout << "\n\n\t\t\t< Search Page >";
            search_page();
            break;
        case '4':
            system("cls");
            cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
            cout << "\n\n\t\t\t< Update Page >";
            update_Admin_page();
            system("pause");
            break;
        case '5':
            system("cls");
            cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
            cout << "\n\n\t\t\t< Delete Page >";
            delete_Admin_page();
            break;
        case '6':
            system("cls");
            cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
            cout << "\n\n\t\t\t< Rating Page >";
            max_rating();
            break;
        case '7':
            HomePage();
            break;
        case '8':
            exit(0);
            break;
        default:
            cout << "\t<<< Error >>>";
            system("cls");
            _getch();
        }
    } while (ch != 9);



}

void DisplayInfo::SignIn_Up()
{
    char ch;
    do {
        system("cls");
        cout << "\n\n\t\t\t*************************[ SIGNING Page ]**************************";

        cout << "\n\n\t\t\t(1) Regestrain / sign up";
        cout << "\n\n\t\t\t(2) Login / sign in";
        cout << "\n\n\t\t\tPlease enter your choice (1-2) :  ";

        ch = _getche();
        switch (ch)
        {
        case '1':
            system("cls");
            cout << "\n\n\t\t\t< User Page >";
            regestration();
            break;
        case '2':
            system("cls");
            cout << "\n\n\t\t\t< User Page >";
            login();
            break;
        }
    } while (ch != 3);
}
void DisplayInfo::create_news()
{
    cout << "\n\n\n\t\t\t----------------------< Create News >--------------------------";
    fp.Open_write_app_NEWS;
    news.createNew();
    Dt();
    //write in file
    fp << write;
    fp.close();
    cout << "\n\n\t\t\t# The News is Created #";
    _getch();
    system("cls");
}
void DisplayInfo::display_All()
{
    cout << "\n\n\t\t\t            < Display Page >";
    cout << "\n\n\t\t\t----------------------< Display All News >-----------------------------";
    cout << "\n\n\t\t\tAll The News information : \n \n";
    fp.Open_read_NEWS;
    table;
    string line;
    while (getline(fp, line))
    {
        cout << "\t\t\t" << line << endl;
        cout << "\t\t\t--------------------------------------------------------------------------------------------\n";
    };
    cout << "\n\n\t\t\t===============================================================================================";
    fp.close();
    _getch();
    system("cls");
}
char k[25];

void DisplayInfo::search_page()
{

    //the map is title && the description
    map<string, string> sear;
    //the read from the file 
    fp.Open_read_NEWS;

    string line;
    // the passing file in to map
    while (getline(fp, line))
    {
        //the split title find-> see the index \t\t ->split
        string t = line.substr(0, line.find("\t\t"));
        string des = line.substr(line.find("\t\t") + 2, line.back());
        sear.insert({ t, des });
    }

    fp.close();


    cout << "\n\t\t\t Enter The Title you want: ";
    string k;   cin >> k;
    int h = 0;

    for (auto i = sear.begin(); i != sear.end(); i++) {
        if (k == i->first)
        {
            cout << "\n\t\t\t Title \t\tDiscription " << endl;
            cout << "\t\t\t  " << i->first << "\t\t" << i->second << endl;
            cout << "\n\n\t\t\t\t << Done !! >> \n";
            h = 1;
            break;

        }
    }


    if (h == 0)
        cout << "\n\t\t\t Wrong Title !!!";

    _getch();
}


void DisplayInfo::update_Admin_page()
{
    system("cls");
    cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
    cout << "\n\n\t\t\t-------------------------( Main Menu )--------------------------";
    cout << "\n\n\t\t\t(1) Update Title of News";
    cout << "\n\n\t\t\t(2) Update Description of News";
    cout << "\n\n\t\t\t(3) Return to Admin Page";
    cout << "\n\n\t\t\tPlease enter your choice (1-3) :  ";
    char ch = _getche();
    //cin >> ch;

    switch (ch)
    {
    case '1':
        system("cls");
        cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
        cout << "\n\n\t\t\t*************************[ Update Page ]**************************";
        update_title();
        update_Admin_page();
        break;
    case '2':
        system("cls");
        cout << "\n\n\t\t\t*************************[ Admin Page ]**************************";
        cout << "\n\n\t\t\t*************************[ Update Page ]**************************";
        update_description();
        update_Admin_page();
        break;

    case '3':
        AdminPage();
    default:
        cout << "\t<<< Error >>>";
        //system("cls");
        _getch();
    }


}

void DisplayInfo::update_title()
{
    fstream fp2;
    fp.Open_read_write_NEWS;
    fp2.open_write_new;

    string k;
    cin.ignore();
    cout << "\n\t\t\t Enter The Title : ";
    cin >> k;
    int h = 0;
    string line;
    if (fp.is_open())
    {
        while (getline(fp, line))
        {
            //////split
            string t = line.substr(0, line.find("\t\t"));
            if (t == k)
            {
                cout << line;
                cout << "\n\t\t\t\t -------------------------------------- \n";
                cout << "\n\t\t\t\t Enter new title : ";
                string s;  cin >> s;
                // split
                string des = line.substr(line.find("\t\t") + 2, line.back());
                fp2 << s << "\t\t" << des << "\n";
                h = 1;
            }
            else
            {
                fp2 << line << endl;  // write
            }
        }
        fp.close();
        fp2.close();
        remove("NEWS.txt");
        rename("replace.txt", "NEWS.txt");

        if (h == 1)
            cout << "\n\t\t\t <<< Done !!! >>>";
        else
            cout << "\n\t\t\t this title doesn't exist";

        _getch();
        system("cls");
    }

}

void DisplayInfo::update_description() {
    fstream fp2;
    fp.Open_read_write_NEWS;
    fp2.open_write_new;

    string k;
    cin.ignore();
    cout << "\n\t\t\t Enter The Title : ";
    cin >> k;
    int h = 0;
    string line;
    if (fp.is_open())
    {
        while (getline(fp, line))
        {
            //////split
            news.setTitle(line.substr(0, line.find("\t\t")));
            if (news.getTitle() == k)
            {
                cout << line;
                cout << "\n\t\t\t\t -------------------------------------- \n";
                cout << "\n\t\t\t\t Enter new description : ";
                string des;   cin.ignore();     getline(cin, des);//the space is easy
                news.setDescription(des);
                // split
                //string des = line.substr(line.find("\t\t") + 2, line.back());
                fp2 << news.getTitle() << "\t\t" << news.getDescription() << "\t\t" << Dt();
                h = 1;
            }
            else
            {
                fp2 << line << endl;  // write
            }
        }
        fp.close();
        fp2.close();
        remove("NEWS.txt");
        rename("replace.txt", "NEWS.txt");

        if (h == 1)
            cout << "\n\t\t\t <<< Done !!! >>>";
        else
            cout << "\n\t\t\t this title doesn't exist";

        _getch();
        system("cls");
    }
}

void DisplayInfo::delete_Admin_page()
{
    fstream fp2;
    fp.open("NEWS.txt", ios::in);
    fp2.open("replace.txt", ios::app);

    fp.seekg(0, ios::beg);
    string k;
    cout << "\n\t\t\t Enter The Title you want delete: ";
    cin >> k;
    int flag = 0;
    string line;

    while (getline(fp, line))
    {

        //split //////
        string t = line.substr(0, line.find("\t\t"));
        if (t != k)
        {
            fp2 << line << endl;
            //flag = 0;
        }
        else
        {
            cout << "\n\n\t\t\t1- to confirm the deleted \n\t\t\t2- cancel :    ";
            int c;
            cin >> c;
            if (c == 1)
            {
                flag = 1;
                continue;
            }
            else
            {
                // fp2.close();
                // fp.close();
                flag = 2;
                fp2 << line << endl;
                continue;
                //remove("replace.txt");

            }
        }


    }

    fp2.close();
    fp.close();
    remove("NEWS.txt");
    rename("replace.txt", "NEWS.txt");
    if (flag == 0)
    {
        cout << "\n\n\t\t\t the title is not in the file\t";
    }
    else if (flag == 1)
    {
        cout << "\n\n\t\t\t the title is deleted";
    }
    else
        cout << "\n\n\t\t\t the operation is cancelled";

    _getch();
    system("cls");
}

void DisplayInfo::regestration()
{
    //load_res_vector();
    DisplayInfo x;
    user_login regist;
    cout << "\n\n\n\t\t\t----------------------< Regestration Form >--------------------------" << endl;
    user.open("User.txt", ios::out | ios::app);
    cin.ignore();
    cout << "\n\t\t\tEnter Your Username: ";    cin >> regist.name;
    cout << "\n\t\t\tEnter Your Password: ";    cin >> regist.pass;
    cout << "\n\t\t\tRegistration has succsed" << endl;
    user << regist.name << '|' << regist.pass << endl;
    res.push_back(regist);
    user.close();
    _getch();
}
int b = 0;
void DisplayInfo::login()
{
    system("cls");
    load_res_vector();
    load_rating();
    cout << "\n\n\t\t\t# Login : ......\n\n";
    //DisplayInfo u;
    user_login log;
    user.open("User.txt", ios::in);
    cin.ignore();
    cout << "\n\t\t\tEnter your first name: ";      cin >> log.name;
    cout << "\n\t\t\tEnter your password: ";        cin >> log.pass;

    for (auto i = res.begin(); i != res.end(); i++) {
        if (i->name == log.name && i->pass == log.pass)
        {
            cout << "\n\t\t\t\t  **login successifully** ";
            UserPage();
            break;

        }
    }



}

void DisplayInfo::UserPage()
{
    system("cls");
    char ch;
    do
    {
        cout << "\n\n\t\t\t(1) Display News";
        cout << "\n\n\t\t\t(2) Searchs for News";
        cout << "\n\n\t\t\t(3) Add rating";
        cout << "\n\n\t\t\t(4) Return to Home Page";
        cout << "\n\n\t\t\tPlease enter your choice (1-4) :  ";
        ch = _getche();
        switch (ch)
        {
        case '1':
            system("cls");
            cout << "\n\n\t\t\t< User Page >";
            display_All();
            break;
        case '2':
            system("cls");
            cout << "\n\n\t\t\t< Search Page >";
            search_page();
            break;
        case '3':
            system("cls");
            cout << "\n\n\t\t\t< add rating >";
            rating_page();
            break;

        case '4':
            system("cls");
            HomePage();
            break;
        default:
            cout << "\t<<< Error >>>";
            system("cls");
            _getch();
        }


    } while (ch != 5);

}

void DisplayInfo::load_res_vector()
{
    if (res.empty())
    {
        user_login st;
        string line;
        user.open("User.txt", ios::in);
        while (getline(user, line))
        {
            st.name = line.substr(0, line.find('|'));
            st.pass = line.substr(line.find('|') + 1, line.back());
            res.push_back(st);
        }
        user.close();
    }
}

string DisplayInfo::Dt()
{
    time_t my_time = time(NULL);
    return string(ctime(&my_time));
}

void DisplayInfo::rating_page()
{
    cout << "\n\t\t\t Enter the rating : ";
    int r;  cin >> r;
    if (r >= 1 && r <= 5)
    {
        rate.push_back(r);
        fr.open("rate.txt", ios::out | ios::app);
        fr << r << endl;
        fr.close();
        cout << "\n\n\t\t\t ** Added succefuly **";
    }
    else
        cout << "\n\n\t\t\t << Invalid rate >>";

    _getch();
    system("cls");
}
void DisplayInfo::load_rating()
{

    if (rate.empty())
    {
        string line;
        fr.open("rate.txt", ios::in);
        while (getline(fp, line))
        {
            int r = stoi(line);
            rate.push_back(r);
        }

        fr.close();
    }
}

void DisplayInfo::max_rating()
{
    load_rating();
    int max, sum = 0;
    for (int i : rate) 
    {
        sum = sum + i;
    }
    max = sum / rate.size();
    cout << "\n\n\t\t\t Max Rating: " << max;
    _getch();
}









