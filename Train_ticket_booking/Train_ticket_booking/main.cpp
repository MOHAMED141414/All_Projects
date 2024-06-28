#include<iostream>
#include<string>
using namespace std;

//Making a Class to take the Guest Data.
class Person{
public:
    string name;
    int age,Phone_number;
    char gender;};

// Storing ID and Names.
void member (int ID, int Password)
{
    if (ID == 200018631 && Password==7777) {
        cout << "Hello MR.Moustafa,";}
    else if (ID == 200016655 && Password==2222) {
        cout << "Hello MR.Mohamed,";}
    else if (ID == 200016465 && Password==3333) {
        cout << "Hello MR.Eslam,";}
    else if (ID == 200016902 && Password==4444) {
        cout << "Hello MR.Disha,";}
    else if (ID == 200016654 && Password==5555) {
        cout << "Hello MR.Abdo,";}
    else{cout<<"Wrong Choice,Please Try Again\n";
        exit(0);}}

int main() {
    // Declare The Variables.
    int date, time, Access, ID, country, Password, day, Class, Seat, want;

    //Infinite Loop.
    while (true) {
        cout << "Hello Sir, Please Choose:\n";
        cout << "1. Member\n2. Guest\n0. Quit\n";
        cout << "Please Choose What You Need:";
        cin >> Access;
        system ("CLS");

        // If He Is MEMBER.
        if (Access == 1) {

            //Asking For ID.
            cout << "Please,Enter Your ID:\a";
            cin >> ID;

            //Asking For Password.
            cout << "Please,Enter Your Password:\a";
            cin >> Password;
            member(ID, Password);
            continuous:
            cout << "Where Do You Want To Go?\n";
            cout << "1.Cairo\n2.Alexandria\n3.Sharm_Elsheikh\n4.Aswan\n5.Assuit\n6.mansoura\n7.Asmalia\n";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> country;
            switch (country) {
                case 1 :
                    break;
                case 2 :
                    break;
                case 3 :
                    break;
                case 4 :
                    break;
                case 5 :
                    break;
                case 6 :
                    break;
                case 7 :
                    break;
                default:
                    if (country == 0) { continue; }
                    else {
                        cout << "Wrong Choice,Do You Want End The Program?\n";
                        cout << "1.YES\n2.NO\n";
                        cout << "Please Choose What You Need:";
                        cin >> want;
                        if (want == 2) { goto continuous; }
                        else {
                            cout << "Thank You, Have a Nice Day\n";
                            return 0;
                        }
                    }
            }
            a:
            system ("CLS");
            cout << "Available Trips\n";
            cout<< " 1-Saturday,20/5/2023\n 2-Sunday,21/5/2023\n 3-Monday,22/5/2023\n 4-Tuesday,23/5/2023\n 5-Wednesday,24/5/2023\n 6-Thursday,25/5/2023\n 7-Friday,26/5/2023\n ";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> day;
            system ("CLS");
            if (day >= 1 && day <= 7) {}
            else if (day == 0) { continue; }
            else {
                cout << "Wrong Choice,Do You Want End The Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please Choose What You Need:";
                cin >> want;
                if (want == 2) { goto a; }
                else {
                    cout << "Thank You,Have a Nice Day\n";
                    break;
                }
            }
            b:
            cout << "Available Time\n";
            cout << " 1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 9\n 10\n 11\n 12\n";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> time;
            system ("CLS");
            if (time >= 1 && time <= 12) {}
            else if (time == 0) { continue; }
            else {
                cout << "Wrong Choice,Do You Want End The Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please Choose What You Need:";
                cin >> want;
                if (want == 2) { goto b; }
                else {
                    cout << "Thank You,Have a Nice Day\n";
                    break;
                }
            }
            c:
            cout << "1.AM\n2.PM\n";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> date;
            system ("CLS");
            if (date == 1 || date == 2) {
                cout << "Please Pay At Window 5\n";
                cout << "Done, Your Ticket Is Reserved, You Will Receive Message On Your Phone\n";
                break;
            } else if (date == 0) { continue; }
            else {
                cout << "Wrong Choice,Do You Want End The Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please Choose What you Need:";
                cin >> want;
                if (want == 2) { goto c; }
                else {
                    cout << "Thank you,Have a Nice Day\n";
                    break;
                }
            }
        }

            // If He Is Guest.
        else if (Access == 2) {
            M:
            Person person;

            // Taking The Name.
            cout << "Please,Enter your Name:";
            cin >> person.name;

            //Taking The Age.
            cout << "Please,Enter Your Age:";
            cin >> person.age;

            //Choosing The Gender.
            cout << "Please,Choose your Gender(M/F):";
            cin >> person.gender;
            if (person.gender == 'm' || person.gender == 'M' || person.gender == 'f' || person.gender == 'F') {}
            else {
                cout << "Wrong Choice Try Again\n";
                goto M;
            }

            //Taking The Phone Number.
            cout << "Please,Enter Your Phone Number:";
            cin >> person.Phone_number;
            system ("CLS");

            back:
            cout << "Hello MR." << person.name << ", Where Do You Want To Go?\n";
            cout << "1.Cairo\n2.Alexandria\n3.Sharm_Elsheikh\n4.Aswan\n5.Assuit\n6.mansoura\n7.Asmalia\n";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> country;
            system ("CLS");

            //Choosing The Country.
            switch (country) {
                case 1 :
                    break;
                case 2 :
                    break;
                case 3 :
                    break;
                case 4 :
                    break;
                case 5 :
                    break;
                case 6 :
                    break;
                case 7 :
                    break;
                default:
                    if (country == 0) { continue; }
                    else {
                        cout << "Wrong Choice,Do You Want End The Program?\n";
                        cout << "1.YES\n2.NO\n";
                        cout << "Please Choose What You Need:";
                        cin >> want;
                        if (want == 2) { goto back; }
                        else {
                            cout << "Thank You ,Have a Nice Day\n";
                            return 0;
                        }
                    }
            }

            //Choosing The Time.
            d:
            cout << "Available Trips\n";
            cout
                    << " 1-Saturday,20/5/2023\n 2-Sunday,21/5/2023\n 3-Monday,22/5/2023\n 4-Tuesday,23/5/2023\n 5-Wednesday,24/5/2023\n 6-Thursday,25/5/2023\n 7-Friday,26/5/2023\n ";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> day;
            system ("CLS");
            if (day >= 1 && day <= 7) {}
            else if (day == 0) { continue; }
            else {
                cout << "Wrong Choice,Do You Want End The Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please Choose What You Need:";
                cin >> want;
                if (want == 2) { goto d; }
                else {
                    cout << "Thank You ,Have a Nice Day\n";
                    break;
                }
            }
            e:
            cout << "Available Time\n";
            cout << " 1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 9\n 10\n 11\n 12\n";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> time;
            system ("CLS");
            if (time >= 1 && time <= 12) {}
            else if (time == 0) { continue; }
            else {
                cout << "Wrong Choice,Do You Want End The Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please Choose What You Need:";
                cin >> want;
                if (want == 2) { goto e; }
                else {
                    cout << "Thank You ,Have a Nice Day\n";
                    break;
                }
            }
            f:
            cout << "1.AM\n2.PM\n";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> date;
            system ("CLS");
            if (date == 1 || date == 2) {}
            else if (date == 0) { continue; }
            else {
                cout << "Wrong Choice,Do you want End the Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please choose what you need:";
                cin >> want;
                if (want == 2) { goto f; }
                else {
                    cout << "Thank You ,Have a Nice Day\n";
                    break;
                }
            }

            //Choosing The Class.
            g:
            cout << "What Class Do You Need?\n";
            cout << " 1. First Class\n 2. Medium Class\n 3. Economy Class\n ";
            cout << "Press 0 For Menu Main\n";
            cout << "Please Choose What You Need:";
            cin >> Class;
            system ("CLS");

            //If He Chose The First Class.
            if (Class == 1) {
                cout << " 1. Beside Window For 100 $\n 2. Middle Seat For 85 $\n";
                cout << "Press 0 For Menu Main\n";
                cout << "Please Choose What You Need:";
                cin >> Seat;
                system ("CLS");
                if (Seat == 1 || Seat == 2) {
                    cout << "Please,Pay At Window 5\n";
                    cout << "Done, Your Ticket Is Reserved, You Will Receive a Message On Your Phone\n";
                    break;
                } else if (Seat == 0) { continue; }
                else {
                    cout << "Wrong Choice,Do you want End the Program?\n";
                    cout << "1.YES\n2.NO\n";
                    cout << "Please Choose What You Need:";
                    cin >> want;
                    if (want == 2) { goto g; }
                    else {
                        cout << "Thank You ,Have a Nice Day\n";
                        break;
                    }
                }
            }

                //If He Chose The Medium Class.
            else if (Class == 2) {
                cout << " 1. Beside Window For 70 $\n 2. Middle Seat For 55 $\n";
                cout << "Press 0 For Menu Main\n";
                cout << "Please Choose What You Need:";
                cin >> Seat;
                system ("CLS");
                if (Seat == 1 || Seat == 2) {
                    cout << "Please,Pay At Window 5\n";
                    cout << "Done, Your Ticket Is Reserved, You Will Receive a Message On Your Phone";
                    break;
                }
                else if (Seat == 0) { continue; }
                else {
                    cout << "Wrong Choice,Do You Want End the Program?\n";
                    cout << "1.YES\n2.NO\n";
                    cout << "Please Choose What You Need:";
                    cin >> want;
                    if (want == 2) { goto g; }
                    else {
                        cout << "Thank You ,Have a Nice Day\n";
                        break;
                    }
                }
            }

                //If He Chose The Economy Class.
            else if (Class == 3) {
                cout << " 1. Beside Window For 50 $\n 2. Middle Seat For 35 $\n";
                cout << "Press 0 For Menu Main\n";
                cout << "Please Choose What You Need:";
                cin >> Seat;
                system ("CLS");
                if (Seat == 1 || Seat == 2) {
                    cout << "Please,Pay At Window 5\n";
                    cout << "Done, Your Ticket Is Reserved, You Will Receive a Message On Your Phone";
                    break;
                }
                else if (Seat == 0) { continue; }
                else {
                    cout << "Wrong Choice,Do you want End the Program?\n";
                    cout << "1.YES\n2.NO\n";
                    cout << "Please Choose What You Need:";
                    cin >> want;
                    if (want == 2) { goto g; }
                    else {
                        cout << "Thank You ,Have a Nice Day\n";
                        break;
                    }
                }
            }
            else if (Class == 0) { continue; }

                // If He Chose Any Other Number .
            else {
                cout << "Wrong Choice,Do You Want End The Program?\n";
                cout << "1.YES\n2.NO\n";
                cout << "Please Choose What You Need:";
                cin >> want;
                if (want == 2) { goto g; }
                else {
                    cout << "Thank You ,Have a Nice Day\n";
                    break;
                }
            }
        } else if (Access == 0) {

            cout << "Goodbye! See You Soon.\n";
            break;
        } else {
            cout << "Wrong Choice,Please Try Again\n";
            continue;
        }
    }
    return 0;
}
