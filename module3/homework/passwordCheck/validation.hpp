#pragma once

#include <algorithm>
#include <string>
#include <map>

enum class ErrorCode {
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch, 
    Ok,
};

int checkPassword(const std::string& password, const std::string& repeatedPassword);
std::string getErrorMessage(const int err);
bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword);
int checkPasswordRules(const std::string& password);
