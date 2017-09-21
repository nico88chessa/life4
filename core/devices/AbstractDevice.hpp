#ifndef ABSTRACTDEVICE_HPP
#define ABSTRACTDEVICE_HPP

namespace life {

class AbstracDevice {
public:
    using Ptr = AbstracDevice *;
    using ConstPtr = const AbstracDevice *;

public:

    /**
     * @brief createConnection
     * @return true se la connessione e' andata a buon fine, false altrimenti
     */
    virtual bool createConnection() = 0;

    /**
     * @brief deleteConnection
     * elimina la connessione precedentemente creata
     */
    virtual void deleteConnection() = 0;

};

}

#endif // ABSTRACTDEVICE_HPP
