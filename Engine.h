#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <Networkmng.h>

class Engine :QObject {
public:
    Engine();

    // request to host
    void registrate();
    void authtorise();
    void getCorruptionerProfile(unsigned long id);
    void sendCorruptioner();


    // internal methods
    void editCorruptionerProfile();
    void addCorruptioner();

    // guiSignals
signals:
    showCorruptionerProfile();
    showProfile();
    showResult();


    // members
private :
     NetworkMng m_NetworkMng;
     m_UserProfile;
     m_correntCorruptionerProfile

     m_infoCoder;
};

#endif // ENGINE_H
