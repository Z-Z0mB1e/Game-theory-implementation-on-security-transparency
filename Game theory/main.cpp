#include <bits/stdc++.h>
#include <windows.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
int qstate;
char Player1[100] = {}, Player2[100] = {};
float player_1[2][2];
float player_2[2][2];
long long i, j, cnt = 0;
float x_var_1, x_var_2, constant_1, constant_2;
long long a1[2], a2[2], a3[2], a4[2];
float c, d;

void input_data()
{
    cout << "Enter Payoff Matrix For Cloud Provider and Client" << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << "Enter the value for Matrix[" << i << "][" << j << "]" << endl;
            cin >> player_1[i][j] >> player_2[i][j];
        }
    }
}

void display1()
{
    cout << "The Payoff Matrix Of Both Cloud Provider and Client is" << endl;
    cout << "\t Client" << endl;
    cout << "\t\t       Buy Don't Buy" << endl;
    cout << endl;

    cout << "Provider" << endl;
    for (i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            cout << "\t\tHigh";
        }
        else
        {
            cout << "\t\tLow";
        }
        for (j = 0; j < 2; j++)
        {
            cout << "\t" << player_1[i][j] << player_2[i][j];
        }
        cout << endl;
    }

}
void display2()
{
    cout << "The Payoff Matrix Of Both Cloud Provider and Client is" << endl;
    cout << "\t Client" << endl;
    cout << "\t\t       Buy Don't Buy" << endl;
    cout << endl;

    cout << "Provider" << endl;
    for (i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            cout << "\t\tMore";
        }
        else
        {
            cout << "\t\tLess";
        }
        for (j = 0; j < 2; j++)
        {
            cout << "\t" << player_1[i][j] << player_2[i][j];
        }
        cout << endl;
    }

}
void display3()
{
    cout << "The Payoff Matrix Of Both Cloud Provider and Client is" << endl;
    cout << "\t Client" << endl;
    cout << "\t\t       Buy  Don't Buy" << endl;
    cout << endl;

    cout << "Provider" << endl;
    for (i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            cout << "\t\tMore";
        }
        else
        {
            cout << "\t\tLess";
        }
        for (j = 0; j < 2; j++)
        {
            cout << "\t" << player_1[i][j] << player_2[i][j];
        }
        cout << endl;
    }

}
void display4()
{
    cout << "The Payoff Matrix Of Both Cloud Provider and Client is" << endl;
    cout << "\t Client" << endl;
    cout << "\t\t       Buy   Don't Buy" << endl;
    cout << endl;

    cout << "Provider" << endl;
    for (i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            cout << "\t\tMore";
        }
        else
        {
            cout << "\t\tLess";
        }
        for (j = 0; j < 2; j++)
        {
            cout << "\t" << player_1[i][j] << player_2[i][j];
        }
        cout << endl;
    }

}

