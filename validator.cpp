#include "validator.h"
#include <QRegularExpressionValidator>

Validator::Validator()
{
    passwordExp.setPattern("[^a-z, A-Z, а-я, А-Я, 0-9&]");
}

bool Validator::validatePassword(QString password)
{

//       QRegularExpressionValidator valid(passwordExp, 0);
//       int pos = 0;
    QRegularExpressionMatch match = passwordExp.match(password);
    if (!match.hasMatch())
        return true;
    else return false;
}
