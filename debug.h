#ifndef ___DEBUG
#define ___DEBUG
/**
 * @brief sadece debug variable bulunuyor
 * 
 */
class Debug{
    private:
    static bool debug;
    public:
    bool static getDebug();
    void static setDebug(bool _d);

};
#endif