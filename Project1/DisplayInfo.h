#pragma once
#include <string>
#include <errno.h>
#include <conio.h>
#include <stdio.h>
//#include <cmath>
//#include <cstdlib>


#include "News.h"
#include <iostream>
#include <fstream>
#include<list>
#include<vector>
#include<ctime>
using namespace std;

struct user_login
{
    string name, pass;
};


class DisplayInfo
{
    News news;
    fstream fp;
    //char name[25];
    //char pass[25];
    vector<user_login> res;
    vector<int>rate;
    fstream user;
    fstream fr;

public:

    void HomePage();

    void AdminPage();


    void create_news();

    void display_All();

    void load_res_vector();

    //void search_Admin_page();
    void search_page();

    void UserPage();

    void update_Admin_page();
    void update_title();
    void update_description();
    void delete_Admin_page();

    void SignIn_Up();
    void regestration();
    void login();
    string Dt();
    void rating_page();

    void load_rating();
    void max_rating();

};


