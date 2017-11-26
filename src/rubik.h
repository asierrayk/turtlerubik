#include <string>

const int kSize = 3;

class Rubik {
public:
    Rubik();
    virtual ~Rubik();
    void ShowState();

    /* void execute(std::string algorithm); */
    void B();
    void B3();
    void B2();
    void D();
    void D3();
    void D2();
    void F();
    void F3();
    void F2();
    void L();
    void L3();
    void L2();
    void R();
    void R3();
    void R2();
    void U();
    void U3();
    void U2();
private:
    short int id [kSize][kSize][kSize];
    short int orientation [kSize][kSize][kSize];
    void cycle(short int &c1, short int &c2, short int &c3, short int &c4);
    void cycleCornerOrientation(short int &c1, short int &c2, short int &c3, short int &c4);
    void cycleEdgeOrientation(short int &c1, short int &c2, short int &c3, short int &c4);
};