void choices3()
{
    cout << "\n\nCASE 1:";
    cout << "\n\nIf Client Chooses Buy" << endl;
    if ((player_1[0][0]) > (player_1[1][0]))
    {
        cout << "\nThen Provider will choose More Security";
        a1[0] = 0;
        a1[1] = 0;
    }
    else
    {
        cout << "\nThen Provider will choose Less Security";
        a1[0] = 1;
        a1[1] = 0;
    }
    cout << "\n\nIf Client Chooses Not to Buy";
    if ((player_1[0][1]) > (player_1[1][1]))
    {
        cout << "\nThen Provider will choose More Security";
        a2[0] = 0;
        a2[1] = 2;
    }
    else
    {
        cout << "\nThen Provider will choose Less Security";
        a2[0] = 1;
        a2[1] = 2;
    }
    cout << "\n\nCASE 2:";
    cout << "\n\nIf Provider chooses More Security";
    if ((player_2[0][0]) > (player_2[0][1]))
    {
        cout << "\nThen Client will choose to Buy";
        a3[0] = 0;
        a3[1] = 1;
    }
    else
    {
        cout << "\nThen Client will choose Not to Buy";
        a3[0] = 0;
        a3[1] = 3;
    }
    cout << "\n\nIf Provider chooses Less Security";
    if ((player_2[1][0]) > (player_2[1][1]))
    {
        cout << "\nThen Client will choose to Buy";
        a4[0] = 1;
        a4[1] = 1;

    }
    else
    {
        cout << "\nThen Client will choose Not to Buy";
        a4[0] = 1;
        a4[1] = 3;
    }

}
void choices4()
{

    cout << "\n\nCASE 1:";
    cout << "\n\nIf Client Chooses to behave Normally";

    if ((player_1[0][0]) > (player_1[1][0]))
    {
        cout << "\nThen Provider will choose not to Monitor";
        a1[0] = 0;
        a1[1] = 0;
    }

    else
    {
        cout << "\nThen Provider will choose to Monitor";
        a1[0] = 1;
        a1[1] = 0;
    }

    cout << "\n\nIf Client Chooses to behave Maliciously";

    if ((player_1[0][1]) > (player_1[1][1]))
    {
        cout << "\nThen Provider will choose not to Monitor";
        a2[0] = 0;
        a2[1] = 2;
    }

    else
    {
        cout << "\nThen Provider will choose to Monitor";
        a2[0] = 1;
        a2[1] = 2;
    }

    cout << "\n\nCASE 2:";
    cout << "\n\nIf Provider chooses not to Monitor";

    if ((player_2[0][0]) > (player_2[0][1]))
    {
        cout << "\nThen Client will choose to behave Normally";
        a3[0] = 0;
        a3[1] = 1;
    }

    else
    {
        cout << "\nThen Client will choose to behave Maliciously";
        a3[0] = 0;
        a3[1] = 3;
    }

    cout << "\n\nIf Provider chooses to Monitor";

    if ((player_2[1][0]) > (player_2[1][1]))
    {
        cout << "\nThen Client will choose to behave Normally";
        a4[0] = 1;
        a4[1] = 1;

    }

    else
    {
        cout << "\nThen Client will choose to behave Maliciously";
        a4[0] = 1;
        a4[1] = 3;
    }

}
void nash3()
{
    cout << "\n\n\nCalculating Nash Equilibrium\n";

    if (a1[0] == 0 && a1[1] == 0)
    {
        if (a3[0] == 0 && a3[1] == 1)
        {
            cout << "\nProvider will choose More Security & Client will choose to Buy:(More,Buy)=" << player_1[0][0] << player_2[0][0] << endl;
            cnt++;
        }
    }

    else
    {
        if (a4[0] == 1 && a4[1] == 1)
        {
            cout << "\nProvider will choose Less Security & Client will choose to Buy:(Less,Buy)=" << player_1[1][0] << player_2[1][0] << endl;
            cnt++;
        }
    }

    if (a2[0] == 0 && a2[1] == 2)
    {
        if (a3[0] == 0 && a3[1] == 3)
        {
            cout << "\nProvider will choose More Security & Client will choose not to Buy:(More,Not Buy)=" << player_1[0][1] << player_2[0][1] << endl;
            cnt++;
        }
    }

    else
    {
        if (a4[0] == 1 && a4[1] == 3)
        {
            cout << "\nProvider will choose Less Security & Client will choose not to Buy:(Less,Not Buy)=" << player_1[1][1] << player_2[1][1] << endl;
            cnt++;
        }
    }
    if (cnt <= 0)
    {
        cout << "\nThere is no Nash Equilibrium\n";
    }

    else
    {
        cout << "\nThere exist" << cnt << " Nash Equilibrium\n\n";
    }

}

void nash4()
{
    cout << "\n\n\nCalculating Nash Equilibrium\n";

    if (a1[0] == 0 && a1[1] == 0)
    {
        if (a3[0] == 0 && a3[1] == 1)
        {
            cout << "\nProvider will choose not to Monitor & Client will choose to behave Normally:(Not Monitor,Normal)=" << player_1[0][0] << player_2[0][0] << endl;
            cnt++;
        }
    }

    else
    {
        if (a4[0] == 1 && a4[1] == 1)
        {
            cout << "\nProvider will choose to Monitor & Client will choose to behave Normally:(Monitor,Normal)=" << player_1[1][0] << player_2[1][0] << endl;
            cnt++;
        }
    }

    if (a2[0] == 0 && a2[1] == 2)
    {
        if (a3[0] == 0 && a3[1] == 3)
        {
            cout << "\nProvider will choose not to Monitor & Client will choose to behave Maliciously:(Not Monitor,Malicious)=" << player_1[0][1] << player_2[0][1] << endl;
            cnt++;
        }
    }

    else
    {
        if (a4[0] == 1 && a4[1] == 3)
        {
            cout << "\nProvider will choose to Monitor & Client will choose to behave Maliciously:(Monitor,Malicious)=" << player_1[1][1] << player_2[1][1] << endl;
            cnt++;
        }
    }

    if (cnt <= 0)
    {
        cout << "\nThere is no Nash Equilibrium\n";
    }

    else
    {
        cout << "\nThere exist" << cnt << " Nash Equilibrium\n\n";
    }

}

