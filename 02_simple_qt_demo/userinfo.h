#ifndef USERINFO_H
#define USERINFO_H
#include <QString>

class UserInfo
{
public:
    UserInfo();
private:
    QString username;
    QString passwd;
    void set_username(QString uname)
    {
        this->username = uname;
    }

    void set_passwd(QString passwd)
    {
        this->passwd = passwd;
    }
    QString get_username()
    {
        return this->username ;
    }

    QString get_passwd()
    {
        return this->passwd ;
    }
};

#endif // USERINFO_H
