#include "Engine.h"

Engine::Engine() : m_correntCorruptionerProfile(0),m_UserProfile(0)
{
    m_NetworkMng.init();
    m_infoCoder;
}

void Engine::registrate(){
    try {
        m_NetworkMng.connect();

        m_NetworkMng.sendRegistreteRequest();
        m_NetworkMng.reciveResponse();

        m_UserProfile.createProfine();
        m_NetworkMng.sendNewProfile();
    }
    catch(eNetworkErrors){/* here will be process of enum of error from the network module*/}
    catch(eUserProfineErrors){/* here will be process of enum of error from the user profile module*/}
    catch(...){throw ;}

}

void Engine::authtorise(){
    try{
        m_NetworkMng.connect();
        m_UserProfile.fillUserAuthData();

        m_NetworkMng.sendAuthtoriseRequest(m_infoCoder.codeToHostFormat(m_NetworkMng.userData));
        m_NetworkMng.reciveResponse();

    }
    catch(eNetworkErrors){ /* here will be process of enum of error from the network module*/}
    catch(eUserProfineErrors){/* here will be process of enum of error from the user-profile module*/}
    catch(...){throw ;}


}

void Engine::getCorruptionerProfile(unsigned long id){
    try {
        m_NetworkMng.connect();

        m_NetworkMng.sendCorruptionerProfileRequest(id);
        m_correntCorruptionerProfile.fillData(m_NetworkMng.reciveResponse());
        showCorruptionerProfile();
    }
    catch(eNetworkErrors){/* here will be process of enum of error from the network module*/}
    catch(eUserProfineErrors){/* here will be process of enum of error from the user profile module*/}
    catch(...){throw ;}

}

void Engine::sendCorruptioner(){
    try {
        m_NetworkMng.connect();
        m_NetworkMng.sendCorruptionerProfile(m_infoCoder.codeToHostFormat(
                                                 m_correntCorruptionerProfile.Data));
        m_NetworkMng.reciveRusult();
        showResult();
    }
    catch(eNetworkErrors){/* here will be process of enum of error from the network module*/}
    catch(eUserProfineErrors){/* here will be process of enum of error from the user profile module*/}
    catch(...){throw ;}
}

void Engine::editCorruptionerProfile(){
        try {
            m_NetworkMng.connect();

            m_NetworkMng.sendCorruptionerProfileRequest(id);
            m_correntCorruptionerProfile.fillData(m_NetworkMng.reciveResponse());
            showCorruptionerProfileEdit();
            m_NetworkMng.sendCorruptionerProfile(m_infoCoder.codeToHostFormat(
                                                     m_correntCorruptionerProfile.Data));
        }
        catch(eNetworkErrors){/* here will be process of enum of error from the network module*/}
        catch(eUserProfineErrors){/* here will be process of enum of error from the user profile module*/}
        catch(...){throw ;}
    }

    void Engine::addCorruptioner(){
        try {
            m_NetworkMng.connect();
            showCorruptionerProfileEdit();
            m_NetworkMng.sendCorruptionerProfile(m_infoCoder.codeToHostFormat(
                                                     m_correntCorruptionerProfile.Data));
        }
        catch(eNetworkErrors){/* here will be process of enum of error from the network module*/}
        catch(eUserProfineErrors){/* here will be process of enum of error from the user profile module*/}
        catch(...){throw ;}
    }
