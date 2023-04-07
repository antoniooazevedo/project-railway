#include <cmath>
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


int getLen(const string str){
    int counter = 0;
    int neg_count = 0;
    for(auto i : str){
        if (i < 0){
            neg_count++;
        }
        if (neg_count > 0){
            if (neg_count % 2 == 0){
                counter++;
            }
        } else{
            counter++;
        }
    }
    return counter;
}

bool fetchStation(Vertex **v, Graph *railway, char quit) {
    string input;
    quit = tolower(quit, locale());

    while (*v == nullptr) {
        getline(cin, input);

        if (input[0] == quit && quit != ' ')
            return false;

        system("clear");

        *v = railway->findVertex(input);
        if (*v != nullptr)
            break;
        cout<<endl;
        cout << "\033[31m - Station not found - " << "\033[0m";
        cout<<endl;
        cout<<endl;
        cout << "\033[34mInput another station: " << "\033[0m";
    }

    return true;
}

bool compareValue(const pair<string,int>& a, const pair<string,int>& b){
    return a.second > b.second;
}
bool sortResultVector(const pair<pair<Vertex*, Vertex*>, int> &p1, const pair<pair<Vertex*, Vertex*>, int> &p2){
    return (p1.second > p2.second);
}


/** Controls the pagination of the drawn table. It allows the user to quit the menu, or jump to the next, previous or any other page directly.
     * @brief Controls the pagination of the drawn table.
     * @see show::draw(vector<Name> data, int page, int nPages)
     * @tparam Name type of the values we want to display
     * @param data the values we want to display
     * complexity O(1)
     */
