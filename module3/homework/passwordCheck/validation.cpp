#include <iostream>
#include "validation.hpp"

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword){
    return password == repeatedPassword;
}

int checkPasswordRules(const std::string& password){
    ErrorCode err;
    if (password.length() < 9)
        err = ErrorCode::PasswordNeedsAtLeastNineCharacters;
    else if (std::none_of(password.begin(), password.end(), ::isdigit))
        err = ErrorCode::PasswordNeedsAtLeastOneNumber;
    else if (std::none_of(password.begin(), password.end(), ::ispunct))
        err = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    else if (std::none_of(password.begin(), password.end(), ::isupper))
        err = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    else 
        err = ErrorCode::Ok;
    return static_cast<int>(err);
}
std::string getErrorMessage(const int err) {
    switch(err){
        case 0:
            return "Password needs at least nine characters";
            break;
        case 1:
            return "Password needs at least one number";
            break;
        case 2:
            return "Password needs at least one special character";
            break;
        case 3:
            return "Password needs at least one upper case letter";
            break;
        case 4:
            return "Passwords doesn\'t match";
            break;
        case 5:
            return "Every think is ok, thanks bye";
            break;
        default:
            return "Sorry, I don\'t know what\'s wrong. Please contact our service";
    }
}

int checkPassword(const std::string& password, const std::string& repeatedPassword){
    if(!doesPasswordsMatch(password, repeatedPassword))
        return static_cast<int>(ErrorCode::PasswordsDoesNotMatch);
    else 
        return checkPasswordRules(password);
}

