#include "utils.h"

/**Functionality: Get the input in a safer way,that is, checking if the input given by the user is valid. If it is it will return true, otherwise
        * it will return false.
*
* Description: This is an auxiliary function, it will have a parameter passed by reference which will be the variable in which we are going to store the input
* (the use of the template will make this function useful for every type of variable) then it will ask the user to give an input and after that will check
* if the input is valid for the type of the variable. If it not valid it will clear the input and return false, otherwise ir will return true. As the
* variable is passed by reference it will keep the value of the input.
* Gets user's input and checks if it valid according to the type of the variable "input". The variable "input" will be
* updated since it is passed by reference.
* @brief Validates the input depending on the type of input that is desired
* @tparam type - variable that will hold the user's input
* @return true if the input was valid, false otherwise.
*/

template<typename type>
bool getInput(type &input){
    cin>>input;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}

template bool getInput<int>(int &input);

bool fetchStation(Vertex **v, Graph *railway, char quit) {
    string input;
    quit = tolower(quit, locale());

    while (*v == nullptr) {
        getline(cin, input);

        if (input.size() == 1 && input[0] == quit && quit != ' ')
            return false;

        system("clear");

        *v = railway->findVertex(input);
        if (*v != nullptr)
            break;
        cout << "There isn't a station named: " << input << endl;
        cout << "Input another station: ";
    }

    return true;
}

Edge* pickAnEdge(const vector<Edge*>& data) {
    int page = 0;
    while (true)
    {
        string option;
        drawEdges(data,page,ceil((float)data.size()/10.0));
        bool cond = true;
        while (cond)
        {
            cout << endl
                 << "\033[33mChoose an option[n/p] or the number of the edge you want to choose[1-"<<
                 ((page + 1) * 10 > data.size() ? data.size() - (page * 10) : 10) <<"]: \033[0m";
            cond = true;
            cin >> option;

            if (option.length() == 1)
            {
                option= ::toupper(option[0]);
                switch (option[0])
                {
                    case 'N':
                        if (page + 1 < (float)data.size() / 10.0) page++;
                        cond=false;
                        break;
                    case 'P':
                        if (page > 0) page--;
                        cond=false;
                        break;

                    default:
                        cond = true;
                }
            }
            if(cond){
                int test;
                try{
                    cond = false;
                    test = stoi(option);
                }catch (invalid_argument){
                    cond=true;
                }
                if (!cond) {
                    cond=true;
                    if (to_string(test).length()==option.length()) {
                        if (test>0 && test <= 10 && page * 10 + test <= data.size()) {
                            return data[page*10 + test - 1];
                        }
                    }

                }
            }
            if (cond)
                cout << "\033[31mInvalid input! Please enter a valid input: \033[0m";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void drawEdges(vector<Edge*> data, int page, int nPages) {
    /* due to the template this functions had to be written here as if it was on the cpp it would not recognize the template*/
    system("clear");
    cout << " _________________________________________________________________________________________________________ " << endl;
    cout << "|\033[40m                                              Select an Edge                                             \033[0m|" << endl;
    cout << "\033[0m";
    cout << "|\033[40m_________________________________________________________________________________________________________\033[0m|" << endl;
    cout << "|\033[40m                                                 Page(" << page + 1 << "/" << nPages << ") ";
    for (int i = 0; i < 8 - to_string(page + 1).length() - to_string(nPages).length(); i++)
        cout << ' ';

    cout << "                                        \033[0m|" << endl;
    cout << "|\033[40m_________________________________________________________________________________________________________\033[0m|" << endl;
    cout << "|\033[40m                      Origin                         |                       Destination                 \033[0m|" << endl;
    cout << "|\033[40m_________________________________________________________________________________________________________\033[0m|" << endl;
    for (int i = 10 * page; i < 10 * page + 10; i++) {
        if (i == data.size())
            break;
        cout<<"|";
        if (i % 2 == 0)
            cout << "\033[47m"
                 << "\033[30m";
        else
            cout << "\033[100m";
        auto aux = data[i];
        // TODO: Use getLen after merging
        cout << "    " << aux->getOrig()->getId() << string(49 - aux->getOrig()->getId().size(), ' ') << "| " << aux->getDest()->getId() << string(49 - aux->getDest()->getId().size(), ' ') << " \033[0m";
        cout<<"\033[0m|"<<endl;

    }

    cout << "|\033[40m_________________________________________________________________________________________________________\033[0m|" << endl;
    cout << "|\033[40m                                        [n]Next      [p]Previous                                         \033[0m|" << endl;
    cout << "|\033[40m_________________________________________________________________________________________________________\033[0m|" << endl;
}