template<typename Name>
void paginationController(vector<Name> data) {
    /* due to the template this functions had to be written here as if it was on the cpp it would not recognize the template*/
    int page = 0;
    while (page >= 0 and page < (float)data.size() / 10.0)
    {
        string option;
        draw(data,page,ceil((float)data.size()/10.0));
        bool cond = true;
        while (cond)
        {
            cout << endl
                 << "\033[32mChoose an option[n/p/q] or the number of the page you would want to go[1-"<<ceil((float)data.size()/10.0)<<"]: ";
            cond = true;
            cin >> option;

            if (option.length() == 1)
            {
                option= ::toupper(option[0]);
                switch (option[0])
                {
                    case 'N':
                        page++;
                        cond=false;
                        break;
                    case 'P':
                        page--;
                        cond=false;
                        break;
                    case 'Q':
                        page = -1;
                        cond=false;
                        break;
                    default:
                        cond = true;
                }
            }
            if(cond){
                int test;
                try{
                    cond=false;
                    test= stoi(option);
                }catch (invalid_argument){
                    cond=true;
                }
                if(!cond){
                    cond=true;
                    if(to_string(test).length()==option.length()){
                        if(test>0 and test <=ceil((float)data.size()/10.0)) {
                            page=test-1;
                            cond= false;
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

template void paginationController<pair<string,int>>(vector<pair<string,int>> data);


/**
 * @brief Draws a table to display values, uses a system of pagination that displays 10 values per page
 * @tparam Name type of the value we want to display
 * @param data the values to display
 * @param page current page
 * @param nPages number of pages that exist
 * complexity O(1)
 */
template<typename Name>
void draw(vector<Name> data, int page, int nPages) {
    /* due to the template this functions had to be written here as if it was on the cpp it would not recognize the template*/
    system("clear");
    cout << "\033[0m";
    cout << " __________________________________________" << endl;
    cout << "|\033[40m                Page(" << page + 1 << "/" << nPages << ")";
    for (int i = 0; i < 8 - to_string(page + 1).length() - to_string(nPages).length(); i++)
        cout << ' ';

    cout << "           \033[0m|" << endl;
    cout << "|\033[40m__________________________________________\033[0m|" << endl;
    cout << "|\033[40m   Flow   |              Name             \033[0m|" << endl;
    cout << "|\033[40m__________________________________________\033[0m|" << endl;
    for (int i = 10 * page; i < 10 * page + 10; i++) {
        if (i == data.size())
            break;
        cout<<"|";
        if (i % 2 == 0)
            cout << "\033[47m"
                 << "\033[30m";
        else
            cout << "\033[100m";
        cout << "    " << data[i].second << string( 6- getLen(to_string(data[i].second)), ' ') << "| " << data[i].first << string(30 - getLen(data[i].first), ' ');
        cout<<"\033[0m|"<<endl;

    }

    cout << "|\033[40m__________________________________________\033[0m|" << endl;
    cout << "|\033[40m  [n]Next      [p]Previous    [q]Go Back  \033[0m|" << endl;
    cout << "|\033[40m__________________________________________\033[0m|" << endl;
}

void drawFlow(int flow){
    int size = flow > 10 ? 2 : 1;
    cout<< "|\033[100m Flow: " << flow<< string(38 - size, ' ') << "\033[0m|\n"
    << "|\033[100m\033[40m---------------------------------------------\033[0m|\n";
}

void drawCost(int cost){
    int size = 0;
    int aux = cost;
    while(aux != 0){
        aux = aux/10;
        size++;
    }
    cout<< "|\033[100m Cost: " << cost<< string(38 - size, ' ') << "\033[0m|\n"
        << "|\033[100m\033[40m---------------------------------------------\033[0m|\n";
}

void drawResults(){
    cout << " _____________________________________________ \n"
         << "|\033[40m                   Results                   \033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n";
}

void drawFooter(vector<Edge*> edges){
    cout << "|\033[40m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n";

    string option;
    bool condition = true;
    while(condition){
        cout << endl;
        cout << "\033[32mMore deitailed information? [y/n]: ";
        cin >> option;
        condition = true;
        if (option.length() == 1)
        {
            option= ::toupper(option[0]);
            switch (option[0])
            {
                case 'N':
                    condition=false;
                    break;
                case 'Y':
                    paginationControllerEdge(edges);
                    condition=false;
                    break;
                default:
                    condition = true;
            }
            if (condition)
                cout << "\033[31mInvalid input! Please enter a valid input: \033[0m";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


template<typename edge>
void paginationControllerEdge(vector<edge> data) {
    /* due to the template this functions had to be written here as if it was on the cpp it would not recognize the template*/
    int page = 0;
    while (page >= 0 and page < (float)data.size() / 10.0)
    {
        string option;
        drawEdge(data,page,ceil((float)data.size()/10.0));
        bool cond = true;
        while (cond)
        {
            cout << endl
                 << "\033[32mChoose an option[n/p/q] or the number of the page you would want to go[1-"<<ceil((float)data.size()/10.0)<<"]: ";
            cond = true;
            cin >> option;

            if (option.length() == 1)
            {
                option= ::toupper(option[0]);
                switch (option[0])
                {
                    case 'N':
                        page++;
                        cond=false;
                        break;
                    case 'P':
                        page--;
                        cond=false;
                        break;
                    case 'Q':
                        page = -1;
                        cond=false;
                        break;
                    default:
                        cond = true;
                }
            }
            if(cond){
                int test;
                try{
                    cond=false;
                    test= stoi(option);
                }catch (invalid_argument){
                    cond=true;
                }
                if(!cond){
                    cond=true;
                    if(to_string(test).length()==option.length()){
                        if(test>0 and test <=ceil((float)data.size()/10.0)) {
                            page=test-1;
                            cond= false;
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

template void paginationControllerEdge<Edge*>(vector<Edge*> data);

template<typename edge>
void drawEdge(vector<edge> data, int page, int nPages) {
    /* due to the template this functions had to be written here as if it was on the cpp it would not recognize the template*/
    system("clear");
    cout << "\033[0m";
    cout << " __________________________________________" << endl;
    cout << "|\033[40m                Page(" << page + 1 << "/" << nPages << ")";
    for (int i = 0; i < 8 - to_string(page + 1).length() - to_string(nPages).length(); i++)
        cout << ' ';

    cout << "           \033[0m|" << endl;
    cout << "|\033[40m_____________________________________________________________________________\033[0m|" << endl;
    cout << "|\033[40m   Flow   |            Origin             |            Destination           \033[0m|" << endl;
    cout << "|\033[40m_____________________________________________________________________________\033[0m|" << endl;
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
        cout << "    " << aux->getFlow() << string( 6- getLen(to_string(aux->getFlow())), ' ') << "| " << aux->getOrig()->getId() << string(30 - getLen(aux->getOrig()->getId()), ' ') << "| " << aux->getDest()->getId() << string(30 - getLen(aux->getDest()->getId()), ' ') << " \033[0m";
        cout<<"\033[0m|"<<endl;

    }

    cout << "|\033[40m__________________________________________\033[0m|" << endl;
    cout << "|\033[40m  [n]Next      [p]Previous    [q]Go Back  \033[0m|" << endl;
    cout << "|\033[40m__________________________________________\033[0m|" << endl;
}
