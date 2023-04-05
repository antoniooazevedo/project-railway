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
