#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;
using std::ifstream;
using std::ofstream;
using std::endl;

class Wordle
{
public:
    void loop();
    void fill_word();
    void output();
    char master[6];
    char result[6];
    char vocab[10][6];
    int num_a,num_e,num_i,num_o,num_u;
};

int main()
{
    ifstream inStream;
    //ofstream outStream;

    inStream.open("VOCAB.txt");
    Wordle wd;

    for(int i=0; i<10; ++i)
    {
        inStream >> wd.vocab[i];
    }
    srand(time(0));
    wd.fill_word();
    cout << "Try to guess (upper only)" << endl;

    //std::string VOCAB;
    cout << "It's have " << wd.num_a << "A"
         << " and " << wd.num_e << "E" << " and "
         << wd.num_i << "I" << " and " << wd.num_o << "O" << " and " << wd.num_u << "U" << endl;

    int j=0;
    while (j<6)
    {
        cin >> wd.result;
        if(strcmp(wd.master,wd.result)==0)
        {
            cout << "You Win!!!" << endl;
            break;
        }
        else
            wd.loop();
        j++;
    }

    wd.output();
    inStream.close();
    //outStream.close();

    return 0;
}
void Wordle::loop()
{
    for(int i=0; i<6; i++)
    {
        if(result[i] == master[i])
        {
            cout << result[i] << " ";
        }
        else
            cout << "_ " ;
    }
    cout << endl;
}
void Wordle::fill_word()
{
    strcpy(master,vocab[rand()%10]);
    num_a=num_e=num_i=num_o=num_u=0;
    for(int i=0; i< 5 ; ++i)
    {
        if(master[i] == 'A')
        {
            ++num_a;
        }
        else if(master[i] == 'E')
        {
            ++num_e;
        }
        else if(master[i] == 'I')
        {
            ++num_i;
        }
        else if(master[i] == 'O')
        {
            ++num_o;
        }
        else if(master[i] == 'U')
        {
            ++num_u;
        }
    }
}
void Wordle::output()
{
    cout << "The word correct is " << master <<endl;
}