void mixed_strategy1()
{
    float a1, b1, c1, d1, e1, f1,h1, i1, j1, k1;
    int g1=1;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "root", "testdb", 3306, NULL, 0);
    cout << "\n\nMixed Strategy\n\n";
    cout << "\nSolving for Player's 1 mixed strategy:\n";
    //E.U.=Expected Utility.
    cout << "E.U(High) = P(Buy)" << player_1[0][0] << " + (1-P(Buy))" << player_1[0][1] << endl;
    cout << "E.U(Low) = P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    cout << "\nE.U(High)=E.U(Low)\n";
    cout << "P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << " = P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    x_var_1 = (player_1[0][0] - player_1[0][1]) - (player_1[1][0] - player_1[1][1]);
    constant_1 = (player_1[1][1] - player_1[0][1]);

    cout << "\nP(Buy) =" << float(abs(constant_1) / abs(x_var_1)) << endl;
    cout << "P(Don't Buy) = 1-P(Buy) =" << float((abs(x_var_1) - abs(constant_1)) / abs(x_var_1)) << endl;

    cout << "\nSolving for Player's 2 Mixed Strategy:\n";
    cout << "E.U(Buy) = P(High)" << player_2[0][0] << "+ (1-P(High))" << player_2[1][0] << endl;
    cout << "E.U(Don't Buy) = P(High)" << player_2[0][1] << "+ (1-P(High))" << player_2[1][1] << endl;
    cout << "\nE.U(Buy)=E.U(Don't Buy)\n";
    cout << "P(High)" << player_2[0][0] << "+ (1-P(High))" << player_2[1][0] << "= P(High)" << player_2[0][1] << "+ (1-P(High))" << player_2[1][1] << endl;
    x_var_2 = (player_2[0][0] - player_2[1][0]) - (player_2[0][1] - player_2[1][1]);
    constant_2 = (player_2[1][1] - player_2[1][0]);
    cout << "\nP(High) =" << float(abs(constant_2) / abs(x_var_2)) << endl;
    cout << "P(Low)= 1-P(High) =" << float((abs(x_var_2) - abs(constant_2)) / abs(x_var_2)) << endl;

    cout << "\nP(High,Buy)=" << float(abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2))) << endl;
    h1 = float(abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2)));
    cout << "\nP(Low,Buy)=" << float(((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2)))) << endl;
    i1 = float(((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2))));
    cout << "\nP(High,Don't Buy)=" << float((abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2))) << endl;
    j1 = float((abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2)));
    cout << "\nP(Low,Don't Buy)=" << float((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2))) << endl;
    k1 = float((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2)));

    c = (abs((constant_1 * constant_2)) * player_1[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_1[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_1[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_1[1][1]);

    d = (abs((constant_1 * constant_2)) * player_2[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_2[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_2[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_2[1][1]);


    cout << "\n\nThe Mixed Strategy Nash Equilibrium is:\n";
    cout << "\n\nCloud Provider: High Security with Probability = " << float(abs(constant_2) / abs(x_var_2)) << "\n and Low Security With Probability = " << float((abs(x_var_2) - abs(constant_2)) / abs(x_var_2)) << endl;
    a1 = float(abs(constant_2) / abs(x_var_2));
    b1 = float((abs(x_var_2) - abs(constant_2)) / abs(x_var_2));
    cout << "\n\nClient Will Buy with Probability = " << float(abs(constant_1) / abs(x_var_1)) << "\n and Will Not Buy with Probability = " << float((abs(x_var_1) - abs(constant_1)) / abs(x_var_1)) << endl;
    c1 = float(abs(constant_1) / abs(x_var_1));
    d1 = float((abs(x_var_1) - abs(constant_1)) / abs(x_var_1));

    cout << "\n\nPayoff For Cloud Provider = " << float(c / abs((x_var_1 * x_var_2))) << endl;
    cout << "Payoff For Client = " << float(d / abs((x_var_1 * x_var_2))) << endl;
    e1 = float(c / abs((x_var_1 * x_var_2)));
    f1 = float(d / abs((x_var_1 * x_var_2)));

    if (conn) {
        puts("Database updated!");
        stringstream querya;
            querya << "INSERT INTO test (case_no, provider_more_trans, provider_less_trans, client_buy, client_dont_buy, provider_payoff, client_payoff, `P(high,buy)`, `P(low,buy)`, `P(high,don't buy)`, `P(low,don't buy)`) VALUES ( '"<< g1 <<"','"<< a1 <<"', '"<< b1 <<"', '"<< c1 <<"', '"<< d1 <<"', '"<< e1 <<"', '"<< f1 <<"','" << h1 << "','" << i1 << "','" << j1 << "','" << k1 << "')";
            
            string query = querya.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

    }
    else {
        puts("Connection to database has failed!");
    }
}
void mixed_strategy2()
{
    float a1, b1, c1, d1, e1, f1, h1, i1, j1, k1;
    int g1 = 2;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "root", "testdb", 3306, NULL, 0);
    cout << "\n\nMixed Strategy\n\n";
    cout << "\nSolving for Player's 1 mixed strategy:\n";
    cout << "E.U(More) = P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << endl;
    cout << "E.U(Less) = P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    cout << "\nE.U(More)=E.U(Less)\n";
    cout << "P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << "= P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    x_var_1 = (player_1[0][0] - player_1[0][1]) - (player_1[1][0] - player_1[1][1]);
    constant_1 = (player_1[1][1] - player_1[0][1]);

    cout << "\nP(Buy) =" << abs(constant_1) / abs(x_var_1) << endl;
    cout << "P(Don't Buy) = 1-P(Buy) =" << (abs(x_var_1) - abs(constant_1)) / abs(x_var_1);

    cout << "\nSolving for Player's 2 Mixed Strategy:\n";
    cout << "E.U(Buy) = P(More)" << player_2[0][0] << "+ (1-P(More))" << player_2[1][0] << endl;                //Expected Utility
    cout << "E.U(Don't Buy) = P(More)" << player_2[0][1] << "+ (1-P(More))" << player_2[1][1] << endl;
    cout << "\nE.U(Buy)=E.U(Don't Buy)\n";
    cout << "P(More)" << player_2[0][0] << "+ (1-P(More))" << player_2[1][0] << "= P(More)" << player_2[0][1] << "+ (1-P(More))" << player_2[1][1] << endl;
    x_var_2 = (player_2[0][0] - player_2[1][0]) - (player_2[0][1] - player_2[1][1]);
    constant_2 = (player_2[1][1] - player_2[1][0]);
    cout << "\nP(More) =" << abs(constant_2) / abs(x_var_2) << endl;
    cout << "P(Less)= 1-P(More) =" << (abs(x_var_2) - abs(constant_2)) / abs(x_var_2) << endl;

    cout << "\nP(More,Buy)=" << abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2)) << endl;
    h1 = abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2));
    cout << "\nP(Less,Buy)=" << ((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2))) << endl;
    i1 = ((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2)));
    cout << "\nP(More,Don't Buy)=" << (abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2)) << endl;
    j1 = (abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2));
    cout << "\nP(Less,Don't Buy)=" << (abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2)) << endl;
    k1 = (abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2));

    c = (abs((constant_1 * constant_2)) * player_1[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_1[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_1[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_1[1][1]);

    d = (abs((constant_1 * constant_2)) * player_2[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_2[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_2[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_2[1][1]);


    cout << "\n\nThe Mixed Strategy Nash Equilibrium is:\n";
    cout << "\n\nCloud Provider: More Transparency with Probability = " << abs(constant_2) / abs(x_var_2) << "\nand Less Transparency  With Probability = " << (abs(x_var_2) - abs(constant_2)) / abs(x_var_2) << endl;
    a1 = abs(constant_2) / abs(x_var_2);
    b1 = (abs(x_var_2) - abs(constant_2)) / abs(x_var_2);
    cout << "\n\nClient Will Buy with Probability = " << float(abs(constant_1) / abs(x_var_1)) << "\nand Will Not Buy with Probability = " << float((abs(x_var_1) - abs(constant_1)) / abs(x_var_1)) << endl;

    c1 = abs(constant_1) / abs(x_var_1);
    d1 = (abs(x_var_1) - abs(constant_1)) / abs(x_var_1);

    cout << "\n\nPayoff For Cloud Provider = " << c / abs((x_var_1 * x_var_2)) << endl;
    cout << "Payoff For Client = " << d / abs((x_var_1 * x_var_2)) << endl;
    e1 = c / abs((x_var_1 * x_var_2));
    f1 = d / abs((x_var_1 * x_var_2));


    if (conn) {
        puts("Database updated!");
        stringstream querya;
        querya << "INSERT INTO test (case_no, provider_more_trans, provider_less_trans, client_buy, client_dont_buy, provider_payoff, client_payoff, `P(high,buy)`, `P(low,buy)`, `P(high,don't buy)`, `P(low,don't buy)`) VALUES ( '" << g1 << "','" << a1 << "', '" << b1 << "', '" << c1 << "', '" << d1 << "', '" << e1 << "', '" << f1 << "','" << h1 << "','" << i1 << "','" << j1 << "','" << k1 << "')";

        string query = querya.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

    }
    else {
        puts("Connection to database has failed!");
    }
}

void mixed_strategy3()
{
    float a1, b1, c1, d1, e1, f1, h1, i1, j1, k1;
    int g1 = 3;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "root", "testdb", 3306, NULL, 0);
    cout << "\n\nMixed Strategy\n\n";
    cout << "\nSolving for Player's 1 mixed strategy:\n";
    cout << "E.U(More) = P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << endl;
    cout << "E.U(Less) = P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    cout << "\nE.U(More)=E.U(Less)\n";
    cout << "P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << "= P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    x_var_1 = (player_1[0][0] - player_1[0][1]) - (player_1[1][0] - player_1[1][1]);
    constant_1 = (player_1[1][1] - player_1[0][1]);

    cout << "\nP(Buy) =" << abs(constant_1) / abs(x_var_1) << endl;
    cout << "P(Don't Buy) = 1-P(Buy) =" << (abs(x_var_1) - abs(constant_1)) / abs(x_var_1) << endl;

    cout << "\nSolving for Player's 2 Mixed Strategy:\n";
    cout << "E.U(Buy) = P(More)" << player_2[0][0] << "+ (1-P(More))" << player_2[1][0] << endl;                //Expected Utility
    cout << "E.U(Don't Buy) = P(More)" << player_2[0][1] << "+ (1-P(More))" << player_2[1][1] << endl;
    cout << "\nE.U(Buy)=E.U(Don't Buy)\n";
    cout << "P(More)" << player_2[0][0] << "+ (1-P(More))" << player_2[1][0] << "= P(More)" << player_2[0][1] << "+ (1-P(More))" << player_2[1][1] << endl;
    x_var_2 = (player_2[0][0] - player_2[1][0]) - (player_2[0][1] - player_2[1][1]);
    constant_2 = (player_2[1][1] - player_2[1][0]);
    cout << "\nP(More) =" << abs(constant_2) / abs(x_var_2) << endl;
    cout << "P(Less)= 1-P(More) =" << (abs(x_var_2) - abs(constant_2)) / abs(x_var_2) << endl;

    cout << "\nP(More,Buy)=" << abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2)) << endl;
    h1 = abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2));
    cout << "\nP(Less,Buy)=" << ((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2))) << endl;
    i1 = ((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2)));
    cout << "\nP(More,Don't Buy)=" << (abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2)) << endl;
    j1 = (abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2));
    cout << "\nP(Less,Don't Buy)=" << (abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2)) << endl;
    k1 = (abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2));

    c = (abs((constant_1 * constant_2)) * player_1[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_1[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_1[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_1[1][1]);

    d = (abs((constant_1 * constant_2)) * player_2[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_2[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_2[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_2[1][1]);


    cout << "\n\nThe Mixed Strategy Nash Equilibrium is:\n";
    cout << "\n\nCloud Provider: More Transparency with Probability = " << abs(constant_2) / abs(x_var_2) << "\nand Less Transparency  With Probability = " << (abs(x_var_2) - abs(constant_2)) / abs(x_var_2) << endl;
    a1 = abs(constant_2) / abs(x_var_2);
    b1 = (abs(x_var_2) - abs(constant_2)) / abs(x_var_2);
    cout << "\n\nClient Will Buy with Probability = " << abs(constant_1) / abs(x_var_1) << "\nand Will Not Buy with Probability = " << (abs(x_var_1) - abs(constant_1)) / abs(x_var_1) << endl;
    c1 = abs(constant_1) / abs(x_var_1);
    d1 = (abs(x_var_1) - abs(constant_1)) / abs(x_var_1);

    cout << "\n\nPayoff For Cloud Provide = " << c / abs((x_var_1 * x_var_2)) << endl;
    cout << "Payoff For Client = " << d / abs((x_var_1 * x_var_2)) << endl;
    e1 = c / abs((x_var_1 * x_var_2));
    f1 = d / abs((x_var_1 * x_var_2));
    if (conn) {
        puts("Database updated!");
        stringstream querya;
        querya << "INSERT INTO test (case_no, provider_more_trans, provider_less_trans, client_buy, client_dont_buy, provider_payoff, client_payoff, `P(high,buy)`, `P(low,buy)`, `P(high,don't buy)`, `P(low,don't buy)`) VALUES ( '" << g1 << "','" << a1 << "', '" << b1 << "', '" << c1 << "', '" << d1 << "', '" << e1 << "', '" << f1 << "','" << h1 << "','" << i1 << "','" << j1 << "','" << k1 << "')";

        string query = querya.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

    }
    else {
        puts("Connection to database has failed!");
    }
}
void mixed_strategy4()
{
    float a1, b1, c1, d1, e1, f1, h1, i1, j1, k1;
    int g1 = 4;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "root", "testdb", 3306, NULL, 0);
    cout << "\n\nMixed Strategy\n\n";
    cout << "\nSolving for Player's 1 mixed strategy:\n";
    cout << "E.U(More) = P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << endl;
    cout << "E.U(Less) = P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    cout << "\nE.U(More)=E.U(Less)\n";
    cout << "P(Buy)" << player_1[0][0] << "+ (1-P(Buy))" << player_1[0][1] << "= P(Buy)" << player_1[1][0] << "+ (1-P(Buy))" << player_1[1][1] << endl;
    x_var_1 = (player_1[0][0] - player_1[0][1]) - (player_1[1][0] - player_1[1][1]);
    constant_1 = (player_1[1][1] - player_1[0][1]);

    cout << "\nP(Buy) =" << abs(constant_1) / abs(x_var_1) << endl;
    cout << "P(Don't Buy) = 1-P(Buy) =" << (abs(x_var_1) - abs(constant_1)) / abs(x_var_1) << endl;

    cout << "\nSolving for Player's 2 Mixed Strategy:\n";
    cout << "E.U(Buy) = P(More)" << player_2[0][0] << "+ (1-P(More))" << player_2[1][0] << endl;                //Expected Utility
    cout << "E.U(Don't Buy) = P(More)" << player_2[0][1] << "+ (1-P(More))" << player_2[1][1] << endl;
    cout << "\nE.U(Buy)=E.U(Don't Buy)\n";
    cout << "P(More)" << player_2[0][0] << "+ (1-P(More))" << player_2[1][0] << "= P(More)" << player_2[0][1] << "+ (1-P(More))" << player_2[1][1] << endl;
    x_var_2 = (player_2[0][0] - player_2[1][0]) - (player_2[0][1] - player_2[1][1]);
    constant_2 = (player_2[1][1] - player_2[1][0]);
    cout << "\nP(More) =" << abs(constant_2) / abs(x_var_2) << endl;
    cout << "P(Less)= 1-P(More) =" << (abs(x_var_2) - abs(constant_2)) / abs(x_var_2) << endl;

    cout << "\nP(More,Buy)=" << abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2)) << endl;
    h1 = abs((constant_1 * constant_2)) / abs((x_var_1 * x_var_2));
    cout << "\nP(Less,Buy)=" << ((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2))) << endl;
    i1 = ((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) / ((abs(x_var_1)) * (abs(x_var_2)));
    cout << "\nP(More,Don't Buy)=" << (abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2)) << endl;
    j1 = (abs(x_var_1) - abs(constant_1)) * abs(constant_2) / abs((x_var_1 * x_var_2));
    cout << "\nP(Less,Don't Buy)=" << (abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2)) << endl;
    k1 = (abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) / abs((x_var_1 * x_var_2));

    c = (abs((constant_1 * constant_2)) * player_1[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_1[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_1[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_1[1][1]);

    d = (abs((constant_1 * constant_2)) * player_2[0][0]) + (((abs(constant_1)) * (abs(x_var_2) - abs(constant_2))) * player_2[0][1]) + ((abs(x_var_1) - abs(constant_1)) * abs(constant_2) * player_2[1][0]) + ((abs(x_var_1) - abs(constant_1)) * (abs(x_var_2) - abs(constant_2)) * player_2[1][1]);


    cout << "\n\nThe Mixed Strategy Nash Equilibrium is:\n";
    cout << "\n\nCloud Provider: More Transparency with Probability = " << abs(constant_2) / abs(x_var_2) << "\nand Less Transparency  With Probability = " << (abs(x_var_2) - abs(constant_2)) / abs(x_var_2) << endl;
    a1 = abs(constant_2) / abs(x_var_2);
    b1 = (abs(x_var_2) - abs(constant_2)) / abs(x_var_2);
    cout << "\n\nClient Will Buy with Probability = " << abs(constant_1) / abs(x_var_1) << "\nand Will Not Buy with Probability = " << (abs(x_var_1) - abs(constant_1)) / abs(x_var_1) << endl;
    c1 = abs(constant_1) / abs(x_var_1);
    d1 = (abs(x_var_1) - abs(constant_1)) / abs(x_var_1);

    cout << "\n\nPayoff For Cloud Provider = " << c / abs((x_var_1 * x_var_2)) << endl;
    cout << "Payoff For Client = " << d / abs((x_var_1 * x_var_2)) << endl;
    e1 = c / abs((x_var_1 * x_var_2));
    f1 = d / abs((x_var_1 * x_var_2));

    if (conn) {
        puts("Database updated!");
        stringstream querya;
        querya << "INSERT INTO test (case_no, provider_more_trans, provider_less_trans, client_buy, client_dont_buy, provider_payoff, client_payoff, `P(high,buy)`, `P(low,buy)`, `P(high,don't buy)`, `P(low,don't buy)`) VALUES ( '" << g1 << "','" << a1 << "', '" << b1 << "', '" << c1 << "', '" << d1 << "', '" << e1 << "', '" << f1 << "','" << h1 << "','" << i1 << "','" << j1 << "','" << k1 << "')";

        string query = querya.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

    }
    else {
        puts("Connection to database has failed!");
    }
}

void menu()
{
    cout << "\n\nEnter your choice case to Analyse Or Press 0 to exit\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        input_data();
        display1();
        mixed_strategy1();
        menu();
        break;

    case 2:
        input_data();
        display2();
        mixed_strategy2();
        menu();
        break;

    case 3:
        input_data();
        display3();
        choices3();
        nash3();
        mixed_strategy3();
        menu();
        break;

    case 4:
        input_data();
        display4();
        choices4();
        nash4();
        mixed_strategy4();
        menu();
        break;


    case 0:
        cout << "\nEXITING..!!!!\n\n";
        exit(0);

    default:
        cout << "\nWrong Input..Try Again...!!!!" << endl;
        menu();
        break;
    }
}

int main() {

    cout << "\t\t\t\t\t\t\t\t\t***************************";
    cout << "\n\t\t\t\t\t\t\t\t\t   High-Low Security Game\n";
    cout << "\t\t\t\t\t\t\t\t\t***************************";

    cout << "\n\nSecurity Transparency Constraints\n";
    cout << "\n\n1.High-Low Security Game\n";
    cout << "\n\n2.Transparency in Cloud Security\n";
    cout << "\n\n3.Transparency in Cloud Security using Nash Equilibrium\n";
    cout << "\n\n4.Transparency in Cloud Security using Mixed Strategy\n";

    menu();



    return 0;

}
